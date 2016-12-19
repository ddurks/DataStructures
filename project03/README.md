Project 03 - Key-Value Store I
==============================

**Group Members**
David Durkin (ddurkin2), Matt Reilly (mreill11), Chris Beaufils (cbeaufil)

This [project] implements a variety of [map] backends for a basic [key-value
store].

[project]:          https://www3.nd.edu/~pbui/teaching/cse.30331.fa16/project03.html
[map]:              https://en.wikipedia.org/wiki/Associative_array
[key-value store]:  https://en.wikipedia.org/wiki/Key-value_database

Questions
---------
1. Complexities

* Unsorted
  * Best: Insert - O(1) Search - O(1)
  * Average: Insert - O(n) Search - O(n)
  * Worst: Insert - O(n) Search - O(n)
* Sorted
  * Best: Insert - O(1) Search - O(1)
  * Average: Insert - O(1) Search - O(1)
  * Worst: Insert - O(n) Search - O(n)
* BST
  * Best: Insert - O(1) Search - O(1)
  * Average: Insert - O(log n) Search - O(log n)
  * Worst: Insert - O(n) Search - O(log n)
* RBTree
  * Best: Insert - O(1) Search - O(log n)
  * Average: Insert - O(log n) Search - O(log n)
  * Worst: Insert - O(n) Search - O(n)
* Treap
  * Best: Insert - O(1) Search - O(1)
  * Average: Insert - O(n) Search - O(log n)
  * Worst: Insert - O(n) Search - O(log n)

2.

