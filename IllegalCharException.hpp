#pragma once
#include <string>
#include <exception>

using namespace std;

class IllegalCharException : public exception
{
  private:
    char illegalchar;

  public:
    IllegalCharException(char c);
    char theChar() const;
    ~IllegalCharException();
};
