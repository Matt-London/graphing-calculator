#ifndef LINEAR_GUARD
#define LINEAR_GUARD

#include <iostream>
#include <string>

#include "Function.hpp"
#include "Coordinate.cpp"

using namespace std;

class Linear : public Function {
    private:
        double m;
        double b;
        char sign;

        Coordinate one;
        Coordinate two;

        // Takes x,y nums
        void solve(double x1, double y1, double x2, double y2);

        // Takes Coords to pull x, y
        void process_coordinates(Coordinate one, Coordinate two);
    
    public:

        // ================ Constructors ================
        // Default
        Linear();

        // m and b
        Linear(double m, double b);

        // Two coords
        Linear(Coordinate a, Coordinate b);

        // ================ Sets ================
        void set_slope(double slope);
        void set_yInt(double yInt);

        // ================ Gets ================
        double get_slope();
        double get_yInt();
        char get_sign();

        // =============== Methods ================
        // Compares m and b
        bool equals(Linear a);

        // Returns f(x) from x
        double trace(double x);

        // returns x from f(x)
        double solve(double y);

        // ================ Debug ===================
        // Print f(x) = mx + b
        string print_equation();

};

#endif