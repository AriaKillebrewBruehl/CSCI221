#include <iostream> //programs to get divisors of a given number 
#include <vector>

std::vector<int> getdivs(int n) {
  std::vector<int> divisors;

  for (int d = 1; d <= n; d++) { /*function to find divisors of number and 
  add them to vector*/
    if (n % d == 0) {
      divisors.push_back(d);
    }
  }

  return divisors;
}

void printdivs(int n, std::vector<int> divisors) { //funciton to print divisors
  if (divisors.size() == 1) {
    std::cout << "The divisor of " << n << " is " << divisors[0];
  } else {
    std::cout << "The divisors of " << n << " are ";
    if (divisors.size() == 2) {
      std::cout << divisors[0] << " and " << divisors[1];
    } else {
      for (int i = 0; i < divisors.size() - 1; i++) {
        std::cout << divisors[i] << ", ";
      }
      std::cout << "and " << divisors[divisors.size() - 1];
    }
  }
  std::cout << ".\n";
}

int main(void) {
  int n;

  std::cout << "Enter a positive integer just below: \n"; //get input 
  std::cin >> n;

  if (n < 1) {
    std::cerr << "The number " << n << " is not a positive number.\n";
    return -1;
  }

  printdivs(n, getdivs(n));
  return 0;
}
