Challenge 04
============

[Ranking Cards](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge04.html)

 Read in a series of cards and players, display them from highest card holder to lowest
 
 Challenge 04: Ranking Cards


Problem
As a good and responsible parent, the instructor is teaching his children how to play cards1. Although they are pretty good at counting, the children still struggle with determining which cards have the highest value due to the fact that some cards have faces rather numbers and that you also have to factor in suits for when the values are the same.

For this problem, you are to read in a series of cardholders and their corresponding cards, and then display the cardholders in the order of highest card value to lowest.

 Inspiration

I just made this one up.
Input
You will be given a series of hands from standard input in the follow format:

N
Name1 Rank1 Suit1
...
NameN RankN SuitN
N indicates the number of cardholders.

Name is the name of the cardholder.

Rank is the rank of the card: 2, 3, 4, 5, 6, 7, 8, 9, 10, J, Q, K, A.

Suit is the suit of the card: C, D, H, S (ie. clubs, diamonds, hearts, spades).

The input will be terminated by a non-positive N value.

Output
You are to order the cardholders of each input set and display them such that the person with the highest card value comes first, while the person with the lowest card value comes last. Separate cardholders with ", ":

NameHighest, ..., NameLowest
You must use the ordering above as the rules of precedence for both Rank and Suit. (Note: you should use the Suit in the case of a tied Rank.)

Example
Given the following input:

4
Peter 10 D
Caleb 9 H
Abigail J H
Madeline J S
-1
Your program should output the following:

Madeline, Abigail, Peter, Caleb
