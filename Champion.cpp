#include "Champion.h"

const Coordinates Champion::play(Board &board)
{
    if (reverse)
    {
        for (int x = board.getSize() - 1; x >= 0; --x)
        {
            Coordinates coor{x, board.getSize() - x - 1};
            if (board[coor] == '.')
            {
                reverse = !reverse;
                return coor;
            }
        }
    }
    else
    {
        for (int x = 0; x < board.getSize(); ++x)
        {
            Coordinates coor{x, board.getSize() - x - 1};
            if (board[coor] == '.')
            {
                reverse = !reverse;
                return coor;
            }
        }
    }
    return {0, 0};
}