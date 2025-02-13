#include "editor_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Functions about ll_text...
// append a line: add to the end of the linked list
ll_text *append_text(ll_text *list, char *text) {

  ll_text *new_node = malloc(sizeof(ll_text));

  if (!new_node) {

    return list;
  }

  new_node->text = strdup(text);

  if (!new_node->text) {
    free(new_node);
    return list;
  }
  new_node->next = NULL;

  if (!list) {
    return new_node;
  }

  ll_text *current = list;

  while (current->next != NULL) {
    current = current->next;
  }
  current->next = new_node;

  return list;
}

void save_to_file(ll_text *list, const char *filename) {
  FILE *outfile = fopen(filename, "w");
  for (ll_text *here = list; here; here = here->next) {
    fprintf(outfile, "%s\n", here->text);
  }
  fclose(outfile);
}

int ll_text_length(ll_text *list) {
  if (list == NULL) {
    return 0;
  }

  ll_text *current = list;
  int count = 0;

  while (current != NULL) {
    current = current->next;
    count++;
  }

  return count;
}

// insert a specific line: add to specific place in the linked list; this is the
// new entry at the specified line
ll_text *insert_text(ll_text *list, char *text, int position) {

  ll_text *new_node = malloc(sizeof(ll_text));

  if (!new_node) {
    free(new_node);
    return list;
  }

  new_node->text = strdup(text);

  if (!new_node->text) {
    free(new_node);
    return list;
  }
  new_node->next = NULL;

  if (position == 0) {
    new_node->next = list;
    return new_node;
  }

  ll_text *current = list;

  for (int i = 0; i < position - 1; i++) {
    if (!current) {
      free(new_node->text);
      free(new_node);

      return list;
    }
    current = current->next;
  }

  if (!current) {
    free(new_node->text);
    free(new_node);
    return list;
  }

  new_node->next = current->next;
  current->next = new_node;

  return list;
}

// delete a specific line: delete the ith entry in the linked list and return
// the new front of the linked list.
ll_text *delete_text(ll_text *list, int position) {

  if (list == NULL) {
    return NULL;
  }

  ll_text *temp;

  if (position == 0) {
    temp = list->next;
    free(list->text);
    free(list);
    return temp;
  }

  ll_text *current = list;

  for (int i = 0; i < position; i++) {
    current = current->next;
  }

  if (!current->next) {
    return list;
  }

  temp = current->next;
  current->next = temp->next;

  free(temp->text);
  free(temp);
  return list;
}
// replace a line: go to the specific entry, free the text that's there, replace
// it with a copy of the specified text.
ll_text *replace_text(ll_text *list, char *text, int position) {

  ll_text *current = list;

  for (int i = 0; i < position; i++) {

    if (current == NULL) {
      return NULL;
    }
    current = current->next;
  }

  if (current->text) {

    free(current->text);
  }

  current->text = strdup(text);
  if (!current->text) {
    return list;
  }

  return list;
}

// duplicate a list. Returns a copy of the list, including newly copied versions
// of all of the strings.
ll_text *duplicate_ll_text(ll_text *list) {

  if (list == NULL) {
    return NULL;
  }

  ll_text *new_head = NULL;

  ll_text **tail = &new_head;

  while (list != NULL) {
    ll_text *new_node = malloc(sizeof(ll_text));

    if (!new_node) {

      while (new_head != NULL) {
        ll_text *temp = new_head;
        new_head = new_head->next;
        free(temp->text);
        free(temp);
      }
      return NULL;
    }

    new_node->text = strdup(list->text);
    if (!new_node) {
      free(new_node);
      while (new_head != NULL) {
        ll_text *temp = new_head;
        new_head = new_head->next;
        free(temp->text);
        free(temp);
      }
      return NULL;
    }

    new_node->next = NULL;
    *tail = new_node;
    tail = &new_node->next;
    list = list->next;
  }

  return new_head;
}

// functions about the state stack...
ll_text_stack *load_from_file(const char *filename) {
  ll_text *lines = NULL;
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  char buf[1024];
  FILE *infile = fopen(filename, "r");
  while (fgets(buf, 1024, infile)) {
    chomp(buf);
    lines = append_text(lines, buf);
  }
  stack->lines = lines;
  return stack;
}

ll_text_stack *new_stack_empty_text(void) {
  ll_text_stack *stack = calloc(1, sizeof(ll_text_stack));
  stack->lines = NULL;
  return stack;
}

// Push a new state onto the stack that's an exact copy of the state currently
// at the top.
ll_text_stack *push_duplicate(ll_text_stack *stack) {

  if (stack == NULL) {
    return NULL;
  }

  ll_text_stack *new_copy = malloc(sizeof(ll_text_stack));

  if (new_copy == NULL) {
    return NULL;
  }

  new_copy->lines = duplicate_ll_text(stack->lines);
  if (!new_copy->lines) {
    free(new_copy);
    return stack;
  }

  new_copy->next = stack;
  return new_copy;
}

// Push a new entry onto the stack that has an empty ll_text at the top.
ll_text_stack *push_empty(ll_text_stack *stack) {

  if (stack == NULL) {
    return NULL;
  }

  ll_text_stack *empty_stack = malloc(sizeof(ll_text_stack));

  empty_stack->lines = NULL;
  empty_stack->next = stack;
  return empty_stack;
}

// undo, removing the most recent state
// this has to free all the memory associated with that state
ll_text_stack *pop_stack(ll_text_stack *stack) {
  if (stack == NULL) {
    return NULL;
  }

  ll_text_stack *temp = stack->next;

  ll_text *current = stack->lines;

  while (current != NULL) {
    ll_text *next = current->next;
    free(current->text);
    free(current);
    current = next;
  }

  free(stack);
  return temp;
}

// Find the first newline in the input and replace it with \0
void chomp(char *s) {
  for (int i = 0; s[i]; i++) {
    if (s[i] == '\n' || s[i] == '\r') {
      // Check for \r in case we're on Windows or a very old Mac??
      // Look, I won't stop you from doing CSE 13s on a Mac from 2001 or prior.
      s[i] = '\0';
      break;
    }
  }
}
