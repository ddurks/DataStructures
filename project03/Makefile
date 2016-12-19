CXX=		g++
CXXFLAGS=	-g -gdwarf-2 -Wall -std=gnu++11
LD=		g++
LDFLAGS=
AR=		ar
ARFLAGS=	rcs
SHELL=		bash

LIBRARY=	libmap.a
LIB_SRC=	constants.cpp unsorted.cpp sorted.cpp bst.cpp rbtree.cpp treap.cpp
LIB_OBJ=	$(LIB_SRC:.cpp=.o)

PROGRAMS=	map_test map_bench frequencies

all:		$(LIBRARY) $(PROGRAMS)

%.o:		%.cpp map.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(LIBRARY):	$(LIB_OBJ)
	$(AR) $(ARFLAGS) $@ $(LIB_OBJ)

map_test:	map_test.o map.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

map_bench:	map_bench.o map.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

frequencies:	frequencies.o map.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

clean:
	rm -f $(LIBRARY) $(PROGRAMS) *.o

test:	test-unsorted test-sorted test-bst test-rbtree test-treap

test-unsorted: map_test
	@echo "Testing Unsorted Map (Correctness)..."
	@./map_test -b unsorted

	@echo "Testing Unsorted Map (Memory)..."
	@[ `valgrind --leak-check=full ./map_test -b unsorted 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-sorted: map_test
	@echo "Testing Sorted Map (Correctness)..."
	@./map_test -b sorted

	@echo "Testing Sorted Map (Memory)..."
	@[ `valgrind --leak-check=full ./map_test -b sorted 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-bst: map_test
	@echo "Testing BST Map (Correctness)..."
	@./map_test -b bst

	@echo "Testing BST Map (Memory)..."
	@[ `valgrind --leak-check=full ./map_test -b bst 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-rbtree: map_test
	@echo "Testing RBTree Map (Correctness)..."
	@./map_test -b rbtree

	@echo "Testing RBTree Map (Memory)..."
	@[ `valgrind --leak-check=full ./map_test -b rbtree 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-treap: map_test
	@echo "Testing Treap Map (Correctness)..."
	@./map_test -b treap

	@echo "Testing Treap Map (Memory)..."
	@[ `valgrind --leak-check=full ./map_test -b treap 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
