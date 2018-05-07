#include "IllegalCharException.hpp"

IllegalCharException::IllegalCharException(const char c)
{
    this->illegalchar = c;
}

string IllegalCharException::theChar() const 
{
stringstream ss;
string target;
char mychar = illegalchar;
ss << mychar;
ss >> target;
}
