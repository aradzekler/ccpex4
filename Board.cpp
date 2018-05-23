#include "Board.h"
using namespace std;

Board::Board(int boardSize)
{
    bsize = boardSize;
    board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        board[i] = new Value[bsize]; //dynamic allocating new values
    }
}

Board::Board(const Board &b)
{
    bsize = b.size;
    board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        board[i] = new Value[bsize];
        for (int j = 0; j < bsize; j++)
        {
            board[i][j] = b.board[i][j];
        }
    }
}

Board::~Board()
{
    for (int i = 0; i < bsize; i++)
    {
        delete board[i];
    }
    delete board;
}

//getter
int Board::size() const
{
    return bsize;
}

// overloading [] // SET
Value &Board::operator[](Coordinate coor)
{
    if (coor.row >= bsize || coor.row < 0 || coor.col >= bsize || coor.col < 0)
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Value Board::operator[](Coordinate coor) const
{
    if (coor.row >= bsize || coor.row < 0 || coor.col >= bsize || coor.col < 0)
    {
        throw IllegalCoordinateException(coor);
    }
    return board[coor.row][coor.col];
}

Board &Board::operator=(const Board &board)
{
    bsize = board.bsize;
    this->board = new Value *[bsize];
    for (int i = 0; i < bsize; i++)
    {
        this->board[i] = new Value[bsize];
        for (int j = 0; j < bsize; j++)
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
        for (int i = 0; i < bsize; i++)
        {
            for (int j = 0; j < bsize; j++)
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
    int objSize = obj.bsize;
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
