
Fill out the table below according to Exercise 1:

     instruction || flip x? | zero y? | flip y? | add 1? || circuit
      (i2:i1:i0) ||   (fx)  |   (zx)  |   (fy)  |  (a1)  || behavior
    -------------++---------+---------+---------+--------++------------
        0  0  0  ||     0   |     0   |     0   |    0   || z := x+y
        0  0  1  ||     0   |     1   |     0   |    0   || z := x
        0  1  0  ||     1   |     0   |     0   |    1   || z := -x
        0  1  1  ||     0   |     0   |     1   |    1   || z := x-y
        1  0  0  ||     0   |     1   |     0   |    1   || z := x+1
        1  0  1  ||     0   |     1   |     1   |    0   || z := -(?)x-1
        1  1  0  ||     1   |     0   |     1   |    1   || z := -x-y-1
        1  1  1  ||     0   |     0   |     0   |    1   || z := x+y+1

Use the result as a guide for the behavior of the four subcircuits you
need to build for Exercise 2.