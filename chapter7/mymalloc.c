#ifdef RUNTIME
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <dlfcn.h>

void * malloc(size_t size)
{
    void * (* mallocop) (size_t size);
    char * error;

    mallocop = dlsym(RTLD_NEXT, "malloc");  // 取得 libc的malloc
    if( (error = dlerror()) != NULL){
        fputs(error, stderr);
        exit(1);
    }
    
    
    
    void * ptr = mallocop(size);
    
    printf("malloc() %ld", size);
    //printf("malloc() %ld", size);
    //printf("malloc() %p", ptr);
    return ptr;
}

void free(void * ptr){

    void (* freep) (void * ) = NULL;
    char * error;

    if(!ptr) return;
    
    freep = dlsym(RTLD_NEXT, "free");
    if( (error = dlerror()) != NULL )
    {
        fputs(error, stderr);
        exit(1);
    }

    freep(ptr);
    printf("free(%p) \n", ptr);
}


#endif