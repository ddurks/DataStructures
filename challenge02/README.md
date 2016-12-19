Challenge 02
============

David Durkin

Data Structures

 Challenge 02: Adding List-Based Integers
Problem
As you may already know from Fundamentals or Computer Architecture, integer values in C and C++ are limited by the number of bits used to represent that data. For instance, a 64-bit unsigned integer has the maximum value of 2^64 - 1 or 18446744073709551615.

To represent integers of arbitrary length, we can use a singly linked list data structure such that that a node in the linked list corresponds to a single digit in the integer.

For instance, the number 123 can be stored as linked-list that looks like the following:

[ 3 ] -> [ 2 ] -> [ 1 ] -> NULL
Note that the first or head node in this list contains the least significant digit (in this case 3), while the last node contains the most significant digit (1).

For this problem, you are to read in pairs of arbitrary length integers into singly linked lists, then use the lists to add the two numbers, and finally output the results.

 Inspiration

Note, this problem is inspired by Problem 8.19 from Elements of Programming Interviews and Problem 2.5 from Cracking the Code Interview.
Input
You will be given a series of integers from standard input in the follow format:

integer1 integer2
integer1 integer2
...
integer1 integer2
Each integer is of arbitrary length. Moreover, integer1 is not guaranteed to be the same length as integer2.

Output
You are to add each pair of integers and then output the resulting total as a single number:

result1
result2
...
resultN
Example
Given the following input:

1 1
123 123
1 12
Your program should output the following:

2
246
13
Requirements
Your solution must meet the following requirements:

You must create a custom linked list (ie. you cannot use std::list).

Your linked list must be templated.

If you dynamically allocate memory, then you must be sure you manage it properly (ie. no memory leaks or segmentation faults).

Hints
You may wish to read the integers in as std::strings.

You may wish to define a struct Node.

You may wish to define a struct List with an operation to add an item to the list.

You may wish to define a function that takes two lists and returns a list that contains the sum of the two input lists.

Be sure to account for the carry when you perform addition.
