Challenge 07
============

[Deduplicating Linked Lists](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge07.html)

Removes duplicates from an unsorted linked list in O(N) time using a hash table.

Challenge 07: Deduplicating Linked Lists
Problem
Write code that removes duplicates from an unsorted linked list in O(N) time using a hash table.

 Inspiration

Note, this problem is inspired by Problem 2.1 from Cracking the Code Interview and Problem 8.10 from Elements of Programming Interviews.
Input
You will be given a series of integers in the following format:

N
INT_1 INT_2 ... INT_N
Each input list consists of two lines:

The first line consists of the N number of items in the list.

The second line consists of the N items in the list separated by spaces.

Output
For each input list, output the list of integers without any duplicates. You should maintain the order in which the numbers appear in the input.

Example
Given the following input:

1
1
3
1 2 1
5
1 2 1 3 4
Your program should output the following:

1
1 2
1 2 3 4
Requirements
Your solution must meet the following requirements:

You must create and utilize a custom linked list (ie. you cannot use std::list) to store the input.

You must implement a deduplicate function or method that removes duplicates from a linked list in O(n) time using a std::unordered_set.
