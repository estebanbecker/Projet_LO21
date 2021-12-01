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
    bucket current = seau;
    bucket next = seau->next;
    while (current != NULL) {
        free(current);
        if(next != NULL) {
            current = next;
            next = next->next;
        }
    }
}

void print_bucket(bucket seau){
    bucket current = seau;
    while (current != NULL) {
        printf("%s\n", current->val);
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

list_of_buckets initialize_list_of_buckets(int argc, char *argv[], list_of_buckets liste, int base){
    int size, size_null;
    char temp[11];
    for (int i = 2;i < argc;i++){
        for(int j = 0; j < 11; j++){
            temp[j] = '\0';
        }
        size=strlen(argv[i]);
        size_null=10-size;

        for (int j = 0; j < size_null; ++j) {
            temp[j] = '0';
        }


        strcat(temp, argv[i]);

        liste[0]=add_head(liste[0],temp );
        
        
    }
    return liste;
}

void free_list_of_buckets(list_of_buckets liste,int base){
    
    for(int i=0; i < base; i++){
        free_bucket(liste[i]);
    }
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
        result = character - 47; //les chiffres de 0 à 9 sont les caractères 48 à 57 du code ASCII
    } else if( character > 96 && character < 103){
        result = character - 96 + 10; //les lettres de l'alphabet majuscules sont les caractères 97 (a) à 122 (z) du code ASCII.
    } else if ( character > 64 && character < 71 ) {
        result = character - 64 + 10; //les lettres de l'alphabet majuscules sont les caractères 65 (A) à 90 (Z) du code ASCII.
    } else if ( character == '\0') {
        result = 0;
    }
    return result;
}

int max_lengh_list(char** liste, int lengh){
    int max = 0;
    for(int i = 2; i < lengh; i++){
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

bucket move_head(bucket bucket_source, bucket bucket_target){
    element * temp;

    add_head(bucket_source, bucket_target->val);
    temp = remove_head(bucket_source);
    return temp;
}

list_of_buckets sort_list_of_buckets(list_of_buckets liste, int level, int base){

    printf("%d",level);

    if(level == 0){
        return liste;
    } else {
        
        list_of_buckets new_list = sort_list_of_buckets(liste, level-1,base);
        for (int  i = 0;  i < base; ++ i) {
            bucket current = liste[i];
            while (current != NULL) {
                char character = get_char_at_pos_in_bucket(current, level);
                int pos = string_to_int_conversion(character);
                move_head(current, new_list[pos]);
                current = current->next;
            }
            free_list_of_buckets(liste,base);
        }
        return new_list;
    }
  
}



//vérifier pour chaque bucket -> parcourir l'ensemble de la liste de bucket
//dans chaque élément, le bouger à l'emplacement correspondant -> si l'élément à 2, le bouger dans le bucket 2 de la liste
