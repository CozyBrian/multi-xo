#include "xo_game.h"
#include <iostream>
#include <ctype.h>

XOGame::XOGame() {
  for (int i = 0; i < 9; ++i) {
    this->board[i] = 0;
  }
}

void XOGame::printBoard(int board[]) {
  system("clear");
  for (int i = 0; i < 3; ++i) {
    for (int j = 0; j < 3; ++j) {
        std::cout << " " << board[i * 3 + j] << " ";
        if (j < 2) std::cout << "|"; // Add vertical lines between cells
    }
    std::cout << std::endl;
    if (i < 2) std::cout << "-----------" << std::endl; // Add horizontal lines between rows
  }
}

void XOGame::getMove() {
  std::cout << "Player " << this->turn << " move: ";
  std::string input;
  char move;
  std::cin >> input;

  if (input[0] == '!') {
    input.erase(0, 1);
    if (input == "exit") {
      return exit(0);
    } else {
      std::cout << "Invalid command" << std::endl;
      return this->getMove();
    }
  }

  if (input.length() != 1) {
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  move = input[0];


  if (!isdigit(move)) {
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  int moveInt = move - '0';
  if (moveInt < 1 || moveInt > 9) {
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  if (this->board[moveInt - 1] != 0) {
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  this->board[moveInt - 1] = this->turn;
}

void XOGame::play() {
  while (this->winner == 0)
  {
    this->printBoard(this->board);
    this->getMove();
  }
}