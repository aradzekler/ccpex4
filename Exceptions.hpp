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
    IllegalCoordinateException(const Coordinates);
    ~IllegalCoordinateException();
};

class IllegalCharException : public exception
{
  private:
    char illegalchar;

  public:
    IllegalCharException(char c);
    char theChar() const;
    ~IllegalCharException();
};
