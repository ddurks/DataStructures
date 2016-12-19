CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
LDFLAGS=	
SHELL=		bash
PROGRAMS=	lsort measure
SOURCES=	main.cpp node.cpp list.cpp stl.cpp qsort.cpp quick.cpp merge.cpp
OBJECTS=	$(SOURCES:.cpp=.o)

all:		$(PROGRAMS)

%.o:		%.cpp
	$(CXX) $(CXXFLAGS) -o $@ -c $^

measure:	measure.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

lsort:	$(OBJECTS) lsort.h
	$(CXX) $(LDFLAGS) -o $@ $(OBJECTS)

clean:
	rm -f $(PROGRAMS) $(OBJECTS)

test:		test-output test-memory test-time

test-output:	$(PROGRAMS)
	@echo "Testing output (stl string)..."
	@diff --suppress-common-lines -y <(./lsort -m stl      < input) output.string
	@echo "Testing output (stl number)..."
	@diff --suppress-common-lines -y <(./lsort -m stl -n   < input) output.number
	@echo "Testing output (qsort string)..."
	@diff --suppress-common-lines -y <(./lsort -m qsort    < input) output.string
	@echo "Testing output (qsort number)..."
	@diff --suppress-common-lines -y <(./lsort -m qsort -n < input) output.number
	@echo "Testing output (merge string)..."
	@diff --suppress-common-lines -y <(./lsort -m merge    < input) output.string
	@echo "Testing output (merge number)..."
	@diff --suppress-common-lines -y <(./lsort -m merge -n < input) output.number
	@echo "Testing output (quick string)..."
	@diff --suppress-common-lines -y <(./lsort -m quick    < input) output.string
	@echo "Testing output (quick number)..."
	@diff --suppress-common-lines -y <(./lsort -m quick -n < input) output.number

test-memory:	$(PROGRAMS)
	@echo "Testing memory (stl)..."
	@[ `valgrind --leak-check=full ./lsort -m stl   < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (qsort)..."
	@[ `valgrind --leak-check=full ./lsort -m qsort < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (merge)..."
	@[ `valgrind --leak-check=full ./lsort -m merge < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing memory (quick)..."
	@[ `valgrind --leak-check=full ./lsort -m quick < input < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-time:	$(PROGRAMS)
	@echo "Testing time (stl)..."
	@./measure ./lsort -m stl   < input 2>&1 | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing time (qsort)..."
	@./measure ./lsort -m qsort < input 2>&1 | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing time (merge)..."
	@./measure ./lsort -m merge < input 2>&1 | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing time (quick)..."
	@./measure ./lsort -m quick < input 2>&1 | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
