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
    // a, b, c values for simple cubic functions
    // Graphing y = (1/2)*x^2
    vector<double> v;
    v.push_back(0); // c
    v.push_back(0); // b
    v.push_back(0.25); // a


    Polynomial q(v);
    Cartesian plane(30, 60);
    plane.plot(q);

    q.print_equation();
    plane.print_graph();

    return 0;
}
