#ifndef __QUEUE_HH
#define __QUEUE_HH

#include <string>
#include <iostream>

struct node {
  int data;
  struct node* next;
};

class Queue {

private:
  node *first;
  node *last;

public:  
  Queue();
  bool is_empty();
  void enqueue(int value);
  int dequeue();
  int head();
  std::string to_string();
  ~Queue();
};

#endif




