/* 
 * tsh - A tiny shell program with job control
 * 
 * <Put your name and login ID here>
 */
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <ctype.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* Misc manifest constants */
#define MAXLINE    1024   /* max line size */
#define MAXARGS     128   /* max args on a command line */
#define MAXJOBS      16   /* max jobs at any point in time */
#define MAXJID    1<<16   /* max job ID */

/* Job states */
#define UNDEF 0 /* undefined */
#define FG 1    /* running in foreground */
#define BG 2    /* running in background */
#define ST 3    /* stopped */

/* 
 * Jobs states: FG (foreground), BG (background), ST (stopped)
 * Job state transitions and enabling actions:
 *     FG -> ST  : ctrl-z
 *     ST -> FG  : fg command
 *     ST -> BG  : bg command
 *     BG -> FG  : fg command
 * At most 1 job can be in the FG state.
 */

/* Global variables */
extern char **environ;      /* defined in libc */
char prompt[] = "tsh> ";    /* command line prompt (DO NOT CHANGE) */
int verbose = 0;            /* if true, print additional output */
int nextjid = 1;            /* next job ID to allocate */
char sbuf[MAXLINE];         /* for composing sprintf messages */

struct job_t {              /* The job struct */
    pid_t pid;              /* job PID */
    int jid;                /* job ID [1, 2, ...] */
    int state;              /* UNDEF, BG, FG, or ST */
    char cmdline[MAXLINE];  /* command line */
};
struct job_t jobs[MAXJOBS]; /* The job list */
/* End global variables */

//volatile pid_t kill_pid = -1;
volatile pid_t gpid;
/* Function prototypes */
volatile char * gcmdline;
/* Here are the functions that you will implement */
void eval(char *cmdline);
int builtin_cmd(char **argv);
void do_bgfg(char **argv);
void waitfg(pid_t pid);

void sigchld_handler(int sig);
void sigtstp_handler(int sig);
void sigint_handler(int sig);

/* Here are helper routines that we've provided for you */
int parseline(const char *cmdline, char **argv); 
void sigquit_handler(int sig);

void clearjob(struct job_t *job);
void initjobs(struct job_t *jobs);
int maxjid(struct job_t *jobs); 
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline);
int deletejob(struct job_t *jobs, pid_t pid); 
pid_t fgpid(struct job_t *jobs);
struct job_t *getjobpid(struct job_t *jobs, pid_t pid);
struct job_t *getjobjid(struct job_t *jobs, int jid); 
int pid2jid(pid_t pid); 
void listjobs(struct job_t *jobs);

void usage(void);
void unix_error(char *msg);
void app_error(char *msg);
typedef void handler_t(int);
handler_t *Signal(int signum, handler_t *handler);

struct job_t * job_convert2pid(char ** argv);



/*
 * main - The shell's main routine 
 */
int main(int argc, char **argv) 
{
    char c;
    char cmdline[MAXLINE];
    int emit_prompt = 1; /* emit prompt (default) */

    /* Redirect stderr to stdout (so that driver will get all output
     * on the pipe connected to stdout) */
    dup2(1, 2);

    /* Parse the command line */
    while ((c = getopt(argc, argv, "hvp")) != EOF) {
        switch (c) {
        case 'h':             /* print help message */
            usage();
	    break;
        case 'v':             /* emit additional diagnostic info */
            verbose = 1;
	    break;
        case 'p':             /* don't print a prompt */
            emit_prompt = 0;  /* handy for automatic testing */
	    break;
	default:
            usage();
	}
    }

    /* Install the signal handlers */

    /* These are the ones you will need to implement */
    Signal(SIGINT,  sigint_handler);   /* ctrl-c */
    Signal(SIGTSTP, sigtstp_handler);  /* ctrl-z */
    Signal(SIGCHLD, sigchld_handler);  /* Terminated or stopped child */

    /* This one provides a clean way to kill the shell */
    Signal(SIGQUIT, sigquit_handler); 

    /* Initialize the job list */
    initjobs(jobs);

    /* Execute the shell's read/eval loop */
    while (1) {

        /* Read command line */
        if (emit_prompt) {
            printf("%s", prompt);
            fflush(stdout);
        }
        if ((fgets(cmdline, MAXLINE, stdin) == NULL) && ferror(stdin))
            app_error("fgets error");
        if (feof(stdin)) { /* End of file (ctrl-d) */
            fflush(stdout);
            exit(0);
        }

        /* Evaluate the command line */
        eval(cmdline);
        fflush(stdout);
        fflush(stdout);
    } 

    exit(0); /* control never reaches here */
}
  
