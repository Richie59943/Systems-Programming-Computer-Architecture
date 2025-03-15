#include "customer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Customer *create_customer(const char *email, const char *name, int shoe_size,
                          const char *favorite_food) {
  Customer *new_customer = malloc(sizeof(Customer));
  if(!new_customer) return NULL;
  new_customer->email = strdup(email);
  new_customer->name = strdup(name);
  new_customer->shoe_size = shoe_size;
  new_customer->favorite_food = strdup(favorite_food);
  new_customer->next = NULL;
  return new_customer;
  free(new_customer);
     if (!new_customer->email || !new_customer->name || !new_customer->favorite_food) {
        free(new_customer->email);
        free(new_customer->name);
        free(new_customer->favorite_food);
        free(new_customer);
        return NULL;

}
return new_customer;
}
void free_customer(Customer *customer) {
if(!customer)
{
	return;}

      
	free(customer->email);
  free(customer->name);
  free(customer->favorite_food);
  free(customer);
}
