// Aria Killebrew Bruehl, HW03 Part 3 (with help from the superb drop-in tutuors!)
// queue.cc
//
// Implementation of the operations for an integer queue, structured as
// a linked list.
//
// Homework 03 CSCI 221 Spring 2020
//
// Author: ??        
//

#include <string>
#include <iostream>
#include "queue.hh"

namespace queue {

  // queue::build():
  // 
  // Constructs a new empty `queue::queue` object returning a pointer
  // to it from the heap.
  //
  queue* build(void) {
    queue* newQ = new queue;
    newQ->first = nullptr; 
    newQ->last  = nullptr; 
    return newQ;
  }

  // queue::isEmpty(Q):
  // 
  // Returns true/false depending on whether `Q` is empty or not.
  //
  bool isEmpty(queue* Q) {
    return (Q->first == nullptr && Q->last == nullptr);
  }

  // queue::toString(Q):
  // 
  // Returns a string representation of the queue.  An empty queue is
  // "[]", a queue with only a head item is like "[(42)]", and a
  // longer queue looks like "[(105) 37 83]".
  //
  std::string toString(queue* Q) {
    // create an empty sting to add to 
    std::string string; 
    string += "[";
    node* current = Q->first; 
    if (current != nullptr) {
      // print head of queue with " ( ) "  
      string += "(";
      string += std::to_string(current->data);
      string += ")";
      current = current->next;
      while (current != nullptr) {
        // traverse the queue and print the nodes
        string += " ";
        string += std::to_string(current->data);
        current = current->next;
      }
    }
    string += "]";
    return  string; 
  }

  // queue::enqueue(Q,item):
  //
  // Adds `item` to the end of the given `Q`.
  //
  void enqueue(queue* Q, int item) {
    // create a new node with data as item and next as nullptr 
    node* newNode = new node;
    newNode->data = item;
    newNode->next = nullptr;
    if (!isEmpty(Q)) {
      // if Q is not empty add newNode to the end and update last 
      Q->last->next = newNode;
      Q->last = newNode;
      return;
    } else {
      // if Q is empty link Q first and Q last to item 
      Q->first = newNode;
      Q->last = newNode;
      return;  
    }
    
  }

  // queue::dequeue(Q):
  //
  // Assumes `Q` is not empty. Removes and returns the item
  // at the head (the first node) of the queue.
  //
  int dequeue(queue* Q) {
    // create node that will be dequeued 
    node* dequeued;
    dequeued = Q->first;
    Q->first = Q->first->next;
    if (Q->first == nullptr) {
      // if Q is empty set last to be null ptr 
      Q->last = nullptr;
    }
    // delete dequeued node 
    delete dequeued;
    return 0;  
  }

  // queue::head(Q):
  //
  // Returns the item stored in the first node of the queue.
  //
  int head(queue* Q) {
    // return data of first node in Q
    return Q->first->data; 
  }

  // queue::destroy(Q):
  // 
  // Returns the storage of the nodes and the top-level `queue` struct
  // back to the heap.
  //
  // This is a "destructor", using C++'s object-oriented terminology.
  //
  void destroy(queue* Q) {
    // start at the front 
    node* current = Q->first;
    // traverse until the end 
    while (current != nullptr){
      // create a temp entry to store current 
      node* temp = current;
      // move to next entry 
      current = temp->next;
      // delete temp entry 
      delete temp;
    }
    // delete empty dict 
    delete Q;
  }

} // end namespace queue
