Challenge 01 - README
=====================

- [Rotating Arrays](http://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge01.html)

Rotating Arrays

 Challenge 01: Rotating Arrays
Problem
A left rotation operation on an array of n size shifts each of the array's elements 1 unit to the left. For example, if 2 left rotations are performed on array [1, 2, 3, 4, 5], then the array would become [3, 4, 5, 1, 2].

Similarly, a right rotation operation on an array of n size shifts each of the array's elements 1 unit to the right. For example if 2 right rotations are performed on array [1, 2, 3, 4, 5], then the array would become [4, 5, 1, 2, 3].

Given an array of n integers, a number r, and a direction d (e.g L or R), perform r rotations on the n integers in the d direction and output the resulting data.

 Inspiration

This problem is based on the Left Rotation challenge on HackerRank.
Input
You will be given a series of inputs from standard input in the follow format:

n r d
i_0 i_1 ... i_n-1
...
Each input array will consist of two lines:

The first line consists of the n number of values, r number of rotations, and d rotational direction (L for left rotation and R for right rotation).

The second line consists of the n elements in the array.

Output
For each input array, you are to perform the specified r rotations in the d direction and print all the resulting array such that the elements are separated by spaces and the last element is followed by a newline character.

Example
Given the following input:

5 4 L
1 2 3 4 5
5 4 R
1 2 3 4 5
Your program should output the following:

5 1 2 3 4
2 3 4 5 1
Hints
You may wish to use a STL Sequence Container such as std::vector.

You may wish to use the std::swap function.
