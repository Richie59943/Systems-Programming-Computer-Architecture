#include "final.h"

#include <stdio.h>
#include <stdlib.h>

void free_tree(BinaryTree *tree) {
  if (!tree)
    return; // If NULL, nothing to free

  free_tree(tree->left);  // Recursively free left subtree
  free_tree(tree->right); // Recursively free right subtree

  free(tree); // Free current node
}

BinaryTree *build_tree(int value, BinaryTree *left, BinaryTree *right) {
  BinaryTree *out = calloc(1, sizeof(BinaryTree));
  out->val = value;
  out->left = left;
  out->right = right;

  return out;
}

void should_be_exactly_equal(const char *message, int expected, int actual) {
  printf("%s\n", message);
  printf("%s: wanted %d, got %d\n",
         (expected == actual) ? "SUCCESS" : "FAILURE", expected, actual);
}

int main(void) {
  BinaryTree *tree = build_tree(
      1, build_tree(2, build_tree(4, build_tree(8, NULL, NULL), NULL), NULL),
      build_tree(3, build_tree(5, build_tree(7, NULL, NULL), NULL),
                 build_tree(6, NULL, NULL)));

  // Here we should find 42 at depth 2 (path is 14->15->42)
  should_be_exactly_equal("8 and 7 at max depth", 15,
                          sum_values_at_max_depth(tree));

  free_tree(tree);

  BinaryTree *tree1 = build_tree(5, NULL, NULL);
  should_be_exactly_equal("Single node tree", 5,
                          sum_values_at_max_depth(tree1));
  free_tree(tree1);

  //  Test 2: Full binary tree
  BinaryTree *tree2 = build_tree(
      10,
      build_tree(20, build_tree(40, NULL, NULL), build_tree(50, NULL, NULL)),
      build_tree(30, build_tree(60, NULL, NULL), build_tree(70, NULL, NULL)));
  should_be_exactly_equal("Full binary tree", 220,
                          sum_values_at_max_depth(tree2));
  free_tree(tree2);

  //  Test 3: Left-skewed tree
  BinaryTree *tree3 = build_tree(
      1, build_tree(2, build_tree(3, build_tree(4, NULL, NULL), NULL), NULL),
      NULL);
  should_be_exactly_equal("Left-skewed tree", 4,
                          sum_values_at_max_depth(tree3));
  free_tree(tree3);

  // Test 4: Right-skewed tree
  BinaryTree *tree4 = build_tree(
      1, NULL,
      build_tree(2, NULL, build_tree(3, NULL, build_tree(4, NULL, NULL))));
  should_be_exactly_equal("Right-skewed tree", 4,
                          sum_values_at_max_depth(tree4));
  free_tree(tree4);

  return 0;
}
