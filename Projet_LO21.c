/**
 * @file Projet_LO21.c
 * @author Becker Esteban, Pierre-Olivier Cayetanot
 * @brief Program using a bucket sort to sort a list of numbers given in parameter in a defined base given as first argument
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
    
    max = max_length_list(argv, argc);
    

    liste=sort_list_of_buckets(liste, max, base);

    print_list_of_buckets(liste, base);

    return 0;
}


/**
 * @brief Verify that the arguments are valid, meaning that the first argument (the basis) is a positive integer between 1 and 16
 * and that the list contains numbers valid for the basis (e.g. 12 isn't valid in base 2)
 * 
 * @param argc 
 * @param argv 
 * @return int 1=valid, 0=invalid
 */
int are_argument_valid(int argc, char *argv[]){
    
    int len=strlen(argv[1]), result=1;

    for(int i=0;i<len;i++){
        if(argv[1][i]<'0' || argv[1][i]>'9'){
            printf("Base is not a number !\n Please use a valid base\n");
            return 0;
        }
    }
    if(atoi(argv[1])>16){
        printf("Base can't be above hexadecimal !\n Please use a valide base\n");
        return 0;
    }
    for(int i=2;i<argc;i++){
        len=strlen(argv[i]);
        if(len > 10){
            result=0;    
        }
        for(int j=0;j<len;j++){

            if(string_to_int_conversion(argv[i][j])>=atoi(argv[1]) || string_to_int_conversion(argv[i][j])==-1){
                result=0;

            }
        }
        
    }
    if(result==0){
        printf("A number in the list does not fit in the base\n Please use a valid set of numbers !\n");
    }
    return result;

}
