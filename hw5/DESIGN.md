# Homework 5: Design Document

  * author: Ricardo Ramires
  * date: February 21, 2025

## introduction

In homework five we are going to inpliment our own version of woordle (word guessing game). This will make us deal with strings, searching, words, and I/O. We will also need to free the memeory that we allocated to make sure there are no leaks.

## Function 1: score_guess

This function determines whether a current players guess matches with the secret word and fills the result string with the feedback using the rules:

'x' for letters not found within the secret word
'y' for letters found withiin the word but not in correct position
'g' for correct letters in the correct position 

we can make this by creating a array to keep track of letter occurances within the secret word. Iterateing through both strings and mark positions where the guess matches the secret word. Finally iterate again to check if the guessed letter appears in the secret word in a defferent position and mark non matching letters with 'x'. We will allocate the memoery before calling the function and then free when we no longer need it.

## Function 2: valid_guess

This function checks if the provided guess is valid within the vocabulary, we do this by iterating throuhg the vocabulary array and compare each word with the guess. We will return true if a match is found otherwise we will return a false. This function will not need to allocate memory

## Function 3: Load_vocabulary

The purpose of this function is to load a list of five letter words within a file into a array of strings. We do this by opening up the file and dynamically allocate memoryy to store the words and we can use malloc() to allocate the initial space and realloc() to dynamically expand the array as new words are added. We will also need to read each word line by line and we will also need a counter, lastly we will return the pointer to the array. Memory management will be handled using strdup() to allocate each word and realloc() will be used like mentioned above, we will also free all this memoery when needed.

## Function 4: free_vocabulary 

The purpose of this function release allocated memoery from the vocabulary array. We do this by looping through each word in the vocabulary and free the memoery, we will also free the main vocabulary array. Each word that was allocated with strdup() will be freed using free() and the vocabulary array allocated usiing malloc() or realloc() will also be freed.





