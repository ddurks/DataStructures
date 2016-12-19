Challenge 10
============

[Minimum Spanning Tree](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge10.html)

Challenge 10: Minimum Spanning Tree
Problem
Given an undirected graph, determine the minimum spanning tree.


For instance, in Graph 0 above, the minimum spanning tree would have a total edge weight of 10 and consist of the following edges:

(A, C)
(B, C)
(C, E)
(D, E)
(D, F)
You will be given a series of graphs specified by a distance matrix. You are to compute the minimum spanning tree and output the total edge weight of the tree and the edges in the tree.

 Inspiration

Note, this problem is inspired by Challenge #152 [Hard] Minimum Spanning Tree from the DailyProgrammer subreddit.
Input
You will be given a series of undirected graphs from standard input in the following format:

NVERTICES
-1 -1 ...
-1 -1 ...
The first line specifies the number of vertices in the undirected graph, which will be between 1 and 26 (inclusive). This is followed by a distance matrix with each row separated by newlines and each column separated by spaces:

-1 is used to denote there is no edge between a pair of vertices.

The vertices are assumed to be named A, B, C, D and so on, with the matrix representing them in that order (left-to-right and top-to-bottom).

Output
For each undirected graph, you are to print out the total weight of the minimum spanning tree, and then the edges of the minimum spanning tree represented by the two vertices such as AB in lexicographical order.

Example
Given the following input:

6
-1  4  2 -1 -1 -1
 4 -1  1  8 -1 -1
 2  1 -1 -1  4 -1
-1  8 -1 -1  2  1
-1 -1  4  2 -1  7
-1 -1 -1  1  7 -1
5
-1  2  6 -1 -1
 2 -1  4  1 -1
 6  4 -1 -1  1
-1  1 -1 -1  1
-1 -1  1  1 -1
Your program should output the following:

10
AC
BC
CE
DE
DF

5
AB
BD
CE
DE
Note: You must put an empty line between the outputs of each graph.

