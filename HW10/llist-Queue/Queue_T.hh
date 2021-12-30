// Aria Killebrew Bruehl HW10 exercise 1 part 2
//
#include <string>
#include <cassert>

// template class for llist queue
template <class X>
struct node {
  X data;
  struct node<X>* next;
};

template <class X>
class Queue {

private:
  node<X> *first;
  node<X> *last;

public:  
  Queue();
  bool is_empty();
  void enqueue(X value);
  X dequeue();
  X head();
  std::string to_string();
  ~Queue();
};

template <class X>
Queue<X>::Queue() :
  first {nullptr},
  last {nullptr}
{ }

template <class X>
bool Queue<X>::is_empty() {
  return ((first == nullptr) && (last == nullptr));
}

template <class X>
void Queue<X>::enqueue(X value) {
  node<X>* newNode = new node<X> { };
  newNode->data = value;
  newNode->next = nullptr;
  if (first == nullptr) {
    first = newNode;
  } else {
    last->next = newNode;
  }
  last = newNode;
}  

template <class X>
X Queue<X>::dequeue() {
  assert(!is_empty());
  X item = head();
  node<X>* oldFirst = first;
  first = first->next;
  if (first == nullptr) {
    last = nullptr;
  }
  delete oldFirst;
  return item;
}  

template <class X>
X Queue<X>::head() {
  assert(!is_empty());
  return first->data;
}  

template <class X>
std::string Queue<X>::to_string() {
  if (is_empty()) {
    return "[ ]";
  } else {
    node<X>* current = first;
    std::string ss = "[("+std::to_string(current->data)+")";
    current = current->next;
    while (current != nullptr) {
      ss += " "+std::to_string(current->data);
      current = current->next;
    }
    return ss + "]";
  }
}

template <class X>
Queue<X>::~Queue() {
  while (!is_empty()) {
    dequeue();
  }
}






