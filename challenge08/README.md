Challenge 08
============

[Palindrome Permutation](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge08.html)

Challenge 08: Palindrome Permutation
Problem
Given a phrase, you are to determine if any permutation of the phrase (ignoring whitespace and punctuation) is a palindrome, which is a phrase that reads the same forwards and backwards. For instance, "taco cat" is an example of a palindrome.


 Inspiration

Note, this problem is inspired by Problem 1.4 from Cracking the Code Interview and Question 30 from Interview Cake.
Input
You will be given a series of phrases from standard input in the following format:

phrase1
phrase2
...
Each line is considered a separate phrase, which can consist of letters, numbers, spaces, and punctuation.

Output
For each input phrase, output a statement saying:

"phrase" is a palindrome permutation
if the input phrase is a palindrome permutation. Otherwise, output:

"phrase" is a not palindrome permutation
Note: You should ignore numbers, spaces, and punctuation in determining if a phrase is a palindrome permutation.

Example
Given the following input:

civic
ivicc
civil
livci
Your program should output the following:

"civic" is a palindrome permutation
"ivicc" is a palindrome permutation
"civil" is not a palindrome permutation
"livci" is not a palindrome permutation
Requirements
Your solution must meet the following requirements:

You must implement and utilize an is_palindrome(s) function that determines if a string s is a palindrome permutation in O(n) time using a std::unordered_set or std::unordered_map.
