Challenge 03
============

[Closest Numbers](http://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge03.html)

Challenge 03: Closests Numbers
Problem
In this problem, you are given a list of unsorted integers, A = {a1, a2, ..., aN} and you are to find the pair of elements that have the smallest absolute difference between them. If there are multiple pairs, then you should find them all.

 Inspiration

Note, this problem is based on the Closest Numbers challenge on HackerRank.
Input
You will be given a series of integers from standard input in the follow format:

N
a_1 a_2 ... a_N
Each input array will consist of two lines:

The first line consists of the N number of elements in the array.

The second line consists of the N elements in the array separated by spaces.

Output
For each input array, output the pairs of elements with the smallest difference. If there are multiple such pairs, then output all of the numbers in ascending order. All the numbers should be outputted on the same line with a single space between each pair of numbers. If a number appears in multiple pairs, print it once per pair.

Example
Given the following input:

10
-20 -3916237 -357920 -3620601 7374819 -7330761 30 6246457 -6461594 266854
Your program should output the following:

-20 30
Hints
You may wish to use the std::sort algorithm with the container of your choice.
