# Homework 3: Design Document

 * author: Ricardo Ramirez
 * date: January 31, 2025

## introduction 

in this homework, we will write some short functions that deal with strings, arrays, and function pointers.The goal is to efficiently inpliment each function while documenting our design approah for each function.

## fuction 1: is one string a suffix of the other?

we can approach this by finding the length of both strings and then comparing the two, if needle is longer than haystack  we return false. We then compare the last characters of haystack with needle and return true if they match and false if they do not.

## function 2: repeats a string n times

we will first need to calculate the required  memory size and allocate the memoery using malloc(). A loop will then iterate n times and each iteration will append s to the allocated memory. Finally after the loop has finalized it will return the newley allocated string.

## function 3: is this string a palindrome? 

for this function we need to check whether the string is a palindrome , ignoring whitespace, puncuation, and case. We will start this off by allocating a new filtered string using malloc() and loop through s keeping only letters and converting them to lowercase using tolower() and storing them within the new st. Second we will use two pointers one at the beginning an one at the end and compare both while iterating to the center if any are not the same then we return false.

## function 4: Computing the dot product of a array 

Go through each pair of the elements within both arrays and multiplying them together, and adding all multiplied pairs to a total count and the final result is returned as the dot product.

## function 5: reduce

this function will inpliment the reduce operation, applying function f cumulatively across an array.
To do so we will just initialize a accumulator and iterate through the array while applying the function f and returning the accumulated result.

## function 6: finding the mximum element of an array with reduce 

We want to find the max value within a array by using a helper function that returns the greater of the two integers. The max value is initialized to the very first element of the array and then compares it to each element within the array and updating the value when a new bigger element is detected.

## function 7: summing all of the positive elements of an array with reduce 

This function computes the sum of all positive numbers within a array using reduce(). We can do this by defining a helper function where if the num is non negative we will add it to a counter if negative the counter returns unchanged. We can then call reduce and this will accumulate the sum of all positive numbers and finally returning the result.


