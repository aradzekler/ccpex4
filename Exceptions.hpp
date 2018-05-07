#include <string>
#include <exception>
#include "Coordinates.hpp"

using namespace std;

class IllegalCoordinateException : public exception
{
  public:
    Coordinates *coor;
    IllegalCoordinateException(const Coordinates);
    string theCoordinate() const;
    IllegalCoordinateException(const Coordinates);
    ~IllegalCoordinateException();
};

class IllegalCharException : public exception
{
  public:
    char illegalchar;
    IllegalCharException(char c);
    char theChar() const;
    ~IllegalCharException();
};