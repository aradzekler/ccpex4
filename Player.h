#pragma once
#include "Board.h"
#include "Coordinate.hpp"

class Player{
    public:
        char value;

        virtual const string name() const;
        virtual const Coordinate play (Board& board);
        char getVal() const {return value;}
};
