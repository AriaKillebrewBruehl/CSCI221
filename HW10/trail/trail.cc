// Aria Killebrew Bruehl HW09 Exercise 4
//

#include <iostream>
#include <string>
#include "Grid.hh"
#include "Turtle.hh"

int main() {
  std::cout << "You've just run my version of trutle!." << std::endl;
  std::cout << "It uses a Grid class and a Turtel class to track a turtle's movements on a 2-D grid space. The turtle is currently in the middle of the grid facing North." << std::endl;

  Grid g {5, 7}; // create grid 
  g.setGrid();
  g.setVEdge();
  g.setHEdge();
  g.setWall(3, 2);
  g.setWall(0, 5); 
  g.setWall(1, 5);
  g.setPrize(3, 3);
  g.setPrize(2, 1);
  g.setPrize(0, 0);
  XTurtleZ t {&g}; // create turtle 
  t.setStart();

  std::string entry;
  do {
    std::cout << "Enter a command just below (h for help):" << std::endl;
    std::cin >> entry;
    // list of possible commands
    if (entry == "h") {
      std::cout << "Commands:" << std::endl;
      std::cout << "\t h - display this message" << std::endl;
      std::cout << "\t q - quit" << std::endl;
      std::cout << "\t forward - move the turtle forward one square" << std::endl;
      std::cout << "\t left - turn the turtle 90 degrees counterclockwise" << std::endl;
      std::cout << "\t right - turn the turtle 90 degrees clockwise" << std::endl;
      std::cout << "\t on - turn the turtle's trail on" << std::endl;
      std::cout << "\t off - turn the turtle's trail off" << std::endl;
      std::cout << "\t dispaly - display the grid" << std::endl;
    } else if (entry == "display" || entry == "d") {
      g.display();
    } else if (entry == "forward" || entry == "f") {
      t.moveForward(); 
    } else if (entry == "left" || entry == "l") {
      t.turnLeft();
    } else if (entry == "right" || entry == "r") {
      t.turnRight();
    } else if (entry == "on") {
      t.trail(true);
    } else if (entry == "off") {
      t.trail(false);
    } else if (entry == "prizes" || entry == "p") {
      std::cout << "You have colleted " << t.prizes() << " prize(s)." << std::endl;
    } else if (entry == "save" || entry == "s") {
      t.save();
    } else if (entry == "restore") {
      if (t.canTransport()) {
        t.restore();
        std::cout << "pew!" << std::endl; // make a noise when you transport!!
      } else {
        std::cout << "No saved locations." << std::endl;
      }
    }
  } while (entry != "q");

    return 0;
}