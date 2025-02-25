#include "wordle_lib.h"
#include <stdlib.h>
#include <string.h>
// Most of the code that you're going to have to implement goes in here.
// Feel free to add more helper functions if necessary.

// Returns true if the guess is an exact match with the secret word, but
// more importantly, fills in the result with the following:
// - 'x' goes in a slot if the corresponding letter in the guess does not appear
//   anywhere in the secret word
// - 'y' goes in a slot if the corresponding letter in the guess appears in the
//   secret word, but not in the corresponding slot
// - 'g' goes in a slot if the corresponding letter in the guess appears in the
//   corresponding slot in the secret word.
//   You can assume that result points at enough memory for a string of length
//   5. (ie, at least 6 bytes long)
bool score_guess(char *secret, char *guess, char *result) {
  // TODO(you): finish this function
  size_t len = strlen(secret);
  char temp[len];

  for (size_t i = 0; i < len; i++) {
    result[i] = 'x';
    temp[i] = 0;
  }
  result[len] = '\0';
  bool is_correct = true;

  for (size_t i = 0; i < len; i++) {
    if (guess[i] == secret[i]) {
      result[i] = 'g';
      temp[i] = 1;
    } else {
      is_correct = false;
    }
  }

  for (size_t i = 0; i < len; i++) {
    if (result[i] != 'g') {
      for (size_t j = 0; j < len; j++) {
        if (guess[i] == secret[j] && result[j] != 'g' && !temp[j]) {
          result[i] = 'y';
          temp[j] = 1;
        }
      }
    }
  }

  temp[len] = '\0';
  return is_correct;
}

// Returns true if the specified guess is one of the strings in the vocabulary,
// and false otherwise. num_words is the length of the vocabulary.
// A simple linear scan over the strings in vocabulary is fine for our purposes,
// but consider: could you do this search more quickly?
bool valid_guess(char *guess, char **vocabulary, size_t num_words) {
  // TODO(you): finish this function

  for (size_t i = 0; i < num_words; i++) {
    if (strcmp(guess, vocabulary[i]) == 0) {
      return true;
    }
  }

  return false;
}

// Returns an array of strings (so, char **), where each string contains a word
// from the specified file. The file is assumed to contain 5-letter words, one
// per line.
// Also, this function sets the value pointed at by *num_words to be the number
// of words read.
// This will need to allocate enough memory to hold all of the char* pointers --
// so you will keep track of the size of your char** array and then use realloc
// to make the array larger over time, so that you have enough space for the
// dynamically-growing array of char *.
// Use fopen to open the input file for reading,
// strdup (or strndup) to make copies of each word read from that file, and
// fclose to close the file when you are done reading from it.
// Each element of the array should be a single five-letter word,
// null-terminated.
char **load_vocabulary(char *filename, size_t *num_words) {
  char **out = NULL;
  // TODO(you): finish this function
  FILE *file = fopen(filename, "r");
  if (!file) {
    return NULL;
  }

  char word[6];    
  size_t count = 0; 

  while (fscanf(file, "%5s", word) ==
         1) 

  {
    char **temp = realloc(out, (count + 1) * sizeof(char *));
    if (!temp) {
      return NULL;
    }
    out = temp;
    out[count] = strdup(word);
    if (!out[count]) {
      fclose(file);
      return NULL;
    }

    count++;
  }

  fclose(file);
  *num_words = count;
  return out;
}

// Free each of the strings in the vocabulary, as well as the pointer vocabulary
// itself (which points to an array of char *).
void free_vocabulary(char **vocabulary, size_t num_words) {
  // TODO(you): finish this function
  for (size_t i = 0; i < num_words; i++) {
    free(vocabulary[i]);
  }
  free(vocabulary);
}
