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
    Cartesian test(30, 60);
    Coordinate one(-5, 22);
    Coordinate two(2, -5);
    Coordinate three(-25, 1);
    Quadratic lin(0.01, 0, -10);
    test.plot(lin);
    test.print_graph();
}