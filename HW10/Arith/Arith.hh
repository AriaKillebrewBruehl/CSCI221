// Aria Killebrew Bruehl, HW10 exercise 6
class Arith {
public:
  virtual int eval(void) = 0;
  virtual ~Arith(void);
};

class Bop : public Arith {
private:
  Arith* left;
  Arith* right;
public:
  Bop(Arith* L, Arith* R);
  ~Bop(void);
  virtual int apply(int l, int r) = 0;
  int eval(void);
};
//
// Uop (unary operation) class
class Uop : public Arith {
private:
  Arith* right; // only has one variable on RHS of unary operation 
public:
  Uop( Arith* R);
  ~Uop(void);
  virtual int apply(int r) = 0;
  int eval(void);
};

class Mul : public Bop {
public:
  Mul(Arith* L, Arith* R);
  int apply(int l, int r);
};

class Add : public Bop {
public:
  Add(Arith* L, Arith* R);
  int apply(int l, int r);
};

//
// Sub class, L - R, subclass of Bop class 
class Sub : public Bop {
public:
  Sub(Arith* L, Arith* R);
  int apply(int l, int r);
};
//
// Div class, L / R, subclass of Bop class 
class Div : public Bop {
public:
  Div(Arith* L, Arith* R);
  int apply(int l, int r);
};
//
// Neg class, -R, subclass of Uop class 
class Neg : public Uop {
public:
  Neg(Arith* R);
  int apply(int r);
};

class Val : public Arith {
private:
  int value;
public:
  Val(int V);
  int eval(void);
}; 