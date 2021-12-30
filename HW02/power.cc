// Aria Killebrew Bruehl, HW02 Exercise 2: Power
#include <iostream>
#include <string>

void output(int base, int power, int value) {
  //  find proper suffix for power, then output complete sentence with base,
  //  power, and value
  std::string suffix;

  if (4 <= power % 10 or power % 10 == 0) {
    suffix = "th";
  } else if (power % 10 == 1) {
    suffix = "st";
  } else if (power % 10 == 2) {
    suffix = "nd";
  } else if (power % 10 == 3) {
    suffix = "rd";
  } else if (11 <= power or power <= 20) {
    suffix = "th";
  }

  suffix = std::to_string(power) + suffix;
  std::cout << "The value of " << base << " to the " << suffix << " is "
            << value << "." << std::endl;
}
int toPower(int base, int power) {
  // function (from README) to raise a base to a power
  if (power == 0) {
    return 1;
  } else {
    return base * toPower(base, power - 1);
  }
}
void evenPower(int base, int power) {
  // method if power is even
  int half = toPower(base, power / 2);
  int value = half * half; // compute value of base raised to power
  output(base, power, value);
}

void oddPower(int base, int power) {
  // method if power is odd
  int result = toPower(base, power - 1);
  int value = result * base; // compute value of base raised to power
  output(base, power, value);
}

int main() {
  // get input, then call correct function to compute power
  std::cout << "Enter an integer base:";
  int base;
  std::cin >> base;
  std::cout << "Enter an integer power:";
  int power;
  std::cin >> power;

  if (power % 2 == 0) {
    evenPower(base, power);
  } else {
    oddPower(base, power);
  }
  return 0;
}