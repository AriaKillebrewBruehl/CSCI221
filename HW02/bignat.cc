// Aria Killebrew Bruehl, HW02: Exercise 5
#include <iostream>
#include <string>

struct number {
    // creates a struct with specified digits and number of digits
    int *digits;
    int numDigits;
};

number makeNumber(std::string value) { 
    // reads through value to create an array that holds the digits of value 
    int *digits = new int[value.length()]; // allocate new memory in heap for number being created
    for (int i = 0; i < value.length(); i++){
        digits[value.length()-1-i] = (int)(value[i]) - 48;
    }
    number n = {digits, value.length()};
    return n;
}

number addNumber(number N1, number N2) {
    // adds two numbers together by creating a third number 
    int num;
    if (N1.numDigits < N2.numDigits) {
        num = N2.numDigits;
    } else {
        num = N1.numDigits;
    }
    number N; 
    N.numDigits = 0;
    N.digits = new int[N1.numDigits + N2.numDigits]; // allocate new memory in heap for new number 

    int d;
    int ones = 0;
    int tens = 0;
    for (int i = 0; i < num; i ++) {
        d = N1.digits[i] + N2.digits[i]; 
        // if d is greater than 9 it must be divided into ones and tens place of the number 
        ones = (d + tens) % 10;
        tens = ((d + tens) / 10); 
        N.digits[i] = ones;
        N.numDigits += 1; 
    }
    if (tens != 0) {
        N.digits[N.numDigits] = tens;
        N.numDigits += 1;
    }
    return N;
}

std::string toString(number N) {
    // convert a number to a string 
    std::string stringNum = "";
    for (int i = N.numDigits - 1; i >= 0; i--){
        stringNum += std::to_string(N.digits[i]);
    }
    return stringNum;
}

int main() {
    // take input from user, create numbers N1 and N2, then all the numbers and output that value
    std::cout << "Enter the first non-negative integer:";
    std::string value1;
    std::cin >> value1;
    number N1 = makeNumber(value1);

    std::cout << "Enter the second non-negative integer:";
    std::string value2;
    std::cin >> value2;
    number N2 = makeNumber(value2);

    number N = addNumber(N1, N2);
    std::cout << "Those numbers added together are: " << toString(N) << std::endl;
    return 0;
}