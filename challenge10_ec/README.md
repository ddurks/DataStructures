 Challenge 10 Extra Credit: Hamiltonian Path Problem
Problem
Hamiltonian

You will be given a series of undirected graphs. For this assignment, you must determine if for the given graph a Hamiltonian path exists.

A Hamiltonian path is a sequence of distinct edges that connects each vertex exactly once.

 Inspiration

This problem is an implementation of Algorithms Homework 1 Question 3.
Input
The input will be a number of graphs. The first line of input for each graph will contain a single integer, representing the number of vertices. What follows will be the N x N adjacency matrix for that graph.

N
A_1,1 A_1,2 ... A_1,N
A_2,1 A_2,2 ... A_2,N
...   ...   ... ...
A_N,1 A_N,2 ... A_N,N
Output
For each graph, you should output

Graph i contains a Hamiltonian path
or

Graph i does not contain a Hamiltonian path.
Example
Given the following input:

8
0 1 0 0 0 0 0 0
1 0 1 1 1 0 0 0
0 1 0 1 1 0 0 0
0 1 1 0 1 1 0 0
0 1 1 1 0 0 0 1
0 0 0 1 0 0 1 0
0 0 0 0 0 1 0 1
0 0 0 0 1 0 1 0
Your program should output the following:

Graph 0 contains a Hamiltonian path.
