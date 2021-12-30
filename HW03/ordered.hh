// 
// llist.hh
//
// Type definitions and prototypes for an integer linked list data
// structure. 
//
// CSCI 221 Spring 2020
//
// Author: Jim Fix
//
// The code below gives the header information for a linked list data
// structure. It defines two types `llist::node` and `llist::llist`,
// the first forming the low-level struct type that's stitched together
// to store a sequence of integers, and the second providing a "housing"
// for the data structure, accepting a collection of operations on 
// that data structure.
//
// Those two types, along with the operations on `llist::llist*`, are 
// all defined under a namespace `llist`. The operations that this
// linked list supports are 
//
// * build, buildWith - construct a new linked list (on the heap)
// * insertAtFront, insertAtEnd - add an integer to the linked list
// * isEmpty, contains, length, toString - check/report the contents
// * deleteFront, deleteEnd, remove - remove an integer
// * destroy - give back the linked list's storage (to the heap)
//
// These operations are implemented in `llist.cc`.
//

#ifndef _LLIST_HH
#define _LLIST_HH

#include <string>

namespace ordered {

  struct entry {
    std::string key;
    int value;          // Item stored at a node.
    struct entry* next; // Links to the successive node, or `nullptr`
  };                   // if at the end.

  struct dict {
    entry* first;       // Link to the first node.
    int defaultValue;
  };

  // "constructors"
  dict* build(int);
  

  int get(dict* D, std::string k);
  void set(dict* D, std::string k, int v);
  std::string toString(dict* D);
  void destroy(dict* D);

  

}

#endif
