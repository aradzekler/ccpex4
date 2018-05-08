#pragma once
#include <iostream>
#include "Value.hpp"
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.hpp"

using namespace std;

class Board
{
private:
  Value **board;
  int size;

public:
  Board();
  Board(int boardSize);
  Board(const Board &);
  ~Board();
  const int getSize();
  Value &operator[](Coordinates);
  Board &operator=(const Board &);
  Board &operator=(char c);
  friend ostream &operator<<(ostream &out, Board const &b);
};
