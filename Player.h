#pragma once
#include "Board.h"
#include "Coordinate.hpp"

class Player{
    public:
        char value;

        virtual const string name() const { return ""; };
        virtual const Coordinate play (const Board& board){ return{0,0}; }
        char getVal() const {return value;}
};
