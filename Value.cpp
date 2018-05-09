#include "Value.hpp"

Value::Value()
{
    val = '.'; // default as point.
}

Value::Value(char c)
{
    if (c != 'X' && c != 'O' && c != '.')
    {
        throw IllegalCharException(c);
    }
    val = c;
}

Value &Value::operator=(char c)
{
    if (c != 'X' && c != 'O' && c != '.')
    {
        throw IllegalCharException(c);
    }
    val = c;
    return *this;
}

Value &Value::operator=(const Value &c)
{
    val = c.val;
    return *this;
}

Value::operator char()
{
    return val;
}

ostream &operator<<(ostream &out, Value const &obj)
{
    out << obj.val;
    return out;
}

bool operator==(const Value c1, const char c2)
{
    return c1.val == c2;
}
