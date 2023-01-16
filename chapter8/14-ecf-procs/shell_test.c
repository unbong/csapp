#include "csapp.h"


// int parseline(char * buf, char **argval){
//     int argcount=0 ;
//     char split = ' ';
//     int start=0;
//     int end=0;
//     char cutpoint = *buf;
    
    
//     // 跳过开头的空格
//     while( cutpoint == ' '  )
//     {
//         start++;
//         buf++;
//         cutpoint = *buf;
//     }
//     //buf = buf[start];
    
//     // int buf_len = strlen(buf);
//     // buf[buf_len-1] = ' ';

//     while(cutpoint != NULL){

//         if(cutpoint == ' ')
//         {
//             // char * dest = "";
//             // strncpy(dest, "this is test case 1." ,  end - start );
//             // start = end +1;
//             // argval[argcount++] = dest;
//             // buf = &buf[start];
//             buf[end] = 0;
//             argval[argcount++] = buf+end;
//         }
//         end++;
//         cutpoint = buf[end];
//     }
// }

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

int main()
{
    
    char * buf = "this is test case 1.";
    char * argval[100] ;

    parseline(buf, argval);
    int i = 0;
    while(argval[i] != NULL)
    {
        printf("arg%d: %s", i, argval[i]);
        i++;
    }
    
    return 0;
}
