#include "IllegalCoordinateException.hpp"

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
