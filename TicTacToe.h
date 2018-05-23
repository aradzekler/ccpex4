#pragma once
#include <iostream>
#include "Board.h"
#include "Player.h"

class TicTacToe
{
  public:
    int size;
    Board* gboard;
    Player* gwinner;

    TicTacToe(int);
    ~TicTacToe();
    Board board() const;
    Player& winner() const;
    void play(Player&, Player&);
    bool check(Coordinate, Board &);
};
