Challenge 11
============

[Inverted Index](https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/challenge11.html)

Challenge 11: Inverted Index
Problem
For this challenge, you are to write both the map and reduce components for generating an Inverted Index:

The map function parses each line in an input file, and emits a sequence of <word, line number> pairs. The reduce function accepts all pairs for a given word, sorts the corresponding line numbers, and emits a <word, list(line numbers)> pair. The set of all the output pairs forms a simple inverted index.
Local Map-Reduce
As discussed in class, the canonical Map-Reduce example is performing a word count on a large collection of documents as shown below:


In the Map-Reduce programming model, you must define two functions:

A map function that transforms, filters, or selects input data

A reduce function that aggregates, combines, or collections results.

While Map-Reduce is normally performed on massive datasets using many networked machines, we can use the Hadoop Streaming interface to write Map-Reduce programs that run on small datasets on our local machines. The Hadoop Streaming interface simply specifies that both the map and reduce functions must emit key value pairs in the following format:

key\tvalue
That is, each line of output consists of the key followed by a tab character (i.e. \t) and then the value.

With this in mind, we can implement the word count application using the Hadoop Streaming interface with the following Python scripts:

# map.py
import sys

for line in sys.stdin:
    key, value = line.split('\t', 1)
    for word in value.strip().split():
        print '{}\t{}'.format(word, 1)

# reduce.py
import sys

key   = None
total = 0
for line in sys.stdin:
    k, v  = line.split('\t', 1)
    count = int(v.strip())

    if key == k:
        total += count
    else:
        if key:
            print '{}\t{}'.format(key, total)
        key   = k
        total = count

if key:
    print '{}\t{}'.format(key, total)
Given these two Python scripts, we can simulate Map-Reduce on a local machine by doing the following:

$ cat inputs.txt | ./map.py | sort | ./reduce.py
The end result will be a stream of key value pairs in the Hadoop Streaming format.

For this challenge, you will have to write two separate programs map.cpp and reduce.cpp that use the Hadoop Streaming interface to generate an Inverted Index.

 Inspiration

Note, this problem is inspired by the description of an Inverted Index in the MapReduce: Simplified Data Processing on Large Clusters paper.
Input / Output
The map.cpp program will receive the text of a document via standard input, while the reduce program will receive the results of the map.cpp program via standard input in Hadoop Streaming format. This means that both the map.cpp and the reduce.cpp programs should emit key value pairs in the Hadoop Streaming format.

Example
For example, given the following input file:

'Beware the Jabberwock, my son!
      The jaws that bite, the claws that catch!
Beware the Jubjub bird, and shun
      The frumious Bandersnatch!"
Running ./map < input.txt should yield the following intermediate outputs:

beware  1
the     1
jabberwock      1
my      1
son     1
the     2
jaws    2
that    2
bite    2
the     2
claws   2
that    2
catch   2
beware  3
the     3
jubjub  3
bird    3
and     3
shun    3
the     4
frumious        4
bandersnatch    4
That is, each line contains the word and the line number on which it occurs.

Note, we start counting the line numbers at 1, we ignore punctuation at the beginning and end of each word, and we ignore case by making everything lower-case.

Running ./map < input.sample | sort | ./reduce should yield the following results:

and     3
bandersnatch    4
beware  1 3
bird    3
bite    2
catch   2
claws   2
frumious        4
jabberwock      1
jaws    2
jubjub  3
my      1
shun    3
son     1
that    2
the     1 2 3 4
That is, each line contains the word and the line numbers on which it appears.

Note, the words are in lexicographical order and the line numbers are sorted from lowest to highest and are unique.