/* 
 * eval - Evaluate the command line that the user has just typed in
 * 
 * If the user has requested a built-in command (quit, jobs, bg or fg)
 * then execute it immediately. Otherwise, fork a child process and
 * run the job in the context of the child. If the job is running in
 * the foreground, wait for it to terminate and then return.  Note:
 * each child process must have a unique process group ID so that our
 * background children don't receive SIGINT (SIGTSTP) from the kernel
 * when we type ctrl-c (ctrl-z) at the keyboard.  
*/
void eval(char *cmdline) 
{

    // 解析 参数
    char buf[MAXLINE];
    strcpy(buf, cmdline);
    char * argval[MAXARGS];
    int bg = parseline(buf, argval);

    if(argval[0] == NULL) return ;
 
    
    // 执行 指令 
    // 非内置命令 
    if( !builtin_cmd(argval))
    {
        // 否则执行路径上的命令
        // fork execve执行命令
        pid_t pid ;
        sigset_t maskall, maskone,mask_int,mask_tstp, prev, prev_int, prev_tstp;
        sigemptyset(&maskone);
        sigemptyset(&prev);
        sigemptyset(&prev_int);
        sigemptyset(&prev_tstp);
        sigaddset(&maskone, SIGCHLD);
        sigaddset(&mask_int, SIGINT);
        sigaddset(&mask_tstp, SIGTSTP);
        sigfillset(&maskall);
        sigprocmask(SIG_BLOCK, &maskone, &prev);
        sigprocmask(SIG_BLOCK, &mask_int,&prev_int);
        sigprocmask(SIG_BLOCK, &mask_tstp, &prev_tstp);

        if( (pid = fork() ) == 0 )
        {
            Signal(SIGINT, SIG_DFL);
            Signal(SIGTSTP, SIG_DFL);  /* ctrl-z */
            sigprocmask(SIG_SETMASK, &prev, NULL);
            setpgid(0, 0);
            execve(argval[0], argval, environ);
        }

        // 后台执行
        if(bg)
        {
            
            // 同步jobs的数据
            sigprocmask(SIG_BLOCK, &maskall, NULL);
            addjob(jobs, pid, BG, cmdline);
            sigprocmask(SIG_SETMASK, &prev, NULL);
            struct job_t * job = getjobpid(jobs, pid);
            printf("[%d] (%d) %s\n", job->jid, job->pid, job->cmdline);
        }
        else{
            // 前台执行
            gcmdline = cmdline;
            gpid = pid;
            // 解除 SIGINT, SIGCHLD的阻塞
            sigprocmask(SIG_SETMASK, &prev, NULL);
            
            // if(waitpid(pid, NULL, 0)<0){
            //     unix_error("wait child error\n");
            // }
            waitfg(pid);
        }
    }
    // 内置命令 
    else{
        
    }
    
    return;
}

/* 
 * parseline - Parse the command line and build the argv array.
 * 
 * Characters enclosed in single quotes are treated as a single
 * argument.  Return true if the user has requested a BG job, false if
 * the user has requested a FG job.  
 */
