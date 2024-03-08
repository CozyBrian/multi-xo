#include "xo_game.h"
#include <iostream>
#include <ctype.h>
#include <ncurses.h>
#include <unistd.h>


XOGame::XOGame() {
  this->turn = 1;
  this->winner = 0;
  for (int i = 0; i < 9; ++i) {
    this->board[i] = 0;
  }
}

void XOGame::printBoard(int board[]) {
    // clear(); // Clear the screen before printing the board
    attron(A_BOLD); // Make the text bold
    int row = 0;
    for (int i = 0; i < 3; ++i) {
        int col = 0;
        for (int j = 0; j < 3; ++j) {
            mvprintw(row, col, " %d ", board[i * 3 + j]);
            if (j < 2) mvprintw(row, col + 3, "|"); // Add vertical lines between cells
            col += 4;
        }
        if (i < 2) mvprintw(row + 1, 0, "-----------"); // Add horizontal lines between rows
        row += 2;
    }
    attroff(A_BOLD); // Turn off the bold text
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
            col += 4;
        }
        if (i < 2) mvprintw(row + 1, 0, "-----------"); // Add horizontal lines between rows
        row += 2;
    }
    refresh(); // Refresh the screen after printing the board
}

void XOGame::getMove() {
  mvprintw(6, 0, "player %d move: ", this->turn);
  refresh();
  bool invalid = false;
  char ch;
  echo();
  ch = getch();
  char command[32];

  if (ch == '!') {
    getstr(command);
    if (strcmp(command, "exit") == 0) {
      endwin(); 
      return exit(0);
    } else {
      mvprintw(7, 0, "Invalid command \"%s\"", command);
      refresh();
      getch();
      return;
    }
  }

  if (!isdigit(ch)) {
    mvprintw(7, 0, "Invalid move \"%c\"", ch);
    refresh();
    getch();
    return;
  }

  int move = ch - '0';

  getch();
  if (move < 1 || move > 9) {
    mvprintw(7, 0, "Invalid move \"%c\"", ch);
    refresh();
    getch();
    return;
  }
  
  if (this->board[move - 1] != 0) {
    mvprintw(7, 0, "Invalid move \"%c\"", ch);
    refresh();
    getch();
    return;
  }
  
  this->board[move - 1] = this->turn;
  if (this->turn == 1) {
    this->turn = 2;
  } else {
    this->turn = 1;
  }
}

void XOGame::checkWinner() {
  for (int i = 0; i < 3; ++i) {
    // Check rows
    if (this->board[i * 3] == this->board[i * 3 + 1] && this->board[i * 3] == this->board[i * 3 + 2] && this->board[i * 3] != 0) {
      this->winner = this->board[i * 3];
      return;
    }
    // Check columns
    if (this->board[i] == this->board[i + 3] && this->board[i] == this->board[i + 6] && this->board[i] != 0) {
      this->winner = this->board[i];
      return;
    }
  }
  // Check diagonals
  if (this->board[0] == this->board[4] && this->board[0] == this->board[8] && this->board[0] != 0) {
    this->winner = this->board[0];
    return;
  }
  if (this->board[2] == this->board[4] && this->board[2] == this->board[6] && this->board[2] != 0) {
    this->winner = this->board[2];
    return;
  }
  
  // Check for draw
  for (int i = 0; i < 9; ++i) {
    if (this->board[i] == 0) {
      return;
    }
  }
  this->winner = 3;

}

void XOGame::printResult() {
  if (this->winner == 1) {
    mvprintw(8, 0, "Player 1 wins!");
  } else if (this->winner == 2) {
    mvprintw(8, 0, "Player 2 wins!");
  } else {
    mvprintw(8, 0, "It's a draw!");
  }
  refresh();
  getch();
}

void XOGame::play() {
  initscr();
  cbreak();
  
  int fps = 0;

  while (this->winner == 0)
  {
    clear();
    this->printBoard(this->board);
    this->getMove();
    this->printBoard(this->board);
    this->checkWinner();
    refresh();
  }
  this->printResult();
  getch();

  endwin();
}