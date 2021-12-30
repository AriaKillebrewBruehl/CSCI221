#include <iostream>

struct node {
  int data;
  struct node* next;
};

void outputSequence(node* first) { 
  
  node* current = first;
  std::cout << "[";
  if (current != nullptr){
    std::cout << current->data;
    current = current->next;
  }
  
  while (current != nullptr) {
    std::cout << ", "<< current->data ;
    current = current->next;
  }

  std::cout << "]" << std::endl;
   /* for part 2 of ex 2:
   if (current == nullptr){
    std::cout << "*empty*" << std::endl;
  }
  else {
    while (current != nullptr) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
  */ 

  
  
}

node* requestSequence(int sz) { 
  node* first = nullptr;
  std::cout << "Enter your sequence, one item per line:" << std::endl;
  for (int i=0; i<sz; i++) {

    // Get a sequence value.
    int entry;
    std::cin >> entry;

    // Add a node for it to the linked list.
    node* newNode = new node;
    newNode->data = entry;
    newNode->next = first;
    first = newNode;
  }

  return first;
}

int main(void) {
  int length;
  std::cout << "Enter the length of your sequence: ";
  std::cin >> length;
  node* first = requestSequence(length);
  std::cout << "The sequence you entered was: " << std::endl;
  outputSequence(first);
}
