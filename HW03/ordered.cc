//Aria Killebrew Bruehl, HW03 Part 2 (with help from the amazing drop-in tutuors!)
// llist.cc
//
// Implementation of the operations for an integer linked list data
// structure.
//
// Homework 03 CSCI 221 Spring 2020
//
// Author: ??        (`length` and `remove`)
// Author: Jim Fix   (the others)
//
// The code below gives the implementation code for a linked list data
// structure. It defines operations on a `llist::llist*` that references
// a sequence of integers. These are all packaged within the namespace
// `llist` and are as follows:
//
// * build, buildWith - construct a new linked list (on the heap)
// * insertAtFront, insertAtEnd - add an integer to the linked list
// * isEmpty, contains, length, toString - check/report the contents
// * deleteFront, deleteEnd, remove - remove an integer
// * destroy - give back the linked list's storage (to the heap)
//
// Homework 03 Part 1 asks that you complete the code for
//
//     int length(llist* list) { ... }
//
// which should traverse the linked list starting at `list->first`
// and count how many nodes are in that linked list. It then asks
// you to write the code for
//
//     int remove(llist* list, int value) { ... }
//
// which searches through the list, looking for a node with its `data`
// field equal to `value`, and excises that node from the linked list.
// (See the `deleteFront` and `deleteEnd` code to see how those cases
// are handled.) If more than one node contains that same value, then
// it only removes the first node with that value.
//

#include <string>
#include <iostream>
#include "ordered.hh"

namespace ordered {

  // llist::build():
  //
  // Constructs a new empty `llist::llist` object returning a pointer
  // to it from the heap.
  //
  dict* build(int v) {
    dict* newDict = new dict;
    newDict->first = nullptr; // Initialize it as an empty dictionary.
    newDict->defaultValue = v;
    return newDict;
  }

  // get function
  //
  // return the value associated with a key `k` or the default value
  //
  int get(dict* D, std::string k) {
    // start at the first entry
    entry* current = D->first;
    // traverse the dict until the end
    while (current != nullptr){
      // if the key is found, return the value
      if (current->key.compare(k) == 0) {
        return current->value;
      }
      // move to next node
      current = current->next;
    }
    // key was not found, return default value
    return D->defaultValue;
  }

  // set function
  //
  // insert an entry or update an existing one
  //
  void set(dict* D, std::string k, int v) {
    // check if inserting or updating at the front
    if (D->first == nullptr || k.compare(D->first->key) <= 0) {
      if (D->first == nullptr || D->first->key != k) {
        // insert at front
        D->first = new entry {.next = D->first, .key = k, .value = v};
      } else {
        // update front
        D->first->value = v;
      }
    } else {
      // start at the first entry
      entry* current = D->first;
      // traverse until end or at insert/update point
      while(current->next != nullptr && k.compare(current->next->key) > 0) {
        current = current->next;
      }
      if (current->next == nullptr || current->next->key != k) {
        // insert after current node
        current->next = new entry {.next = current->next, .key = k, .value = v};
      } else {
        // update current node
        current->next->value = v;
      }
    }
  }
  
  // toString function
  // 
  // makes a string for the dict similar to Python's string representation 
  // 
  std::string toString(dict* D) {
    // create a balnk string 
    std::string string;
    string += "{";
    entry* current = D->first;
    if (current != nullptr){
      while (current->next != nullptr){
        // traverse until end, putting " ' " around key and " : " between key and value 
        string += "'";
        string += current->key;
        string += "' : " ;
        string += std::to_string(current->value);
        string += ", ";
        current = current->next;
      }
      // add the last data which could be the first 
      string += "'";
      string += current->key;
      string += "' : ";
      string += std::to_string(current->value);
    }
    string += "}";
    return string;
  }

  // destroy fucntion 
  // 
  // traverse dict and destroy each entry by deleting it and return memeory to the heap 
  void destroy(dict* D) { 
    // start at the front 
    entry* current = D->first;
    // traverse until the end 
    while (current != nullptr){
      // create a temp entry to store current 
      entry* temp = current;
      // move to next entry 
      current = temp->next;
      // delete temp entry 
      delete temp;
    }
    // delete empty dict 
    delete D;
  }
}