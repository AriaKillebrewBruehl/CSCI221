// Aria Killebrew Bruehl, HW02 Exercise 1: Primes

#include <iostream>
#include <vector>

int isqrt(int num) {
  // returns the largest integer less than or equal to num's real square root
  int sqrt = 1;
  int test = 1;
  while (test <= num) {
    test = sqrt * sqrt;
    sqrt += 1;
  }
  return sqrt;
}

bool isPrime(int num) {
  // returns a boolean statement to tell if a num is prime
  bool prime = true;
  // special condiditon for 2 since 2 is the only prime where 2%2 = 0
  if (num == 2) {
    return prime;
  }
  for (int d = 2; d < isqrt(num); d++) {
    if (num % d == 0) {
      prime = false; // if a num has a divisor that is not 1 or that num prime =
                     // false
      return prime;
    }
  }
  return prime;
}

void findPrimes(int num) {
  // find primes of number, then prints them
  for (int test = 2; test <= num; test++) {
    if (isPrime(test)) {
      std::cout << test << std::endl;
    }
  }
}
int main() {
  //  get input and finf the primes less than or equal to that number
  std::cout << "Enter an integer: ";
  int num;
  std::cin >> num;

  findPrimes(num);

  return 0;
}
