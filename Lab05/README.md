# Lab 05: some digital circuits

*Due 3/2 by 3pm*

---

We will work together in lab to complete some of these exercises in
lab today.  Whatever you do not finish in the lab, complete by
Monday's lecture as homework. I'll post a repo on Git Classroom
entitled **Homework 05** that you'll use to submit your work
for Monday.

### Set up

You should already have downloaded a copy of
[Logisim](http://www.cburch.com/logisim/) which allows you to draw
digital circuit diagrams and test their circuit's logic and
behavior. [In this `lb05` zipped folder](lb05.zip) we've placed several
Logisim files (ending in `.circ`) that we'll use as the starting
points for these exercises.

The Logisim project has been abandoned by its creator, Carl Burch, and
so it hasn't been updated in nearly a decade. As a result, some
students have struggled to get Logisim working on their computer.
An alternative is to use the computers hidden in the desks of the ETC
lab. These have Logisim installed. You'll just need a way of saving
the work you complete in lab (a bunch of files that end with `.circ`)
for your own records.  Remember to email them to yourself, or save
them on a flash drive, or upload them to Google Drive, etc. when you
are done working in lab today.

Another alternative is [Logisim
Evolution](https://github.com/reds-heig/logisim-evolution) which
continues to be developed and updated, and mostly from the original
Logisim Jave source code. You could try using it instead.  To run it,
you need Java 9 installed on your system and this Java archive (or
JAR) file:
[logisim-evolution.jar](http://reds-data.heig-vd.ch/logisim-evolution/logisim-evolution.jar).
Once you've downloaded this file (and moved it into, say, the `lb05`
folder) you can go to that folder in the console and type

    java -jar logisim-evolution.jar

to get the program running.


### Sum of products method

Today we'll build circuit diagrams that compute some elementary boolean
functions, but ones that will be useful as part of our toolkit of 
circuits that make up a computer processor. To devise thse circuits,
we'll follow the method we covered in lecture, namely:

1. Examine the truth table for a boolean function, focusing on each
output bit's column. Within each column, we pay attention
to each row where that column's output bit is a `1`.

2. For each such row, we devise a boolean expression describing the
state of its variables. We write that row's condition as a conjunction
(as an **AND**) of variables (or a variable's negation).  Each row,
then, can be described as a *product* of these variable *literals*.

3. We then write down a disjunction, or *sum*, of all these conditions
by stitching them together with **OR** (i.e. with the `+` operation).
This gives the boolean expression for that output bit in *disjunctive
normal form*.

4. Repeat this procedure for each output bit of the function.

As an example, we considered this truth table

     x0 | y0 || z1 | z0
    ----+----++----+----
      0 |  0 || 0  | 0
      0 |  1 || 0  | 1   <== *
      1 |  0 || 0  | 1   <== *
      1 |  1 || 1  | 0   <== @

Working from this table to devise an expression for the
`z1` output bit, we write down only a single row (marked with 
`@`) in step 2.  This gives us the product expression

    z1 := x0.y0

Repeating this work for `z0`, we look at the rows marked with
`*` and obtain the expression

    z0 := x0'.y0 + x0.y0'

(Here, we are using a `'` mark to indicate variable negation,
rather than putting a line above the variable.) As you can
see, this method produces a *sum of product terms* for each
output bit. We'll call this the *SOP method*.

If you load the circuit file `1ha.circ` in Logisim you will
see a layout of a digital circuit diagram that computes
these two bits of output from those two bits of input.
You can change the input bits values (set them to either
`0` and `1`) and see that the circuit's behavior mimics
its truth table specification.

For each of the exercises below, I'll ask you to build a circuit for a
bunch of boolean functions. You should use the sum of products method
to devise each circuit. Using this method, you'll end up with a "three
layer design" where the input variables feed to the outputs by passing
their information through wires to at most three gates. That is: if
we trace any wire path from an input to some output, we'll pass through
at most three gates. They would appear in the order `NOT` (the first
layer), then `AND` (the second layer), then `OR` (the third and final
layer), before reaching an output.

This three-layer circuit design is very standard, and it results from
following the SOP method.

---

### Exercise 1: XOR and PARITY

The behavior of the `z0` output bit for the `1ha.circ` turns out to be
an *exclusive OR* or *XOR*.  This is a circuit that outputs a `1`
exactly when one of its two inputs is `1`, that is, when an odd number
of its inputs are `1`.  Note that this means that it also functions as
a two input "parity" circuit (PARITY). That is, it indicates whether
the number of `1` inputs is odd. A PARITY gate outputs `1` when the
number of `1` inputs is odd. It outputs `0` when the number of `1`
inputs is even.

We've provided a standalone 2-input XOR/PARITY circuit in the file 
`xor.circ`.

These two gate types (XOR and PARITY) can each be generalized to take
three or more inputs. When there are three inputs the behavior of the
XOR gate and the PARITY gate differ from each other, and so their logic
circuits must be different.  Both circuits will output a `1` when exactly
one of their three inputs is `1`. However, when all three inputs are set
to `1` then the XOR circuit outputs `0`. When all three inputs are set
to `1` the PARITY circuit outputs `1` instead, since 3 is an odd number
of `1` inputs.

**Exercises**  

**1a.** Build a 3-input XOR circuit within the file `xor3.circ`.  

**1b.** Build a 3-input PARITY circuit within the file `parity3.circ`.  

These circuits should be built using only AND, OR, and NOT gates, and
the circuits should be explainable as a sum of products. If you choose to
*also* devise a circuit for either some other way, you can include it
as an extra circuit that you submit, in addition to the two you submit
in SOP form.

---

### Exercise 2. multiplexers

When building larger digital circuits, we often have several
different lines of output from a number of components feeding 
their input into some other part of the circuit, and where we
want to *select* which component to "pay attention to" based on
some computed condition. For example, we may be updating a
value as a result of either an addition computation or
a multiplication computation. So, in that case, we have a subcircuit
that computes the addition, and maybe a different subcircuit that
computes the multiplication, and so we can build a circuit that
chooses which of those two results we want to use to perform
an update.

The standard circuit component that performs this kind of
"signal selection" is called a *multiplexer* or *MUX* circuit.
MUXs are characterized by the number of inputs that you
can choose from (usually a power of two, say *2^k*) and
the *width* of the signal in number of bits of information.
Here' we'll just focus on single-line inputs, ones of
width 1. Such MUXs are called *2^k:1* MUXs and they have
*2^k + k* inputs, and 1 bit of output.

A 2:1 MUX, for example, has three inputs and one output.

* two of the inputs are signal lines `line0` and `line1`

* the third input is a `select` line, used to choose which
input line signal should be passed through as the output.

This is also called a 2:1 MUX. It has the truth table:


      select line0 line1 | MUX2(select,line0,line1)
    ---------------------+---------------------------
         0     0     0   |    0 \
         0     0     1   |    0  \___ outputs line0
         0     1     0   |    1  /
         0     1     1   |    1 /
         1     0     0   |    0 \
         1     0     1   |    1  \___ outputs line1
         1     1     0   |    0  /
         1     1     1   |    1 /

It has a behavior that mimics this Python function's
definition:

    def MUX2(select, line0, line1):
        if select == 1:
            return line1
        else:
            return line0

**Exercises**

**2a.** Build the circuit for a 2:1 multiplexer using only AND, OR, and NOT gates.
Following the SOP method blindly, you'll have four products. BONUS: See if you can
simplify those so that you only use two products.  Submit it as `2to1mux.circ`.

**2b.** A 4:1 MUX is similar. It has six inputs: `line00`, `line01`,
`line10`, and `line11`, along with `select1` and `select0`.  The two
select lines are used to choose which of the four other lines are
output.  For example, When `select1`:`select0` are set to `0:0`, then
`line00` gets output. If set to `1:0`, then `line10` is output. Etc.
Build a 4:1 MUX circuit. This can be done however you like, not
necessarily using SOP. Put the design in `4to1mux.circ`.  **NOTE:** Be
careful about your use of the two select lines! Don't reverse their
roles.

---

### Exercise 3: Addition circuits

It turns out that the truth table we devised that computes then *bit vector*
`z1z0` from the input bits `x0` ans `y0` is computing addition of integers
in binary notation.  If you think about decimal addition, we have the 
schoolbook formulae:

      0      0      1      1
    + 0    + 1    + 0    + 1
    ---    ---    ---    ---
      0      1      1      2

Since this is base 10 notation, we have the digit `2` to represent the
fourth sum. In base 2 notation, we can only have `0`s and `1`s, so we 
write these sums instead

      0      0      1      1
    + 0    + 1    + 0    + 1
    ---    ---    ---    ---
     00     01     01     10

In the rightmost sum, we write 2 as "binary 'ten'", but in actuality
this result is just the 1st power of two, namely, 2.  (And binary `100`
would be 4, binary `1000` would be 8, and so forth. `01` is the 0th
power of two, namely, 1.) So what we're now seeing is that the `z1`
bit is the "twos bit" of the sum of `x0` and `y0`. And `z0` is the
"ones bit" of that same sum.

We could do longer additions in binary.  Consider the "schoolbook"
binary addition:

      1001100
    +   10110
    ---------
      1100010

Here, we computed sums over each column, moving from right to left.
We wrote, in the ones bit column, that `0 + 0 = 0`. In the twos bit
column we wrote that `0 + 1 = 1`.  In the "fours bit" column, we might
want to write that *1 + 1 = 2*, but we now know that
2 is `10` in binary so, like in base 10 schoolbook addition, we instead write
down a `0` bit and then "carry" the `1` bit to the eights bit column.
In that column, we think *1 + 1 + 1 = 3* but, since 3 is written `11`
in binary, we instead write a `1` and carry the `1` to the 16s bit
column.

To make this process more clear, here is the same sum with the carry bits
displayed on an extra row at the top:

       111
      1001100
    +   10110
    ---------
      1100010

Or, even more carefully, we have this binary addition

      011100
      1001100
    +   10110
    ---------
      1100010

So, in actuality, we are figuring out column sums that
follow these patterns:

      0     0     0     0     1     1     1     1
      0     0     1     1     0     0     1     1
    + 0   + 1   + 0   + 1   + 0   + 1   + 0   + 1
    ---   ---   ---   ---   ---   ---   ---   ---
     00    01    01    10    01    10    10    11

This could be more generally expressed as a function
on three input bits `c0`, `x0`, and `y0` yielding two
output bits `c1`, `z0`.  The bit `c0` is often called
the "carry in." The bit `c1` is often called the 
"carry out".  

The general addition looks like

       c0
       x0
    +  y0
    -----
    c1 z0

A single column of three input bits leads to two columns of
output bits.

**Exercises**  

**3a.** Build a circuit that behaves like this single
column addition. It should take those three bits
of "ones bit" input and produce the "ones and twos
bits" as output. This, by the way, is called a
*1-bit full adder* circuit. The circuit we built
before, incidentally, is called a 1-bit *half adder* 
because it lacks the ability to process a *carry in*
bit. (It's not fully functional, I suppose.) Use the
file `1fa.circ`.   

**3b, as a BONUS.** Build a 4-bit full adder circuit using whatever
method you like. (Part of this bonus has you figuring out what I mean
by that!) Submit it as the file `4fa.circ`.  

