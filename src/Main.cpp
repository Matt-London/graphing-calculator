#include <iostream>
#include <vector>

#include "../include/objects/Function.hpp"
#include "../include/objects/Coordinate.hpp"
#include "../include/objects/Linear.hpp"
#include "../include/objects/Quadratic.hpp"
#include "../include/objects/Cartesian.hpp"
#include "../include/objects/Polynomial.hpp"

using namespace std;

int main() {
    Quadratic q(1, 0, 0);
    Cartesian plane(30, 60);
    plane.plot(q);

    q.print_equation();
    plane.print_graph();

    return 0;
}
