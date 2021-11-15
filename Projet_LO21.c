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

    char* char_base = argv[1];
    int base = string_to_int_conversion(*char_base);

    base = 16;

    list_of_buckets liste = create_list_of_buckets(base);
    initialize_list_of_bucket(argc, argv, liste);

    for (int i  = 0; i  < base; ++i ) {
        print_list_of_buckets(liste);
        liste = sort_list_of_buckets(liste, i, base);
    }
}
//    int max;
//    list_of_buckets liste;
//    max = max_lengh_list(argv,argc);
//    printf("%d\n",max);//fonction de debug
//    return 0;