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
#include <string.h>
#include "bucket.h"

int are_argument_valid(int argc, char *argv[]);

int main(int argc, char *argv[]){
    
    if(argc <3){
        printf("Usage: %s <base> <list>\n", argv[0]);
        return EXIT_FAILURE;
    }
    if(!are_argument_valid(argc, argv)){
        printf("Usage: %s <base> <list>\n", argv[0]);
        return EXIT_FAILURE;
    }

    int max, base=atoi(argv[1]);
    list_of_buckets liste;

    liste = create_list_of_buckets(base);
    

    liste=initialize_list_of_buckets(argc, argv, liste);
    
    max = max_lengh_list(argv, argc);
    

    liste=sort_list_of_buckets(liste, max, base);

    print_list_of_buckets(liste, base);

    return 0;
}


/**
 * @brief Verify that the arguments are valid, which means that the first argument is a positive integer and the list is a list of numbers is in the base
 * 
 * @param argc 
 * @param argv 
 * @return int 1=valid, 0=invalid
 */
int are_argument_valid(int argc, char *argv[]){
    
    int len=strlen(argv[1]), result=1;

    for(int i=0;i<len;i++){
        if(argv[1][i]<'0' || argv[1][i]>'9'){
            printf("Please use a valid base\n");
            return 0;
        }
    }
    if(atoi(argv[1])>16){
        printf("Please use a valid base\n");
        return 0;
    }
    for(int i=2;i<argc;i++){
        len=strlen(argv[i]);
        for(int j=0;j<len;j++){

            if(string_to_int_conversion(argv[i][j])>=atoi(argv[1]) || string_to_int_conversion(argv[i][j])==-1){
                result=0;
                
            }
        }
        
    }
    if(result==0){
        printf("The number list does not fit in the base\n");
    }
    return result;

}