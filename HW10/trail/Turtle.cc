// Aria Killebrew Bruehl HW10 Exercises 2-4 (with help from the fabulous TAs!)
#include "Turtle.hh"
#include "Grid.hh"
#include <string>
#include <iostream>

Turtle::Turtle(Grid* grid) :
    g {grid},
    trailState {true}, // initialize trailState as true 
    xpos {grid->getCols()/2}, // position turtle in center of grid 
    ypos {grid->getRows()/2},
    dir {'N'}
{ }
// place turtle at starting postion
void Turtle::setStart() {
  g->setTurtle(ypos, xpos, trailState);
}
//
// trail(state) funct to set state of trail 
void Turtle::trail(bool state) {
    trailState = state;
}
//
// moveForward() funct taken from HW02 turtle.cc to increment turtle's xpos and ypos
void Turtle::moveForward() {
  // check that turtle wont hit wall
  if (canStep()) {
    int lastX = xpos; // set lastX as current xpos
    int lastY = ypos; // set lastY as current ypos
    xpos += (dir == 'E') - (dir == 'W'); // using bool values to move turtle according to dir
    ypos -= (dir == 'N') - (dir == 'S');
    g->setTurtle(ypos, xpos, trailState); // set turtle at current position
    // check if turtle should leave a trail 
    if (trailState) {
      g->setTrail(lastY, lastX);
      g->setTrailEdge(ypos, xpos, dir);
    }
    // else mark last location as empty 
    else {
      // if turtle was on in last position leave trail 
      if (g->hasTurt(lastY, lastX)) {
        g->setTrail(lastY, lastX);
      } else {
        g->setEmpty(lastY, lastX);
      }
    }
  // if trutle will hit wall give error message
  } else {
    std::cout << "The turtle cannot move forward anymore, turn to continue." << "(" << xpos << " ," << ypos << " ," << dir << ")" << std::endl;
  }
}
void Turtle::turnRight() {
  if (dir == 'E') {
    dir = 'S';
  } else if (dir == 'S') {
    dir = 'W';
  } else if (dir == 'W') {
    dir = 'N';
  } else if (dir == 'N') {
    dir = 'E';
  }
}
void Turtle::turnLeft() {
  if (dir == 'E') {
    dir = 'N';
  } else if (dir == 'N') {
    dir = 'W';
  } else if (dir == 'W') {
    dir = 'S';
  } else if (dir == 'S') {
    dir = 'E';
  }
}
// canStep() funct to check if turtle will leave grid or hit wall
bool Turtle::canStep() {
  // check if turtle will leave grid
  if (xpos <= 0 && dir == 'W') {
    return false;
  } else if (xpos >= g->getCols() && dir == 'E') {
    return false;
  } else if (ypos <= 0 && dir == 'N') {
    return false;
  } else if (ypos >= g->getRows() && dir == 'S') {
    return false;
  } 
  // check if turtle will hit wall 
  else {
    int nextX = xpos + (dir == 'E') - (dir == 'W'); // use bool values to calculate nextX
    int nextY = ypos - (dir == 'N') - (dir == 'S');
    return !g->hasWall(nextY, nextX);
  }
}
bool Turtle::seesTrail() {
  return g->hasTrail(xpos, ypos);

}
// destructor 
Turtle::~Turtle() {
}

TurtleZ::TurtleZ(Grid* grid) :
  Turtle {grid}, 
  numPrizes {0}
{ }
// prizes() return number of prizes turtle has collected 
int TurtleZ::prizes() {
  return numPrizes;
}
//
// moveForward() funct now records prizes collected
void TurtleZ::moveForward() { 
  int nextX = xpos + (dir == 'E') - (dir == 'W'); // use bool values to calculate nextX
  int nextY = ypos - (dir == 'N') - (dir == 'S');
  // check if turtle will collect a prize by moving forward
  if (g->hasPrize(nextY, nextX) && canStep()) {
    numPrizes++;
  }
  Turtle::moveForward();
}
// destructor 
TurtleZ::~TurtleZ() {
}

XTurtleZ::XTurtleZ(Grid* grid) :
  TurtleZ {grid}
{ };
//
// save() funct add pair (xpos, ypos) to Stck
void XTurtleZ::save() {
  s.push(std::make_pair(xpos, ypos));
}
//
// restore() sets trail at current pos then sets turtle at last position 
void XTurtleZ::restore() {
  if (g->hasTurt(xpos, ypos)) {
        g->setTrail(ypos, xpos);
      } else {
        g->setEmpty(ypos, xpos);
      }
  const auto last = s.pop();
  xpos = last.first;
  ypos = last.second;
  g->setTurtle(ypos, xpos, trailState);
}
//
// cantTransport() checks that Stck has positions stored 
bool XTurtleZ::canTransport() {
  return !s.is_empty();
}
// destructor 
XTurtleZ::~XTurtleZ() {
}