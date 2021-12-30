#include <iostream> /*program that computes the smallest power of 2 that is 
greater than or equal to a given integer */


int getnum(int n){

    if (n < 2){
        return 1;
    }
    int num = 2;
    while (n > num){ //while loop used to find smallest power of 2 
        num = num*2;
    }
    return num;
}
int main(){
    std::cout << "Enter an integer: ";
    int n;
    std::cin >> n; //get input 

    int power = getnum(n);
    std::cout << power << std::endl; //return output 

    return 0;
}
