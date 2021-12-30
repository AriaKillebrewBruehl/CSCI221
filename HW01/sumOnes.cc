#include <iostream> /*program that uses sums of 1s to express decompositions
of powers of 2*/
#include <string>

void getstring(int pow){
    std::string sum = "1";

    if (pow == 0){
        std::cout << sum;
    }

    int i = 0;
    while (i <= pow - 1){ //using while loop to get next set of sums
        std::cout << sum << std::endl; 
        sum = "(" + sum + " + " + sum + ")";
        ++i;
    }
}


int main(void) {
    std::cout << "Enter an integer: "; //get input 
    int p;
    std::cin >> p;

    getstring(p);
}
