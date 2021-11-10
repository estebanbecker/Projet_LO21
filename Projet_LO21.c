#include <stdio.h>
#include "bucket.h"

int main(int argc, char *argv[]){
    
    int max;
    list_of_buckets list[12] = {NULL};

    max = max_lengh_list(argv,argc);

    printf("%d\n",max);//fonction de debug

    return 0;
}