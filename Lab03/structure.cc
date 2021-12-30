#include <iostream>

struct node {
  int data;
  struct node* next;
};

int main(void) {
  node a;
  node b;
  node c;
  a.data = 5;
  b.data = 7;
  c.data = 3;
  node* first = &b;
  a.next = nullptr;
  b.next = &c;
  c.next = &a;

  node* current = first;
  while (current != nullptr) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  

}
