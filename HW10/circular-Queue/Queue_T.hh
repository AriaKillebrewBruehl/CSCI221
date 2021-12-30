// Aria Killebrew Bruehl HW10 exercise 1 part 1 
#include <string>

// template class for ciricular queue 
template <class X>
class Queue {

private:
  X *elements;
  int headIndex;
  int tailIndex;
  int capacity;

public:  
  Queue(int capacity);
  bool is_empty();
  void enqueue(X value);
  X dequeue();
  X head();
  std::string to_string();
  ~Queue();
};

template <class X>
Queue<X>::Queue(int capacity) :
  elements {new X[capacity]},
  headIndex {0},
  tailIndex {0},
  capacity {capacity}
{ }

template <class X>
bool Queue<X>::is_empty() {
  return (headIndex == tailIndex);
}

template <class X>
void Queue<X>::enqueue(X value) {
  elements[tailIndex] = value;
  tailIndex = (tailIndex + 1) % capacity;
}  

template <class X>
X Queue<X>::dequeue() {
  assert(!is_empty());
  int item = head();
  headIndex = (headIndex + 1) % capacity;
  return item;
}  

template <class X>
X Queue<X>::head() {
  assert(!is_empty());
  return elements[headIndex];
}  

template <class X>
std::string Queue<X>::to_string() {
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

template <class X>
Queue<X>::~Queue() {
  delete [] elements;
}







