#include "midterm.h"

#include <stdio.h>

ll_float *delete_range(ll_float *list, float start, float end) {

  if (list == NULL || start > end) {
    return list;
  }

  ll_float *current = list;
  ll_float *prev = NULL;

  while (current != NULL && current->value >= start && current->value <= end) {
    ll_float *temp = current;
    current = current->next;
    free(temp);
  }

  list = current;

  while (current != NULL) {
    if (current->value >= start && current->value <= end) {
      ll_float *temp = current;
      prev->next = current->next;
      current = current->next;
      free(temp);
    } else {
      prev = current;
      current = current->next;
    }
  }
  return list;
}
