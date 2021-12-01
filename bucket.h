/**
 * @file bucket.h
 * @author Becker Esteban, Pierre-Olivier Cayetanot
 * @brief List of fuctions to manage the bucket.
 * @version 0.1
 * @date 2021-11-12
 * 
 * @copyright Creative Commons Attribution Non-Commercial (CC BY-NC) 2020
 * 
 */

#ifndef bucket_h
#define bucket_h

#define MAX_LENGH_CHAR 11

/**
 * @brief Element of the bucket represented with a chained list.
 * 
 */
typedef struct elem{
    char val[11]; //!< Value of the element.
    struct elem *next; //!< Pointer to the next element.
}element;

//! @brief Pointer to the head of the bucket.
typedef element *bucket;

//! @brief List of buckets that will have the size of the basis.
typedef bucket *list_of_buckets;

/**
 * @brief remove the head of the bucket
 * @param seau bucket to remove the head from
 * @return bucket
 * @author Esteban Becker
 */
bucket remove_head(bucket seau);

/**
 * @brief add a new element at the tail of the bucket
 * @param seau bucket to add the element to
 * @param val value to add
 * @return bucket
 * @author Esteban Becker
 */
bucket add_tail(bucket seau, char *nombre);



/**
 * @brief free the bucket
 * @param seau bucket to free
 * @return void
 * @author Pierre-Olivier Cayetanot
 */
void free_bucket(bucket seau);

/**
 * @brief print the bucket
 * @param seau bucket to print
 * @return void
 * @author Pierre-Olivier Cayetanot
 */
void print_bucket(bucket seau);

/**
 * @brief print the list of buckets
 * @param list_of_buckets list of buckets to print
 * @param bases size of the bases
 * @return void
 * @author Pierre-Olivier Cayetanot
 */
void print_list_of_buckets(list_of_buckets liste, int base);

/**
 * @brief initialize a list of buckets
 * @param argc number of arguments
 * @param argv arguments
 * @param liste pointer to list of buckets to create
 * @return list_of_buckets
 * @author Pierre-Olivier Cayetanot
 */
list_of_buckets initialize_list_of_buckets(int argc, char *argv[], list_of_buckets liste);

/**
 * @param argc number of arguments
 * @param argv arguments
 * @return list_of_buckets
 * @author Pierre-Olivier Cayetanot
 */
list_of_buckets create_list_of_buckets(int base);

/**
 * @brief free the list of buckets
 * @param list_of_buckets list of buckets to free
 * @return void
 * @author Pierre-Olivier Cayetanot
 */
void free_list_of_buckets(list_of_buckets liste,int base);

/**
 * @brief Know the max lengh of the longest string in the list
 * @param char list where to search
 * @param int lengh of the list
 * @return int
 * @author Esteban Becker
 */
int max_lengh_list(char** liste, int lengh);



/**
 * @brief Know the charactère at a given position in a string of a bucket
 * @param seau bucket to know the charactère
 * @param pos position to know the charactère
 * @return char
 * @return NULL if the position is out of range
 * @note the position is counted from the end
 * @author Pierre-Olivier Cayetanot
 */
char get_char_at_pos_in_bucket(bucket seau, int pos);


/**
 * @brief convert a string to its int conterpart in base 10 (a->11, f->)
 * @param character character to be converted
 * @return
 * @author Pierre-Olivier Cayetanot
 */
int string_to_int_conversion(char character);

/**
 * @brief Sort the list of buckets
 * @param list_of_buckets list of buckets to sort
 * @param int interation level
 * @param int base
 * @return list_of_buckets
 * @authors Esteban Becker, Pierre-Olivier Cayetanot
 * @note the list of buckets is sorted using an recursive algorithm
 */
list_of_buckets sort_list_of_buckets(list_of_buckets liste, int level, int base);

#endif /* bucket_h */