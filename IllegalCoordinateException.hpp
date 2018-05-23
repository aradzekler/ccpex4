#pragma once
#include <string>
#include <exception>
#include "Coordinate.hpp"

using namespace std;

class IllegalCoordinateException : public exception
{
private:
  Coordinate *coor;

public:
  IllegalCoordinateException(const Coordinate &);
  string theCoordinate() const;
  ~IllegalCoordinateException();
};
