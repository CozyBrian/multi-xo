#include "xo_game.h"
#include <iostream>
#include <ctype.h>

void eraselines(int count) {
    if (count > 0) {
        std::cout << "\x1b[2k"; // delete current line
        // i=1 because we included the first line
        for (int i = 1; i < count; i++) {
            std::cout
            << "\x1b[1a" // move cursor up one
            << "\x1b[2k"; // delete the entire line
        }
        std::cout << "\r"; // resume the cursor at beginning of line
    }
}

XOGame::XOGame() {
  for (int i = 0; i < 9; ++i) {
    this->board[i] = 0;
  }
}

void XOGame::printBoard(int board[]) {
  // system("clear");
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
  char move;
  std::cin >> move;

  std::cout << "Move: " << move << std::endl;

  if (!isdigit(move)) {
    eraselines(1);
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  int moveInt = move - '0';
  if (moveInt < 1 || moveInt > 9) {
    eraselines(1);
    std::cout << "Invalid move" << std::endl;
    return this->getMove();
  }

  if (this->board[moveInt - 1] != 0) {
    eraselines(1);
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