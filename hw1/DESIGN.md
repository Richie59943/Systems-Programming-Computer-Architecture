# Homework 1: Design Document

  * author: Ricardo Ramirez
  * date: January 16, 2025

## introduction

In this homework, I will be implementing five different C functions and a program named `caat.c`. Each function has a specific purpose and will demonstrate key programming concepts, including mathematical computations, conditional logic, and range checking. The `caat.c` program will handle character processing, ensuring that vowels are identified and doubled in the output if found.
 

## function 1: area_of_disk

Within this function we will be using the formula for the area of a cirlce: A = Pi * r^2, the function will take the radius of the disk and output the area of the circle.

## function 2: area_of_ring 

This function is going to take the outer radius of a disk and the inner radius of the hole and will retunr the area of the ring using the formula A = Pi(R^2-r^2) where R^2 is the Outer Radius and r^2 is the inner radius. Within this formula the Outer radius must be greater than the Inner radius for it to work so i have inplimented a if statement checking if it is greater than the program will run if not the program will output a Error.

## function 3: bigger_minus_smaller

This function will figure out which of the two numbers is greater by using a if statement that will compare the two numbers and figure out which of the two is greatest, if true then the it will subtract the second number from the first and if false returns then it will subtract the first number from the second..
## function 4: value_in_range

This function will take in three numbers (a lower bound, a specific value, and an upper bound) and will return true if the value inputted is within the range of the lower and upper numbers and false otherwiseindicating that the value was not within range. These user inputs can be negative but the upper must be greater than the lower bound.

## fuction 5: sum_of_greater_squares

This function will take three numbers a,b,and c and will return the sum of the two greatest squares out of the three. We will do so by squaring each number, use a if statement to see if the first sqaure is less than or equal to the second sqaure and third square, if true then the second sqaure is added to the third sqaure. While if it returns false then we check of the second sqaure is less than or equal to the first sqaure and the third sqaure, if true is returned then we will take the first sqaure and add the third swaure to it and if false we will return the first sqaure plus the second sqaure.

## the caat program

Within this code we are using getchar() to read and take each character of a string one at a time, which allows us to check for any vowels. The program works by taking in the string of characters and printing out the character and then if it is a vowel then we will print it again.
