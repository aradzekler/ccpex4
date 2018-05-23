#include "TicTacToe.h"

TicTacToe::TicTacToe(int size)
{
    gboard = new Board(size);
    this->size = size;
}

TicTacToe::~TicTacToe()
{
    delete gboard;
}

Board TicTacToe::board() const
{
    return *gboard;
}

Player& TicTacToe::winner() const
{
    return *gwinner;
}

void TicTacToe::play(Player &xPlayer, Player &oPlayer)
{
    *gboard = '.';
    Coordinates tempc;
    gwinner = &oPlayer;

    xPlayer.value = 'X';
    oPlayer.value = 'O';
    
    int i = 0;
    while (i < size * size)
    {
        try
        {
            tempc = xPlayer.play(*gboard);
            if ((*gboard)[tempc] != '.')
            {
                gwinner = &oPlayer;
                break;
            }
            (*gboard)[tempc] = 'X';
            if (check(tempc, (*gboard)))
            {
                gwinner = &xPlayer;
                break;
            }
            i++;
        }
        catch (...)
        {
            gwinner = &oPlayer;
            break;
        }
        if (i != size * size)
        {
            try
            {
                tempc = oPlayer.play(*gboard);
                if ((*gboard)[tempc] != '.')
                {
                    gwinner = &xPlayer;
                    break;
                }
                (*gboard)[tempc] = 'O';
                if (check(tempc, (*gboard)))
                {
                    gwinner = &oPlayer;
                    break;
                }
                i++;
            }
            catch (...)
            {
                gwinner = &xPlayer;
                break;
            }
        }
    }
}

bool TicTacToe::check(Coordinates coor, Board &board)
{
    char symb = board[coor];
    for (int i = 0; i < size; i++)
    {
        if (board[{coor.row, i}] != symb)
            break;
        else if (i == size - 1)
            return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (board[{i, coor.col}] != symb)
            break;
        else if (i == size - 1)
            return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (board[{i, i}] != symb)
            break;
        else if (i == size - 1)
            return true;
    }
    for (int i = 0; i < size; i++)
    {
        if (board[{i, size - i - 1}] != symb)
            break;
        if (i == size - 1)
            return true;
    }
    return false;
}