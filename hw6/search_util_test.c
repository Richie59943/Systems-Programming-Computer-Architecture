// A nice place for you to mess with the functions, while you're developing.

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "search_util.h"

int main(void) {
  char words[10][6] = {"stalk", "scrap", "shear", "batch", "motif",
                       "tense", "ultra", "vital", "ether", "nadir"};

  // make a dynamically-allocated vocabulary that you can mess with, including
  // freeing elements of it when necessary.
  char **vocabulary = calloc(10, sizeof(char *));
  for (int i = 0; i < 10; i++) {
    vocabulary[i] = strdup(words[i]);
  }
  size_t num_words = 10;

  // TODO(you): exercise all of your functions in here. Write some good test
  // cases! You may want to repeatedly set up the vocabulary and filter it down,
  // testing as you go. This is up to you!

  // Test score_letter
  printf("Score for letter 'a': %d\n",
         score_letter('a', vocabulary, num_words));

  // Test for score_word
  int letter_scores[26] = {1,  2,  3,  4,  5,  6,  7,  8,  9,  10, 11, 12, 13,
                           14, 15, 16, 17, 18, 19, 20, 21, 22, 23, 24, 25, 26};

  for (size_t i = 0; i < num_words; i++) {
    printf("Score for word %s : %d\n", words[i],
           score_word(words[i], letter_scores));
  }

  // Test for filter_vocabulary_gray
  printf("Apllying the filter_vocabulary_gray  on letter'a': %lu\n",
         filter_vocabulary_gray('p', vocabulary, num_words));

  // Test for Filter_vocabulary_yellow
  printf("Applying the filter_vocabulary_yellow  on letter 'p' at position 3: %lu\n",
         filter_vocabulary_yellow('l', 3, vocabulary, num_words));

  // Test for filter_vocabulary_green
  printf("Applying the filter_vocabulary_green 's' at position 1: %lu\n",
         filter_vocabulary_green('s', 4, vocabulary, num_words));

  // cleaning up the vocabulary memory
  free_vocabulary(vocabulary, num_words);

  return 0;
}
