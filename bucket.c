#include <stdio.h>
#include <string.h>

#include "bucket.h"

int max_lengh_list(char** liste, int lengh){
    int max = 0;
    for(int i = 1; i < lengh; i++){
        if(strlen(liste[i]) > max){
            max = strlen(liste[i]);
        }
    }
    return max;
}
