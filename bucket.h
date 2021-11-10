//chained list of string of size 11
typedef struct elem{
    char *val[11];
    struct elem *next;
}element;

typedef element *bucket;

typedef bucket *list_of_buckets;

/**
 * @brief remove the head of the bucket
 * @param bucket bucket to remove the head from
 * @return bucket
 */
bucket remove_head(bucket bucket);

/**
 * @brief add a new element at the head of the bucket
 * @param bucket bucket to add the element to
 * @param val value to add
 * @return bucket
 */
bucket add_head(bucket bucket, char *val);

/**
 * @brief move head element from a bucket to another
 * @param bucket bucket to move the head element from
 * @param bucket_to bucket to move the element to
 * @return bucket
 */
bucket move_head(bucket bucket, bucket bucket_to);

/**
 * @brief create a new bucket
 * @return bucket
 */
bucket create_bucket();

/**
 * @brief free the bucket
 * @param bucket bucket to free
 * @return void
 */
void free_bucket(bucket bucket);

/**
 * @brief print the bucket
 * @param bucket bucket to print
 * @return void
 */
void print_bucket(bucket bucket);

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
int max_lengh_list_of_buckets(list_of_buckets list_of_buckets);

