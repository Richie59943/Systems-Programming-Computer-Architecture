#include "midterm.h"

#include <stdio.h>

// PROBLEM 3
void bubble_sort_customers(ShoeCustomer *customers, size_t n_customers) {
  // Your code here! Make them sorted by number of purchases, increasing!
  int swapped;

  do {
    swapped = 0;
    for (size_t i = 0; i < n_customers; i++) {
      for (size_t j = 1; j < n_customers + 1; j++) {
        if (customers[i].num_purchases > customers[j].num_purchases) {
          ShoeCustomer temp = customers[i];
          customers[i] = customers[j];
          customers[j] = temp;
          swapped = 1;
        }
      }
    }
    n_customers--;
  } while (swapped);
}
