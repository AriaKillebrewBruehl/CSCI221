#include <iostream>
#include <string>

void getstring(int pow){
    std::string sum = "1";

    int i = 0;
    while (i <= pow){
        std::cout << sum ; 
        sum = "(" + sum + " + " + sum + ") \n";
        ++i;
    }
}


int main(void) {
    std::cout << "Enter an integer: ";
    int p;
    std::cin >> p;

    getstring(p);
}