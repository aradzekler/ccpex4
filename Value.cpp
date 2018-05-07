#include "Value.hpp"

Value::Value(char c)
{
    val = c;
}

Value::Value()
{
    val = '.';
}

Value &Value::operator=(char c)
{
    if (c != 'X' && c != 'O' && c != '.')
        throw IllegalCharException(c);
    val = c;
    return *this;
}

Value &Value::operator=(const Value &c)
{
    val = c.val;
    return *this;
}

bool operator==(const Value c1, const char c2)
{
    return c1.val == c2;
}

Value::operator char()
{
    return val;
}

ostream &operator<<(ostream &os, Value const &obj)
{
    os << obj.val;
    return os;
}
