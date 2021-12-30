#include <iostream> /* program that reverses a set of digits*/
#include <vector>
#include <math.h>

std::vector<int> reverse(int num) {
    std::vector<int> reversed;
    
    while (num > 0) { //using while loop to break number into digits and reverse them
        int rem = num % 10;
        reversed.push_back(rem);
        num = (num / 10);
    }
    return reversed ;
}

void printrev(int num, std::vector<int> reversed){ /*function to print reversed 
number and check cases*/
    int result = 0;
    for (int i = 0; i <= reversed.size() - 1; i++){
        result += reversed[i] * pow(10, reversed.size() - 1 - i);
    }
    std::cout << "Its reversal number is " << result << "." << std::endl;

    if (result == num) {
        std::cout << "That number is a decimal palindrome." << std::endl;
    }
}

int main(void){
    std::cout << "Enter a number and I will report its reversal number: "; //get input 
    int num;
    std::cin >> num;
    if (num % 10 == 0){
        std::cout << "Oops! I can't handel that number. Sorry!";
    }
    else {
        printrev(num, reverse(num));
    }
}