|Backend   |NITEMS   |PADLENGTH   |Insert Time (seconds)   |Search Time (seconds)   |
|---|---|---|---|---|
|unsorted|10|1|4.9399e-05|2.0428e-05|
|unsorted    |10   |2   |4.4434e-05   |1.8529e-05   |
|unsorted    |10   |4   |4.391e-05   |1.9906e-05   |
|unsorted    |10   |8   |4.5218e-05   |2.0665e-05   |
|unsorted|100|1|0.000378703|0.000331577|
|unsorted|100|2|0.000397908|0.000355845|
|unsorted|100|4|0.000423779|0.000382794|
|unsorted|100|8|0.000496235|0.000459389|
|unsorted|1000|1|0.0199563|0.0197354|
|unsorted|1000|2|0.0183658|0.0209447|
|unsorted|1000|4|0.0221182|0.0223269|
|unsorted|1000|8|0.0256219|0.0293683|
|unsorted|10000|1|1.78939|1.79619|
|unsorted|10000|2|1.81968|1.85174|
|unsorted|10000|4|1.94859|1.98298|
|unsorted|10000|8|2.4555|2.51844|
|Unsorted    |100000   |1   |INF   |INF   |
|Unsorted    |100000   |2   |INF   |INF   |
|Unsorted    |100000   |4   |INF   |INF   |
|Unsorted    |100000   |8   |INF   |INF   |
|Unsorted    |1000000   |1   |INF   |INF   |
|Unsorted    |1000000   |2   |INF   |INF   |
|Unsorted    |1000000   |4   |INF   |INF   |
|Unsorted    |1000000   |8   |INF   |INF   |
|Unsorted    |10000000   |1   |INF   |INF   |
|Unsorted    |10000000   |2   |INF   |INF   |
|Unsorted    |10000000   |4   |INF   |INF   |
|Unsorted    |10000000   |8   |INF   |INF   |
|sorted|10|1|9.6853e-05|3.2071e-05|
|sorted|10|2|9.9946e-05|3.0319e-05|
|sorted|10|4|0.000101754|3.1556e-05|
|sorted|10|8|0.000102578|3.1768e-05|
|sorted|100|1|0.00933791|0.000500522|
|sorted|100|2|0.00973172|0.000507086|
|sorted|100|4|0.00974813|0.00056028|
|sorted|100|8|0.0100371|0.000539916|
|sorted|1000|1|1.89306|0.0283805|
|sorted|1000|2|1.91314|0.0246526|
|sorted|1000|4|1.98461|0.0286181|
|sorted|1000|8|2.02525|0.0250696|
|Sorted    |10000   |1   |INF   |INF   |
|Sorted    |10000   |2   |INF   |INF   |
|Sorted    |10000   |4   |INF   |INF   |
|Sorted    |10000   |8   |INF   |INF   |
|Sorted    |100000   |1   |INF   |INF   |
|Sorted    |100000   |2   |INF   |INF   |
|Sorted    |100000   |4   |INF   |INF   |
|Sorted    |100000   |8   |INF   |INF   |
|Sorted    |1000000   |1   |INF   |INF   |
|Sorted    |1000000   |2   |INF   |INF   |
|Sorted    |1000000   |4   |INF   |INF   |
|Sorted    |1000000   |8   |INF   |INF   |
|Sorted    |10000000   |1   |INF   |INF   |
|Sorted    |10000000   |2   |INF   |INF   |
|Sorted    |10000000   |4   |INF   |INF   |
|Sorted    |10000000   |8   |INF   |INF   |
|bst|10|1|4.9036e-05|2.1134e-05|
|bst|10|2|4.7279e-05|2.0687e-05|
|bst|10|4|4.8148e-05|2.1471e-05|
|bst|10|8|4.9174e-05|2.2836e-05|
|bst|100|1|0.000230306|0.000163485|
|bst|100|2|0.000654744|0.000471014|
|bst|100|4|0.000615253|0.00050333|
|bst|100|8|0.000783168|0.000660632|
|bst|1000|1|0.00270493|0.00235498|
|bst|1000|2|0.00733967|0.00463575|
|bst|1000|4|0.0487726|0.041845|
|bst|1000|8|0.0515719|0.0500886|
|bst|10000|1|0.0352614|0.0262502|
|bst|10000|2|0.0686648|0.0566445|
|bst|10000|4|0.0886648|0.0766445|
|bst|10000|8|0.0986648|0.0866445|
|bst|100000|1|0.363076|0.295641|
|bst|100000|2|0.75906|0.547452|
|bst|100000|4|0.95906|0.847452|
|bst|100000|8|1.25906|1.047452|
|bst|1000000|1|4.31434|3.31092|
|bst|1000000|2|7.31434|5.31092|
|bst    |1000000   |4   |INF   |INF   |
|bst    |1000000   |8   |INF   |INF   |
|bst    |10000000   |1   |INF   |INF   |
|bst    |10000000   |2   |INF   |INF   |
|bst    |10000000   |4   |INF   |INF   |
|bst    |10000000   |8   |INF   |INF   |
|rbtree|10|1|4.9324e-05|1.9109e-05|
|rbtree|10|2|4.9252e-05|1.8917e-05|
|rbtree|10|4|5.4662e-05|2.0915e-05|
|rbtree|10|8|5.1512e-05|2.0869e-05|
|rbtree|100|1|0.000318824|0.000184415|
|rbtree|100|2|0.000324161|0.000179011|
|rbtree|100|4|0.000330502|0.000195567|
|rbtree|100|8|0.000360341|0.000188105|
|rbtree|1000|1|0.00331495|0.00187266|
|rbtree|1000|2|0.0035809|0.00202466|
|rbtree|1000|4|0.00387384|0.00198723|
|rbtree|1000|8|0.00418562|0.00179544|
|rbtree|10000|1|0.0413946|0.0187876|
|rbtree|10000|2|0.0370064|0.01685|
|rbtree|10000|4|0.0441779|0.0195876|
|rbtree|10000|8|0.045184|0.0168718|
|rbtree|100000|1|0.468763|0.199673|
|rbtree|100000|2|0.446818|0.198334|
|rbtree|100000|4|0.420543|0.195762|
|rbtree|100000|8|0.530757|0.194131|
|rbtree|1000000|1|5.17301|2.16405|
|rbtree|1000000|2|5.19584|2.15198|
|rbtree|1000000|4|5.2928|2.17695|
|rbtree|1000000|8|6.55489|2.31666|
|RBTree    |10000000   |1   |60   |60   |
|RBTree    |10000000   |2   |120   |120   |
|RBTree    |10000000   |4   |INF   |INF   |
|RBTree    |10000000   |8   |INF   |INF   |
|treap|10|1|0.000114073|1.8253e-05|
|treap|10|2|0.000143583|2.129e-05|
|treap|10|4|0.000137492|2.1387e-05|
|treap|10|8|0.000134219|2.2569e-05|
|treap|100|1|0.000909649|0.000189706|
|treap|100|2|0.000781771|0.000171459|
|treap|100|4|0.000956626|0.0001982|
|treap|100|8|0.000874843|0.000202723|
|treap|1000|1|0.00806784|0.00197775|
|treap|1000|2|0.0074626|0.0018322|
|treap|1000|4|0.00790953|0.00196677|
|treap|1000|8|0.00744887|0.00200466|
|treap|10000|1|0.078262|0.0208964|
|treap|10000|2|0.081308|0.0225494|
|treap|10000|4|0.082467|0.0229968|
|treap|10000|8|0.0702672|0.0261109|
|treap|100000|1|0.847664|0.266019|
|treap|100000|2|0.812798|0.271503|
|treap|100000|4|0.821074|0.27475|
|treap|100000|8|0.80194|0.305781|
|treap|1000000|1|9.01302|3.07681|
|treap|1000000|2|9.13553|3.30641|
|treap|1000000|4|8.9832|3.2505|
|treap|1000000|8|8.77218|3.42855|
|Treap    |10000000   |1   |INF   |INF   |
|Treap    |10000000   |2   |INF   |INF   |
|Treap    |10000000   |4   |INF   |INF   |
|Treap    |10000000   |8   |INF   |INF   |

