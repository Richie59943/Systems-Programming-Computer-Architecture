# Homework 6: Design Document

  * Author: Ricardo Ramirez
  * Date: February 27, 2025

## Introduction

In this homework we are going to implement our own solver for the word-guessing game named wordle. The program will be able to evaluate the frequency of letters found within the players guess and prioritize words that contain the letters within the secret word and the players guess.

## Function 1: score_letter

This function will compute how many words within vocabulary contain the given letter. It will be able to iterate through all of vocabulary and checks if any words within contain the given letter then a counter will increase

Pseudocode:
create a counter "this will keep track of amount of words containing letter"

for (i at 0 will iterate from 0 to num_words)
    if (the word is found within vocabulary)
        we will add one to counter
    
return the counter

## Function 2: score_word

This function is going to calculate the total amount of points a players guess is worth baed on its unique letters. In a function called letter_scores each score of the letter has been filled out, slot 0 contains the score for 'a' and slot 25 score for 'z'.

Pseudocode:
create a counter to keep track of the score 
create a array 

 for (i at 0 will iterate through size of the word)
    if (the letter it not in array)
        add it to the score
        mark the letter as seen 
return the total score

## Function 3: filter_vocabulary_grey

This function will filter down the vocabulary based on the letter that is not in the secret word. So if there is a word within vocabualry that do not contain said letter we will free up that pointer and set it to null.

Pseudocode:
create a counter
for ( i is 0 will iterate num_words)
    if(the word in vocab is not null and contains letter)
        free the word and set to null
increase counter
return counter 

## Function 4: filter_vocabulary_yellow 
This function will cut down the vocabulary based on if the letter is within the word but not at the guessed position , so we will remove any word that has the letter at that specified location or any word that does not contain said letter.

Pseudocode:
create a counter for the words that will be filtered from the vocabulary 

    for( i iterate through num_words)
        if (word not null)
            does it contain the ltter
            does it not contain the ltter   
            if so free the word and set it to null
            increment counter
return counter

## Function 5: Filter_vocabulary_green

This function will filter down the vocabualry based on if the letter is in the correct spot and if so remove the words that do not contain the letter at that position.

Pseudocode:
create a counter 

    for( i iterate through to num_words)
        if the word does not contain the letter at specified location and word is not NULL  
            free the wod and set it to NULL
            increment counter
return counter

## Memory Mnagement Plan 

the dynamic allocations within the load_vocabulary will need to be freed in free_vocabulary this will free any remaining words and the vocabulary array its self.
