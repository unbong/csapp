#include "cachelab.h"
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

typedef struct  line_s
{
    /* data */
    char is_valid;          // 
    unsigned long  tag;     //  tag
    int count;              // count  
} line_s ;

typedef struct set_s{
    int lineSize ;
    line_s * lines ;
}set_s ;

typedef struct summary{
    int miss ;
    int evict ;
    int hit;
} summary;



void print_help()
{
    printf("Usage: ./csim [-hv] -s <num> -E <num> -b <num> -t <file>\n");
    printf("Options:\n");
    printf("  -h         Print this help message.\n");
    printf("  -v         Optional verbose flag.\n");
    printf("  -s <num>   Number of set index bits.\n");
    printf("  -E <num>   Number of lines per set.\n");
    printf("  -b <num>   Number of block offset bits.\n");
    printf("  -t <file>  Trace file.\n");

    printf("\n");
    printf("Examples:\n");
    printf("  linux>  ./csim-ref -s 4 -E 1 -b 4 -t traces/yi.trace\n");
    printf("  linux>  ./csim-ref -v -s 8 -E 2 -b 4 -t traces/yi.trace\n");
}

int parse_param(int count,char const *argv[], int * s, int * E, int * b,  bool * v,const char ** t)
{
    for(int i = 1; i < count; i++){
        if (strcmp("-h", argv[i]) == 0){
            print_help();
            exit(0);
        }
        else if(strcmp("-s", argv[i])== 0)
        {
            i++;
            *s = atoi(argv[i]);
        }
        else if(strcmp("-E", argv[i])== 0)
        {
            i++;
            *E = atoi(argv[i]);
        }
        else if(strcmp("-b", argv[i])== 0)
        {
            i++;
            *b = atoi(argv[i]);
        }
        else if(strcmp("-t", argv[i]) == 0)
        {
            i++;
            *t = argv[i];
        }
        else if(strcmp("-v", argv[i])== 0)
        {
            
            *v = true;
        }
    }
    return 0;
}


void initializeCache(long setSize, long E, long blockSize, set_s * sets )
{   
    for(int i = 0; i < setSize; i++)
    {
        sets[i].lineSize = E;
        sets[i].lines = (line_s *)malloc(E * sizeof(line_s));
        for(int j = 0; j < E; j++)
        {
            sets[i].lines[j].is_valid = false;
            sets[i].lines[j].tag = __LONG_MAX__;
            sets[i].lines[j].count =0;
            
        }
    }
    
    // char *  malloc(blockSize * sizeof(char));
}   

void freeCache(long setSize, long E, long blockSize, set_s * sets ){

    for(int i = setSize -1; i >= 0; i--)
    {
        for(int j = E-1; j>= 0 ; j--)
        {
            
            // for(int z = blockSize-1; z >= 0; z--)
            // {
            //     free(sets[i].lines[j].blocks[z]);
            // }
            //free(sets[i].lines[j].blocks);
            
        }
        free(sets[i].lines);
    }
}


bool optCache(set_s * sets,
      unsigned long set_bit, unsigned long  tag_bit, char * text , summary * sum  )
{
    bool isHit = false;
    int oldestLine = -1;
    int maxCounter = 0;
    int E = sets[set_bit].lineSize;
      
    for(int i = 0; i < E; i++)
    {
        sets[set_bit].lines[i].count++; 
        // hit
        if(sets[set_bit].lines[i].tag == tag_bit 
            && sets[set_bit].lines[i].is_valid && !isHit )
        {
            sets[set_bit].lines[i].count = 0;
            isHit = true;
            strcat(text, " hit");
            sum->hit++;
        }
        if ( sets[set_bit].lines[i].count > maxCounter )
        {
            maxCounter = sets[set_bit].lines[i].count;
            oldestLine = i;
        }
    }

    // miss 
    if( !isHit  )
    {

        sets[set_bit].lines[oldestLine].count = 0;
        sets[set_bit].lines[oldestLine].is_valid = true;
        strcat(text, " miss");
        sum->miss ++;
        // 
        if(sets[set_bit].lines[oldestLine].tag != __LONG_MAX__  )
        {
            strcat(text, " eviction");
            sum->evict++;
        }
        sets[set_bit].lines[oldestLine].tag = tag_bit;
    }
    
    return isHit;
}


int main(int argc, char const *argv[])
{
    int s = 0;
    int E = 0;
    int b = 0;
    bool v = false;
    const char * t = NULL;
    
    
    parse_param(argc, argv, &s, &E, &b, &v , &t);
    printf("s %d, E %d, b %d, v %d, t %s \n", s, E,b,v, t);
    
    long   setSize = powl(2l, s);
    
    long blockSize = powl(2l, b);

    set_s sets[setSize];
    initializeCache(setSize, E, blockSize, sets);

    // read file 
    FILE * fp = fopen(t, "r");
    if(fp == NULL){

        exit(-1);
    }

    char mode;
    unsigned long addr;
    int size;

    summary sum ;
    sum.evict =0;
    sum.hit = 0;
    sum.miss = 0;
    char text[200];

    while( fscanf(fp, " %c %lx,%d", &mode, &addr, &size) > 0 )
    {
        if(mode == 'I') continue;
        unsigned long addrTmp = addr;
        // unsigned long block_bit =  addr & (blockSize - 1);
        addr =  addr >> b  ;
        unsigned long set_bit = addr & (setSize -1) ;
        addr =  addr >> s ;
        unsigned long  tag_bit =addr ;

        memset(text,0 ,200);
        sprintf(text, " %c %lx,%d", mode, addrTmp, size);
        // store or load
        if(mode == 'S' ||mode == 'L' )
        {
            
            // if line is not used
            optCache(sets, set_bit, tag_bit, text, &sum);
            
            // if line is used
            // LRU policy
            
        }
        else if(mode == 'M')
        {
            optCache(sets, set_bit, tag_bit, text, &sum);
            optCache(sets, set_bit, tag_bit, text, &sum);
        }

        if(v)
            printf("%s \n", text);
        
    }

    freeCache(setSize, E, blockSize, sets);
    printSummary(sum.hit, sum.miss, sum.evict);
    return 0;
}
