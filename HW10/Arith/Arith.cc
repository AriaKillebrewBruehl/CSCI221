// Aria Killebrew Bruehl HW10 exercise 6
#include "Arith.hh"

Arith::~Arith(void) { }

Val::Val(int V) 
: value {V} 
{ }

int Val::eval(void) {
  return value;
}

Bop::Bop(Arith* L, Arith* R) 
  : left {L}, right {R} 
{ }

Bop::~Bop(void) {
  delete left;
  delete right;
}

int Bop::eval(void) {
  int lv = left->eval();
  int rv = right->eval();
  return apply(lv,rv);
}
//
// Uop constructor 
Uop::Uop(Arith* R) 
  : right {R} 
{ }
// Uop destrctor
Uop::~Uop(void) {
  delete right;
}
// Uop method eval()
int Uop::eval(void) {
  int rv = right->eval();
  return apply(rv);
}

Add::Add(Arith* L, Arith* R) 
  : Bop {L,R}
{ }

int Add::apply(int l, int r) { 
  return l + r;
}

Mul::Mul(Arith* L, Arith* R) 
  : Bop {L,R}
{ }

int Mul::apply(int l, int r) { 
  return l * r;
}

//
// Sub, L - R
Sub::Sub(Arith* L, Arith* R) 
  : Bop {L,R}
{ }
//
int Sub::apply(int l, int r) { 
  return l - r;
}
//
// Div, L / R
Div::Div(Arith* L, Arith* R) 
  : Bop {L,R}
{ }
//
int Div::apply(int l, int r) { 
  return l / r;
}
//
// Neg, -R
Neg::Neg(Arith* R) 
  : Uop {R}
{ }
//
int Neg::apply(int r) { 
  return (-1) * r;
}


