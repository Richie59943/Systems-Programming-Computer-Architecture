#include "final.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
WordCountTree *merge_trees(WordCountTree *tree1, WordCountTree *tree2) {
  if (!tree1)
    return tree2;
  if (!tree2)
    return tree1;

  int cmp = strcmp(tree1->word, tree2->word);
  WordCountTree *merged = (WordCountTree *)malloc(sizeof(WordCountTree));

  if (!merged) {
    fprintf(stderr, "Memory allocation failed\n");
    exit(1);
  }

  merged->left = NULL;
  merged->right = NULL;
  merged->word = strdup(tree1->word);

  if (cmp < 0) {

    merged->count = tree1->count;
    merged->left = merge_trees(tree1->left, tree2);
    merged->right = merge_trees(tree1->right, NULL);
  } else if (cmp > 0) {

    free(merged->word);
    merged->word = strdup(tree2->word);
    merged->count = tree2->count;
    merged->left = merge_trees(tree1, tree2->left);
    merged->right = merge_trees(NULL, tree2->right);
  } else {

    merged->count = tree1->count + tree2->count;
    merged->left = merge_trees(tree1->left, tree2->left);
    merged->right = merge_trees(tree1->right, tree2->right);
  }

  return merged;
}
