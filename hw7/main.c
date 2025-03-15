#include "fileIO.h"
#include "hash_table.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_INPUT 100

void remove_tabs(char *str) {
  for (int i = 0; str[i] != '\0'; i++) {
    if (str[i] == '\t') {
      str[i] = ' ';
    }
  }
}

int main(void) {
  HashTable table = {0};
  char choice[MAX_INPUT];
  char email[MAX_INPUT], name[MAX_INPUT], favorite_food[MAX_INPUT];
  int shoe_size;

  load_from_file(&table, "customers.tsv");
  while (1) {
    printf("Please choose one of the following "
           "(add,delete,lookup,list,save,quit): ");
    scanf("%s", choice);

    if (strcmp(choice, "add") == 0) {
      printf("Enter a email: ");
      getchar();
      fgets(email, sizeof(email), stdin);
      email[strcspn(email, "\n")] = 0;
      remove_tabs(email);

      printf("Enter a name: ");

      fgets(name, sizeof(name), stdin);
      name[strcspn(name, "\n")] = 0;
      remove_tabs(name);

      printf("Enter a shoe size: ");

      scanf("%d", &shoe_size);

      while (getchar() != '\n')
        ;

      printf("Enter a favorite food: ");

      fgets(favorite_food, sizeof(favorite_food), stdin);
      favorite_food[strcspn(favorite_food, "\n")] = 0;
      remove_tabs(favorite_food);

      add_customer(&table, email, name, shoe_size, favorite_food);
      
    }

    if (strcmp(choice, "delete") == 0) {
      printf("Please enter email: ");
      scanf("%s", email);
      Customer *customer = lookup_customer(&table, email);
      if (customer) {
        delete_customer(&table, email);
      } else {
        printf("Customer NOT in database!!\n");
      }
    }

    if (strcmp(choice, "lookup") == 0) {
      printf("Please enter the email you would like to find: ");
      scanf("%s", email);
      Customer *customer = lookup_customer(&table, email);
      if (customer) {
        printf("Email: %s, Name: %s, Size: %d, Favorite Food: %s\n",
               customer->email, customer->name, customer->shoe_size,
               customer->favorite_food);
      } else {
        printf("Customer NOT in Database!\n");
      }
    }

    if (strcmp(choice, "list") == 0) {
      for (int i = 0; i < TABLE_SIZE; i++) {
        Customer *current = table.buckets[i];
        while (current) {

          printf("Email: %s, Name: %s, shoe size: %d,Favorite Food: %s\n",
                 current->email, current->name, current->shoe_size,
                 current->favorite_food);
          current = current->next;
        }
      }
    }

    if (strcmp(choice, "quit") == 0) {
     
	    cleanup_table(&table);

      break;
    }

    if (strcmp(choice, "save") == 0) {
      save_to_file(&table, "customers.tsv");
    }
  }
  return 0;
}
