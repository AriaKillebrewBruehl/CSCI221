#include "Queue.hh"
#include <cassert>
#include <string>

Queue::Queue() :
  first {nullptr},
  last {nullptr}
{ }

bool Queue::is_empty() {
  return ((first == nullptr) && (last == nullptr));
}

void Queue::enqueue(int value) {
  node* newNode = new node { };
  newNode->data = value;
  newNode->next = nullptr;
  if (first == nullptr) {
    first = newNode;
  } else {
    last->next = newNode;
  }
  last = newNode;
}  

int Queue::dequeue() {
  assert(!is_empty());
  int item = head();
  node* oldFirst = first;
  first = first->next;
  if (first == nullptr) {
    last = nullptr;
  }
  delete oldFirst;
  return item;
}  

int Queue::head() {
  assert(!is_empty());
  return first->data;
}  

std::string Queue::to_string() {
  if (is_empty()) {
    return "[ ]";
  } else {
    node* current = first;
    std::string ss = "[("+std::to_string(current->data)+")";
    current = current->next;
    while (current != nullptr) {
      ss += " "+std::to_string(current->data);
      current = current->next;
    }
    return ss + "]";
  }
}

Queue::~Queue() {
  while (!is_empty()) {
    dequeue();
  }
}

