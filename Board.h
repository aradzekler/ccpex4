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
  int size() const;
  Value &operator[](Coordinate);
  Value operator[](Coordinate) const;
  Board &operator=(const Board &);
  Board &operator=(char c);
  friend ostream &operator<<(ostream &out, Board const &b);
};
