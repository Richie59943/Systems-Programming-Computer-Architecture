#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void should_be_exactly_equal(const char *message, size_t expected,
                             size_t actual) {
  printf("%s\n", message);
  printf("%s: wanted %lu, got %lu\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {

  // example from the README
  int **matrix1;
  matrix1 = calloc(4, sizeof(int *));
  for (int i = 0; i < 4; i++) {
    // now allocate each individual row, filled with 0 initially.
    matrix1[i] = calloc(3, sizeof(int));
  }
  matrix1[0][0] = 1;
  matrix1[1][0] = 2;
  matrix1[2][0] = 3;
  matrix1[3][0] = 4;
  matrix1[0][1] = 3;
  matrix1[1][1] = 4;
  matrix1[2][1] = 5;
  matrix1[3][1] = 6;
  matrix1[0][2] = 2;
  matrix1[1][2] = 2;
  matrix1[2][2] = 3;
  matrix1[3][2] = 5;

  should_be_exactly_equal("two strictly increasing colument", 2,
                          count_increasing_columns(matrix1, 4, 3));
  for (int i = 0; i < 4; i++) {
    free(matrix1[i]);
  }
  free(matrix1);

  // === Test 2: All columns are strictly increasing ===
  int **matrix2 = calloc(3, sizeof(int *));
  for (int i = 0; i < 3; i++) {
    matrix2[i] = calloc(3, sizeof(int));
  }
  matrix2[0][0] = 1;
  matrix2[1][0] = 2;
  matrix2[2][0] = 3;
  matrix2[0][1] = 2;
  matrix2[1][1] = 3;
  matrix2[2][1] = 4;
  matrix2[0][2] = 3;
  matrix2[1][2] = 4;
  matrix2[2][2] = 5;

  should_be_exactly_equal("Test 2: All columns strictly increasing", 3,
                          count_increasing_columns(matrix2, 3, 3));
  for (int i = 0; i < 3; i++) {
    free(matrix2[i]);
  }
  free(matrix2);

  // === Test 3: No strictly increasing columns (all decreasing) ===
  int **matrix3 = calloc(3, sizeof(int *));
  for (int i = 0; i < 3; i++) {
    matrix3[i] = calloc(3, sizeof(int));
  }
  matrix3[0][0] = 5;
  matrix3[1][0] = 4;
  matrix3[2][0] = 3;
  matrix3[0][1] = 6;
  matrix3[1][1] = 5;
  matrix3[2][1] = 4;
  matrix3[0][2] = 7;
  matrix3[1][2] = 6;
  matrix3[2][2] = 5;

  should_be_exactly_equal("Test 3: No strictly increasing columns", 0,
                          count_increasing_columns(matrix3, 3, 3));

  for (int i = 0; i < 3; i++) {
    free(matrix3[i]);
  }
  free(matrix3);

  // === Test 4: A single row matrix (edge case) ===
  int **matrix4 = calloc(1, sizeof(int *));
  matrix4[0] = calloc(3, sizeof(int));
  matrix4[0][0] = 10;
  matrix4[0][1] = 20;
  matrix4[0][2] = 30;

  should_be_exactly_equal("Test 4: Single row matrix", 0,
                          count_increasing_columns(matrix4, 1, 3));
  for (int i = 0; i < 1; i++) {
    free(matrix4[i]);
  }
  free(matrix4);
  // === Test 5: All elements are the same ===
  int **matrix5 = calloc(3, sizeof(int *));
  for (int i = 0; i < 3; i++) {
    matrix5[i] = calloc(3, sizeof(int));
  }
  matrix5[0][0] = 1;
  matrix5[1][0] = 1;
  matrix5[2][0] = 1;
  matrix5[0][1] = 1;
  matrix5[1][1] = 1;
  matrix5[2][1] = 1;
  matrix5[0][2] = 1;
  matrix5[1][2] = 1;
  matrix5[2][2] = 1;

  should_be_exactly_equal("Test 5: All elements the same", 0,
                          count_increasing_columns(matrix5, 3, 3));
  for (int i = 0; i < 3; i++) {
    free(matrix5[i]);
  }
  free(matrix5);

  return 0;
}
