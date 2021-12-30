// Aria Killebrew Bruehl HW10 exercise 7
#include "Bool.hh"

// destructor 
Cond::~Cond() = default;
//
// constructor 
And::And(Cond* L, Cond* R) 
  : left {L}, right {R}
{ }
bool And::chck(bind* bindings) {
  return left->chck(bindings) && right->chck(bindings);
}
// destructor 
And::~And() {
  delete left;
  delete right;
}
//
// constructor 
Or::Or(Cond* L, Cond* R) 
  : left {L}, right {R}
{}
bool Or::chck(bind* bindings) {
  return left->chck(bindings) || right->chck(bindings);
}
// destructor 
Or::~Or() {
  delete left;
  delete right;
}
//
// constructor 
Not::Not(Cond* L) 
  : left {L}
{}
bool Not::chck(bind* bindings) {
    return !left->chck(bindings);
}
// destructor 
Not::~Not() {
  delete left;
}
//
// contructor 
Var::Var(std::string V) 
: name {V} 
{ }

bool Var::chck(bind* bindings) {
  // loop trough bindgins to find binding w corresponding name
  for(int i = 0; ; i++) {
    if (name == bindings[i].name) {
      return bindings[i].value;
    }
  }
}
// destructor 
Var::~Var() = default;