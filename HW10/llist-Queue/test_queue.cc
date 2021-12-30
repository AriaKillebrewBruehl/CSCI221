//
// test_queue
//
// Homework 10 for CSCI 221 Spring 2020
//
// Author: Jim Fix
//
// This program is the driver for a series of tests of a queue data
// structure.  The code can be compiled with the unix command line
//
//   g++ --std=c++11 -g -o test_queue test_queue.c Queue.cc
//
// and then run with the unix command line
//
//   ./test_queue 
//
// Once running, the program asks for a series of commands, ones that
// perform a suite of operations on the queue. For example:
//
//   $ ./test_queue
//   Your queue contains []
//   Enter a command: head
//   Your queue is empty and has no head.
//   Your queue contains []
//   Enter a command: enqueue 1
//   Your queue contains [(1)]
//   Enter a command: enqueue 2
//   Your queue contains [(1) 2]
//   Enter a command: enqueue 3
//   Your queue contains [(1) 2 3]
//   Enter a command: head
//   1 is at the head of your queue.
//   Enter a command: dequeue
//   1 was removed from the head of your queue.
//   Your queue contains [(2) 3]
//   Bye!
//   $
//
// The set of commands it accepts is reported by the `help` command
// and is the following:
//
//   enqueue <number>
//   dequeue
//   head
//   help
//   quit
//

#include "Queue.hh"
#include <iostream>
#include <string>
#include <sstream>
#include <vector>

// parseCommand(command):
//
// Takes a string `command` and gives back a vector of strings,
// split into words according to spaces within `command`.
//
std::vector<std::string> parseCommand(std::string command) {
  std::istringstream iss(command);
  std::vector<std::string> words(std::istream_iterator<std::string>{iss},
				 std::istream_iterator<std::string>());  
  return words;
}

// main():
//
// This program tests our queue code, looping by receiving test
// commands. The commands are listed at the top of this page.
//
int main(int argc, char** argv) {

  Queue q { };

  //
  // Loop, processing commands.
  // 
  // Each command line is processed as a C++ `vector` of strings.
  std::string command;
  do {
    //
    // Get a command line from the user.
    std::cout << "Your queue contains ";
    std::cout << q.to_string();
    std::cout << "." << std::endl;
    std::cout << "Enter a command: ";
    getline(std::cin,command);
    std::vector<std::string> commandWords = parseCommand(command);

    // 
    // Process that command and perform it.
    std::string keyword = commandWords[0];
    
    //
    // enqueue <value>
    if (keyword == "enqueue") {

      int what = std::stoi(commandWords[1]);
      q.enqueue(what);

    //
    // dequeue
    } else if (keyword == "dequeue") {
      if (q.is_empty()) {
	std::cout << "Your queue is already empty." << std::endl;
      } else {
	int head = q.dequeue();
	std::cout << head << " was removed from the head of your queue." << std::endl;
      }

    //
    // head
    } else if (keyword == "head") {

      if (q.is_empty()) {
	std::cout << "Your queue is empty and has no head." << std::endl;
      } else {
	int head = q.head();
	std::cout << head << " is at the head of your queue." << std::endl;
      }

    } else if (keyword == "help") {

      //
      // help
      std::cout << "Here are the commands I know:" << std::endl;
      std::cout << "\tenqueue <number>" << std::endl;
      std::cout << "\tdequeue" << std::endl;
      std::cout << "\thead" << std::endl;
      std::cout << "\thelp" << std::endl;
      std::cout << "\tquit" << std::endl;

    } else if (keyword != "quit") {

      // 
      // Bad command.
      std::cout << "I don't know that command." << std::endl;
      std::cout << "Enter \"help\" to see the commands I know." << std::endl;

    }

  } while (command != "quit");

  // 
  // Say goodbye
  std::cout << "Bye!" << std::endl;
}


  
  
