#include <iostream>
#include <exception>
#include "Board.hpp"
#include "Exceptions.hpp"
#include "Coordinates.hpp"
using namespace std;

Board::Board(int boardSize)
{
    this->size = boardSize;
    Value **temp = new Value *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = new Value[size];
    }
    board = temp;
}

Board::Board(const Board &b)
{
    this->size = b.size;
    Value **temp = new Value *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = new Value[this->size];
        for (int j = 0; j < this->size; j++)
        {
            temp[i][j] = b.board[i][j];
        }
    }
    board = temp;
}

Board::~Board()
{
    for (int i = 0; i < this->size; i++)
    {
        delete board[i];
    }
    delete board;
}

// overloading [] // SET
Value &Board::operator[](Coordinates coor)
{
    if ((coor.row * this->size + coor.col) < 0 || size * size <= (coor.row * this->size + coor.col))
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

// GET
Value Board::operator[](Coordinates coor) const
{
    if ((coor.row * this->size + coor.col) < 0 || size * size <= (coor.row * this->size + coor.col))
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Board &Board::operator=(const Board &board)
{
    this->size = board.size;
    Value **temp = new Value *[this->size];
    for (int i = 0; i < this->size; i++)
    {
        temp[i] = new Value[this->size];
        for (int j = 0; j < this->size; j++)
        {
            temp[i][j] = board.board[i][j];
        }
    }
    board = temp;
    return *this;
}

Board &Board::operator=(char c)
{
    if (c == '.')
    {
        for (int i = 0; i < this->size; i++)
        {
            for (int j = 0; j < this->size; j++)
            {
                board[i][j] = '.';
            }
        }
    }
    else
        throw IllegalCharException(c);
    return *this;
}

// overloading <<
ostream &operator<<(ostream &out, Board &board)
{
    for (int i = 0; i < board.size; i++)
    {
        for (int j = 0; j < board.size; j++)
        {
            out << board.board[i][j];
        }
        out << "\n";
    }
    return out;
}
