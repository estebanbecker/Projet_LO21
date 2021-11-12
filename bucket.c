/**
 * @file bucket.c
 * @author Becker Esteban, Pierre-Olivier Cayetanot
 * @brief All the functions to manage the bucket.
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Creative Commons Attribution Non-Commercial (CC BY-NC)
 * 
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

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
    element *temp=malloc(sizeof(element));
    strcpy(temp->val, nombre);
    temp->next = seau;
    return temp;
}

bucket remove_head(bucket seau){
    element *temp;
    if(seau != NULL){
        temp->next = seau->next;
        free(seau);
    }
    return temp;
}

bucket move_head(bucket seau_from, bucket seau_to){
    element * temp;;
    add_head(seau_to, seau_from->val);
    temp = remove_head(seau_from);
    return temp;
}