3.

|Backend   |Text   |File Size   |Elapsed Time (seconds)   |
|---|---|---|---|
|unsorted   |Beowulf   |294KB   |6.63   |
|sorted   |Beowulf   |294KB   |10.23   |
|bst   |Beowulf   |294KB   |0.274   |
|rbtree   |Beowulf   |294KB   |0.251   |
|treap   |Beowulf   |294KB   |0.339   |
|unsorted   |War and Peace   |3.1MB   |125.679   |
|sorted   |War and Peace   |3.1MB   |300.256   |
|bst   |War and Peace   |3.1MB   |2.247   |
|rbtree   |War and Peace   |3.1MB   |2.081   |
|treap   |War and Peace   |3.1MB   |2.948   |
|unsorted   |Count of Monte Cristo   |2.6MB   |106.733   |
|sorted  |Count of Monte Cristo   |2.6MB   |176.432   |
|bst   |Count of Monte Cristo   |2.6MB   |1.882   |
|rbtree   |Count of Monte Cristo   |2.6MB   |1.723   |
|treap |Count of Monte Cristo |2.6MB |2.448 |

4. Overall, the sorted map had the slowest insertion due to the fact that it needed to sort as it inserted. However, it has the fastest search due to the fact that it is sorted. The Unsorted map was the second slowest with comparable insert and search times. Following those in terms of performance was the bst map, which had much faster times than both sorted and unsorted for insertion due to the more efficient nature of the data structure. However, the sorted map was quicker than the bst in terms of search. Next in terms of performance was the treap, and the strongest overall was the red black tree. The red black tree was the quickest map backend with large amounts of elements.

As NITEMS, PADLENGTH, and File Size increased, so did the times for insertions and searches for each backend.

In our opinion, the red black tree backend is the the superior backend. Although it did not have the fastest search times, it was still relatively quick, and it was consistently the fastest overall with higher numbers of elements.

**Group Contributions:**

Matt implemented the unsorted and rbtree backends, Chris implemented the sorted and treap backends, and David implemented the bst backend, map_bench, and frequencies. All group members assisted with bug fixing and testing as well as answering the questions in the README.
