#include <arpa/inet.h>
#include <stdlib.h>
#include <stdio.h>

int main(int argc, char const *argv[])
{


    // if(argc != 2)
    // {
    //     printf("argv invaild.\n");
    //     exit(1);
    // }
    
    // char * src = argv[1];

    char * src = "0x8002c3f3";
    int ipsrc = atoi(src);
    
    char  dst[20] ;
    char * ret = inet_ntop(AF_INET,src, dst, sizeof(dst));
    if(ret ==1){
        printf("ip to n failed.\n");
        exit(1);
    }
    
    uint32_t dst2 = htonl(dst);
    
    printf("%x \n",dst2);

    return 0;
}
