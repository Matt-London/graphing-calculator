#include <iostream>

#include "objects/Function.hpp"
#include "objects/Coordinate.hpp"
#include "objects/Linear.hpp"
#include "objects/Quadratic.hpp"
#include "objects/Cartesian.hpp"
#include "objects/Polynomial.hpp"

using namespace std;

int main() {
    Cartesian test;
    Quadratic q(1, 30, 215);
    Linear l(1, -8);

    test.plot(q);
    test.plot(l);
    test.set_height(30);
    test.set_width(60);
    test.print_graph();
}
