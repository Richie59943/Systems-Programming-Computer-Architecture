#include "final.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void should_be_exactly_equal(const char *message, char *expected,
                             char *actual) {
  printf("%s\n", message);
  printf("%s: wanted %s, got %s\n",
         !strcmp(expected, actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  char *text = "Sphinx of black quartz, judge my vow";
  char *toremove = "aeiou";
  char *expected = "Sphnx f blck qrtz, jdg my vw";

  char *result = remove_characters(text, toremove);
  should_be_exactly_equal("should remove vowels not including y", expected,
                          result);
  free(result);

  // === Test Case: Remove Specific Characters ===
  char text2[] = "Hello, World!";
  char toremove2[] = "lo";
  result = remove_characters(text2, toremove2);
  should_be_exactly_equal("Test: Remove 'lo'", "He, Wrd!", result);

  free(result);
  // === Test Case: Empty 'toremove' (Should return a copy of text) ===
  char text3[] = "Keep this text intact!";
  char toremove3[] = "";
  result = remove_characters(text3, toremove3);
  should_be_exactly_equal("Test: No characters removed",
                          "Keep this text intact!", result);
  free(result);

  // === Test Case: Remove All Characters (Should return empty string) ===
  char text4[] = "abcde";
  char toremove4[] = "abcde";
  result = remove_characters(text4, toremove4);
  should_be_exactly_equal("Test: Remove all characters", "", result);
  free(result);


  return 0;
}
