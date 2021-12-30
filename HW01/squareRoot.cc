#include <iostream> /*program that gets sucessive estimate of the square root of a 
number that differes from the previous estimate by no more than 0.000000001 */ 
#include <cmath>

void getest(double num){
    double current = num / 2;
    double last = num;
    while (std::abs(current - last) > 0.000000001){ /*using while loop to 
    compute difference of sucessive guesses*/
        std::cout << current << std::endl;
        last = current;
        current = 0.5*(last + num/last);      
    }     
}



int main(void){ 
    std::cout << "Enter a number: ";
    double num;
    std::cin >> num;

    getest(num);
}
