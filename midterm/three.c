#include "midterm.h"

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

size_t count_strings_with_property(bool (*property)(char *), char **strings,
                                   size_t len) {

  int count = 0;

  for (size_t i = 0; i < len; i++) {
    if (property(strings[i]) == true) {
      count++;
    }
  }
  return count;
}
