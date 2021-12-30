# Lab 03: Intro to Linked Lists

*Please try to complete these exercises in lab today.  
Whatever you do not finish in the lab, try to complete by the
start of lecture on Friday.*

**Note:** We'll work together to complete several of the exercises
today. Hopefully these will prompt questions in lab or in lecture
tomorrow.

This is the initial repository for the third lab assignment for the
Spring 2020 offering of Reed's CSCI 221. It contains several simple
programs that use a struct named `node`. The programs use pointers
to these structs, address values of type `node*`, to develop a data
structure called a *linked list*. In the upcoming lectures, we will
develop the ideas exercised in these programs a bit further, essentially
build a collection of methods that operate on this data structure.

---

## Linked Lists

Linked lists are a classic "link-based" data structure that can be
used to represent a collection of data values, and also a sequence
of data values. It is an example of a *container*, but is normally
a low-level implementation of the storage structure for more rich, and
less "raw", container data types. In fact, a linked list is often just a "model
organism" (like a biology course's fruit fly, or *E. coli*) illustrating the
core aspects of the family of link-based data structures. We'll use linked 
list coding as practice for developing a variety of data structures.

These are called linked lists because of their mechanism for
organizing the data stored in their structure. Each data item
is stored in its own struct, but then each struct knows the
struct of some other item in the collection, that is, it 
links to another struct. In C++, we do that using C++'s 
*pointer* data type. One struct knows the pointer to another 
struct. We can then "traverse" the data items in a linked
list by starting at a first, or "head" struct, then following
the pointer that links to another data item's struct, and so
forth. All we need, then, is a pointer to the first item's
struct, and the rest form the remainder of the sequence.

Here, then, is an example of the definition of a linked list
struct, one that holds a single integer data value:

    struct node {
      int data;
      struct node* next;
    };

This code, then, would build a linked list of three integers,
the sequence 5, 7, 3:

    node a;
    node b;
    node c;
    a.data = 5;
    b.data = 7;
    c.data = 3;
    node* first = &a;
    a.next = &b;
    b.next = &c;
    c.next = nullptr;

Here, we've allocated three structs of type `node` on the stack,
filling them with the sequence values using their `data` field.
We then link them together: `a` has a field named `next` that points
to `b`. And `b` has its `next` set to a pointer to `c`. The variable
`first`, then, can be seen as a reference to the whole sequence
and we can work from it to inspect all the data items.

Note that the last `node` in the list does not link to any others.  So
what we need to do is have a value that represents "no link", to mean
there is "no successor", no valid `next` struct. In C++ this is done
using the value `nullptr`. This is standard terminology in most
languages---a "null pointer" or a "nil pointer" is one that doesn't
point to anything at all. (In Python, people often use the value
`None` to mimic a null object reference.)  List nodes whose `next` is
null are at the end of their list's sequence.

Now that we've built a list like this we can do the following:

    node* current = first;
    while (current != nullptr) {
      std::cout << current.data << std::endl;
      current = current.next;
    }
    
There are several things going on here. The first thing to note is
that we are using a pointer `current` to refer to *some* node in the
list. The second is that, we *move* that reference from one node to
another, following the `next` links. This is called a *linked list
traversal*. We start at the first node, print its data, then move to
the next, print its data, and so on.  When we have printed the data
value of the node at the end, then `current->next == nullptr`,
and so the loop body line

      current = current->next;

sets `current` so that it has the value of the null pointer. So then
when the `while` condition is checked, the loop will terminate and
continue with the lines below the `while` end brace.

Lastly, the code above **is incorrect**. It is using the **wrong
notation for accessing the fields of a struct pointed at by a
variable**. It is mistakenly using Python (and also Java) syntax.
In those languages, the fact that a variable referencing an object
is a pointer is completely hidden from the programmer. In those
languages any such name is *implicitly a pointer*. In C++ we're
instead seeing two different data types. If I have a struct type
`S`, then I can have two types:

    S  sas;
    S* pts;

The first is a name of a stack-allocated struct of type `S`. The second
is the name of a pointer to a struct of type `S`. In the first case,
we access a field `fld` with the "dot" notation like so:

    ... sas.fld ...

In the case we instead have a pointer, like `pts` above, we instead  
must use the C++ "arrow" notation like so:

    ... pts->fld ...

This is read as "using the pointer `pts`, go to the struct it 
references and access its field named `fld`. 

With that notation, the loop code should instead be:

    node* current = first;
    while (current != nullptr) {
      std::cout << current->data << std::endl;
      current = current->next;
    }

Now, let's change this code a little. In the above, we allocate
the nodes' structs on the stack. It turns out we can instead
allocate those node's on the heap. To obtain a pointer to a
struct of type `S` allocated on the heap, we use the declaration
   
    S* ptr = new S;

alternatively, if we already have declared a variable `ptr` to 
be of type `S*`, we can then just assign it to point to a new
struct, one obtained from the heap, with the statement

    ptr = new S;

Then we instead want our program code to be:

    node* a = new node;
    node* b = new node;
    node* c = new node;
    a->data = 5;
    b->data = 7;
    c->data = 3;
    node* first = a;
    a->next = b;
    b->next = c;
    c->next = nullptr;

