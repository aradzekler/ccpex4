#include <iostream>
#include "Value.hpp"
using namespace std;

class Board
{
  public:
    int size;
    Value **board;
    Board();
    Board(int boardSize);
    Board(const Board &);
    ~Board();
    //Value getValue(int row, int col);
    Value &operator[](Coordinates);
    Value operator[](Coordinates) const;
    Board &operator=(const Board &);
    Board &operator=(char c);
    friend ostream &operator<<(ostream &out, Board &b);
};

class Coordinates
{
  public:
    int row;
    int col;
};
