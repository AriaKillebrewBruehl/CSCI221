# Lab 02: Intro to Arrays and Structs 

*Please try to complete these exercises in lab today.  
Whatever you do not finish in the lab, try to complete by the
start of lecture on Friday.*

**Note:** We'll work together to complete several of the exercises
today. Hopefully these will prompt questions in lab or in lecture
tomorrow.

This is the initial repository for the second lab assignment for the
Spring 2020 offering of Reed's CSCI 221. It contains a few sample C++
files that you will modify for this assignment.  This lab exercise is
a warm-up giving you practice with two *aggregate* types in C++,
namely, *arrays* and *structs*. Each of these are a kind of primitive
object type, and they each house collections of data of a fixed
size. Arrays are aggregates whose components are homogeneous in
type and structs are heterogeneously typed aggregates.

Both can be used as the low-level building blocks of data structures
that you invent yourself, and are often the low-level components
of the library classes that come with C++.

### Arrays

Arrays allow you to construct a fixed-size sequence of data values,
all of the same type.  The elements of an array can be accessed by
an index, numbered from 0 up to, but excluding, the size of that
array. For example, this statement builds an array of 10 elements,
with each of type `int`, and then gives that array the name `elts`:

    int elts[10];

The contents of the array are allocated, but the actual values of each
are indeterminant. So we need to explicitly give each array item a 
value. This statement, for example, would set the elements to be the
first 10 integer squares, starting at 0:

    for (int i=0; i < 10; i++) {
        elts[i] = i * i;
    }	

At this point in our instruction, we have only taught you a limited 
type of array, what's called a *stack-based* array. It's hard to fully
explain what this means exactly, we are working up to it, but essentially
this means that its contents are compiled to live alongside the storage of
all the other local variables of the procedure or function where it is
used. This has interesting implications, namely that its lifetime is the 
lifetime of the call of the function where it is mentioned/local. Also,
the size of the array must be a constant (though C++ now does allow you
to use the same syntax to create an array whose size might depend on some
calculation, we are discouraging you from using that feature).

Also, at the moment, we haven't told you yet how to pass an array as a
parameter to a function or a procedures, say one that's called by the
function where the array is allocated. We will start talking about more
complex allocation, and passing of arrays as arguments, when we start
digging into C++ *pointers*, and also when we start talking about
allocation of data structures on the *heap* rather than on the stack.

So initially we mostly work on arrays only in `main`, certainly only
allocated within `main`. Exercises 3 and 4 have you write procedures
and functions that take arrays as arguments.

### Structs

Structs are like primitive object classes. The "instances" are just
a collection of named data items---the contents of the structs *fields*---
but they have no methods, at least not in the object-oriented sense.
They have to be defined first, and that definition introduces a new
type into your program. Here is an example:

    struct CS2Student {
        std::string name;
        int year;
	bool isTA;
    };

Note the final semicolon!

Once defined, you can then have variables of type `CS2Student` throughout
the code below the definition. For example, a function could have
a variable declaration:

    CS2Student s;

and this would allocate space for two string objects, followed by an
integer, amongst the stack space that holds that function's variables.
The contents will be indeterminate (just like the stack-based array),
so you need to set the content, and that can be done using field access
syntax similar to Python's, like so:

    s.name = "Rory Gluthy";
    s.year = 1;
    s.isTA = false;

Structs can be passed as values to functions, and returned as values
from functions. We'll see that, under the covers, C++ just copies
the individual fields to a struct allocated in the called function
(the "callee"). And so a procedure like

    void introduce(CS2Student t) { ... }

called with `introduce(s)` can be thought of as like the procedure

    void intro_like(std::string nm, int yr, bool ta) {
        CS2Student t;
	t.name = nm;
	t.year = yr;
	t.isTA = ta;
        ...
    }

called with `intro_like(s.name,s.year,s.isTA);`.

There's an obvious convenience to passing/returning the aggregate
struct by value. We'll see they have even greater power when we
start allocating structs on the heap instead of within the 
program's call stack.

---

## Array Exercises

---

**Exercise 1.** the mean value

Modify the code `stats.cc` that we just examined in class. It creates
an array of `double` of size 10, and then "fills" it with a (possibly
smaller) set of values.

Your code should add a section that computes and outputs the mean
of the data that was entered. This is just the sum of the data values
divided by the size of the data set. Since the size of the data is an
`int`, you'll want to convert it (in C++ terminology: to
"cast" it) to a `double`. Use the expression

    static_cast<double>(size)

