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
    Cartesian test;
    Quadratic q(1, 0, 0);
    Linear l(1, 0);

    test.plot(q);
    test.plot(l);
    test.set_height(30);
    test.set_width(60);

    test.print_graph();
}