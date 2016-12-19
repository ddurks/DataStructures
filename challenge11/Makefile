CXX=		g++
CXXFLAGS=	-g -Wall -std=gnu++11
SHELL=		bash
MEASURE=	../common/measure

all:		map reduce

map:		map.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

reduce:		reduce.cpp
	$(CXX) $(CXXFLAGS) -o $@ $^

clean:
	rm -f map reduce

test:		test-map-output test-map-memory test-map-time \
		test-reduce-output test-reduce-memory test-reduce-time \
		test-map-reduce

test-map-output:	map
	@echo "Testing map (small) output..."
	@diff --suppress-common-lines -y <(./map < input.small) output.small.map
	@echo "Testing map (large) output..."
	@diff --suppress-common-lines -y <(./map < input.large) output.large.map

test-map-memory:	map
	@echo "Testing map (small) memory..."
	@[ `valgrind --leak-check=full ./map < input.small 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing map (large) memory..."
	@[ `valgrind --leak-check=full ./map < input.large 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-map-time:		$(MEASURE) map
	@echo "Testing map (small) time..."
	@$(MEASURE) ./map < input.small | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing map (large) time..."
	@$(MEASURE) ./map < input.large | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'

test-reduce-output:	reduce
	@echo "Testing reduce (small) output..."
	@diff --suppress-common-lines -y <(LC_ALL=C sort output.small.map | ./reduce) output.small.reduce
	@echo "Testing reduce (large) output..."
	@diff --suppress-common-lines -y <(LC_ALL=C sort output.large.map | ./reduce) output.large.reduce

test-reduce-memory:	reduce
	@echo "Testing reduce (small) memory..."
	@[ `LC_ALL=C sort output.small.map | valgrind --leak-check=full ./reduce 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]
	@echo "Testing reduce (large) memory..."
	@[ `LC_ALL=C sort output.large.map | valgrind --leak-check=full ./reduce 2>&1 | grep ERROR | awk '{print $$4}'` = 0 ]

test-reduce-time:		$(MEASURE) reduce
	@echo "Testing reduce (small) time..."
	@LC_ALL=C sort output.small.map | $(MEASURE) ./reduce | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'
	@echo "Testing reduce (large) time..."
	@LC_ALL=C sort output.large.map | $(MEASURE) ./reduce | tail -n 1 | awk '{ if ($$1 > 1.0) { print "Time limit exceeded"; exit 1} }'

test-map-reduce:	map reduce
	@echo "Testing map reduce (small) output..."
	@diff --suppress-common-lines -y <(./map < input.small | LC_ALL=C sort | ./reduce) output.small.reduce
	@echo "Testing map reduce (large) output..."
	@diff --suppress-common-lines -y <(./map < input.large | LC_ALL=C sort | ./reduce) output.large.reduce
