#include "midterm.h"

long long *factorial_numbers(size_t n) {
  // You're going to have to allocate an array, fill it in, and return it.
  // The array should be of length n.
  // Recall the first few entries should be 1, 1, 2, 6, 24, 120...
  if (n == 0) {
    return NULL;
  }
  long long *new_arr = malloc(n * sizeof(long long));
  if (!new_arr) {
    return NULL;
  }

  new_arr[0] = 1;

  for (size_t i = 1; i < n; i++) {
    new_arr[i] = new_arr[i - 1] * i;
  }

  return new_arr;
}
