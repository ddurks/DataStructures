Challenge 09 Extra Credit: Graph Partitioning
Problem
For this problem, you are to partition an undirected graph into connected subgraphs. That is, given a graph, you must break up the graph into multiple subgraphs such that for each subgraph there exists a series of 1 or more edges between any two distinct nodes in the subgraph.

Connected Graph
For example, the graph above should be separated into two subgraphs: one containing a, b, c, d, and e, and a second with x and y.

 Inspiration

This challenge was inspired by a real-world problem. The Office of Information-Technologies at Notre Dame was looking to create backups of the EC2 Security Groups in their Amazon Web Services account. They were looking to create CloudFormation templates to recreate their security groups in a disaster-recovery scenario. EC2 Security Groups can reference other security groups as dependencies, so its necessary to have all security groups that depend on each other in the same CloudFormation template. Amazon Web Services only allows a maximum of 200 objects per CloudFormation template, so each connected cluster of dependent security groups had to be distilled and placed in separate templates.
Input
The input will be a series of single-character labels for some number of vertices, followed by the adjacency matrix for the graph. The first line of the input specifies the number of vertices. The adjacency matrix lists which vertices are connected to which. Because the graph is undirected, the adjacency matrix will always be symmetric.

N
V_1   V_2   ... V_N
A_1,1 A_1,2 ... A_1,N
A_2,1 A_2,2 ... A_2,N
...   ...   ... ...
A_N,1 A_N,2 ... A_N,N
Output
For each graph, output the connected subgraph(s) by specifying first the vertices in the graph, and then the corresponding adjacency matrix. The vertices must be output with the same relative order as they appear in the input, and the subgraphs must be ordered according to their first vertex. Separate consecutive subgraphs with a blank line.

Example
Given the following input:

5
a b c d e
0 1 0 0 0
1 0 0 0 0
0 0 0 0 1
0 0 0 0 0
0 0 1 0 0
Your program should output the following:

a b
0 1
1 0

c e
0 1
1 0

d
0
