#pragma once
#include <iostream>
#include <fstream>
#include "Value.hpp"
#include "IllegalCoordinateException.hpp"
#include "IllegalCharException.hpp"
#include "Color.hpp"

using namespace std;

class Board
{
private:
  Value **board;
  int bsize;

public:
  string fname;
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
  friend istream &operator>>(istream &in, Board &);
  string draw(int size);
  void drawboard(Color **image, int size);
  void drawX(Color **image, int size, int k, int j);
  void drawO(Color **image, int size, int k, int j);
};
