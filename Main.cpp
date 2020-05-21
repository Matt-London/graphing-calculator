#include <iostream>
#include <string>
#include <cmath>

#include "objects/Coordinate.cpp"
#include "objects/Linear.cpp"
#include "objects/Quadratic.cpp"

using namespace std;

int main() {
    Coordinate a(0, 0);
    Coordinate b(1, 1);
    Coordinate c(-1, 1);

    Quadratic eq(a, b, c);
    cout << eq.print_equation() << "\n";
}