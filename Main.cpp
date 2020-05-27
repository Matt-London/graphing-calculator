#include <iostream>
#include <string>
#include <cmath>
#include <vector>

#include "objects/Coordinate.cpp"
#include "objects/Linear.cpp"
#include "objects/Quadratic.cpp"
#include "objects/Cartesian.cpp"

using namespace std;

int main() {
    Cartesian test(10, 20);
    Coordinate testc(2, 3);
    test.plot(testc);
    testc.set_coord(0.5, 4);
    test.plot(testc);
    test.print_graph();
}