Note the changes carefully! Now the variables `a`, `b`, and `c`
aren't the nodes themselves, but rather they are each *pointers
to structs allocated on the heap*. And note also the assignment
to `first`, namely

    node* first = a;

This means that both `first` and `a` are pointing to the same struct
in the heap memory. It's possible to have several different things
point to the same place. (We also saw it in our animation of
`append` in lecture yesterday.) These pointers `first` and `a`
are *aliases* for the same struct in memory. They both refer to
the same node.
    
This is the start of our playing with these linked structures.
The exercises below have you slowly gain familiarity with the
standard operations on linked lists.

---

**Exercise 1.** restructuring a list

The code excerpts above are from the source code `restructure.cc`.
The `main` function does all the work of creating and outputting 
this three item list.

For this exercise I want you to first cut-and-paste the code that
traverses and outputs the list. Just between those two loops add
the line:

    std::cout << std::endl;

Now, also between those two loops, I want tyou to restructure the
list so that the variable `first` is referring to the sequence
7, 3, 5 instead. To do this **do not touch** any of the code
that sets the `data` fields of the nodes. Also **do not add**
any code that modifies the `data` fields. Instead, change
which node `field` references, and change the `next` fields
of the linked list nodes. When that code is added, the code
should output 5, 7, 3 and then output 7, 3, 5.

---

**Exercise 2.** building a list

Now look at the code `building.cc`. This code is a bit different,
but uses the same ideas. We now have two definitions:

    void outputSequence(node* first) { ... }
    node* requestSequence(int sz) { ... }

The first takes a pointer to a node, one that is assumed to be the
first node in a linked list, and then outputs its values in order.

The second takes an integer, then requests that the user of the
program enter that many integers, one per line. It stitches them
together as a linked list and returns a pointer to the first node of
the list it just built. Then `main` just does this

    int main(void) {
        int length;
        std::cout << "Enter the length of your sequence: ";
        std::cin >> length;
        node* first = requestSequence(length);
        outputSequence(first);
    }

**Part 1**. Compile and run the program. Request a length of 3 and
then enter in the values 5, 7, 3, in that order. Note that it then
outputs the values in reverse order!  It outputs 3, then 7, then
5. Explain why this happens. On your own (say, on paper), run the code
for `requestSequence` "by hand" to see how it handles this series of
inputs. Draw a picture of the linked list that gets constructed, also
illustrating the intermediate structures as it gets built. (You can
take a picture of that drawing and submit its file as part of this
repo.)

**Part 2**. Note the the code gracefully works when you enter a
`length` of 0. It outputs nothing in that case. That's because, in
that case, the pointer `first` returned will be the null pointer value
`nullptr`.  This is the standard way of representing an the empty
sequence of a linked list of length 0. Rather than the pointer being
valid, and pointing to an actual node struct, it is "invalid", pointing
to no struct at all. This is an indicator that the data structure holds
no data. Rewrite the code so that it handles the length 0 case more gracefully.
The `outputSequence` procedure should output a single line with 
the string `*empty*` when the linked list has no data values.

**Part 3**. Write the code for `outputSequence` so that it instead outputs
the data in Python list format. That means that output strings should
look like these lines

    [3, 7, 5]
    []
    [108]

The first should be the output for the linked list we built in Part 1. The second
should be the output for the empty linked list we discussed in Part 2. The third
should be the output resulting from building a linked list of length 1.

---

**Exercise 3.** the last node

I've modified the code from Exercise 2, now named `last.cc`.  Its
version of the procedure `requestSequence` relies on a helper function
named `insertAtFront`. That code does the exact same work as the code
within the loop of `requestSequence` in `building.cc`. But this simply
packages that code as a useful scheme for updating a linked list to
take on a different structure, in this case, the structure that
results from pointing a new value onto the front of the list. Here is
that code:

    node* insertAtFront(int value, node* oldFirst) { 
      node* newFirst = new node;
      newFirst->data = value;
      newFirst->next = oldFirst;
      return newFirst;
    }

What it does is build a new node holding `value` in its
`data` field, and then have its `next` point to the first
node of the list it was given. It that returns a pointer
to that new node. This means that when we use the line

    first = insertAtFront(entry, first);

we are updating our sense of the first node in the list,
inserting that just-entered value `entry` onto the front,
as a new node, and then with the others linked behind it.

**Exercise.** Write a procedure with this type signature

    void outputLast(node* first) { ... }

that does one of two things:

• If the list it is given is empty, it should output a line
saying

    *There is no last element of this empty list.*

• If the list has length of 1 or more, it should output a
line like

    The last element of this list is 5.

This is what it should output if the sequence ends in 5.
It should work for any such list, outputting the element
sitting at the end node of the list.

Change your `main` so that it calls `outputLast` after calling
`outputSequence`, and test that your procedure works.

**BONUS Exercise**. If you are quick at understanding these
linked list operations, or maybe regardless, try this exercise.
Write a function

    node* insertAtEnd(int value, node* first) { ... }

and replace the use of `insertAtFront` within `requestSequence` with a
use of `insertAtEnd`. The result should be that the sequence that gets
built should be in exactly the same order that the user entered their
sequence numbers. The code for `insertAtEnd` should do the work of 
traversing the list to find the last node, then linking on a new node
containing `value` onto that end. Note that you will need a special
case for when `first` is null. In that case, just return a pointer
to that new node instead.
