#include <iostream>
#include "game/xo_game.h"

int main() {
  int board[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

  XOGame game;
  game.play();

  return 0;
}
