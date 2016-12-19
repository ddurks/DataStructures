Challenge 09
============

[Graph Paths](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge09.html)

 Challenge 09: Graph Paths
Problem
Given a directed graph, determine if there is a path between two nodes in the graph.


For instance, in Graph 4 above, there is a path from A to D, but no path from D to A.

You will be given a series of graphs specified by edge pairs, and then a series of paths to check for. For each path, you are to determine if the graph contains a route from the specified source to the specified destination.

 Inspiration

Note, this problem is inspired by Problem 4.2 from Cracking the Code Interview.
Input
You will be given a series of directed graphs from standard input in the following format:

NEDGES
SRC1 DST1
...
NPATHS
SRC1 DST1
...
The first line specifies the number of edges in the directed graph, followed by NEDGES pairs of nodes where the first string is the source and the second string is the destination, which indicates that there is an edge from source to destination. After this, you are given NPATHS which is the number of paths or routes to search for. The exact paths to verify follow this line as a a series of source and destination pairs.

Output
For each path for a particular directed graph, output a statement saying:

In Graph 1 there is a path from A to B

if there is a path from A to B. Otherwise, output a statement saying:

In Graph 1 there is no path from A to B

Put an empty line between the output for each graph as shown below.

Example
Given the following input:

1
A B
2
A B
B A

3
A B
A C
B C
4
A B
A C
B C
C B
Your program should output the following:

In Graph 1 there is a path from A to B
In Graph 1 there is no path from B to A

In Graph 2 there is a path from A to B
In Graph 2 there is a path from A to C
In Graph 2 there is a path from B to C
In Graph 2 there is no path from C to B
Requirements
Your solution must meet the following requirements:

You must represent the graph using either adjacency list or adjacency matrix.
