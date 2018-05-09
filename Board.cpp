#include "Board.h"
using namespace std;

Board::Board(int boardSize)
{
    size = boardSize;
    board = new Value *[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = new Value[size]; //dynamic allocating new values
    }
}

Board::Board(const Board &b)
{
    size = b.size;
    board = new Value *[size];
    for (int i = 0; i < size; i++)
    {
        board[i] = new Value[size];
        for (int j = 0; j < size; j++)
        {
            board[i][j] = b.board[i][j];
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < size; i++)
    {
        delete board[i];
    }
    delete board;
}

//getter
const int Board::getSize()
{
    return size;
}

// overloading [] // SET
Value &Board::operator[](Coordinates coor)
{
    if (coor.row >= size || coor.row < 0 || coor.col >= size || coor.col < 0)
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Board &Board::operator=(const Board &board)
{
    size = board.size;
    this->board = new Value *[size];
    for (int i = 0; i < size; i++)
    {
        this->board[i] = new Value[size];
        for (int j = 0; j < size; j++)
        {
            this->board[i][j] = board.board[i][j];
        }
    }
    return *this;
}

Board &Board::operator=(char c)
{
    if (c == '.')
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                board[i][j] = '.';
            }
        }
    }
    else
    {
        throw IllegalCharException(c);
    }
    return *this;
}

// overloading <<
ostream &operator<<(ostream &out, Board const &obj)
{
    int objSize = obj.size;
    for (int i = 0; i < objSize; i++)
    {
        for (int j = 0; j < objSize; j++)
        {
            out << obj.board[i][j];
        }
        out << "\n";
    }
    return out;
}
