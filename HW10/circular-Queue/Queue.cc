#include "Queue.hh"
#include <cassert>
#include <string>
#include <iostream>

Queue::Queue(int capacity) :
  elements {new int[capacity]},
  headIndex {0},
  tailIndex {0},
  capacity {capacity}
{ }

bool Queue::is_empty() {
  return (headIndex == tailIndex);
}

void Queue::enqueue(int value) {
  elements[tailIndex] = value;
  tailIndex = (tailIndex + 1) % capacity;
}  

int Queue::dequeue() {
  assert(!is_empty());
  int item = head();
  headIndex = (headIndex + 1) % capacity;
  return item;
}  

int Queue::head() {
  assert(!is_empty());
  return elements[headIndex];
}  

std::string Queue::to_string() {
  if (is_empty()) {
    return "[ ]";
  } else {
    int i = headIndex;
    std::string ss = "[("+std::to_string(elements[i])+")";
    i++;
    while(i != tailIndex) {
      ss += " "+std::to_string(elements[i]);
      i = (i + 1) % capacity;
    }
    return ss + "]";
  }
}

Queue::~Queue() {
  delete [] elements;
}

