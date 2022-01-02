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


void free_bucket(bucket seau){
    bucket current = seau, next;
    while (current != NULL) {
        next = current->next;
        free(current);
        if(next != NULL) {
            current = next;
        }
    }
}

void print_bucket(bucket seau){
    int j;
    bucket current = seau;
    while (current != NULL) {
        //print the value of current element without the 0 at the begening, example: 0000023587 -> 23587
        j=0;
        while (current->val[j] == '0' && j < 9) {
            j++;
        }
        printf("%s\n", current->val+ j);
        
        
        current = current->next;
    }
}

void print_list_of_buckets(list_of_buckets liste, int base){ 
    for(int i=0; i < base; i++){
        print_bucket(liste[i]);
    }

}

list_of_buckets create_list_of_buckets(int base){
    list_of_buckets liste = NULL;
    liste = malloc(sizeof(bucket) * base);
    for (int i = 0; i < base; ++i) {
        liste[i] = malloc(sizeof(bucket));
        liste[i] = NULL;
    }
    return liste;
}

list_of_buckets initialize_list_of_buckets(int argc, char *argv[], list_of_buckets liste){
    int size, size_null;
    char temp[MAX_LENGH_CHAR];
    for (int i = 2;i < argc;i++){
        for(int j = 0; j < MAX_LENGH_CHAR; j++){
            temp[j] = '\0';
        }
        size=strlen(argv[i]);
        size_null=10-size;

        for (int j = 0; j < size_null; ++j) {
            temp[j] = '0';
        }


        strcat(temp, argv[i]);

        liste[0]=add_tail(liste[0],temp );
        
        
    }
    return liste;
}

void free_list_of_buckets(list_of_buckets liste,int base){
    
    for(int i=0; i < base; i++){
        free_bucket(liste[i]);
    }
    free(liste);
}

char get_char_at_pos_in_bucket(bucket seau, int pos){
    int length = strlen(seau->val);
    if(pos <= length){
        char value = seau->val[length - pos];
        return value;
    } else {
        return '\0';
    }
}

int string_to_int_conversion(char character) {
    int result = -1;
    if( character > 47 && character < 58) {
        result = character - '0'; 
    } else if( character > 96 && character < 103){
        result = character - 'a' + 10; 
    } else if ( character > 64 && character < 71 ) {
        result = character - 'A' + 10; 
    } else {
        result = -1;
    }
    return result;
}

int max_length_list(char** liste, int length){
    int max = 0;
    for(int i = 2; i < length; i++){
        if(strlen(liste[i]) > max){
            max = strlen(liste[i]);
        }
    }
    return max;
}

bucket add_tail(bucket seau, char *nombre)
{
    element *insert = malloc(sizeof(element));
    element *temp;

    strcpy(insert->val, nombre);
    insert->next=NULL;

    if(seau==NULL){
        return insert;
    }else{
        temp=seau;
        while (temp->next !=NULL)
        {
            temp=temp->next;
        }
        temp->next=insert;
    }
    return seau;

}

bucket remove_head(bucket seau){
    bucket temp;
    if(seau != NULL){
        temp = seau->next;
        free(seau);
    }
    return temp;
}



list_of_buckets sort_list_of_buckets(list_of_buckets liste, int level, int base){

    list_of_buckets  liste_to;
    int value;

    if (level == 0) {
        return liste;
    } else {
        liste=sort_list_of_buckets(liste, level-1, base);
        liste_to=create_list_of_buckets(base);

        //printf("Level: %d\n", level);

        for (int i = 0 ; i<base ; i++){

           // printf("Analysing Bucket: %d\n", i);
            
            for(int j=0; j<base;j++){
            
                while (liste[i] != NULL) {
                    value = string_to_int_conversion(get_char_at_pos_in_bucket(liste[i], level));
                    

                    liste_to[value] = add_tail(liste_to[value], liste[i]->val);
                    
                    liste[i] = remove_head(liste[i]);

                }
           }
            
        }
        free_list_of_buckets(liste, base);
        return liste_to;       
    }
}



//vérifier pour chaque bucket -> parcourir l'ensemble de la liste de bucket
//dans chaque élément, le bouger à l'emplacement correspondant -> si l'élément à 2, le bouger dans le bucket 2 de la liste
