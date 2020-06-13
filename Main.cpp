#include <iostream>

#include "objects/Function.hpp"
#include "objects/Coordinate.hpp"
#include "objects/Linear.hpp"
#include "objects/Quadratic.hpp"
#include "objects/Cartesian.hpp"
#include "objects/Polynomial.hpp"

using namespace std;

int main() {
    Cartesian test(30, 60);
    Coordinate one(-21, 4);
    Coordinate two(-8.6, 30);
    Coordinate three(28, -29);

    Quadratic q(one, two, three);
    q.print_equation();

    test.plot(q);
    test.print_graph();
}
