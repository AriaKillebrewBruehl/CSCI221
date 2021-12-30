#include <string>
#include <cassert>

template <class X>
struct node {
  X data;
  struct node<X>* next;
};

template <class X>
class Stck {

private:
  node<X>* first;

public:  
  Stck(void);
  const bool is_empty() const;
  void push(const X value);
  X pop();
  const X top() const;
  const std::string to_string() const;
  ~Stck();
};

template <class X>
Stck<X>::Stck(void) :
  first {nullptr}
{ }

template <class X>
const bool Stck<X>::is_empty() const {
  return (first == nullptr);
}

template <class X>
void Stck<X>::push(const X value) {
  node<X>* newNode = new node<X> { };
  newNode->data = value;
  newNode->next = first;
  first = newNode;
}  

template <class X>
X Stck<X>::pop() {
  X item = top();
  node<X>* oldFirst = first;
  first = first->next;
  delete oldFirst;
  return item;
}  

template <class X>
const X Stck<X>::top() const {
  assert(first != nullptr);
  return first->data;
}  

template <class X>
const std::string Stck<X>::to_string() const {
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
Stck<X>::~Stck() {
  while (!is_empty()) {
    pop();
  }
}
