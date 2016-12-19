Project 02: lsort
===================
Group Members: David Durkin, Matt Reilly, Chris Beaufils

This is a simple implementation of the Unix [sort] utility that works on
[singly-linked lists].

[sort]: http://man7.org/linux/man-pages/man1/sort.1.html
[singly-linked lists]: https://en.wikipedia.org/wiki/Linked_list#Singly_linked_lists

**1**
```
stl: From the documentation, the time complexity of std::sort is O(nlog(n)) on
average. Because the C++11 standard requires the worst case time complexity to
be at least O(nlog(n)), that is the worst case of the algorithm. This sort is
an introsort, which is a hybrid sorting algorithm.

qsort: The time complexity of qsort is not provided in the documentation.
However, since we know it is a quick sort implementation, we can assume that
best case and average case are O(nlog(n)) while worst case is O(n^2) in the
case that the lowest or highest number is chosen as a pivot.

quick: The time complexity in the best and average case of the quick sort is
O(nlog(n)), while the worst case is O(n^2), this occurs when the highest or
lowest number in the list is selected as the pivot value.

merge: The time complexity of merge sort is O(nlog(n)) in all cases. This is
because the algorithm is executed the same way each time on all different types
of lists.
```

**2**

| Mode  	| Size     	| Elapsed Time (s) 	| Memory (Mbytes) 	|
|-------	|----------	|------------------	|-----------------	|
| STL   	| 10       	| 0.001999         	| 1.113           	|
| STL   	| 100      	| 0.001999         	| 1.121           	|
| STL   	| 1000     	| 0.004998         	| 1.199           	|
| STL   	| 10000    	| 0.04299          	| 2.0352          	|
| STL   	| 100000   	| 0.476            	| 9.828           	|
| STL   	| 1000000  	| 5.283            	| 86.898          	|
| STL   	| 10000000 	| 61.995           	| 893.0938        	|
| QSORT 	| 10       	| 0.001999         	| 1.1055          	|
| QSORT 	| 100      	| 0.001998         	| 1.1133          	|
| QSORT 	| 1000     	| 0.004998         	| 1.246           	|
| QSORT 	| 10000    	| 0.03799          	| 2.0898          	|
| QSORT 	| 100000   	| 0.4119           	| 10.4141         	|
| QSORT 	| 1000000  	| 4.4033           	| 92.8086         	|
| QSORT 	| 10000000 	| 48.315           	| 917.148         	|
| MERGE 	| 10       	| 0.001998         	| 1.1094          	|
| MERGE 	| 100      	| 0.002998         	| 1.1094          	|
| MERGE 	| 1000     	| 0.004998         	| 1.1836          	|
| MERGE 	| 10000    	| 0.04099          	| 1.8672          	|
| MERGE 	| 100000   	| 0.4339           	| 8.7383          	|
| MERGE 	| 1000000  	| 5.0652           	| 77.4023         	|
| MERGE 	| 10000000 	| 53.3099          	| 764.05078       	|
| QUICK 	| 10       	| 0.001998         	| 1.10547         	|
| QUICK 	| 100      	| 0.001998         	| 1.1133          	|
| QUICK 	| 1000     	| 0.004998         	| 1.1836          	|
| QUICK 	| 10000    	| 0.03599          	| 1.867           	|
| QUICK 	| 100000   	| 0.433            	| 8.742           	|
| QUICK 	| 1000000  	| 5.412            	| 77.4062         	|
| QUICK 	| 10000000 	| 71.0922          	| 764.05078       	|

**3**
In terms of execution time, the qsort was the fastest algorithm overall, followed by merge sort, stl sort, and finally quick sort. However, in terms of memory used, merge sort and quick sort used the least with very similar memory space, followed by stl sort and finally qsort. These results show that theoretical complexity is not an exact representation of the performance of an algorithm, and in practice there is some variation in performance based on other circumstances. In my opinion, merge sort is the best sorting algorithm out of the four algorithms used. Although it is not the fastest, it comes in a close second, only a few seconds behind stl sort in the 10000000 value sort. On top of this it also uses the least amount of space out of all of the algorithms. In addition, it has a very consistent time complexity, and unlike quick sort, there are no scenarios in which time complexity becomes very poor.

**Contributions**
Matt primarily implemented the sort and qsort algorithms, Chris implemented the Merge Sort algorithm and David implemented the Quick Sort algorithm. All members collaborated in testing and bug fixing, and all members assisted in answering the questions.
