#include "xo_game.h"
#include <iostream>
#include <ctype.h>
#include <ncurses.h>

XOGame::XOGame() {
  for (int i = 0; i < 9; ++i) {
    this->board[i] = 0;
  }
}

void XOGame::printBoard(int board[]) {
    clear(); // Clear the screen before printing the board
    int row = 0;
    for (int i = 0; i < 3; ++i) {
        int col = 0;
        for (int j = 0; j < 3; ++j) {
            mvprintw(row, col, " %d ", board[i * 3 + j]);
            if (j < 2) mvprintw(row, col + 3, "|"); // Add vertical lines between cells
            col += 5;
        }
        if (i < 2) mvprintw(row + 1, 0, "-----------"); // Add horizontal lines between rows
        row += 2;
    }
    refresh(); // Refresh the screen after printing the board
}

void XOGame::printBoard(char board[]) {
    clear(); // Clear the screen before printing the board
    int row = 0;
    for (int i = 0; i < 3; ++i) {
        int col = 0;
        for (int j = 0; j < 3; ++j) {
            mvprintw(row, col, " %c ", board[i * 3 + j]);
            if (j < 2) mvprintw(row, col + 3, "|"); // Add vertical lines between cells
            col += 5;
        }
        if (i < 2) mvprintw(row + 1, 0, "-----------"); // Add horizontal lines between rows
        row += 2;
    }
    refresh(); // Refresh the screen after printing the board
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
  initscr();

  // while (this->winner == 0)
  // {
    this->printBoard(this->board);
    // this->getMove();
  // }
  getch();

  endwin();
}