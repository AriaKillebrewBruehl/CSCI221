#include <iostream>

//
// stats.cc
//
// Starting code for ARRAY/STATS part of Lab 02.
//
int main() {

  // Allocate the array.
  double data[10];
  const int maxSize = 10;

  // Get the data set size.
  int size;
  do {
    std::cout << "What's the size of your data set? ";
    std::cin >> size;
    if (size < 1 || size > maxSize) {
      std::cout << "The size must be between 1 and " << maxSize << ".\n";
    }
  } while (size < 1 || size > maxSize);

  // Get the data.
  for (int i=0; i < size; i++) {
    std::cout << "Enter entry number "<< i << ": ";
    std::cin >> data[i];
  }

  // Report the data.
  std::cout << "Here is what you entered:\n";
  for (int i=0; i < size; i++) {
    std::cout << "Entry " << i << ": " << data[i] << "\n";
  }
  
  return 0;
}


