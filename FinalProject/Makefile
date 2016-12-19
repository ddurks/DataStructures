CXX=		g++
CXXFLAGS=	-g -gdwarf-2 -Wall -std=gnu++11
LD=		g++
LDFLAGS=
AR=		ar
ARFLAGS=	rcs
SHELL=		bash

LIBRARY=	libTrie.a
LIB_SRC=	Trie.cpp
LIB_OBJ=	$(LIB_SRC:.cpp=.o)

PROGRAM= 	dictionary measure

all: $(LIBRARY) $(PROGRAM)

%.o:		%.cpp Trie.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

Trie.o: Trie.cpp Trie.h
	$(CXX) $(CXXFLAGS) -o $@ -c $<

$(LIBRARY):	$(LIB_OBJ) Trie.h
	$(AR) $(ARFLAGS) $@ $(LIB_OBJ)

dictionary: dictionary.o Trie.h $(LIBRARY)
	$(LD) $(LDFLAGS) -o $@ $< $(LIBRARY)

measure: test/measure.c
	gcc -Wall -std=gnu99 -o $@ $^

clean:
	rm -f $(LIBRARY) $(PROGRAMS) *.o

test: test-output test-memory test-time dictionary measure

test-output:
	@echo "Testing Output..."
	@diff --suppress-common-lines -y <(./dictionary -s < test/test.input) test/test.output

test-memory:
	@echo "Testing Memory..."
	@[ `valgrind --leak-check=full ./dictionary -s < test/test.input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-time:
	@echo "Testing Time..."
	@./measure ./dictionary -s < test/test.input | tail -n 1 | awk '{ if ($$1 > 5.0) { print "Time limit exceeded"; exit 1} }'
