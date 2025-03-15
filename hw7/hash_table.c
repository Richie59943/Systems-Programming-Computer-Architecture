#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned long djb_hash(const char *email) {
  unsigned long hash = 5381;
  int c;

  while (*email) {
    c = *email;
    hash = ((hash << 5) + hash) + (unsigned char)c;
    email++;
  }
  return hash % TABLE_SIZE;
}

void add_customer(HashTable *table, const char *email, const char *name,
                  int shoe_size, const char *favorite_food) {
  unsigned long index = djb_hash(email);
  Customer *current = table->buckets[index];

  while (current) {
    if (strcmp(current->email, email) == 0) {
      free(current->name);
      free(current->favorite_food);
      free_customer(current);
      current->name = strdup(name);
      current->shoe_size = shoe_size;
      current->favorite_food = strdup(favorite_food);
      return;
    }
    current = current->next;
  }

  Customer *new_customer =
      create_customer(email, name, shoe_size, favorite_food);
  new_customer->next = table->buckets[index];
  table->buckets[index] = new_customer;
}

Customer *lookup_customer(HashTable *table, const char *email) {
  unsigned long index = djb_hash(email);

  Customer *current = table->buckets[index];
  while (current) {
    if (strcmp(current->email, email) == 0) {
      return current;
    }
    current = current->next;
  }
  return NULL;
}

void delete_customer(HashTable *table, const char *email) {
  unsigned long index = djb_hash(email);

  Customer *current = table->buckets[index];
  Customer *prev = NULL;
  while (current) {
    if (strcmp(current->email, email) == 0) {
      if (prev) {

        prev->next = current->next;

      } else {
        table->buckets[index] = current->next;
      }
      
      free(current->email);
      free(current->name);
      free(current->favorite_food);
      free(current);
      
      
      //free_customer(current);
      return;
    }

    prev = current;
    current = current->next;
    
  }
}

void cleanup_table(HashTable *table) {

  for (int i = 0; i < TABLE_SIZE; i++) {
    Customer *current = table->buckets[i];
    while (current) {
      Customer *temp = current;
      current = current->next;

      free(temp->email);
      free(temp->name);
      free(temp->favorite_food);

  
      free(temp);
     
    }
    table->buckets[i] = NULL;
  
  }
}
