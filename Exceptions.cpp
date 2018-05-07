#include <iostream>
#include "Exceptions.hpp"

IllegalCoordinateException::IllegalCoordinateException(const Coordinates &illegal)
{
    coor = new Coordinates(illegal);
}

string IllegalCoordinateException::theCoordinate() const
{
    return to_string(coor->row) + "," + to_string(coor->col);
}

IllegalCoordinateException::~IllegalCoordinateException()
{
    delete coor;
}

IllegalCharException::IllegalCharException(const char c)
{
    this->illegalchar = c;
}

char IllegalCharException::theChar() const
{
    return this->illegalchar;
}

IllegalCharException::~IllegalCharException()
{
    //
}

