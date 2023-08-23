#include "shell.h"
#define MAXARGS 128
#define FGPGID 121

int main()
{
    
   char cmd[MAXARGS];

    while(1){

        printf(">");
        Fgets(cmd, MAXARGS, stdin);
        if(feof(stdin))
            exit(0);

        eval(cmd);
    }

    return 0;
}

int parseline(char *buf, char **argval) 
{
    char *delim;         /* Points to first space delimiter */
    int argc;            /* Number of args */
    int bg;              /* Background job? */

    buf[strlen(buf)-1] = ' ';  /* Replace trailing '\n' with space */
    while (*buf && (*buf == ' ')) /* Ignore leading spaces */
	buf++;

    /* Build the argval list */
    argc = 0;
    while ((delim = strchr(buf, ' '))) {
	argval[argc++] = buf;
	*delim = '\0';
	buf = delim + 1;
	while (*buf && (*buf == ' ')) /* Ignore spaces */
            buf++;
    }
    argval[argc] = NULL;
    
    if (argc == 0)  /* Ignore blank line */
	return 1;

    /* Should the job run in the background? */
    if ((bg = (*argval[argc-1] == '&')) != 0)
	argval[--argc] = NULL;

    return bg;
}

int built_command(char ** argv)
{
    if(strcmp(argv[0], "quit") == 0){
        exit(0);
    }
    else if(strcmp(argv[0], "&") == 0){ 
        return 1;
    }
    else if(strcmp(argv[0], "fg") ==0)
    {
        pid_t pid = atoi(argv[1]);

        kill(pid, SIGCONT);
        waitpid(pid, NULL, 0);
        printf("run fg\n");
        return 1;
    }
    return 0;
}

void sigint_handler(int sig){
    
    killpg(FGPGID, SIGINT);
}

void sigtstp_handler(int sig){
    killpg(FGPGID, SIGTSTP);
}

void sigchld_handler(int sig){

    sigset_t mask, prev;
    Sigemptyset(&mask);
    Sigaddset(&mask, SIGCHLD);
    Sigprocmask(SIG_BLOCK, &mask, &prev);
    
    while( waitpid(-1, NULL, 0) > 0 ) {

    }
    Sigprocmask(SIG_SETMASK, &prev, NULL);
    exit;
}


void eval(char * cmdline){

    // 解析cmd 
    char *argv[MAXARGS]; /* Argument list execve() */
    char buf[MAXLINE];   /* Holds modified command line */
    int bg;              /* Should the job run in bg or fg? */
    pid_t pid;           /* Process id */
    
    strcpy(buf, cmdline);

    bg = parseline(buf, argv);

    //printf("pgid: %d, pid: %d, ppgid: %d, ppid:%d \n", getpgid(getpid()), getpid(), getpgid(getppid()), getppid());
    if(argv[0] == NULL)
        return;
    
    signal(SIGINT, sigint_handler);
    signal(SIGTSTP, sigtstp_handler);


    // 根据cmd 生成用于execve执行的内容
    if(!built_command(argv))
    {
        if((pid= Fork()) == 0)
        {
            //Setpgid(getpid(), getpgid(getppid()));
            if(! bg)
            {
                setpgid(getpid(), FGPGID);
            }
            if(execve(argv[0], argv, environ)<0){
                printf("%s Command not found\n", argv[0]);
                exit(0);
            }
        }
        
        // back running
        if(bg)
        {
            signal(SIGCHLD, sigchld_handler );
        }
        // 前台作业
        else{
            int status;
            Waitpid(pid, &status, 0);
        }
    }
    
    
    // 执行cmd 根据是前台作业还是后台作业需要做区分 how
}