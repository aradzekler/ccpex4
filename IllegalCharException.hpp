#pragma once
#include <string>
#include <sstream>
#include <exception>

using namespace std;

class IllegalCharException : public exception
{
  private:
    char illegalchar;

  public:
    IllegalCharException(const char c);
    string theChar() const;
};
