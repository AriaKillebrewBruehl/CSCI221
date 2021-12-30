// Aria Killebrew Bruehl, HW10 exercise 7
#include "Bool.hh"
#include <iostream>

int main(void) {
  Var* x = new Var{"x"};
  Var* y = new Var{"y"};
  Var* z = new Var{"z"};
  Not* a1 = new Not{x};
  And* a2 = new And{z, a1};
  Or* a3 = new Or{x, y};
  Not* a4 = new Not{a3};
  Or* a5 = new Or{a4, a2};

  bind bs[3];
  bs[0].name  = "x";
  bs[0].value = true;
  bs[1].name  = "y"; 
  bs[1].value = false;
  bs[2].name  = "z"; 
  bs[2].value = true;
  bool result = a5->chck(bs);
  std::cout << result << std::endl;
}

