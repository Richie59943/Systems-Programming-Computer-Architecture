#include "final.h"

#include <stdio.h>

int sum_values_at_max_depth(BinaryTree *tree) {
  // Your code here!
  if (!tree)
    return 0;

  int queue_size = 1000;
  BinaryTree **queue = malloc(queue_size * sizeof(BinaryTree *));
  if (!queue)
    return 0;

  int front = 0, rear = 0;
  queue[rear++] = tree;

  int level_sum = 0;

  while (front < rear) {
    int level_size = rear - front;
    level_sum = 0;

    for (int i = 0; i < level_size; i++) {
      BinaryTree *node = queue[front++];
      level_sum += node->val;

      if (node->left)
        queue[rear++] = node->left;
      if (node->right)
        queue[rear++] = node->right;
    }
  }

  free(queue);      // Free queue memory
  return level_sum; // Return sum of deepest level
}
