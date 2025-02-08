# Homework 4: Design Document 
    
 * author: Ricardo Ramirez
 * date: February 6, 2025

## Introduction 

Going to create a functional text editor using linked lists for managing text lines and stacks to support a undo feature. The nine functions I am going to write will be able to make this text editor work.

## Function 1: ll_text *append_text(ll_text *list, char *text)

We will do this allocating memeory for a new ll_text node and using strdup() to store a copy of text which we will then traverse the linked list until we reach the last node where we will append a new node at the end. If the list is NULL, we will return the newly created node.

## Function 2: ll_text *insert_text(ll_text *list, char *text, int position)

This function will insert a new node at the specified position within the list. We will inpliment this by allocating a new node and copy text using strdup() , while traversing to the position where new node needs to go. Adjust the pointers while inserting new node and if the position is 0 then we must update the list head.

## Function 3: ll_text *delete_text(ll_text *list, int position)

This function will delete a node from a specified position within the linked list. We will do this by traversing the list to find the node right before the position we will then fix the pointers and free the memory of the deleted node. If it deletes the head node then we will update the head pointer.

## Function 4: ll_text *replace_text(ll_text *list, char *text, int position)

This function will replace the node at a specified location. It will do this by traversing to the nodes specified location and will free the existing text and will allocate new memoery using strdup() and assign it to text.

## Function 5: ll_text *duplicate_ll_text(ll_text *list)

This function will create a copy of the linked list. And will do so by traversing through the original list and create a new one, we will allocate memory for each node and copy text using the strdup() and link new nodes.

## Function 6: int ll_text_length(ll_text *list)

This function just counts the number of nodes within the linked list. We do this by starting a counter and traverse through the list and as each iteration encounters a node the count will increase.

## Function 7: ll_text_stack *push_duplicate(ll_text_stack *stack)

This function will push a duplicate of ll_text onto the stack, and will do so by allocating a new node  where then we will duplicate the ll_text list and link the new stack node to the previous top and returning the top of the stack.

## Function 8: ll_text_stack *push_empty(ll_text_stack *stack)

This function creates a new stack with a empty list. Where we will allocate a new ll_text_stack node and its lines pointer will be set to NULL. Lastly the new stack entry will be linnked to the previous stack state.

## Function 9: ll_text_stack *pop_stack(ll_text_stack *stack)

This function will be helpfull in undo and it will remove the top entry of a stack while freeing its associated memory, including the linked lists within that entry. If the stack becomes empty then the function will return NULL. Otherwise, it will return a pointer to the new top of the stack.



