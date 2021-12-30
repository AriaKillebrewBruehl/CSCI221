// Aria Killebrew Bruehl, HW09 Exercise 4 
#ifndef __GRID_HH
#define __GRID_HH

#include <string>
#include <iostream>

enum Mark{Empty, Wall, Trail, Prize};
// Grid class to create grid for turtle to live on 
class Grid {
private:
  Mark* grid; // posititon t can sit 
  bool* vedge; 
  bool* hedge;
  char* display; // not really needed, any time they call display just do grid vedge hedge
  int num_rows;
  int num_cols;
public:  
  // Grid constructor 
  Grid(int rows, int columns);
  // Grid methods 
  void setEdge(int x1, int y1, int x2, int y2, bool state); // sets state of edge between point (x1, y1) and (x2, y2)
  void setPoint(int x1, int y1, bool state); // sets state of point (x1, y1)
  void displayRow(int point);
  void display(); // displays grid to terminal 
  int getRows();
  int getCols();
  void setWall(int r, int c);
  void setEmpty(int r, int c);
  void setTrail(int r, int c);
  void setPrize(int r, int c);
  bool hasWall(int r, int c);
  bool hasPrize(int r, int c);
  bool hasTrail(int r, int c);
  ~Grid(); // destructor 
};

#endif