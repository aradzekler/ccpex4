#include <iostream>
#include "IllegalCharException.hpp"


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