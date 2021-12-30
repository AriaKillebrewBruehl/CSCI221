# Homework 10: inheritance and templates

*Exercises 1, 2, and 3 are due April 22nd, 3pm PST*  
*Exercises 4, 6, and 7 are due April 27th, 3pm PST*  
*Exercise 5 is a BONUS.*

Here again we modify and create a few C++ classes. They each ask you
to either make a template class or to make derived classes, and some
methods, with each exercise. 

---

Exercise 1: template queues
---------------------------

In this repo you will find a folder `array-Stack_T`. This contains
my implementation of the `dc` calculator program that uses a `Stck<int>` 
to store its calculated results. It relies heavily on the template
class defined in `Stck_T.hh`.  This is the example code I showed you
in Lecture 10-2.  There is a second folder `llist-Stack_T` that
has the same, except it uses a linked list-based representation
for the stack's underlying data structure. It, too, is written
as a template class `Stck<X>`. In that code you'll see that their is a 
need for a template struct `node<X>` that has a `data` member of
type `X`, for any type `X`.

Finally, there are two folders each containing the specification, 
implementation, and test code for a `Queue` class. The folder 
`circular-Queue` is my solution to the second exercise of
Homework 09 (don't look at it if you are still working on
that homework for some reason), using an array to represent a
circular buffer. The folder `llist-Queue` essentially contains
my solution to Homework 03, a linked list implementation of a
queue using `first` and `last` node pointers.

This exercise comes in two parts, but each are essentially the same exercise:

**Part 1.** Make a template version of the circular buffer
implementation of a queue, mimicking the work I did in
`array-Stack_T`.  To do so, make a `Queue_T.hh` that contains both the
specification and implementation code, essentially the stuff in
`Queue.hh` and `Queue.cc`, but defining a template class `Queue<X>`
with that code. Also make a copy of `test_queue.cc` named
`test_queue_t.cc` that tests the template class code you've just written,
building a queue of type `Queue<int>`.

**Part 2.** Make a template version of the linked list implementation
of a queue, mimicking the work I did in `llist-Stack_T`.  Again make a
`Queue_T.hh` and a `test_queue_t.cc` to implement and test your work.
Note that your header file will define both a template struct
`node<X>` and a template class `Queue<X>`, and will also give the
methods of that queue data structure.

All of these folders contain a `Makefile` where typing `make` should build
the test code I've provided. And then, in each of the queue-based 
folders, you should be able to compile your template class test code
with `make test_queue_t`.

Exercise 2. walled Grid
-----------------------

In Homework 09, I asked you to develop a `Grid` class that represented
a bounded integer lattice of a certain width and a certain height.
I'd like you to change the code slightly so that there are three kinds
of marks on grid locations: they can either contain a wall, or they
can contain a trail left by the turtle, or they can contain a prize. 
Otherwise a location is empty. A location can't have a trail and a
prize. A prize can't be held where a wall sits. And a turtle trail
can't be sitting on a wall. 

A grid should display its walls. The locations with walls should be
marked with `X`. And any grid edge connecting two locations marked
with walls should be depicted with `x`. Any edge between a walled
and an unwalled location should be marked with spaces (rather than
`|` and `---`).  Edges between two unwalled locations should 
still be marked as `|` and `---`.

