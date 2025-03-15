#ifndef HASH_TABLE_H
#define HASH_TABLE_H
#include "customer.h"
#include <stdlib.h>
#define TABLE_SIZE 10

typedef struct {
  Customer *buckets[TABLE_SIZE];
} HashTable;

unsigned long djb_hash(const char *email);
void add_customer(HashTable *table, const char *email, const char *name,
                  int shoe_size, const char *favorite_food);

Customer *lookup_customer(HashTable *table, const char *email);

void delete_customer(HashTable *table, const char *email);
void cleanup_table(HashTable *table);

#endif
