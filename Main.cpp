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
    // printf("\n\n=====================================================\n\n");
    // vector<Coordinate> b = test.get_plotted();
    // for(int i = 0; i < b.size(); i++) {
    //     printf("%s, ", b[i].print_pair());
    // }
    test.print_graph();
}