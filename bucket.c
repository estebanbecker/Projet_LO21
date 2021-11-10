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

bucket add_head(bucket seau, char *nombre)
{
    bucket new_seau;
    strcpy(new_seau->val, nombre);
    new_seau->next = seau;
    return new_seau;
}

bucket remove_head(bucket seau){
    bucket new_seau;
    new_seau = seau->next;
    free(seau);
    return new_seau;
}

bucket move_head(bucket seau_from, bucket seau_to){
    bucket new_seau;
    add_head(seau_to, seau_from->val);
    new_seau = remove_head(seau_from);
    return new_seau;
}