to do so.

---

**Exercise 2.** the minimum value

Now add a section of the code that computes the minimum value of
the data in the array and reports it.

---

**Exercise 3.** mean and min functions

Restructure the code that you just wrote so that it instead
computes the mean value of an array of data using a function
named `meanValue`. The type signature for this should be the
code

    double meanValue(double* values, int length) { ... }

Let's not worry for now what the meaning of the type `double*`
is (it is something called a *pointer type*; we'll talk about
this in class tomorrow.) Just copy the code verbatim.

Now modify `main` so that it uses this function. It should
say something like

    std::cout << "The mean value of that data is "; 
    std::cout << meanValue(data,size);
    std::cout << ".\n"

Now do the same for the minimum value calculation. Write a similar
function named `minValue` and have it used in `main`.

---

**Exercise 4.** appending arrays

Arrays are fairy primitive constructs, whereas Python lists are rich
objects. You can append onto the end of a Python list, extend a Python
list, concatenate two Python lists, delete an item in the middle of
a Python list, and so on. With C arrays, you have to build these features,
and the code that does this has to work explicitly with the array's
memory.

In this exercise, you are going to write one example of such code,
and then write a small `main` that tests it.  Write a procedure
`appendInto` with the following type signature:

    void appendInto(int* a1, int n1,
                    int* a2, int n2,
		    int* a) { ... }

It should copy the first `n1` data items of `a1` into `a`, then
copy the next `n2` data items of `a2` after them. It can assume
that  `a` is large enough to hold `n1+n2` items.

Now write a `main` procedure that declares three `int` arrays,
two of length 10 and a third of length 20. It should then
ask the  user to enter the data for the first one, for data
set size they specify. It should do the same for the second
one. And then the code should report the result of `appendInto`
run on those two and the third.

It should look something like:    

    > ./appendInto
    Enter the size of the first sequence: 4
    Enter its 4 items below, one per line:
    5
    2
    3
    6
    Enter the size of the second sequence: 2
    Enter its 3 items below, one per line:
    8
    8
    1

    The result of concatenating
    [5,2,3,6]
    with
    [8,8,1]
    is the sequence
    [5,2,3,6,8,8,1]
    >

Write a procedure `output` that performs the print, one with
the type signature:

    void output(int* a, int n) { ... }

Use this procedure to output the sequence lines like in the
example above.
    
---

## Struct Exercises

---


**Exercise 5.** complex product

In lab we just demonstrated a program `cmpx.cc` that computed with
complex numbers using a struct we invented called `cmpx`.  We wrote
additon to report the sum of two complex numbers.

Add a function and its use in `main` that computes the product
of two complex numbers. Call it `times`.

Note that the product of *a + bi* with *c + di* (because of "FOIL")
has a real part equal to *ac - bd* and an imaginary part equal to
*ad + bc*.

---

**Exercise 6.** complex division

The *conjugate* of a complex value *a + bi* is the complex
value *a - bi*. Add two functions named `conjugate` and `modulus2`.
The first, when given a complex value, should give back its
conjugate. The second, when given a complex value,
should compute the product of it and its conjugate. That result,
in principle, should be a purely real number, one with the 
the imaginary part null. (In practice, the `im` field will be
very small, close to 0.0.). **Just return the `re` part
as a `double` value.**

So `conjugate` and `modulus2` each take a `cmpx`. The first 
returns a `cmpx` and the second returns a `double`.

Now, it turns out that the reciprocal of a complex number
`z` is just its conjugate, but with its real and imaginary
parts scaled by the fraction `1.0/modulus2(z)`. This is
written as a formula in 
[Wikipedia's description of the complex reciprocal.](https://en.wikipedia.org/wiki/Complex_number#Reciprocal_and_division)
Write a function `reciprocal` that computes this complex value
from a complex value.

To demonstrate that it works, take the product of `z1` and
`z2` that your code calculated, and output its product with
the reciprocal of `z2`, and then also its product with the
reciprocal of `z1`. You should then get as output, in order,
the two complex numbers that were entered (or nearly those,
because there could be some numerical inprecision).

Note that what you are doing here is simply dividing the
product by `z2` to get `z1`, etc. If you like, instead,
you could write a helper function `over` that computes
the quotient of two complex numbers for a BONUS exercise.
