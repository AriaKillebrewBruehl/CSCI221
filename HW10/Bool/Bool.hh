// Aria Killebrew Bruehl, HW10 exercise 7
#include <string>

struct bind {
  std::string name;
  bool        value;
};

class Cond {
private:
  bind* binding;
public:
  virtual bool chck(bind* bindings) = 0;
  virtual ~Cond();
};

class And : public Cond {
private:
Cond* left;
Cond* right;
public:
  And(Cond* L, Cond* R);
  bool chck(bind* bindings);
  ~And();
};

class Or : public Cond {
private:
Cond* left;
Cond* right;
public:
  Or(Cond* L, Cond* R);
  bool chck(bind* bindings);
  ~Or();
};

class Not : public Cond {
  private:
  Cond* left;
public:
  Not(Cond* L);
  bool chck(bind* bindings);
  ~Not();
};

class Var : public Cond {
private:
  std::string name;
public:
  Var(std::string name);
  bool chck(bind* bindings);
  ~Var();
}; 



