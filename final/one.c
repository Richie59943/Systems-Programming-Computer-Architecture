#include "final.h"
#include <stdio.h>

size_t count_increasing_columns(int **matrix, size_t rows, size_t cols) {
  // we need to iterate throuhg all
  // we alos need to have a count that will count the amount of time we iterate
  if (matrix == NULL || rows <= 1) {
    return 0;
  }

  size_t count = 0;

  for (size_t col = 0; col < cols; col++) {
    int is_strictly_increasing = 1;

    for (size_t row = 1; row < rows; row++) {
      if (matrix[row][col] <= matrix[row - 1][col]) {
        is_strictly_increasing = 0;
        break;
      }
    }

    if (is_strictly_increasing) {
      count++;
    }
  }

  return count;
}
