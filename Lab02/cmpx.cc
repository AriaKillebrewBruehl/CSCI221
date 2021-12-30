#include <iostream>
#include <cmath>

//
// cmpx.cc
//
// Starting code for STRUCT/CMPX exercises of Lab 02.
// It uses a struct to implement a complex number type.
//

struct cmpx {
  double re;
  double im;
};

cmpx plus(cmpx z1, cmpx z2) {
  cmpx z;
  z.re = z1.re + z2.re;
  z.im = z1.im + z2.im;
  return z;
}

std::string to_string(cmpx z) {
  if (z.im < 0.0) {
    return std::to_string(z.re) + std::to_string(z.im) + "i";
  } else {
    return std::to_string(z.re) + "+" + std::to_string(z.im) + "i";
  }
}
  
cmpx input() {
  cmpx z;
  std::cout << "Real part? ";
  std::cin >> z.re;
  std::cout << "Imaginary part? ";
  std::cin >> z.im;
  return z;
}

int main() {

  std::cout << "Enter a complex number just below:\n";
  cmpx z1 = input();
  std::cout << "Now enter another complex number.\n";
  cmpx z2 = input();

  std::cout << "Their sum is " << to_string(plus(z1,z2)) << ".\n";
  
  return 0;
}
