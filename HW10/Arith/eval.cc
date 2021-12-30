// Aria Killebrew Bruehl, HW10 exercise 6
#include "Arith.hh"
#include <iostream>

int main(void) {
  Arith* a1 = new Val {31};
  Arith* a2 = new Val {100};
  Arith* a3 = new Val {2};
  Arith* a4 = new Val {4};
  Arith* a5 = new Val {2};
  Arith* a6 = new Val {3};
  Arith* a7 = new Mul {a2,a3};
  Arith* a8 = new Add {a5,a6};
  Arith* a9 = new Mul {a4,a8};
  Arith* aA = new Add {a7,a9};
  Arith* aB = new Add {a1,aA};
  std::cout << aB->eval() << std::endl;
  Arith* aC = new Val {3};
  Arith* aD = new Val {50};
  Arith* aE = new Val {10};
  Arith* aF = new Div {aD, aE};
  Arith* aG = new Neg {aF};
  Arith* aH = new Sub {aC, aG};
  std::cout << aH->eval() << std::endl;
  delete aB;
  delete aH;
}

