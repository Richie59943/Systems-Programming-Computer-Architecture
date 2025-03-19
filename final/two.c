#include "final.h"
#include <stdio.h>
#include <string.h>

char *remove_characters(char *text, char *toremove) {

  if (text == NULL) {
    return NULL;
  }

  if (toremove == NULL || *toremove == '\0') {

    return strdup(text);
  }

  size_t text_len = strlen(text);

  char *result = (char *)malloc((text_len + 1) * sizeof(char));

  if (result == NULL) {
    return NULL;
  }

  size_t j = 0;

  for (size_t i = 0; i < text_len; i++) {

    int should_remove = 0;
    for (size_t k = 0; toremove[k] != '\0'; k++) {
      if (text[i] == toremove[k]) {
        should_remove = 1;
        break;
      }
    }

    if (!should_remove) {
      result[j++] = text[i];
    }
  }

  result[j] = '\0';

  return result;
}