int parseline(const char *cmdline, char **argv) 
{
    static char array[MAXLINE]; /* holds local copy of command line */
    char *buf = array;          /* ptr that traverses command line */
    char *delim;                /* points to first space delimiter */
    int argc;                   /* number of args */
    int bg;                     /* background job? */

    strcpy(buf, cmdline);
    buf[strlen(buf)-1] = ' ';  /* replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* ignore leading spaces */
	buf++;

    /* Build the argv list */
    argc = 0;
    if (*buf == '\'') {
	buf++;
	delim = strchr(buf, '\'');
    }
    else {
	delim = strchr(buf, ' ');
    }

    while (delim) {
	argv[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* ignore spaces */
	       buf++;

	if (*buf == '\'') {
	    buf++;
	    delim = strchr(buf, '\'');
	}
	else {
	    delim = strchr(buf, ' ');
	}
    }
    argv[argc] = NULL;
    
    if (argc == 0)  /* ignore blank line */
	return 1;

    /* should the job run in the background? */
    if ((bg = (*argv[argc-1] == '&')) != 0) {
	argv[--argc] = NULL;
    }
    return bg;
}

/* 
 * builtin_cmd - If the user has typed a built-in command then execute
 *    it immediately.  
 */
int builtin_cmd(char **argv) 
{

    sigset_t mask_int,  prev_int, mask_tstp, prev_tstp;
    sigemptyset(&prev_int);
    sigaddset(&mask_int, SIGINT);
    sigemptyset(&prev_tstp);
    sigaddset(&mask_tstp, SIGTSTP);

    //sigprocmask(SIG_BLOCK, &maskone, &prev);
    
    //  
    if( strcmp(argv[0], "quit") == 0){
        exit(0);
    }
    // The fg <job> command restarts <job> by sending it a SIGCONT signal, and then runs it in
    // the foreground. The <job> argument can be either a PID or a JID
    // %5 jid 5 pid
    else if(strcmp(argv[0], "fg") == 0){
        
        if(argv[1] == NULL){
            printf("commad fg <job> is invalid.\n");
            return 1;
        }

        struct job_t * job = job_convert2pid(argv);

        if(job == NULL) return 1;
        // 如果状态是STOP  发送SIGCONT 状态设置为FG
        if(job->state == ST)
        {
            kill(job->pid, SIGCONT);
            job->state = FG;
        }
        // 如果状态是BG 发送SIGCONT 状态=FG
        else if(job->state == BG)
        {
            sigprocmask(SIG_BLOCK, &mask_int,&prev_int);
            sigprocmask(SIG_BLOCK, &mask_tstp, &prev_tstp);

            kill(job->pid, SIGCONT);
            job->state = FG;

            gpid = job->pid;
            sigprocmask(SIG_SETMASK, &prev_int, NULL);            
        
        }
        waitfg(job->pid);

        return 1;
    }
    // bg <job> command restarts <job> by sending it a SIGCONT signal, and then runs it in
    // the background. The <job> argument can be either a PID or a JID
    else if(strcmp(argv[0], "bg") == 0){
        
        
        if(argv[1] == NULL)
        {
            printf("commad bg <job> is invalid.\n");
            return 1;
        }
        // 判断job的状态是否为
        //int jid;
        // 判断pid还是jid 如果是jid 则转换正pid
        struct job_t *job = job_convert2pid(argv);
        
        if(job == NULL)
        {
            return 1;
        }
        // 如果job的状态不是STOP 则什么都不做
        if(job->state != ST){
            return 1;
        }
        job->state = BG;
        // 对id 发送SIGCONT信号
        kill(job->pid, SIGCONT);
        return 1;
    }   
    // command lists all background jobs
    else if(strcmp(argv[0], "jobs") == 0){

        listjobs(jobs);
        return 1;
    }
    
    else if(strcmp(argv[0], "kill") == 0){
        if(argv[1] == NULL)
        {
            printf("commad kill <job> is invalid.\n");
            return 1;
        }

        struct job_t *job = job_convert2pid(argv);
        
        // 对id 发送SIGKILL信号
        //kill_pid = job->pid;
        kill(job->pid, SIGKILL);

        return 1;
    }
    else if(strcmp(argv[0], "&") == 0){
        return 1;
    }
    return 0;     /* not a builtin command */
}

/* 
 * do_bgfg - Execute the builtin bg and fg commands
 */
void do_bgfg(char **argv) 
{

    return;
}

/* 
 * waitfg - Block until process pid is no longer the foreground process
 */
void waitfg(pid_t pid)
{
    if(waitpid(pid,NULL, WUNTRACED) <0)
        unix_error("wait child error\n");
    return;
}

/*****************
 * Signal handlers
 *****************/

/* 
 * sigchld_handler - The kernel sends a SIGCHLD to the shell whenever
 *     a child job terminates (becomes a zombie), or stops because it
 *     received a SIGSTOP or SIGTSTP signal. The handler reaps all
 *     available zombie children, but doesn't wait for any other
 *     currently running children to terminate.  
 */
void sigchld_handler(int sig) 
{
    int olderrno = errno;
    sigset_t maskall, prev;
    sigemptyset(&prev);
    sigfillset(&maskall);
    
    pid_t pid;
    while((pid =waitpid(-1, NULL, WNOHANG|WUNTRACED)) >0){
        //write(STDOUT_FILENO, "reap child\n", 12);
        
        // block all signal
        sigprocmask(SIG_BLOCK, &maskall, &prev);
        
        deletejob(jobs, pid);
        sigprocmask(SIG_SETMASK, &prev, NULL);
    }
    
    //kill_pid = -1;
    // if(errno != ECHILD)
    //     write(STDOUT_FILENO, "waitpid error\n", 13);
    
    errno = olderrno;
    return;
}

/* 
 * sigint_handler - The kernel sends a SIGINT to the shell whenver the
 *    user types ctrl-c at the keyboard.  Catch it and send it along
 *    to the foreground job.  
 */
void sigint_handler(int sig) 
{
    int olderrno = errno;
    // 取得要中断的pid 
    // 取得pid的进程组
    // 终止进程组中的进程
    sigset_t maskall, prev;
    sigemptyset(&prev);
    sigfillset(&maskall);
    kill(gpid, SIGINT);
    //struct job_t * job = getjobpid(jobs, gpid);
    //write(STDOUT_FILENO, "Job ",);
    sigprocmask(SIG_BLOCK, &maskall, &prev);
    deletejob(jobs, gpid);
    sigprocmask(SIG_SETMASK, &prev, NULL); 
    errno = olderrno;
    return;
}

/*
 * sigtstp_handler - The kernel sends a SIGTSTP to the shell whenever
 *     the user types ctrl-z at the keyboard. Catch it and suspend the
 *     foreground job by sending it a SIGTSTP.  
 */
void sigtstp_handler(int sig) 
{

    int olderrno = errno;
    sigset_t maskall, prev;
    sigemptyset(&prev);
    sigfillset(&maskall);
    
    kill(gpid, SIGTSTP);
    printf("gpid:%d", gpid);
    sigprocmask(SIG_BLOCK, &maskall, &prev);
    struct job_t *job = getjobpid(jobs, gpid);
    if(job == NULL)
    {   
        addjob(jobs, gpid, ST, gcmdline);
    }
    else 
        job->state = ST;
    //deletejob(jobs, gpid);
    // 将jobs更新为stop
    
    sigprocmask(SIG_SETMASK, &prev, NULL); 
    errno = olderrno;
    //write(STDOUT_FILENO, "SIGTSTP sended\n", 20);
    return;
}

/*********************
 * End signal handlers
 *********************/

/***********************************************
 * Helper routines that manipulate the job list
 **********************************************/

/* clearjob - Clear the entries in a job struct */
void clearjob(struct job_t *job) {
    job->pid = 0;
    job->jid = 0;
    job->state = UNDEF;
    job->cmdline[0] = '\0';
}

/* initjobs - Initialize the job list */
void initjobs(struct job_t *jobs) {
    int i;

    for (i = 0; i < MAXJOBS; i++)
	clearjob(&jobs[i]);
}

/* maxjid - Returns largest allocated job ID */
int maxjid(struct job_t *jobs) 
{
    int i, max=0;

    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].jid > max)
	    max = jobs[i].jid;
    return max;
}

