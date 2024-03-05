#ifndef XO_GAME_H
#define XO_GAME_H

class XOGame {
  private:
    int board[9];
    int turn = 1;
    int winner = 0;
    void printBoard(int board[]);
    void getMove();
    /* data */
  public:
    XOGame(/* args */);
    void play();

};

#endif