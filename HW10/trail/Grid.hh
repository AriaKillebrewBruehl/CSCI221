// Aria Killebrew Bruehl, HW010 Exercises 2-4 (with help from the wonderful TAs!)
#ifndef __GRID_HH
#define __GRID_HH

#include <string>
#include <iostream>


enum Mark{Empty, Wall, Trail, Prize, Turt, oTurtle};
// Grid class to create grid for turtle to live on 
class Grid {
  private:
  Mark* grid ; // posititon t can sit 
  bool* vedge; 
  bool* hedge;
  int num_rows;
  int num_cols;
public:  
  // Grid constructor 
  Grid(int rows, int columns);
  // Grid methods 
  int getIndexVEdge(int r, int c);
  int getIndexHEdge(int r, int c);
  int getIndexPoint(int r, int c);
  void setGrid();
  void setVEdge();
  void setHEdge();
  void setTrailEdge(int r, int c, char dir);
  void position(int row, int col);
  void vEdge(int r, int c);
  void hEdge(int row, int col);
  void blankRow(int i, int time);
  void display();
  int getRows();
  int getCols();
  void setWall(int r, int c);
  void setEmpty(int r, int c);
  void setTrail(int r, int c);
  void setPrize(int r, int c);
  void setTurtle(int r, int c, bool state);
  bool hasWall(int r, int c);
  bool hasPrize(int r, int c);
  bool hasTrail(int r, int c);
  bool hasTurt(int r, int c);
  ~Grid(); // destructor 
};

#endif




