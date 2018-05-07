#include "IllegalCharException.hpp"

IllegalCharException::IllegalCharException(const char c)
{
    this->illegalchar = c;
}

string IllegalCharException::theChar() const 
{
    return to_string(illegalchar);
}
