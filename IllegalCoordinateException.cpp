#include "IllegalCoordinateException.hpp"

IllegalCoordinateException::IllegalCoordinateException(const Coordinate &illegal)
{
    coor = new Coordinate(illegal);
}

string IllegalCoordinateException::theCoordinate() const
{
    return to_string(coor->row) + "," + to_string(coor->col);
}

IllegalCoordinateException::~IllegalCoordinateException()
{
    delete coor;
}
