CXX=g++
CXX_FLAGS=-g -std=c++11
.PHONY: all clean
TARGETS=dc

all: $(TARGETS)


dc: dc.cc Stck_T.hh
	$(CXX) $(CXX_FLAGS) -o $@ dc.cc

clean:
	rm -f *~ *.o $(TARGETS)
