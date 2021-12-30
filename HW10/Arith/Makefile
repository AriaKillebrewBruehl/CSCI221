CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=eval

all: $(TARGETS)


Arith.o: Arith.hh
Arith.o: Arith.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

eval.o: Arith.hh
eval.o: eval.cc
	$(CXX) $(CXX_FLAGS) -c -o $@ $<

eval: eval.o Arith.o
	$(CXX) $(CXX_FLAGS) -o $@ $^

clean:
	rm -f *~ *.o $(TARGETS)
