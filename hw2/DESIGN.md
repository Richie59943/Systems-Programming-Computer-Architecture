# Homework 2: Design Document

  * author: Ricardo Ramirez
  * date: Janurary 22, 2025

## introduction

In this homework, I will write 5 functions that deal with numbers and arrays as well as write a calculator program which will read it's input from a file.

## function 1: Computing the next Collatz number

We will create this fucntion by checking with a if statemnet if the number being passed (n) is even then we will divide by 2 if this number were to be odd then we will multiply the number n by 3 and add 1. This function will make sure to compute the next Collatz number.e

## function 2: Counting  Collatz steps to convergence  
The count_collatz_steps function computes how many iterations are required for a number n to reach 1 following the rules of the Collatz sequence. Starting with the input value of n, it repeatedly calls next_collatz_number to generate the next number in the sequence. Each step increments a counter, current_num, which tracks the total number of iterations. The loop terminates when n equals 1, at which point the function returns the counter
## function 3: Finding the maximum element of an array
The maximum function finds the largest integer in an array. It initializes a placeholder to the first element of the array and iterates through the rest, updating the placeholder whenever a larger value is found. The function returns the placeholder as the maximum value, ensuring no out-of-bounds errors.


## function 4: Summing all of the positive elements of an array
The sum_positive function computes the sum of all positive integers (greater than 0) in an array. It begins by initializing a variable, pos_total, to 0 to store the cumulative sum. The function iterates through each element in the array using a for loop, checking if the current element is positive (>0). If the condition is met, the element is added to pos_total. After the loop completes, the function returns pos_total

## Counting all the negative numbers in an array
The count_negative function counts the number of elements in an array that are less than 0. It initializes a counter variable, neg_nums_total, to 0 and iterates through the array using a for loop. For each element, the function checks if it meets the condition (< 0) and increments the counter if true. At the end of the iteration, the function returns the total count.



## the calculator program

The calculator_program function processes a file containing numbers and arithmetic operators to compute a result. The first line of the file contains the initial number, which is converted from a string to a long using strtol() and stored in a current_total  variable. The second line is an arithmetic operator that is stored in an operator variable. The third line is another number, and the program combines it with the current_totall variable using the previously stored operator. If the operator is a division sign (/), the program checks if the number being divided by is zero; if true, it prints "ERROR\n" and terminates. Otherwise, the program continues.
