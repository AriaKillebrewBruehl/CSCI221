# Homework 02: functions, structs, arrays

*Due 2/12 by 3pm*

---
 
This is the initial repository for the second homework assignment for
the Spring 2020 offering of Reed's CSCI 221.

You should create a C++ source file (with suffix `.cc`) for each of
the exercises below. Follow each specification carefully, test your
code with several inputs to see whether your code works, and submit
a branch named `work` of your repo using the add/commit/push Git 
commands.

Please work to mimic the 
[coding style guidelines](https://jimfix.github.io/csci221/assigns/C_style_guide_hw02.html) 
and formatting I've
suggested so far. Include comments that describe the code, when
appropriate. Include some comments at the top of your source code,
including your name and other brief info describing the program. There
should also be a brief comment that precedes each struct, function, 
and procedure definition you write.

You should work to complete each of these exercises so that they
compile and run correctly. Should you face problems in solving an
exercise, you can still submit broken code. In your top comment in
that file **PLEASE** *let us know in what way the code is broken* (why
it doesn't compile, or what tests failed, etc.). In many cases, we are
willing to give partial credit if you identify problems in the code.

Regarding scoring, we give credit not just for correct code, but also
for how well the code is written. On the last homework, the scoring
was as follows:
 
* 5 points for making *some* earnest, maybe partial attempt
* 10 points for correctness, with partial credit for bugs
* 5 points for elegance and simplicity of the solution
* 5 points for style and clarity of the coding

Though we may score these exercises differently, we will weigh each of
these characteristics similarly.

---

### Exercise 1: primes

Recall that a number is prime if it is positive and has exactly two
positive divisors. Write a C++ program `primes.cc` that, given any
integer value, will output all the primes *less than or equal* to that
value, one prime per line. That means that if there are no primes less
than or equal to that integer, it shouldn't output anything.

    % ./primes
    Enter an integer: 6
    2
    3
    5

I want you to write two C++ functions that you use to solve this
exercise. The first should be a boolean function `isPrime` whose
definition starts as follows:

    bool isPrime(int n) {
        ...

It should work by testing divisors from 2 up to the square root of
that number, if that number is positive. To do that calculation, I
also want you to write the C++ function:

    int isqrt(int n) { 
    ...

When given a non-negative integer `x`, the function `isqrt(x)` should
return the largest integer less than or equal to the real square root
of `x`.  You should only use integer calculations to compute that
value. There is no need to use any library functions and/or floating
point to solves this exercises.

---

### Exercise 2: power

The C++ code below is the definition of a function that computes the
integer value `x` taken to the integer power `n`;

    int power(int x, int n) {
        if (n == 0) {
            return 1;
        } else {
            return x * power(x,n-1);
        }
    }

Note that this is written recursively rather than iterively (i.e. it
is a function that calls itself; it does not use a loop). Rewrite this
function so that it uses the *method of repeated squaring* to compute the
power. This can be described like so:

     If n is 0, then the result of power is trivially 1. If n is an
     odd integer, then just compute x to the power n-1 and multiply
     that result by x. Otherwise, if it's even, compute the power of x
     to half of n. Now take that result and square it.

Write a simple testing program that tests this new version of the
function, like so:

    Enter an integer base: 2
    Enter an integer power: 10
    The value of 2 to 10th power is 1024.

You should write the output as `0th`, `1st`, `2nd`, `3rd`, `4th` and
so on. Note also that it should be `21st` but `11th`, `23rd` but `13th`,
etc. (There is something special about the teens.)

You can assume that the integers entered are non-negative, that they are
never both 0, and that the second one is non-negative.  Once again,
you shouldn't need anything but the primitive integer operations to
solve this.

**BONUS exercise:** Note that this method performs at most *2lg(n)*
multiplications (where *lg* is the logarithm base 2) rather than the
*n* multiplications used by the code up top. Write an iterative
version (use a loop, rather than recursion) that achieves the same
performance. Call this different version of the program `powerit.cc`.

---

### Exercise 3: merging

Create a new program `merge.cc` that asks for two sequence sizes and
builds two C++ `int` arrays, say, named `seq1` and `seq2`. It should
then ask the user for the values of those two integer sequences, like
so:

    Enter the first sequence size: 4
    Enter its values below:
    9
    5
    2
    3
    Okay. Now enter the second sequence size: 5
    Enter its values below:
    2
    1
    5
    10
    6

Note that you should be allocating the arrays on the heap using `new`.
That means that `seq1` and `seq2` should be variables of type `int*`.

Write a procedure named `sort` with this type signature

    void sort(int* A, int n) { ... }

and use it to sort each of the two sequences. The sorting algorithm
you use should be *insertion sort*. This algorithm works as described
below. You should not look up its code on-line! Write it yourself from
my description (or from memory if you've learned it before):

    To sort the array A[0..n-1], we make n-1 passes. After the k-th
    pass, all the items up to the k-th will be in sorted order, i.e.,
    the part A[0..k] will be in sorted order. So, if we start with 
    the unsorted array being the sequence
    
                          5 9 2 0 3 7 1 6
    
    then after 3 passes the array will have the contents
                          _ _ _ _
                          0 2 5 9 3 7 1 6
                                  
    With A[0..3] holding 0,2,5,9 now being sorted. In the k-th pass,
    we focus on A[k] and figure out its placement amongst the sorted
    elements A[0:k-1]. So, for the 4-th pass on the sequence just
    above, we are focusing on placing 3 within the left sorted part
    0,2,5,9. We scan down through A[k-1], A[k-2], A[k-3], etc, until
    we either (i) find an item smaller than A[k] or (ii) see that A[k]
    is smaller than all of A[0] through A[k-1]. In case (i), we shift
    all the elements larger than A[k] one position to the right,
    "inserting" A[k] just left of them. So the 4-th pass would place
    the 3 just left of the 5 and the 9 like so
                          _ _ _ _ _
                          0 2 3 5 9 7 1 6
                              ^---+
    
    and so now 0,2,3,5,9 are sorted. On this example, insertion sort
    would then continue with pass 5 (placing the 7), pass 6 (placing
    the 1), then end with pass 7 (placing the 6).
    
    Note that case (ii) happened when we placed 0 in the 3rd pass. Before
    the 3rd pass the array would have been
                          _ _ _
                          2 5 9 0 3 7 1 6

    and we moved the 0 left past the 2,5,9 placing it at index 0,
    shifting those values each one to the right in the array.

Having now written insertion sort, sort the two sequences. Have the 
program output

    Thanks. Those sequences, sorted, are:
    [2,3,5,9]
    [1,2,5,6,10]

Now write a function `merge` that has the following type signature:

    int *merge(int* A, int n, int* B, int m) { ... }

It should return a pointer to the start of a C++ array, newly
allocated on the heap, one that contains the combination of the values
in `A` and in `B`, and in sorted order. Your `main` should call the
`merge` function, passing it the pointers `seq1` and `seq2` and the
two sizes. The call returns a pointer, which you can assign to the
variable `seq3`, That should point to the new array of merged
values. Report the result of the merge as follows:

    Merging those sequences. The result is 
    [1,2,2,3,5,5,6,9,10]
    Bye!
    
You should write a helper function `output` that does the work of
outputting an integer sequence stored in a C++ array. It should be
called three times in `main`, one for each of the sequences created.
You'll call `output` once for `seq1`, once for `seq2`, and then at the
end for `seq3`.

When `main` is done, before the `return 0;` line, it should deallocate
those three arrays from the heap using `delete []`.

---

### Exercise 4: a turtle

The language LOGO introduced beginners to programming by having them
write code that moved a "turtle" to roam on a two-dimensional world.
Here, we develop a program `turtle.cc` that controls a turtle object
living on an integer grid. We represent a turtle with a struct.

Define a struct type named `turtle` that holds four pieces of
information:

* its name, as a string
* an integer representing its *x*-coordinate on the grid
* an integer representing its *y*-corrdinate on the grid
* a `char` representing the direction it's facing which will be one of
`N`, `S`, `E`, or `W`.

When the turtle is facing east it's looking in the positive *x*
direction. When facing north it's looking in the positive *y*
direction.

Write a `main` program that asks the user for the turtle's name, then
puts the turtle at (0,0), facing east.  The program should then loop
accepting four commands: `forward`, `left`, `right`, and `quit`. The
last command stops the loop and exits the program. The other three
should call the appropriate one of these three functions, ones that
you should also write:

* `turtle moveForward(turtle t)`: move the turtle one unit forward
* `turtle turnRight(turtle t)`: turn the turtle clockwise 90 degrees
* `turtle turnLeft(turtle t)`: turn the turtle counter-clockwise 90 degrees

These each should take a turtle struct and return a modified turtle
struct.
    
Finally, before each command is entered, the current state of the turtle
should be reported. Write a function

    std::string toString(turtle t) { ... }

that gives back a string reporting the turtle's state, something like

    "Rory is located at (-1,4) facing east."

Your main should output this string to `std::cout` before receiving
each command.

---

### Exercise 5: adding large integers

Develop a program `bignat.cc` that works as described below. It will
allow us to compute with integers of arbitrary size, rather than with
the limited `int` type

Create a new struct type for holding a sequence of integer digits.
Call it `number`.  It should have two fields: an `int*` field named
`digits` and also an `int` field named `numDigits`.

Now write a C++ procedure that has the signature:

    number makeNumber(std::string value) { ... }
    
It works by assuming that the string `value` contains a bunch of
decimal digits for a valid non-negative integer, like `"12345"` or
`"1213"` or `"10"` or `"9"` or `"0"`, or maybe even
`"76876876218700032230"`.  It should examine the contents of that
string, character by character, and place each digit, as an `int`, into
the number's `digits`.

To do this, you'll need two operations on strings. The expression

    value.length()

gives back the number of characters in that string's sequence. And the
expression

    value[i]
    
will get the `i`-th character in the string.

The `makeNumber` function should allocate heap space for those digits
in a `number` struct's `digits` array.  When `makeNumber` returns, it
should have placed the ones digit of the string in `digits[0]`, the
tens digit in `digits[1]`, the hundreds digit in `digits[2]`, and so
forth. And then `numDigits` should have the length of that number's
decimal representation. It returns that struct with that `numDigits`
and that pointer to `digits`.

Now write a C++ function that has the signature:

    number addNumbers(number N1, number N2) { ... }

It should give back a `number` struct, one whose `digits` were also
allocated on the heap. So you'd have, within this function's code,
lines like

    number N;
    N.numDigits = some appropriate size;
    N.digits = new int[N.digits];

and then the last line should be

    return N;
    
write its code so that it performs a proper place-wise "long addition"
of the two numbers, digit by digit, with carrying, storing the
resulting digits into struct `N`. 

**Note:** It's okay if you allocate a `digits` array to be larger than
ultimately needed, just so `numDigits` is set to the appropriate number 
of digits, with no leading 0s.

Now devise a `main` that tests out these new functions. At a minimum,
it should ask the user for two strings, build two `number` structs
using `makeNumber`, and then build a third using `addNumbers`. Then
report the result.

You'd should write and use a function

    std::string toString(number N) { ... }
    
that allows you to output your results to `cout`.

Finally, before `main` ends, it should deallocate the `digits`
of those three `number` structs.
