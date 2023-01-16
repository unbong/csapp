#include <arpa/inet.h>

int main(int argc, char const *argv[])
{


    if(argc != 2)
    {
        printf("argv invaild.\n");
        exit(1);
    }

    char * src = argv[1];
    //char * src = "255.255.0.1";
    int dst = 0;
    int ret = inet_pton(AF_INET,src,  &dst);
    if(ret <1){
        printf("ip to n failed.\n");
        exit(1);
    }
    
    uint32_t dst2 = htonl(dst);
    
    printf("%x \n",dst2);

    return 0;
}
