// Aria Killebrew Bruehl, HW02 Exercise 4: a turtle
#include <iostream>
#include <string>

struct turtle {
  // create a new turtle
  std::string name;
  int x, y;
  char dir;
};

turtle moveForward(turtle t) {
  // move  turtle forward
  t.x += (t.dir == 'E') - (t.dir == 'W'); // using bool values to move turtle
  t.y += (t.dir == 'N') - (t.dir == 'S');
  return t;
}

turtle turnRight(turtle t) {
  // trun turtle right
  if (t.dir == 'E') {
    t.dir = 'S';
  } else if (t.dir == 'S') {
    t.dir = 'W';
  } else if (t.dir == 'W') {
    t.dir = 'N';
  } else if (t.dir == 'N') {
    t.dir = 'E';
  }
  return t;
}

turtle turnLeft(turtle t) {
  // turn turtle left
  if (t.dir == 'E') {
    t.dir = 'N';
  } else if (t.dir == 'N') {
    t.dir = 'W';
  } else if (t.dir == 'W') {
    t.dir = 'S';
  } else if (t.dir == 'S') {
    t.dir = 'E';
  }
  return t;
}

std::string toString(turtle t) {
  // create sentence that gives information about turtle
  std::string direction;
  if (t.dir == 'E') {
    direction = "east";
  } else if (t.dir == 'W') {
    direction = "west";
  } else if (t.dir == 'N') {
    direction = "north";
  } else if (t.dir == 'S') {
    direction = "south";
  }
  return t.name + " is located at (" + std::to_string(t.x) + ", " +
         std::to_string(t.y) + ")" + " and is facing " + direction + ".";
}

int main() {
  // get input, create initial turlte and take input
  std::cout << "Enter the turtle's name:";
  std::string name;
  std::cin >> name;
  turtle t = {name, 0, 0, 'E'};

  std::string input;
  while (true) {
    std::cout << toString(t) << std::endl;
    std::cin >> input;
    if (input == "quit") {
      break;
    } else if (input == "forward") {
      t = moveForward(t);
    } else if (input == "right") {
      t = turnRight(t);
    } else if (input == "left") {
      t = turnLeft(t);
    }
  }
  return 0;
}