#include <iostream>
#include <fstream>
using namespace std;

struct Color
{
    uint8_t red, green, blue;

  public:
    Color() {}
    Color(uint8_t red, uint8_t green, uint8_t blue) : red(red), green(green), blue(blue) {}
};
