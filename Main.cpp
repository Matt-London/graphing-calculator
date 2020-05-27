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
    for(int i = -14; i < 30; i++) {
        test.plot((double) i, (double) pow(i, 2));
    }
    test.print_graph();
}