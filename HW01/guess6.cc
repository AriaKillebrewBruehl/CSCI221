/*
 
  guess6.cc

  author: Jim Fix, from code provided by the Reed CS2 course.

  This is a solution to Lab 1 Part 3 Exercise 4. It illustrates 
  the structure of main and incorporates comments.

  The code plays a guessing game with its user, one
  where they have a limited number of guesses (six).

*/

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

int main(void) {

  // Pick a number.
  srand(time(0));
  int target = rand() % 100 + 1;
  
  // Give instructions.
  std::cout << "I've chosen a number from 1 to 100. ";
  std::cout << "Try to guess what it is.\n";

  // Play the game.
  bool success = false;
  int tries = 0;

  do {

    //
    // Prompt for a guess.
    if (tries == 0) {
      std::cout << "Enter a number: ";
    } else if (tries == 5) {
      std::cout << "This is your final guess. What's my number? ";
    } else {
      std::cout << "What's your next guess? ";
    }

    //
    // Get the guess.
    int guess;
    std::cin >> guess;
    tries = tries + 1;

    //
    // Assess the guess.
    if (guess == target) {
      // Correct? Report nothing. Set success flag.
      success = true;
    } else if (guess < target) {
      std::cout << "That's too low. Try again.\n";
    } else {
      std::cout << "That's too high. Try again.\n";
    } 

  } while (!success && tries < 6);

  //
  // Congratulate them or give them the bad news.
  if (success) {
    std::cout << "Well done! ";
  } else {
    std::cout << "Sorry, you are out of guesses...\n";
  }
  std::cout << target << " was the number I chose.\n";

  return 0;
}
