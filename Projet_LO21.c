/**
 * @file Projet_LO21.c
 * @author Becker Esteban, Pierre-Olivier Cayetanot
 * @brief Program that use bucket sort to sort a list given in parameter in a defined base
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Creative Commons Attribution Non-Commercial (CC BY-NC) 2020
 * 
 */

#include <stdio.h>
#include "bucket.h"

int main(int argc, char *argv[]){
    
    int max;
    list_of_buckets liste;

    max = max_lengh_list(argv,argc);

    printf("%d\n",max);//fonction de debug

    return 0;
}