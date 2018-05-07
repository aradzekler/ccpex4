#pragma once
#include "Coordinates.hpp"
#include <iostream>
#include "Exceptions.hpp"
using namespace std;

class Value{
    public:
        char val;
        Value(char);
        Value();
        friend ostream& operator<<(ostream& os, Value const& obj);
        Value& operator=(char c);
        Value& operator=(const Value& c);
        friend bool operator==(const Value c1 , const char c2);
        operator char();
};