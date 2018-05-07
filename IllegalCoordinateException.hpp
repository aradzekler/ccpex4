#pragma once
#include <string>
#include <exception>
#include "Coordinates.hpp"

using namespace std;

class IllegalCoordinateException : public exception
{
  private:
    Coordinates *coor;

  public:
    IllegalCoordinateException(const Coordinates &);
    string theCoordinate() const;
    ~IllegalCoordinateException();
};
