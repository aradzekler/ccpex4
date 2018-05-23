#pragma once
#include <iostream>
#include "Coordinate.hpp"
#include "IllegalCharException.hpp"

using namespace std;

class Value{
    public:
        char val;
        Value(char c);
        Value();
        friend ostream& operator<<(ostream& out, Value const& obj);
        Value& operator=(char c);
        Value& operator=(const Value& c);
        friend bool operator==(const Value c1 , const char c2);
        operator char();
};
