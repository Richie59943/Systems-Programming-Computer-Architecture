/*
 * All of your code for hw3 goes in here. Your goal is to finish these
 * functions.
 */

#include "hw3.h"
#include <ctype.h>
#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
bool str_suffix(char *haystack, char *needle) {

  int length_haystack = strlen(haystack);
  int length_needle = strlen(needle);

  if (length_needle > length_haystack) {
    return false;
  }

  for (int i = 0; i < length_needle; i++) {
    if (haystack[length_haystack - length_needle + i] != needle[i]) {
      return false;
    }
  }
  return true;
}
char *str_repeat(char *s, int n) {

  if (n == 0) {
    char *empty = malloc(sizeof(char) * 1);

    if (!empty) {
      return NULL;
    }
    empty[0] = '\0';
    return empty;
    free(empty);
  }

  int s_length = strlen(s);

  int total_size = (s_length * n) + 1;

  char *out = malloc(sizeof(char) * total_size);
  if (!out) {
    return NULL;
  }

  char *ptr = out;
  for (int i = 0; i < n; i++) {
    strcpy(ptr, s);
    ptr += s_length;
  }

  return out;

  free(out);
}

bool str_is_palindrome(char *s) {

  if (!s) {
    return true;
  }

  int length = strlen(s);
  int total_length = length + 10;

  char *alloc_mem = malloc(sizeof(char) * total_length);

  int j = 0;

  for (int i = 0; i < length; i++) {
    char c = s[i];

    if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z')) {
      alloc_mem[j++] = tolower(c);
    }
  }

  alloc_mem[j] = '\0';

  int left = 0;
  int right = j - 1;
  while (left < right) {
    if (alloc_mem[left] != alloc_mem[right]) {
      free(alloc_mem);
      return false;
    }
    left++;
    right--;
  }

  free(alloc_mem);
  return true;
}

float dot_product(float *vec_a, float *vec_b, int length) {

  if (length == 0) {
    return 0;
  }

  int add_array = 0;

  for (int i = 0; i < length; i++) {
    int total = vec_a[i] * vec_b[i];
    add_array += total;
  }

  return add_array;
}

int reduce(int *nums, int length, int (*f)(int, int), int initial) {

  int cumulative = initial;

  for (int i = 0; i < length; i++) {
    cumulative = f(cumulative, nums[i]);
  }

  return cumulative;
}

// These two functions will end up as a *single call to reduce*, but you'll have
// to write a new helper function for each of them. Those helper functions will
// be quite short though!
int max_function(int a, int b) {
  if (a > b) {
    return a;
  } else {
    return b;
  }
}

int maximum_with_reduce(int *nums, int length) {

  return reduce(nums, length, max_function, INT_MIN);
}

int sum_positive(int a, int b) {
  int sum_positive = 0;
  if (a > 0) {
    sum_positive += a;
  }
  if (b > 0) {
    sum_positive += b;
  }

  return sum_positive;
}

int sum_positive_with_reduce(int *nums, int length) {

  return reduce(nums, length, sum_positive, 0);
}
