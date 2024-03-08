#ifndef XO_GAME_H
#define XO_GAME_H

class XOGame {
  private:
    int board[9];
    int turn;
    int winner;

    void printBoard(int board[]);
    void printBoard(char board[]);

    void getMove();
    void checkWinner();
    void printResult();
    /* data */
  public:
    XOGame(/* args */);
    void play();

};

#endif