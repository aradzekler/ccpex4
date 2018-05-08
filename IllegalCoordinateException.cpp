#include "IllegalCoordinateException.hpp"

IllegalCoordinateException::IllegalCoordinateException(const Coordinates &illegal)
{
    coor = new Coordinates(illegal);
}

string IllegalCoordinateException::theCoordinate() const
{
    //return to_string(coor->row) + "," + to_string(coor->col);
    ostringstream out;
    out << coor->row << "," << coor->col;
    return out.str();
}

IllegalCoordinateException::~IllegalCoordinateException()
{
    delete coor;
}
