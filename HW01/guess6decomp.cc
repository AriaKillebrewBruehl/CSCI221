/*
 
  guess6decomp.cc

  author: Jim Fix, from code provided by the Reed CS2 course.

  This is a highly decomposed solution to Lab 1 Part 3 Exercise 4. It
  illustrates the structure of a basic C++ program, using procedures
  and functions, that we will show off this week.

  The code plays a guessing game with its user, one where they have a
  limited number of guesses (six).

*/

#include <iostream>
#include <ctime>    // For time()
#include <cstdlib>  // For srand() and rand()

// randomInt: generate a random number within a range
//
// low:  lowest number possible in range
// high: highest number possible in range
//
int randomInt(int low, int high) {
  return (rand() % (high - low + 1)) + low;
}

// assessGuess - helper function for `playGame`, just below
//
// Outputs some text indicate the quality of a player's guess.
//
// guess:  the number they guessed
// target: the number they were supposed to guess
//
// Returns whether their guess was correct.
//
bool assessGuess(int guess, int target) {
  //
  // correct? report nothing. return success flag.
  if (guess == target) return true;

  //
  // otherwise report low/high. bad guess.
  if (guess < target) {
    std::cout << "That's too low. Try again.\n";
  } else {
    std::cout << "That's too high. Try again.\n";
  } 
  return false;
}

// promptForGuess - helper function for `playGame`, just below
//
// Outputs a proper prompt for a guess based on which attempt
// they are on (first, last, or neither)
//
// tries: number of attempts they've made so far
// bound: number of tries they get
//
void promptForGuess(int tries, int bound) {
  if (tries == 0) {
    std::cout << "Enter a number: ";
  } else if (tries == bound-1) {
    std::cout << "This is your final guess. What's my number? ";
  } else {
    std::cout << "What's your next guess? ";
  }
}

// playGame - plays a guessing game
//
// number: the number that a player must guess
// bound:  the number of tries they're allowed
//
// returns whether they won the game
//
bool playGame(int number, int bound) {
  bool success = false;
  int tries = 0;

  do {
    promptForGuess(tries,bound);
    int guess;
    std::cin >> guess;
    tries = tries + 1;
    success = assessGuess(guess,number);
  } while (!success && tries < 6);
  return success;
}

int main(void) {
  // pick a number
  srand(time(0));
  int number = randomInt(1,100);
  
  // give instructions
  std::cout << "I've chosen a number from 1 to 100. ";
  std::cout << "Try to guess what it is.\n";

  // play the game
  bool theyWon = playGame(number,6);

  // congratulate or taunt
  if (theyWon) {
    std::cout << "Well done! ";
  } else {
    std::cout << "Sorry, you are out of guesses...\n";
  }
  std::cout << number << " was the number I chose.\n";

  return 0;
}
