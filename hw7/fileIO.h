#ifndef FILE_IO_H
#define FILE_IO_H
#include "hash_table.h"
#include <stdio.h>

void save_to_file(HashTable *table, const char *filename);
void load_from_file(HashTable *table, const char *filename);

#endif
