#include "final.h"

#include <stdio.h>

int apply_many_times(int (*func)(int), int x, size_t n) {

  if (n == 0) {
    return x;
  }

  return apply_many_times(func, func(x), n - 1);
}
