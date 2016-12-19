English Dictionary Implementation using a Trie
==============================================

**Group Members:** David Durkin, Matt Reilly, Chris Beaufils


**DESCRIPTION**
--------------
We plan to implement an interactive english dictionary program that includes
a spell-check "did you mean?" feature. The primary data structure will be a
Trie or prefix tree.

**USAGE**
---------
This is a program which used terminal by first typing make to compile, and then run by using the command ./dictionary with the following options:

```
usage: dictionary
    -i    INTERACTIVE mode, user is prompted for words to define
    -s    STANDARD mode, words are taken from standard in
    -l    LOAD ONLY mode, dictionary file is loaded, nothing else
```

The program can also be tested by running "make test".

An example run of the program in interactive mode:

```
Davids-MacBook-Pro:FinalProject dldurks$ ./dictionary -i
Welcome to our Dictionary!
==========================
Enter a word: dictionary
Definition: n. (pl. -ies) 1 book listing (usu. Alphabetically) and explaining the words of a language or giving corresponding words in another language. 2 reference book explaining the terms of a particular subject. [medieval latin: related to *diction]
----------
Enter a word: 
```

**ANALYSIS**
------------
Lists of random words were generated using: https://www.randomlists.com/random-words

Average load time and memory usage for 40,000 word dictionary:

|Average Load Time|Average Memory Usage|
|-----------------|--------------------|
|0.5490032s|50.8695312MB|


Time and space to define different amounts of words (maximum was 2,643):

|Words|Time|Memory|
|-----|----|------|
|10|0.551816 seconds|	50.875000 Mbytes|
|100|0.942860 seconds|	50.898438 Mbytes|
|500|5.385268 seconds|	50.933594 Mbytes|
|1000|36.009338 seconds|	50.953125 Mbytes|
|2643|80.120125 seconds|	50.976562 Mbytes|

Most of the slowdown is caused by the Levenshtein Distance algorithm and generating suggestions. When searching only for words in the dictionary, the results are different:

|Words|Time|Memory|
|-----|----|------|
|ALL|0.971934 seconds|	50.894531 Mbytes|
