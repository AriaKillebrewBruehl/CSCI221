CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=test_queue

all: $(TARGETS)


Queue.o: Queue.hh
Queue.o: Queue.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_queue.o: Queue.hh
test_queue.o: test_queue.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

test_queue: test_queue.o Queue.o
	$(CXX) $(CXX_FLAGS) -o $@ $^


test_queue_t: test_queue_t.cc Queue_T.hh
	$(CXX) $(CXX_FLAGS) -o $@ test_queue_t.cc

clean:
	rm -f *~ *.o $(TARGETS)
