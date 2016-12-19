CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash
MEASURE=	../common/measure

all:		solution

solution:	solution.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f solution

test:		test-output test-memory test-time

test-output:	solution
	@echo Testing output...
	@diff --suppress-common-lines -y <(./solution < input) output

test-memory:	solution
	@echo Testing memory...
	@[ `valgrind --leak-check=full ./solution < input 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-time:	$(MEASURE) solution
	@echo Testing time...
	@$(MEASURE) ./solution < input | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'

