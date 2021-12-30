#include <iostream>

struct node {
  int data;
  struct node* next;
};

void outputLast(node* first){
  node* current = first;
  if (current == nullptr){
    std::cout << "*There is no last element of this empty list.*" << std::endl;
  } else {
    while (current -> next != nullptr) {
    current = current->next;  
    } 
    std::cout << "The last element in of this list is " << current->data << std::endl;
  }

}

void outputSequence(node* first) { 

  node* current = first;
  while (current != nullptr) {
    std::cout << current->data << std::endl;
    current = current->next;
  }
}

node* insertAtFront(int value, node* first) {
  node* newNode = new node;
  newNode->data = value;
  newNode->next = first;
  return newNode;
}

node* requestSequence(int sz) { 
  node* first = nullptr;
  std::cout << "Enter your sequence, one item per line:" << std::endl;
  for (int i=0; i<sz; i++) {

    // Get a sequence value.
    int entry;
    std::cin >> entry;

    // Add a node for it to the linked list.
    first = insertAtFront(entry, first);
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
  outputLast(first);
}
