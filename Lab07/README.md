# Lab 07: MIPS32 assembly programming in SPIM

*Treat these three lab exercises as a Homework 07 that is due Monday,
 March 16th. 3pm.*

In this lab, you will begin practice with assembly machine-level
programming. You'll be programming using the MIPS32 instruction set,
which normally can be used to program a family of computer processors
of the MIPS architecture. Here, instead, we will be running our
programs on the SPIM simulator, a free piece of softaware available
from a U. of Wisconsin researcher. We'll use the beginning of the lab
to set up this software, and then write MIPS assembly programs,
testing them in SPIM, for the remainder of the lab.

The kind of programming exercises you're being asked to do here are
not too complex, mostly because our goal is to get you used to the
logistics and quirks of this style of programming. There are many
aspects of this kind of programming that will be new, and potentially
many details that we could cover. Rather than give you complete
information about the assembler syntax, and SPIM, instead I encourage
you to learn today by copying my program examples, tweaking the code
I've given you (by figuring out what that code does), and getting
those to work.

Neverthless, there are several resources you can access to learn
the details of MIPS and SPIM, listed below:  
• [the SPIM simulator](http://pages.cs.wisc.edu/~larus/spim.html)  
• [the MIPS32 processor family](https://www.mips.com/products/architectures/mips32-2/)  
• [SPIM's MIPS information links](http://pages.cs.wisc.edu/~larus/spim.html#information)  
• [the MIPS32 programmer's guide](https://jimfix.github.io/csci221/lecs/wk06/MIPS_Vol2.pdf)  
For today, you might most benefit from referring to these resources:  
• [the MIPS32 quick reference](https://jimfix.github.io/csci221/lecs/wk06/MIPS-QR.pdf)  
• [this SPIM system call reference](https://www.doc.ic.ac.uk/lab/secondyear/spim/node8.html)  
These two, and the instructions and examples below, ought to be enough for you get this work done.

In addition, I've placed in this folder six sample programs that are
variations on the code I showed you yesterday in lecture. These all
roughly perform the same task: summing the numbers from 1 up to a
number.  You'll want to dig through these to learn the general format
of MIPS assembly programs, and to see use of the instructions and
system calls you'll need to get your programs working. The
instructions used can be summarized as below:

* `ADDU $Rdst, $Rsrc1, $Rsrc2`: sum two registers, placing result in a third 
* `ADDIU $Rdst, $Rsrc, constant`: sum a register with a constant
* `SUBU $Rdst, $Rsrc1, $Rsrc2`: subtract two registers, placing result in a third 
* `LI $Rdst, constant`: set a register to some constant's value
* `LW $Rdst, label`: load a register from a labelled word in the data segment
* `LA $Rdst, label`: load a register with the address of a labelled location in the data segment
* `MOVE $Rdst, $Rsrc`: copy a value from one register into another
* `BLT $Rsrc1,$Rsrc2,label`: jump to a line if one register's value is less than another. Also `GT`, `GE`, `LE`, `EQ`, and `NE`.
* `B label`: jump to a line if one register's value is less than another. Also `GT`, `GE`, `LE`, `EQ`, and `NE`.

The registers you can use in these instructions hold a 32-bit
value. You'll normally either treat that value as an integer (using
two's complement), or as its 32 bits (where certain bit operations can
be used to examine or change its bits), or as an address that points
somewhere in memory where data can be fetched and stored. There are 32
of these registers, however some of these are reserved for specific uses
(that I'll work to teach you).  The registers are divided up and named
for these different kinds of uses.

The registers are `v0`, `v1`, `a0-a3`, `t0-t9`, `s0-s7`, `gp`, `sp`,
`fp`, and `ra`. For now, we'll only use `t0-t9` in our programs, with
some others used when following specific conventions for specific
other instructions.

We'll learn a lot of this by just looking at some sample programs.

### Our first MIPS program

Take a look at the `sample1.s` program included in this repo. I've also
included it as text just below. The code computes the sum of the numbers
from 1 up to 100. It tracks the sum within register `t0` and the current
integer of its count using the register `t2`. It has a loop of instructions
that increment that count by 1, and then bump the sum up by that count.
Here is that code, described further below:

    	.globl main
    	.text
    
    main:
    	li	$t0, 0		# sum = 0    
    	li	$t1, 1		# inc = 1    
    	li	$t2, 0          # count = 0  
    	li 	$t3, 100        # last = 100 
    loop:	
    	beq	$t3, $t2, done  # if last == count goto done    
    	addu	$t2, $t2, $t1   # count += inc
    	addu	$t0, $t0, $t2   # sum += count
    	b	loop
    
    done:	
    	li	$v0, 0		# return 0
    	jr	$ra		#

You'll see three kinds of lines. The top two lines are "header"
information that communicate that a `main` function is being defined,
and then that the "text" of the program will follow just
after. Littered throughout the code are lines that are *labels*. These
names `main`, `loop`, and `done` can be used by program instructions
as targets of "jumps" and "branches" in the code. Finally, there are
the actual instruction lines. They each start with an instruction's
"mnemonic" like `li`, `addu`, `bgt` describing what the instrcution
is, followed by the registers that they act upon.

The instruction

    	li 	$t3, 100     

"loads" the value of `100` into the register named `t3`. The instruction

    	addu	$t2, $t2, $t1

computes the sum of registers `t2` and `t1`, and stores the result into
register `t2`.  If, instead, we wanted to store that sum into `t7` the
instruction would be

    	addu	$t7, $t2, $t1

The instruction

    	beq	$t3, $t2, done

is a "branch." It checks the values of `t3` and `t2`, comparing
their values. If `t3` and `t2` hold the same value, then the
processor should jump to the instruction just below the label
`done`. If not, then it should continue by executing the `addu`
instruction just below.

This is all great, but probably you want to see the code in 
action.

### Setting up SPIM to run MIPS code

This repo contains a "tarball" of SPIM's source code. This is a
*compressed* binary *archive* file that contains the C source code for
the simulator. Type the following commands in the console while in
your MIPS work folder:

    tar xvfpz spim-simulator-master.tgz 
    pushd spim-simulator-master/spim
    make

This will make the SPIM simulator as an executable file named `spim`.
You'll want to make copies of that simulator executable (along with
a supporting file) and put them within this repo folder so you can 
complete your work. Type these commands:
 
    cp spim-simulator-master/spim/spim .
    cp spim-simulator-master/CPU/exceptions.s .
    cp spim-simulator-master/helloworld.s .
    ./spim -f helloword.s

The last line will actually run SPIM on a simple MIPS32 assembly program,
one that greets the world. 

### Sample programs

To instead run our sample code, type

    ./spim -f sample1.s

It will run to completion, doing its work silently. A more interesting
program to run is `sample2.s`. This, like `helloworld.s`, actually 
outputs the summed result to the console. 

    ./spim -f sample2.s

The key to its output is some special MIPS/SPIM machinery for 
"system calls". There are several such calls that SPIM supports
in your programs. They will allow you to write more interactive 
code, much like a C++ program. They each have a number. Here
are the ones we'll use

• **System call #1:** Output an integer to the console.  
• **System call #4:** Output a string to the console.  
• **System call #5:** Get an integer input from the console.   

The program `sample2.s` uses #4 and #1 to report the sum.
Try now running `sample4.s`. This one, unlike the other two, 
pauses to accept an integer input from the console, using
system call #5. Each has their own peculiar way of being called.

To system call #1, we are asked to load the register `v0` with
the number 1. (For the others, we instead load it with 4 or 5.)
We are also required to put the value that we want to output
into register `a0`. This is the "argument register" normally.
So we use the `move` instruction, like so:

    move $a0, $t0

so that we can output the sum.

For outputting a string, we instead are required to put the
address that's the start of a character string into `a0`.
The top lines of that program

            .data
    fdbk:	.asciiz "The sum from 1 to 100 is "
    eoln:	.asciiz "\n"

tell SPIM two labelled locations in the program's image
with addresses `fdbk` and `eoln` where two zero-terminated
ASCII character strings live. These each get used in
the `sample2.s` program to format the output. We use
the "load address" instruction to put those addresses
into `a0` before system call #4, like so:

    	li	$v0, 4		
    	la	$a0, fdbk	
    	syscall			

The `sample4.s` program uses a system call that fills in
a console input into a register. In the code you see the
lines

	li	$v0, 5		
	syscall			
	move	$t3, $v0	

This calls the "input integer" system procedure. It happens
to place the input value into register `v0` by convention.
This register is normally the "return value" register.
And then our last line moves (well, copies) that value
into register `t3` so that we can use it as our maximum
count value within the loop.

Incidentally, these system calls are [documented here](http://students.cs.tamu.edu/tanzir/csce350/reference/syscalls.html).

---

### Exercises

**Exercise 1: multiplication of integers**  
Write a MIPS assembly program `multiply.s` that asks for two positive 
integers as input and computes the product of those two integers. It should
output the product to the console.

To do this, I'd like you to use the method of *repeated addition*.
To explain this, let's call the two numbers *n* and *m*. Designate
one of the registers to hold a sum, initializing it to 0. Then
loop *m* times, adding the value *n* to that sum, one time for
each iteration of the loop.

Your best bet is to work from the code in `samples/sample5.s` found
within this folder. That code counts from a number down to 0, and
adds the count to a sum. Your code shouldn't be much different
than this.

---

**Exercise 2. integer division**  
Now write a MIPS assembly program `divide.s` that asks for two
positive integers as input and computes the division of the
one integer by the other. It should output the quotient and
also the remainder that are computed by that division.

To do this, I'd like you to use the method of *repeated subtraction*.
Let's call the two numbers *n* and *d*. To compute the quotient,
we repeatedly subtract *d* from *n* in a loop, counting how many
times we can do this until we reduce the value down to the
remainder due to this division.

This code should not be too dissimilar from the first exercise.

---

**BONUS Exercise 3. guessing game**  
Write a program `guess.s` that has an integer between 1 and 100 stored
in its data segment. (See `sample3.s` for an example of how I stored
100 in the data segment of the program.)  This will serve as the
"random number" to be guessed by the program user for a guessing game
program that you write.

The program should prompt the user for an integer value,
telling them whether they are correct and, if not,
reporting whether they guessed too high or too low.
They should be allowed to keep guessing in this way 
until they guess the number correctly. It should tell 
them when their guess is correct.

**DOUBLE BONUS.**   
Only allow them at most 6 guesses in a version named `guess6.s`.  If
they fail to guess correctly after 6 attempts, then the program should
halt and tell them what the number was.

**NOTE:** For this one we can't generate a random number.  Instead,
you'll want to test the code by varying the number listed in the
`.data` segment of the program for several different runs. Try enough
hidden numbers to convince yourself that the code is correct.




 



    
