#include <iostream>

struct node {
  int data;
  struct node* next;
};

int main(void) {
  
  // Allocate the nodes on the heap, getting their pointers.
  node* a = new node;
  node* b = new node;
  node* c = new node;

  // Set their `data` fields.
  a->data = 5;
  b->data = 7;
  c->data = 3;

  // Structure them by setting their `next` pointers.
  // Have a pointer named `first` that refers to the
  // first node in the sequence.
  //
  node* first = a;
  a->next = b;
  b->next = c;
  c->next = nullptr;
  
  // Traverse the linked list using a pointer
  // variable named `current`. Start it at the
  // first, and them move it down to the other
  // nodes, one at a time.
  //
  node* current = first;
  while (current != nullptr) {
    std::cout << current->data << std::endl;
    current = current->next;  // This advances the pointer, moving it to the next node.
  }

  std::cout << std::endl;

  current = first;
  while (current -> next != nullptr) {
    current = current->next;  // This advances the pointer, moving it to the next node.
  }
  std::cout << current->data << std::endl;

  delete a;
  delete b;
  delete c;
}
