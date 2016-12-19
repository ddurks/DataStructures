Challenge 06
============

[Lowest Common Ancestor](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge06.html)

Implemented binary search tree + finding the lowest common ancestor of two nodes.

Challenge 06: Lowest Common Ancestor


Problem
When Dr. Danny Chen isn't cranking out a gazillion papers per month, he is probably devising mindtwisters to torture his Algorithms 1 students (among many other things). One of his favorite problems is to take an ordinary data structure and require the students to augment it with a new method or algorithm in an efficient and optimal manner.

For this problem, you are to implement a binary search tree (BST) and augment it with a new FindLowestCommonAncestor method which returns the lowest or nearest common ancestor of two nodes in the BST. Consider the tree to the right: The LCA for 1 and 7 is 3, while the LCA for 4 and 14 is 8. You are to augment a BST with a O(logn) implementation of this LCA method.

 Inspiration

Note, this problem is inspired by Problem 4.7 from Cracking the Code Interview and Problem 15.5 from Elements of Programming Interviews. I also had this as a homework question in Algorithms when I was an undergrad. Good times.
Input
The input will be a series of nodes which you will need to insert into a BST. The first line will specify the number of nodes in the tree. This will be followed by the nodes themselves. The next line will indicates the number of node pairs to compute the LCA on, followed by the pairs, one on each line. The input will be terminated by a -1 as the first line of the test case.

N
Node1 Node2 ... NodeN
P
A1 B1
...
AP BP
Output
For each test case, output the LCA for each pair of nodes (one on each line). Separate outputs from different trees with a blank line.

Example
Given the following input:

9
8 3 10 1 6 14 4 7 13
2
1 7
4 14
-1
Your program should output the following:

3
8
