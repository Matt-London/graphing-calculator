#ifndef QUADRATIC_GUARD
#define QUADRATIC_GUARD

#include <iostream>
#include <string>
#include <cmath>

#include "Coordinate.hpp"
#include "Function.hpp"

using namespace std;

class Quadratic : public Function {
    private:
        double a;
        double b;
        double c;

        Coordinate one;
        Coordinate two;
        Coordinate three;

        // break into x and y
        void process_coordinates(Coordinate one, Coordinate two, Coordinate three);

        // solve from coords
        void solve(double x1, double y1, double x2, double y2, double x3, double y3);


    public:
        // ================ Constructors ================
        Quadratic();

        Quadratic(double a, double b, double c);

        Quadratic(Coordinate one, Coordinate two, Coordinate three);

        // ================ Sets ================
        void set_a(double a);
        void set_b(double b);
        void set_c(double c);

        // ================ Gets ================
        double get_a();
        double get_b();
        double get_c();

        // ================ Methods ================
        bool equals(Quadratic test);

        // Returns f(x) from x
        double trace(double x);

        // returns x from f(x)
        double *solve(double y);

        // ================ Debug ================
        void print_equation();

};


#endif