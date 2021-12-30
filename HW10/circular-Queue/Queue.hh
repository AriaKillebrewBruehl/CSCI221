#ifndef __QUEUE_HH
#define __QUEUE_HH

#include <string>
#include <iostream>

class Queue {

private:
  int *elements;
  int headIndex;
  int tailIndex;
  int capacity;

public:  
  Queue(int capacity);
  bool is_empty();
  void enqueue(int value);
  int dequeue();
  int head();
  std::string to_string();
  ~Queue();
};

#endif




