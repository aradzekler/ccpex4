#include "IllegalCharException.hpp"

IllegalCharException::IllegalCharException(const char c)
{
    this->illegalchar = c;
}

string IllegalCharException::theChar() const
{
    ostringstream out;
    out << illegalchar;
    return out.str();
}
