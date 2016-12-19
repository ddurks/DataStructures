Challenge 05
============

[BST Check](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge05.html)

Array Implementation Binary Search Tree. Determining whether input is a BST

Challenge 05: BST Check


Problem
For this challenge, you are giving a series of binary trees and you are to check if each given binary tree is also a binary search tree. Recall that a binary search tree is a binary tree such that:

The value at a node is never less than an entry in its left subtree.

The value at a node is less than every entry in its right subtree.

For instance, the tree to the right is in fact a binary search tree.

 Inspiration

Note, this problem is inspired by Problem 4.5 from Cracking the Code Interview.
Input
You will be given a series of trees specified in Breadth First Search order from standard input:

N N_0 N_1 ... N_N-1
The first number of each line is the number of nodes in the binary tree.

The remaining numbers are the values for each node.

Any nodes with the value -1 are considered empty nodes (ie. they don't exist).

Output
For each tree, you should output the message:

Tree N is a BST
if the binary tree is a binary search tree. Otherwise, you should output:

Tree N is not a BST
Note, N is the tree number in the order in each it was read (starting from 1).

Example
Given the following input:

2 20 20
3 20 -1 20
14 8 3 10 1 6 -1 14 -1 -1 4 7 -1 -1 13
Your program should output the following:

Tree 1 is a BST
Tree 2 is not a BST
Tree 3 is a BST
