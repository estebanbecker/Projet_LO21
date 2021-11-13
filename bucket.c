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

bucket create_bucket(){
    bucket head = NULL;
    head = malloc(sizeof(bucket));
    head->next = NULL;
    head->val = NULL;
    return head;
}

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

void print_list_of_buckets(list_of_buckets liste){
    int size = sizeof liste / sizeof *liste; //calcul de la taille de la liste -> taille de la liste divisé par la taille d'un élément
    for(int i=0; i < size; i++){
        print_bucket(liste[i]);
    }
}



list_of_buckets create_list_of_buckets(int base, int argc, char *argv[]){
    list_of_buckets liste = NULL;
    liste = malloc(sizeof(bucket) * base);
    for (int i = 0; i < base; ++i) {
        liste[i] = create_bucket();
    }
}

list_of_buckets initialize_list_of_buckets(int argc, char *argv[], list_of_buckets liste){
    for (int i = 1;i < argc;i++){
        add_head(liste[1], argv[i]);
    }
    return liste;
}

void free_list_of_buckets(list_of_buckets liste){
    int size = sizeof liste / sizeof *liste;
    for(int i=0; i < size; i++){
        free_bucket(liste[i]);
    }
}

char get_char_at_pos_in_bucket(bucket seau, int pos){
    char value = seau->val[pos];
    return value;
}

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
    element * temp;
    add_head(seau_to, seau_from->val);
    temp = remove_head(seau_from);
    return temp;
}

