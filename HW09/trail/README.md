UPDATE APRIL 18 10:25 am:
All working now! 

// I was unable to finish this exercise because I couldn't figure out how to make the turtle class function 
// properly. 
//
// I completed Grid.hh and Grid.cc and they work to the best of my knowledge. In Grid.cc, display()
// displays a grid to the terminal and the functions SetEdge and SetPoint work to update the grid if an edge
// or a point has been visited. 
// 
// In Turtle.hh I made the variables xpos, ypos, dir, and trailState to track the turtle's x position on the
// grid, y position on the grid, direction on the grid, and whether its trail was on or off. I was unable 
// to correctly set these variable in Turtle.cc so the rest of the program doesn't work. In Turtle.cc I also
// defined the methods moveForward(), turnRight(), and turnLeft() based off of the turtle.cc exercise in HW02
// to instruct the turtle to move on the grid. The moveForward() method makes calls to setEdge and setPoint
// in the Grid class to update the grid based on the turtle's movements. 
// 
// In I completed trail.cc to the best of my abilities (but left all function class to the Turtle class 
// commented out so they would not give errors). If the user enters "display" the initial grid will be 
// displayed to the terminal. If the commented code above "g.display()" is uncommented you can see that setEdge
// and setPoint work. 
//
// I will continue to work on this and hopefully will be able to fix these bugs!