/* addjob - Add a job to the job list */
int addjob(struct job_t *jobs, pid_t pid, int state, char *cmdline) 
{
    int i;
    
    if (pid < 1)
	return 0;

    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid == 0) {
	    jobs[i].pid = pid;
	    jobs[i].state = state;
	    jobs[i].jid = nextjid++;
	    if (nextjid > MAXJOBS)
		nextjid = 1;
	    strcpy(jobs[i].cmdline, cmdline);
  	    if(verbose){
	        printf("Added job [%d] %d %s\n", jobs[i].jid, jobs[i].pid, jobs[i].cmdline);
            }
            return 1;
	}
    }
    printf("Tried to create too many jobs\n");
    return 0;
}

/* deletejob - Delete a job whose PID=pid from the job list */
int deletejob(struct job_t *jobs, pid_t pid) 
{
    int i;

    if (pid < 1)
	return 0;

    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid == pid) {
	    clearjob(&jobs[i]);
	    nextjid = maxjid(jobs)+1;
	    return 1;
	}
    }
    return 0;
}

/* fgpid - Return PID of current foreground job, 0 if no such job */
pid_t fgpid(struct job_t *jobs) {
    int i;

    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].state == FG)
	    return jobs[i].pid;
    return 0;
}

/* getjobpid  - Find a job (by PID) on the job list */
struct job_t *getjobpid(struct job_t *jobs, pid_t pid) {
    int i;

