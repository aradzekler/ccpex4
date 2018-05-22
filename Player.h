#pragma once
#include "Board.h"
#include "Coordinates.hpp"

class Player{
    public:
        char value;

        virtual const string name() const;
        virtual const Coordinates play (Board& board);
        char getVal() const {return value;}
};