#include "fileIO.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void save_to_file(HashTable *table, const char *filename) {
  FILE *filepointer = fopen(filename, "w");
  if (!filepointer) {
    printf("Failed to open current file!\n");
  }

  

  for (int i = 0; i < TABLE_SIZE; i++) {
    Customer *current = table->buckets[i];
    while (current) {
      fprintf(filepointer, "%s\t%s\t%d\t%s\n", current->email, current->name,
              current->shoe_size, current->favorite_food);
      current = current->next;
    }
  }
  fclose(filepointer);
  cleanup_table(table);
}

void load_from_file(HashTable *table, const char *filename) {
  FILE *filepointer = fopen(filename, "r");
  if (!filepointer) {
    perror("Failed to open file!\n");
  }

  char email[256];
  char name[256];
  char favorite_food[256];
  int shoe_size;
  char line[256];
  while (fgets(line, sizeof(line), filepointer)) {
    line[strcspn(line, "\n")] = 0;

    char *email = strtok(line, "\t");
    char *name = strtok(NULL, "\t");
    char *shoe_size_str = strtok(NULL, "\t");
    char *favorite_food = strtok(NULL, "\t");

    if (!email || !name || !shoe_size_str || !favorite_food) {
      printf("Error found in file format make sure all are spaced out by "
             "tabs!!\n");
      continue;
    }

    int shoe_size = atoi(shoe_size_str);
    add_customer(table, email, name, shoe_size, favorite_food);
  }
  fclose(filepointer);
}
