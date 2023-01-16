#include "csapp.h"

/* $begin fork */
/* $begin wasidefork */


void fork1()
{
    if(Fork() == 0){
        printf("a"); fflush(stdout);
    }
    else{
        printf("b"); fflush(stdout);
        waitpid(-1, NULL, 0);
    }

    printf("c"); fflush(stdout);
    //printf("\n");
    exit(0);

}

void fork2()
{
    pid_t pid;
    printf("0 ppid: %d, pid: %d\n", getppid(),getpid());
    Fork();
    printf("a ppid: %d, pid: %d\n", getppid(),getpid());
    Fork();    
    printf("b ppid: %d, pid: %d\n", getppid(),getpid());

    //if(pid != 0)
    while( waitpid(-1, NULL, 0) > 0){

    }
    printf("c ppid: %d, pid: %d\n", getppid(),getpid());
    //printf("\n");
    exit(0);

}

void fork3()
{
    pid_t pid;
    int N = 2;
    int status ;
    for(int i = 1; i<=N; i++)
    {
        if( (pid = Fork()) == 0  ) 
        {
            srand(10);
            Sleep(rand()%5);
            exit(100+i);

        }
    }

    int s = 0;
    int retpid;
    while( (retpid = waitpid(-1, &status, 0) )> 0){
        if( WIFEXITED(status) )
        {
            printf("child %d terminated normally with exit status=%d\n",retpid, WEXITSTATUS(status));
        }    
        else {
            printf("child %d terminated abnormally \n", retpid );
        }    
    }

    if(errno != ECHILD)
        unix_error("waitpid error");
    //printf("\n");
    exit(0);

}

void fork4()
{
    
    int N = 2;
    pid_t pid, pids[N];
    int status ;
    for(int i = 0; i<N; i++)
    {
        if( (pids[i] = Fork()) == 0  ) 
        {
            srand(10);
            Sleep(rand()%5);
            exit(100+i);

        }
    }

    int s = 0;
    int retpid;
    while( (retpid = waitpid(pids[s++], &status, 0) )> 0){
        if( WIFEXITED(status) )
        {
            printf("child %d terminated normally with exit status=%d\n",retpid, WEXITSTATUS(status));
        }    
        else {
            printf("child %d terminated abnormally \n", retpid );
        }    
    }

    if(errno != ECHILD)
        unix_error("waitpid error");
    //printf("\n");
    exit(0);

}

void sigint_handler(int sig){
    printf("Caught SIGINT\n");
    exit(0);
}

void fork5()
{
    if(signal(SIGINT, sigint_handler)  == SIG_ERR){
        unix_error("signal error");
    }

    Pause();
}

void sigint_handler2(int sig){
    printf("Slept for %d of %d");
}

void fork6(unsigned sec)
{
    if(signal(SIGINT, sigint_handler2) == SIG_ERR)
    {
        unix_error("signal error.");
    }

    sleep(sec);

}


void fork7()
{
    pid_t pid;

    if((pid = Fork()) == 0){

        printf("child print\n");
        exit(0);
    }

    printf("child pid %d\n", pid);
    Sleep(10);
    printf("wait e\n");
    waitpid(pid, NULL, 0);
     printf("sleep e\n");
    Sleep(10);
    printf("end fork7\n");
}


int main(int argc, char *argv[]) 
{
    // pid_t pid;
    // int x = 1;

    // pid = Fork(); //line:ecf:forkreturn
    // if (pid == 0) {  /* Child */
	// printf("child %d : x=%d\n",pid, ++x); //line:ecf:childprint
	// exit(0);
    // }

    // /* Parent */
    // printf("parent:%d x=%d\n",pid, --x); //line:ecf:parentprint
    // exit(0);


    int option = 0;
    if (argc > 1)
	option = atoi(argv[1]);
    switch(option) {
    case 1: fork1();
	break;
    
    case 2: fork2();
	break;
    case 3: fork3();
	break;
    case 4: fork4();
	break;
    case 5: fork5();
	break;
    // case 6: fork6();
	// break;
    case 7: fork7();
	break;
    // case 8: fork8();
	// break;
    // case 9: fork9();
	// break;
    // case 10: fork10();
	// break;
    // case 11: fork11();
	// break;
    // case 12: fork12();
	// break;
    // case 13: fork13();
	// break;
    // case 14: fork14();
	// break;
    // case 15: fork15();
	// break;
    // case 16: fork16();
	// break;
    // case 17: fork17();
	//break;
    default:
	printf("Unknown option %d\n", option);
	break;
    }
    return 0;
}
/* $end fork */
/* $end wasidefork */