Prize locations should be marked with `$`. Trail locations and their
connecting edges should be marked *nearly* as before, except you
should use `o` at trail-marked locations (and then `z` and `Z` to
cover trail-covered edges. 

Furthermore, when a grid is constructed, it should have an extra
surrounding layer of walls as its border. Finally, you should mark the
current location of the turtle. If the location of the turtle has no
trail, depict it as `O`. If it has the turtle and the trail, depict it
as `@`.

Here, for example, is the 7 x 5 grid from the last homework, 
with the turtle having walked as in that example, and with 
a prize sitting at the upper left corner.

    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX
    x                               x
    X   $---@---+---+---+---+---+   X
    x   |   Z   |   |   |   |   |   x
    X   +---ozzzozzzo---+---+---+   X
    x   |   |   |   Z   |   |   |   x
    X   +---+---+---o---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x                               x
    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX

And here is a grid where the turtle has turned off its 
trail and walked east along three edges.

    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX
    x                               x
    X   $---o---+---+---O---+---+   X
    x   |   Z   |   |   |   |   |   x
    X   +---ozzzozzzo---+---+---+   X
    x   |   |   |   Z   |   |   |   x
    X   +---+---+---o---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x                               x
    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX

And here, lastly, is the same grid state
but where locations (0,5) and (1,5) are 
also marked with walls:

    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX
    x                       x       x
    X   $---o---+---+---O   X   +   X
    x   |   Z   |   |   |   x   |   x
    X   +---ozzzozzzo---+   X   +   X
    x   |   |   |   Z   |       |   x
    X   +---+---+---o---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x   |   |   |   |   |   |   |   x
    X   +---+---+---+---+---+---+   X
    x                               x
    XxxxXxxxXxxxXxxxXxxxXxxxXxxxXxxxX

Add these methods to your `Grid` class to support these markings:

    void setWall(int r, int c);
    void setEmpty(int r, int c);
    void setTrail(int r, int c);
    void setPrize(int r, int c);
    bool hasWall(int r, int c);
    bool hasPrize(int r, int c);
    bool hasTrail(int r, int c);

You may have this already in some form, but you'll probably also want
a method like

    void setTrailEdge(int r, int c, char dir);

or something similar, to leave a trail on edges between locations.

Change your `Turtle` so that, rather than checking whether it would
fall "off the edge" it instead checks whether it can make a step
forward without hitting a wall. Add the method

    bool canStep();

that returns whether or not the location it is facing with a
forward step contains a wall. For example, in the last picture
above, it would return `true` if the turtle is facing north or
east, and return `false` if the turtle is facing south or
west. Note that your `forward` method can now use this method
to check whether a move is possible, and make it if so.

Finally, change your `Turtle` so that it can also check whether 
the place it's about to step has a trail on it. Write the 
method

    bool seesTrail();

That returns `true` if the cell it would next enter with a
`forward` is marked with its trail. It should return `false`
otherwise.

Note that, here, you are not making new *subclasses* of 
`Grid` and `Turtle`. Rather, we're just adding a few features
to the classes you've already built.

Note also that there is an ambiguity here about tracking and depicting
locations with prizes. Make it so that when a grid location is `set`,
the prior information about prizes/trails/walls at that location are
lost. Even still, it is possible for a location to both have a prize
and hold a turtle (with no trail). In that case, show only the turtle.
(We'll essentially fix this issue in the next exercise.)

You can also assume that a turtle never gets placed onto a grid where
its initial location has a wall.

Exercise 3. prize-counting Turtle
---------------------------------
Now we enhance your turtle so that it collects prizes. 
Make a subclass of `Turtle` named `TurtleZ` like
so. 

    class TurtleZ : public Turtle { ... };

A `TurtleZ` has all the data members and methods
that a `Turtle` does, but also a count of how many
prizes it has found. It should override the `forward` 
method so that, if it walks onto a grid location 
that contains a prize, then the prize gets removed from
the grid at that location and the turtle's prize
count increases by one. Include the getter method

    int prizes(void);

that returns how many prizes the `TurtleZ` has 
gathered while moving around on the grid.

Note that the `TurtleZ` might get placed initially
on a grid location that contains a prize. That means
that that location should have its prize removed 
immediately, and the turtle's prize count should
start at 1.

Exercise 4. transporting Turtle
-------------------------------

Now derive a subclass of `TurtleZ` named `XTurtleZ`. 
This kind of turtle has the amazing ability to remember
a location where it sits, along with the direction it
faces, and then jump back to that spot, restoring
its orientation as it remembered it. This gives a
`XTurtleZ` an ability to transport (or *X-port*)
itself around the grid, though only to places/directions
it was once before. It does this by supporting these
two methods:

    void save();
    void restore();

Its ability to transport in this way is both unlimited and limited.
It can remember a series of locations, of any number.  That is, it can
perform a series of `save` operations, remembering all of the
locations where it performed them. But it must follow a
*stack discipline*. When it saves a location and orientation,
it pushes that information onto a stack.  When it restores 
a location and orientation, it does so by popping that information
(a grid row, a grid column, and a direction it was facing) off
of a stack, and setting its own state accordingly with those
three pieces of information.

So, this means that, when an `XTurtleZ` is created, it is given an
empty stack. A `save` leads it to push stuff onto that stack. A
`restore` leads it to pop stuff off the stack. If you want, consider
those three pieces of information its current *frame* of reference.
So it saves a frame onto its stack of frames, and restores a frame
from its stack of frames.

It should have a method

    bool canTransport(void)

that indicates whether it has saved any frames, or not.

You are welcome to use my template class for stacks to do this work.

BONUS Exercise 5. amazing Turtle
--------------------------------

This is an optional exercise, but the last three exercises have set you 
up to do it. Create yet another turtle subclass, one that derives from
`XTurtleZ`.  Call it the `GOATurtle`. This turtle, when created,
gets placed at location (0,0) on the grid. It assumes that it has been
placed in a grid that is a *maze*. This means that the turtle can assume
it has *exactly one path* between any two unwalled locations in the grid.
It also assumes that there is a single prize located at some reachable
location in the grid.

The `GOATurtle` has only one additonal method, and no additional data members,
namely

    bool solve(void);

This method's code should be an algorithm that makes it find the prize by
searching the maze.

Here is a (rough) description of how that search algorithm could
work:

*The turtle leaves a trail to mark places it has already searched.
 Anytime it first enters a location in the grid without finding a
 prize, it saves that location. It then attempts to step forward in
 each of the unwalled, unseen locations reachable from that location,
 to see if it can find the prize going that direction. If it ever hits
 a dead end, then it restores a prior location and resumes its search
 from there. (In doing this, it might want to re-save that prior
 location after it jumps back to it.) A dead end occurs at any
 location where there are no unwalled, unseen locations around it.*

Of course this search ends when the turtle has found the prize in 
the maze.

Write `solve`. I encourage you to write it so that it relies entirely
on methods it has inherited, adding no additional methods.
Specifically, you should be able to write it using only `trail`,
`left`, `forward`, `canStep`, `seesTrail`, and `prizes`.  It shouldn't
need to use any other methods or access any data members. 
(Although you'll probably want to display the grid while your
turtle searches its way through the grid.) This means that it
shouldn't call `solve` recursively.

To aid in testing your code, you could add a different kind of
constructor for `Grid` that takes only a filename as a string

    Grid(std::string filename);

It can then open that file and read the contents of that file.  The
file itself can describe the size of the grid, the location of the
prize, and the locations that contain walls. For example, this
could describe the grid that I depicted earlier

    5 7
    0 0
    2
    0 5
    1 5

The top line gives the dimensions of the grid, the number of rows 
followed by the number of columns. The second line gives the
location of the prize, at (0,0). The next line gives the number of 
locations (inside the border) that contain walls. In this case,
there are 2.  And then the remaining (two) lines give the locations
of walls.

Here is some sample C++ code for reading a file. It looks very similar
to the code you write for scanning `std::cin`, only you are allowed to
build a `std::ifstream` object that is an "input file stream" and it
acts just like `std::cin`. 

    std::ifstream fs;
    
    // Open the file.
    //
    fs.open(filename);
    
    if (fs) {
      // Read it if no errors occurred.
      //
      int rows, columns;
      fs >> rows >> columns;

      int prize_row, prize_column;
      fs >> prize_row >> prize_column;

      int walls;
      fs >> walls;
      ... 
      // read all the wall information    
    }
    
    // Close it.
    //
    fs.close();

To do this work, you'll need to `#include` the appropriate
header information for input file streams, so you'll need
the line

    #include <fstream>

sitting at the top of your `Grid` implementation code.

Exercise 6. integer arithmetic
------------------------------

If you look in the files `Arith.hh` and `Arith.cc`, you will
see the specification and implementation of a class hierarchy
that describes "expression trees" for arithmetic expressions.
Let me take you through some of the concepts behind its design
and then describe each of the classes in those files.

Here is the driving idea: we want a way of representing
arithmetic expressions, things like

    31 + 100 x 2 + 4 x ( 2 + 3 )

That expression above happens to evaluate to 251. Without evaluating
it, though, we can see that it has a syntactic structure. Particularly, 
it has subexpressions, like `100 x 2` and `2 + 3`.  These can each be
evaluated resulting in 200 and 5, respectively.  And then 31 can be
added to 200, yielding 231. And 5 can be multiplied by 4, yielding 20. 
And then 231 can be added to 20, yielding 251.

To summarize that series of calculations, its useful to relate
the syntactic structure, its subexpressions, with the order of
calculations that you make to apply its operations. This syntactic
structure is best depicted as a tree, like so

         x
        / \
       /   \
      x     \ 
     / \     \
    31  \     \
         x     \
        / \     x
      100  2   / \
              4   +
                 / \
                2   3

This is sometimes called the *parse tree* of the expression
`31 + 100 x 2 + 4 x (2 + 3)`.  It has a *recursive* structure:
each subexpression that describes a computed value has a corresponding
subtree, for example the `2 + 3` hanging off the right hand side
of the rightmost `x` operation. Taking this view, the integer
values are *trivial* subtrees, ones that have no subtrees.
These are often called *leaves*. And then `x` and `+` sit above 
two subtrees hanging below them.  This is because they are *binary* 
operations.

Taking this view, we can now see the order that the expression
should be evaluated. It is encoded in the structure of the tree.
The values at the leaves can be seen as being "fed upward" to
the operations that use them. And those operations, if not at
the top, feed their values up to the opeartions above them.

Put another way, any subtree is either a leaf or instead a
binary operation with two subtrees. And any subtree has
a value. In the case of a leaf, its value is just its
integer. In the case of an operation-topped subtree, its
value is just the value of its two subtrees, with its
operation then applied to them. (Note that this
description is giving a recursive algorithm for 
evaluating any subtree.)

We are now ready to talk about the code in `Arith.hh` and
`Arith.cc`.  The class `Arith` defines an *abstract* class
that is the base class of the three types of arithmetic
subtrees, `Add`, `Mul`, and `Val`.  For `Add` and `Mul`,
we make them each a subclass of an intermediate binary
operation abstract subclass `Bop`. The classes `Val`
and `Bop` each define a method `eval` that
has this signature

    int eval(void);

that knows how to evaluate its kind of subtree. For 
`Val` the method is trivial, just returning that 
leaf's value. For the `Bop` subtrees, the `eval`
method invokes the `eval` method on each of its
subtrees, and then combines the result with a
different method `apply`. Finally, each of 
the subclasses (`Add` and `Mul`) define the
meaning of `apply`. For `Add`, that method adds
the two integers it is given. For `Mul`, the
`apply` method multiplies them.

And then its possible to build an expression
tree by making a pointer of type `Arith*`
that points to any one of the "concrete"
subclass instances of `Val`, `Mul, and `Add`.
For example, the code below build the expression
tree for `2 + 3 x 4`:

    Arith* a = new Val {2};
    Arith* b = new Val {3};
    Arith* c = new Val {4};
    Arith* t = new Mul {b,c};
    Arith* p = new Add {a,t};

And then you can compute its result, 14, by
something like the following:
   
    std::cout << p->eval() << std::endl;

If you check the code for `eval.cc`, you will
see code like the code above, but it instead
constructs a tree for the expression that
led off this exercise, and printing its result.
In that code, it ultimately builds an
expression as an `Arith` pointer named `aB`,
and it outputs `aB->eval()`.

You'll notice, also, that I devised destructors
for `Arith` and `Bop`. The former is trivial 
(does nothing), but the latter destructor
does some real work. It actually calls
`delete` on its two subtree pointers. That
will lead to calls to the destructors of
the two objects that the binary operation
object points to. If either of those happens
to be a `Bop`, then this same code will 
be called recursively.

**Exercise**. Create classes `Sub` and `Div`
that can be used to express subtraction and
division operations. Also add a `Neg` class
that represents "unary" negation. This
means, for example, that

   3 - ( - ( 50 / 10 ) )

can be built as an `Arith*` and then evaluated.
(It would evaluate to 8.)

You'll have to define constructors for each,
a destructor and `eval` for `Neg`, and
`apply` for `Sub` and `Div`.

Exercise 7. boolean conditions
------------------------------

Mimic what I've done with integer arithmetic to build a
class hierarchy for boolean conditions. The expression
trees that the hierarchy represents should be boolean
formula using logical negation (NOT), logical conjunction
(OR), and logical disjunction (AND), and over variables.
For example, an expression like

    NOT ( x OR y ) OR ( z AND (NOT x) )

Name the base class `Condn` and devise subclasses to express `Not`,
`And`, and `Or`.  The leaf expressions should be represented as
a class `Var` with a constructor that takes a string:

    Var(std::string name);

All those classes shopuld support a method:

    bool chck(bind* bindings);

that determine whether its expression is `true` or `false`
when given an assignment to its variables expressed in the
array `bindings`.  A `bind` is just a pairing of a variable
name with a boolean value:

    struct bind {
      std::string name;
      bool        value;
    };

So, for example, if we built an expression tree as a pointer
of type `Condn*` named `c`, we could do the following:

    bind bs[3];
    bs[0].name  = "x";
    bs[0].value = true;
    bs[1].name  = "y"; 
    bs[1].value = false;
    bs[2].name  = "z"; 
    bs[2].value = true;
    bool result = c->chck(bs);

If `c` represented the expression that led this exercise description,
then the `result` would be `false`.

Write a `main` test in a file named `chck.cc` to demonstrate that
your code works.

