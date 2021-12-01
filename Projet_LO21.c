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
#include <stdlib.h>
#include "bucket.h"

int main(int argc, char *argv[]){
    
    int max, base=atoi(argv[1]);
    list_of_buckets liste;

    liste = create_list_of_buckets(base);
    

    liste=initialize_list_of_buckets(argc, argv, liste,base);


    max = max_lengh_list(argv, argc);


    print_list_of_buckets(liste, max);
    
    printf("%d",max);

    sort_list_of_buckets(liste,max,base);

    print_list_of_buckets(liste, max);

    return 0;
}