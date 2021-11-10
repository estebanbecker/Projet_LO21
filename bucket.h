//chained list of string of size 11
typedef struct elem{
    char *val[11];
    struct elem *next;
}element;

typedef element *bucket;

typedef bucket *list_of_buckets;

/**
 * @brief remove the head of the bucket
 * @param sceau bucket to remove the head from
 * @return bucket
 * @author Esteban Becker
 */
bucket remove_head(bucket sceau);

/**
 * @brief add a new element at the head of the bucket
 * @param sceau bucket to add the element to
 * @param val value to add
 * @return bucket
 * @author Esteban Becker
 */
bucket add_head(bucket sceau, char *val);

/**
 * @brief move head element from a bucket to another
 * @param sceau bucket to move the head element from
 * @param sceau_to bucket to move the element to
 * @return bucket
 * @author Esteban Becker
 */
bucket move_head(bucket sceau, bucket sceau_to);

/**
 * @brief create a new bucket
 * @return bucket
 */
bucket create_bucket();

/**
 * @brief free the bucket
 * @param sceau bucket to free
 * @return void
 */
void free_bucket(bucket sceau);

/**
 * @brief print the bucket
 * @param sceau bucket to print
 * @return void
 */
void print_bucket(bucket sceau);

/**
 * @brief print the list of buckets
 * @param list_of_buckets list of buckets to print
 * @return void
 */
void print_list_of_buckets(list_of_buckets list_of_buckets);

/**
 * @brief create a new list of buckets
 * @return list_of_buckets
 */
list_of_buckets create_list_of_buckets();

/**
 * @brief free the list of buckets
 * @param list_of_buckets list of buckets to free
 * @return void
 */
void free_list_of_buckets(list_of_buckets list_of_buckets);

/**
 * @brief Know the max lengh of the longest string in the list of buckets
 * @param list_of_buckets list of buckets to know the max lengh
 * @return int
 */
int max_length_list_of_buckets(list_of_buckets list_of_buckets);

/**
 * @brief Know the charactère at a given position in a string of a bucket
 * @param sceau bucket to know the charactère
 * @param pos position to know the charactère
 * @return char
 * @return NULL if the position is out of range
 * @note the position is counted from the end
 * @author Pierre-Olivier Cayetanot
 */
char get_char_at_pos_in_bucket(bucket sceau, int pos);

/**
 * @brief Sort the list of buckets
 * @param list_of_buckets list of buckets to sort
 * @param int interation level
 * @return list_of_buckets
 * @author Esteban Becker
 * @note the list of buckets is sorted using an recursive algorithm
 */
list_of_buckets sort_list_of_buckets(list_of_buckets list_of_buckets, int level);
