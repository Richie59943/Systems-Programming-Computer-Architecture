# Homework 7: Customer Database with Hash Tables

 * Author: Ricardo Ramirez
 * Date: March 3, 2025

## Introduction

In this homework we are going to create a simple customer databse system that stores information about customers who purchase food and shoes. This database will use a hash table to store and mange the customers records. A command line interface will allow users to interact with the data base by adding, deleting,listing, and saving customer records to a file.

## Data Structure Choice

The purpose of choosing a hash table is that this will allow us to do quick lookups and not use up so muhc memory in comparison to other data strcutures. The Hash table consitsis of Buckets that are array's where each index contains a linked list of customers while the hash function computes an index using the email adress and takes the modulo of the bucket count and if there were to be collisions we will seperate them with the linked lists.

## Loading the Customer Database from File 

We will need to open the customers.tsv for reading whcih will allow us to read each line containing email,name,shoe size, and favorite food and we can do this using strtok(). We will then create a new customer and insert this into the hash table but also here is where we will have error handling if there are any input errors.

Pseudocode 

open customers.tsv
while(fgets(line))
{   
    parse email, anem , shoe size, favorite food
    insert into hash table
}
close file

## The Main interaction loop

This part of the code will continuously prompt the user for commands and process them, such as add which will allow to insert a new customer or lookup which will retrive the information of a customer if present in database or delete which will remove a customer from the database. Also list which would show the list of customers within the database or also save which will write the databse to customers.tsv and lastly quit which will free memory and exit

Pseudocode

while (true) {
    display prompt
    read command
    if command == "add" then add customer()
    if command == "lookup" then lookup customer()
    if command == "delete" then delete customer()
    if command == "list" then list customers()
    if command == "save" then save to file()
    if command == "quit" then cleanup and exit
}

## Adding a customer 

We will prompt the user for the details of this customer and insert them into the hash table and if the email already exsit we will replace data and free the old memeory.

Pseudocode

read email, name, shoe size, favorite food
hash the email to find bucket
if ( email exisit then replace data)
else insert new customer into linked list

## Lookin Up a Customer

Prompt for an email and get the data from the hash table and finaly display the details of the specified customer or display error message

Pseudocode 

read email
hash the email to find bucket
search linked list
if found then display customer details 
else print "Customer not in databae"

## Deleting Customer 

We will prompt for a email and locate this customer in the hash table and remove it by freeing the allocated memory

Pseudocode

read email
hash email to find bucket
search linked list
if (found then remove node and free memory)
else print "customer not in database"

## Listing All Customers

we will do this but iterating through all the buckets and printing the customers details

Pseudocode

for(each bucket)
    for(each customer in linked list)
        print customer details

## Saving the Databse to file 

We will open the customers.tsv for writing and then write each data of the customer into a tab seperated format

open customers.tsv for writing 
for each bucket
    for each customer in linked list
        write email,name,shoe size, favorite food
close file

