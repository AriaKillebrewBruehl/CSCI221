// Aria Killebrew Bruehl, HW09 Exercise 4
#include "Grid.hh"
#include <string>
#include <iostream>


int rows = 4;
int columns = 6;


Grid::Grid(int rows, int columns) :
  grid {new char[((rows + 2) * 2 + 1) * ((columns + 2) * 2 + 1)]('d')}, // create a chr array filled with false for all points and edges
  num_rows {rows}, // create var to hold number of rows in grid
  num_cols {columns} // create var to hold number of columns in grid
{ }
//
// setEdge(x1, y1, x2, y2, sate) funct to set state of edge connecting points (x1, y1) and (x2, y2)
//
void Grid::setEdge(int x1, int y1, int x2, int y2, bool state) {
    // set state of vertical edges
    if (y1 - y2 == 0) {
        grid[(2 * num_cols + 1) * (2 * y1) + (2 * x1) + 1] = state; // compute location of edge in array and set state
    }
    // set state of horizontal edges
    else if (x1 - x2 == 0) {
       grid[(2 * num_cols + 1) * (2 * y2 - 1) + (2 * x1)] = state; // compute location of edge in array and set state
    }
}
//
// setPoint(x1, y1, state) funct to set state of point (x1, y1)
//
void Grid::setPoint(int x1, int y1, bool state) {
    grid[(2 * num_cols + 1) * (2 * y1) + (2 * x1)] = state; // compute location of point in array and set state

}
//
// topWall(num_cols) creates top (or bottom) wall
void topWall(int num_cols) {
    int i = 0;
    for (int col = 0; col < num_cols; col++){
        std::cout << (i++, "X"); // output 'X'' and increment i
        std::cout << (i++, "xxx"); // output 'xxx grid edge and increment i
    }
    std::cout << (i++, "X") <<std::endl;
}
//
// blankRow(num_cols) create second to top (or bottom) row
void blankRow(int num_cols) {
    int i = 0;
    // create second "blank" row
    std::cout << (i++, "x");
    for (int col = 0; col < num_cols - 1; col++){
        std::cout << (i++, "    "); // fill row with spaces and increment i
    }
    std::cout << (i++, "   x") << std::endl;
}
//
// gridPoint(grid[i]) outputs correct display given state of grid point
void Grid::displayRow(int point) {
    if (grid[point] == "e") {
        std::cout << "   ";
    }
    if (point % 2 == 0) {
        if (grid[point] == 'd') {
            std::cout << "+";
        } else if (grid[point] == 'v') {
            std::cout << "o";
        } else if (grid[point] == 't') {
            std::cout << "@";
        } else if (grid[point] == 'o') {
            std::cout << "0";
        }
    } else if (point % 2 == 1) {
        if (grid[point] == 'd') {
            std::cout << "---";
        } else if (grid[point] == 'v') {
            std::cout << "zzz";
        }
    } if ((point + 1) % (2 * num_cols + 1) == 0) {
        std::cout << "   X" << std::endl;
    }
}
//
// display() function to output grid using std::cout
void Grid::display() {
    // do top wall
    // loop over positions, some have e edge or s edge or both which fills in display
    for (int j = 0; j < num_rows * num_cols; j++) {
        // compute r c of postion into index
        // use rc to figure index into bool array for e edge and s edge
        // helper funct for postion
        // helper for e edge
        // helper for the s edge
        // do middle stuff
    }
    // do bottom wall

    // create top "walled" row
   topWall(num_cols + 2);
   // create second "blank" row
   blankRow(num_cols + 2);
   int i = 2 * (2 * (num_cols + 2) + 1) ;
    // loop through every row
    for (int row = 0; row < num_rows; row++ ){
        std::cout << "X   ";
        // loop through every column in row
        for (int col = 0; col < num_cols; col++){
            // display points
            displayRow(i);
            i++;
            // display edges
            displayRow(i);
            i++;
        }
        displayRow(i); // output state of furthest right grid point
        i++;
        // loop through every column in between two rows
        std::cout << "x   ";
        for (int col = 0; col < num_cols; col++){
            if (grid[i] == 'd') {
                std::cout << "|";
            } else if (grid[i] == 'v') {
                std::cout << "Z";
            }
            i++;
            std::cout << (i++, "   "); // output spaces between edges and increment i
        }
        if (grid[i] == 'd') {
                std::cout << "|";
            } else if (grid[i] == 'v') {
                std::cout << "Z";
            }
        i++;
        std::cout << "   x" <<std::endl; // output state of farthest right vertical edge
    }
    // loop through columns of lowest row
    std::cout << "X   ";
    for (int col = 0; col < num_cols; col++){
        // display points
        displayRow(i);
        i++;
        // display edges
        displayRow(i);
        i++;
    }
    displayRow(i); // output state of furthest right grid point
    i++;
    std::cout << "   X" << std::endl;
    // create second to bottom "blank" row
    blankRow(num_cols + 2);
    // create bottom "walled" row
    topWall(num_cols + 2);
}
//
// getRows() funct to return num_rows in grid
int Grid::getRows() {
    return num_rows;
}
//
// getCols() funct to return num_cols in grid
int Grid::getCols() {
    return num_cols;
}
/*
//
// setWall(r, c) funct sets location (r, c) as wall
void Grid::setWall(int r, int c) {

}
//
// setEmpty(r, c) funct sets location (r, c) as empty
void Grid::setEmpty(int r, int c) {

}
//
// setTrail(r, c) funct sets location (r, c) as containing trail
void Grid::setTrail(int r, int c){

}
//
// setPrize(r, c) funct sets location (r, c) as containing prize
void Grid::setPrize(int r, int c) {

}
*/
//
// hasWall(r, c) funct return if location (r, c) has wall
bool Grid::hasWall(int r, int c) {
    return grid[(2 * num_cols + 1) * (2 * r) + (2 * c)] == 'w';
}
//
// hasPrize(r, c) funct returns if location (r, c) has prize
bool Grid::hasPrize(int r, int c) {
    return grid[(2 * num_cols + 1) * (2 * r) + (2 * c)] == 'p';
}
//
// hasTrail(r, c) funct returns if location (r, c) has trail
bool Grid::hasTrail(int r, int c) {
    return grid[(2 * num_cols + 1) * (2 * r) + (2 * c)] == 'v';
}

// destructor
Grid::~Grid() {
    delete [] grid; // return memory back to heap
}