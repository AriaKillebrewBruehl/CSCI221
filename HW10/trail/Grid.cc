// Aria Killebrew Bruehl, HW10 Exercises 2-4 (with help from the superb TAs!)
#include "Grid.hh"
#include <string>
#include <iostream>


Grid::Grid(int rows, int columns) :
  grid {new Mark[rows * columns ]()}, // grid points where turtle can "sit"
  vedge {new bool[(rows -1) * columns]()}, // vertical edges
  hedge {new bool[rows * (columns - 1)]()}, // horizontal edges
  num_rows {rows}, // create var to hold number of rows in grid 
  num_cols {columns} // create var to hold number of columns in grid 
{ }
// get correct index in vedge array based on r and c 
int Grid::getIndexVEdge(int r, int c) {
    return num_cols*r + c; 
}
// get correct index in hedge array based on r and c 
int Grid::getIndexHEdge(int r, int c) {
    return (num_cols - 1)*r + c; 
}
// get correct index in grid array based on r and c 
int Grid::getIndexPoint(int r, int c) {
    return num_cols*r + c; 
}
int Grid::getRows() {
    return num_rows;
}
int Grid::getCols() {
    return num_cols;
}
//
// setter functions to set position (c, r) as mark
//
void Grid::setWall(int r, int c) {
    grid[(num_cols * r) + c] = Wall;
}
void Grid::setEmpty(int r, int c) {
    grid[(num_cols * r) + c] = Empty;
}
void Grid::setTrail(int r, int c) {
    grid[(num_cols * r) + c] = Trail;
}
void Grid::setPrize(int r, int c) {
    grid[(num_cols * r) + c] = Prize;
}
void Grid::setTurtle(int r, int c, bool state) {
    if (state) {
        grid[(num_cols * r) + c] = Turt;
    } else {
        grid[(num_cols * r) + c] = oTurtle;
    }
}
//
// has functions return if position (c, r) has mark 
bool Grid::hasWall(int r, int c) {
    return grid[(num_cols * r) + c] == Wall;
}
bool Grid::hasPrize(int r, int c) {
    return grid[(num_cols * r) + c] == Prize;
}
bool Grid::hasTrail(int r, int c) {
    return grid[(num_cols * r) + c] == Trail;
}
bool Grid::hasTurt(int r, int c) {
    return grid[(num_cols * r) + c] == Turt;
}
// 
// setGrid() initializes grid to Empty
void Grid::setGrid(){
    for (int i = 0; i < num_rows; i++) {
        for (int j = 0; j < num_cols; j++) {
            setEmpty(i, j);
        }
    }
}
//
// setVEdge() initializes vedge to flase
void Grid::setVEdge(){
    for (int i = 0; i < num_rows - 1; i++) {
        for (int j = 0; j < num_cols; j++) {
            int k = getIndexVEdge(i, j);
            vedge[k] = false;
        }
    }
}
//
// setHEdge() initializes hedge to false
void Grid::setHEdge(){
    for (int i = 0; i < num_rows; i ++) {
        for (int j = 0; j < num_cols - 1; j++) {
            int k = getIndexHEdge(i, j);
            hedge[k] = false;
        }
    }
}
// 
// setEdge(r, c, dir) funct to set state of edge at (c, r) in direction dir
void Grid::setTrailEdge(int r, int c, char dir) {
    if (dir == 'N') {
        int vi = getIndexVEdge(r, c);
        vedge[vi] = true;
    } else if (dir == 'S') {
        int vi = getIndexVEdge(r - 1, c);
        vedge[vi] = true;
    } else if (dir == 'E') {
        int hi = getIndexHEdge(r, c - 1);
        hedge[hi] = true;
    } else if (dir == 'W') {
        int hi = getIndexHEdge(r, c);
        hedge[hi] = true;
    }
}
//
// solidWall(num_cols) outputs solid wall (top and bottom rows) for grid  num_cols wide
void solidWall(int num_cols) {
    for (int col = 0; col < num_cols + 1; col++){
        std::cout << "X"; // output 'X'' and increment i  
        std::cout << "xxx"; // output 'xxx grid edge and increment i 
    } 
    std::cout << "X" <<std::endl;
}
//
// blankRow(num_cols) outputs blank row (second from top and bottom rows) for grid num_cols wide
void Grid::blankRow(int num_cols, int time) {
    std::cout << "x   ";
    for (int i = 0; i < num_cols - 1; i++) {
        if (grid[i] == Wall && time == 1) { 
           std::cout << "x   ";
        } else if (grid[num_cols * (num_rows -1) + i] == Wall && time ==2) {
            std::cout << "x   ";
        } else {
            std::cout << "    ";
        }
    }
    std::cout << "    x" << std::endl;;
}
//
// poisitoin(i) outputs mark at grid[i], call w r c then compute i 
void Grid::position(int row, int col) {
    int i = getIndexPoint(row, col);
    if (grid[i] == Empty){
        std::cout << "+";
    } else if (grid[i] == Wall) {
        std::cout << "X";
    } else if (grid[i] == Trail) {
        std::cout << "o";
    } else if (grid[i] == Prize) {
        std::cout << "$";
    } else if (grid[i] == Turt) {
        std::cout << "@";
    } else if (grid[i] == oTurtle) {
        std::cout << "0"; 
    } else {
        std::cout << "! " << i << " "<< grid[i];
    }
}
//
// vEdge(i) outputs vertical edges of grid including walls
void Grid::vEdge(int r, int c) {
    int vi = getIndexVEdge(r, c);
    int gi = getIndexPoint(r, c);
    if (grid[gi] == Wall && grid[gi + num_cols] == Wall) {
        std::cout << "X";
    } else if (grid[gi] == Wall && grid[gi + num_cols] != Wall) {
        std::cout << " ";
    } else if (grid[gi] != Wall && grid[gi + num_cols] == Wall) {
        std::cout << " ";
    } else {
       std::cout << (vedge[vi]?"Z":"|");
    }
}
//
// hEdge(i) outputs horizontal edges of grid including walls
void Grid::hEdge(int row, int col) {
    int hi = getIndexHEdge(row, col);
    int gi = getIndexPoint(row, col);
    if (grid[gi] == Wall && grid[gi + 1] == Wall) {
        std::cout << "xxx";
    } else if (grid[gi] == Wall && grid[gi + 1] != Wall) {
        std::cout << "   ";
    } else if (grid[gi] != Wall && grid[gi + 1] == Wall) {
        std::cout << "   ";
    } else {
        std::cout << (hedge[hi]?"zzz":"---");
    }
}
//
// display() function to output grid using std::cout 
void Grid::display() {
    // output top two rows
    solidWall(num_cols);
    blankRow(num_cols, 1);
    int row = 0;
    int col = 0;
    int i = 0;
    // output every row 
    for (row = 0; row < num_rows - 1; row++ ){ 
        std::cout << "X";
        i = getIndexPoint(row, col);
        // check if left most edge of row is wall 
        if (grid[i] == Wall) {
            std::cout << "xxx";
        } else {
            std::cout << "   ";
        }
        // loop through every column in row 
        for (col = 0; col < num_cols - 1; col++){
            position(row, col); // output state of grid point
            hEdge(row, col); // output state of horizontal grid edge
        } 
        position(row, col); // output state of grid point
        i = getIndexPoint(row, col); 
        if (grid[i] == Wall) {
            std::cout << "xxx";
        } else {
            std::cout << "   ";
        }
        std::cout << "X" << std::endl;
        // begin row of vertical edges 
        std::cout << "x   ";
        int col = 0;
        for (col = 0; col < num_cols - 1; col++){
            vEdge(row, col); // output state of vertical edge
            std::cout << (i++, "   "); // output spaces between edges
        } 
        vEdge(row, col); // output state of vertical edge
        std::cout << "   x" << std::endl;
    }
    // loop through columns of lowest row 
    std::cout << "X";
    i = getIndexPoint(row, col);
    if (grid[i] == Wall) {
        std::cout << "xxx";
    } else {
        std::cout << "   ";
    }
    for (int col = 0; col < num_cols - 1; col++){
        position(row, col); // output state of grid point
        hEdge(row, col); // output state of horizontal grid edge
    } 
    position(row, col); // output state of grid point
    i = getIndexPoint(row, col);
    if (grid[i] == Wall) {
        std::cout << "xxx";
    } else {
        std::cout << "   ";
    }
    std::cout << "X" << std::endl;
    // output bottom two rows
    blankRow(num_cols, 2);
    solidWall(num_cols);
}
// destructor 
Grid::~Grid() {
    delete [] grid; // return memory back to heap 
}

