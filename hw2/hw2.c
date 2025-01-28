/*
 * All of your code for these five functions goes in here. These are for you to
 * finish. The code for the calculator is separate. Feel free to include more
 * headers or define helper functions if you want, but you can do this homework
 * without doing either.
 */

#include "hw2.h"

int next_collatz_number(int n) {

  if (n % 2 == 0) {

    return n / 2;
  } else {
    return ((n * 3) + 1);
  }
  return 0;
}

int count_collatz_steps(int n) {

  int current_num = 0;

  while (n != 1) {

    n = next_collatz_number(n);
    current_num++;
  }

  return current_num;
}

int maximum(int *nums, int len) {

  if (len == 0) {
    return 0;
  }

  int place_holder = nums[0];

  for (int i = 1; i < len; i++) {
    if (nums[i] > place_holder) {

      place_holder = nums[i];
    }
  }
  return place_holder;
}

int sum_positive(int *nums, int len) {

  int pos_total = 0;

  for (int i = 0; i < len; i++) {
    if (nums[i] > 0) {
      pos_total += nums[i];
    }
  }
  return pos_total;
}

int count_negative(int *nums, int len) {

  int neg_nums_total = 0;

  for (int i = 0; i < len; i++) {
    if (nums[i] < 0) {
      neg_nums_total++;
    }
  }
  return neg_nums_total;
}
