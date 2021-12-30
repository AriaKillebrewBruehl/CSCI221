#include <iostream> //program to draw a triangle made up of *s

void draw_triangle(int height) { //function to draw triangle 
  for (int row = 1; row <= height; ++row) {
    for (int space = 0; space < height - row; ++space) {
      std::cout << " ";
    }
    for (int star = 0; star < row; ++star) {
      std::cout << "*";
      if (star != row - 1) {
        std::cout << " ";
      }
    }
    std::cout << std::endl;
  }
}
int main(void) {
  std::cout << "Enter a height: "; //get input 
  int height;
  std::cin >> height;
  draw_triangle(height);
  return 0;
}