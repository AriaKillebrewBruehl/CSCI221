// Aria Killebrew Bruehl, HW010 Exercises 2-4 (with help from the amazing TAs!)
#ifndef __TURTLE_HH
#define __TURTLE_HH

#include <string>
#include <iostream>
#include "Grid.hh"
#include "../llist-Stck_T/Stck_T.hh"

class Turtle {

protected:
  Grid* g;
  int xpos;
  int ypos;
  char dir;
  bool trailState;
public:  
  // constructors 
  Turtle(Grid* grid);
  // methods 
  void setStart(void);
  void trail(bool state);
  virtual void moveForward();
  void turnRight();
  void turnLeft();
  bool canStep();
  bool seesTrail();
  // destructor 
  ~Turtle();
};

class TurtleZ : public Turtle { 
private:
  int numPrizes;
public:  
  // constructors 
  TurtleZ(Grid* grid);
  // methods 
  void moveForward();
  int prizes(void);
  // destructor 
  ~TurtleZ();
 };

class XTurtleZ : public TurtleZ { 
private:
  Stck<std::pair<int, int>> s;
public:  
  // constructors 
  XTurtleZ(Grid* grid);
  // methods 
  void save();
  void restore();
  bool canTransport();
  // destructor 
  ~XTurtleZ();
 };

#endif