    if (pid < 1)
	return NULL;
    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].pid == pid)
	    return &jobs[i];
    return NULL;
}

/* getjobjid  - Find a job (by JID) on the job list */
struct job_t *getjobjid(struct job_t *jobs, int jid) 
{
    int i;

    if (jid < 1)
	return NULL;
    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].jid == jid)
	    return &jobs[i];
    return NULL;
}

/* pid2jid - Map process ID to job ID */
int pid2jid(pid_t pid) 
{
    int i;

    if (pid < 1)
	return 0;
    for (i = 0; i < MAXJOBS; i++)
	if (jobs[i].pid == pid) {
            return jobs[i].jid;
        }
    return 0;
}

/* listjobs - Print the job list */
void listjobs(struct job_t *jobs) 
{
    int i;
    
    for (i = 0; i < MAXJOBS; i++) {
	if (jobs[i].pid != 0) {
	    printf("[%d] (%d) ", jobs[i].jid, jobs[i].pid);
	    switch (jobs[i].state) {
		case BG: 
		    printf("Running ");
		    break;
		case FG: 
		    printf("Foreground ");
		    break;
		case ST: 
		    printf("Stopped ");
		    break;
	    default:
		    printf("listjobs: Internal error: job[%d].state=%d ", 
			   i, jobs[i].state);
	    }
	    printf("%s", jobs[i].cmdline);
	}
    }
}
/******************************
 * end job list helper routines
 ******************************/


/***********************
 * Other helper routines
 ***********************/

/*
 * usage - print a help message
 */
void usage(void) 
{
    printf("Usage: shell [-hvp]\n");
    printf("   -h   print this message\n");
    printf("   -v   print additional diagnostic information\n");
    printf("   -p   do not emit a command prompt\n");
    exit(1);
}

/*
 * unix_error - unix-style error routine
 */
void unix_error(char *msg)
{
    fprintf(stdout, "%s: %s\n", msg, strerror(errno));
    exit(1);
}

/*
 * app_error - application-style error routine
 */
void app_error(char *msg)
{
    fprintf(stdout, "%s\n", msg);
    exit(1);
}

/*
 * Signal - wrapper for the sigaction function
 */
handler_t *Signal(int signum, handler_t *handler) 
{
    struct sigaction action, old_action;

    action.sa_handler = handler;  
    sigemptyset(&action.sa_mask); /* block sigs of type being handled */
    action.sa_flags = SA_RESTART; /* restart syscalls if possible */

    if (sigaction(signum, &action, &old_action) < 0)
	unix_error("Signal error");
    return (old_action.sa_handler);
}

/*
 * sigquit_handler - The driver program can gracefully terminate the
 *    child shell by sending it a SIGQUIT signal.
 */
void sigquit_handler(int sig) 
{
    printf("Terminating after receipt of SIGQUIT signal\n");
    exit(1);
}

/*
    将内置指令的参数的 <JOB> 返回job
*/
struct job_t * job_convert2pid(char ** argv)
{
    int jid;
    struct job_t * job = NULL;
    if(argv[1][0] == '%')
    {
        jid = atoi(argv[1]+1);
        job  = getjobjid(jobs, jid);
        if (job == NULL){
            printf("jobid is invalid,<jid %d>\n",jid);
            return job;
        }
    }
    else {
        
        pid_t pid =  atoi(argv[1]);
        if(pid == 0)
        {
            printf("pid is invalid,<jid %d>\n",pid);
            return job;
        }

        job = getjobpid(jobs, pid);
    }
    return job;
}


