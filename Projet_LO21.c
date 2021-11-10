#include <stdio.h>
#include "bucket.h"

int main(int argc, char *argv[]){
    
    int max;

    max = max_lengh_list(argv,argc);
    printf("%d\n",max);

    return 0;
}