#include "Champion.h"

const Coordinate Champion::play(const Board& board)
{
    if (reverse)
    {
        for (int i = board.size() - 1; i >= 0; --i)
        {
            Coordinate coor{i, board.size() - i - 1};

            if (board[coor] == '.')
            {
                reverse = !reverse;
                return coor;
            }
        }
    }
    else
    {
        for (int i = 0; i < board.size(); ++i)
        {
            Coordinate coor{i, board.size() - i - 1};

            if (board[coor] == '.')
            {
                reverse = !reverse;
                return coor;
            }
        }
    }
    return {0, 0};
}
