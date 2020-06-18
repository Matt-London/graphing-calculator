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
    vector<double> t;
    t.push_back(0);
    t.push_back(0);
    t.push_back(0);
    t.push_back(-0.25);

    Polynomial p(t);
    Cartesian plane(30, 60);
    plane.plot(p);

    p.print_equation();
    plane.print_graph();

    return 0;
}
