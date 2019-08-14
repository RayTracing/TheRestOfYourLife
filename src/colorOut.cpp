#include "vec3.h"
#include <iostream>

using namespace std;

int intensity (double x)
{
    return (x <= 0) ? 0
         : (x >= 1) ? 255
         : int(256.0 * x);
}

const vec3& catchNaN(const vec3& v, const vec3& substitute)
{
    bool hasNaN = std::isnan(v[0]) || std::isnan(v[1]) || std::isnan(v[2]);
    return hasNaN ? substitute : v;
}

void printColor (ostream& out, const vec3& color)
{
    const static auto nanColor = vec3(0, 1, 1);
    auto& colorVec = catchNaN(color, nanColor);

    out << intensity(colorVec[0]) << " "
        << intensity(colorVec[1]) << " "
        << intensity(colorVec[2]);
}


void main ()
{
    double nan = 0.0;
    nan /= nan;

    cout << "( 0.125, 0.250, 0.500): "; printColor(cout, vec3( 0.125, 0.250, 0.500)); cout << "\n";
    cout << "( 0.000, 0.250, 1.000): "; printColor(cout, vec3( 0.000, 0.250, 1.000)); cout << "\n";
    cout << "(-0.125, 0.250, 2.500): "; printColor(cout, vec3(-0.125, 0.250, 2.500)); cout << "\n";
    cout << "(   NaN, 0.250, 0.500): "; printColor(cout, vec3(   nan, 0.250, 0.500)); cout << "\n";
    cout << "( 0.125,   NaN, 0.500): "; printColor(cout, vec3( 0.125,   nan, 0.500)); cout << "\n";
    cout << "( 0.125, 0.250,   NaN): "; printColor(cout, vec3( 0.125, 0.250,   nan)); cout << "\n";
}
