#include "Quadratic.hpp"

// PRIVATE
// break into x and y
void Quadratic::process_coordinates(Coordinate one, Coordinate two, Coordinate three) {
    this->solve(one.get_x(), one.get_y(), two.get_x(), two.get_y(), three.get_x(), three.get_y());
}

// solve from coords
void Quadratic::solve(double x1, double y1, double x2, double y2, double x3, double y3) {
    double aNum = -1 * (x1 * (y2 - y3) - y1 * (x2 - x3) + x2 * y3 - y2 * x3);
    double aDen = (pow(x1, (double) 2) - x1 * (x2 + x3) + x2 * x3) * (x2 - x3);
    a = aNum / aDen;

    double bNum = pow(x1, (double) 2) * (y2 - y3) - y1 * (x2 + x3) * (x2 - x3) + pow(x2, (double) 2) * y3 - y2 * pow(x3, (double) 2);
    double bDen = (pow(x1, (double) 2) - x1 * (x2 + x3) + x2 * x3) * (x2 - x3);
    b = bNum / bDen;

    double cNum = pow(x1, (double) 2) * (x2 * y3 - y2 * x3) - x1 * (pow(x2, (double) 2) * y3 - y2 * pow(x3, (double) 2)) + y1 * x2 * (x2 - x3) * x3;
    double cDen = (pow(x1, (double) 2) - x1 * (x2 + x3) + x2 * x3) * (x2 - x3);
    c = bNum / cDen;

    if(a < 0 && b < 0 && c < 0) {
        a *= -1;
        b *= -1;
        c *= -1;
    }

    // Adjust for negative 0;
    if(a == 0) {
        a = 0;
    }
    if(b == 0) {
        b = 0;
    }
    if(c == 0) {
        c = 0;
    }
}

// ================ Sets ================
void Quadratic::set_a(double a) {
    this->a = a;
}
void Quadratic::set_b(double b) {
    this->b = b;
}
void Quadratic::set_c(double c) {
    this->c = c;
}

// ================ Gets ================
double Quadratic::get_a() {
    return a;
}
double Quadratic::get_b() {
    return b;
}
double Quadratic::get_c() {
    return c;
}

// ================ Methods ================
bool Quadratic::equals(Quadratic test) {
    if(test.get_a() == a && test.get_b() == b && test.get_c() == c) {
        return true;
    }
    return false;
}

// Returns f(x) from x
double Quadratic::trace(double x) {
    return (a * pow(x, (double) 2)) + (b * x) + c;
}

// returns x from f(x)
double *Quadratic::solve(double y) {
    static double xVals[2];
    if(pow(b, ((double) 2) - 4 * a * c) < 0) {
        return NULL;
    }
    // Solve through quadratic formula
    // Plus
    xVals[0] = (-1 * b + (pow(b, ((double) 2) - 4 * a * c) < 0)) / (2 * a);

    // Minus
    xVals[1] = (-1 * b - (pow(b, ((double) 2) - 4 * a * c) < 0)) / (2 * a);
    return xVals;

}

// ================ Debug ================
string Quadratic::print_equation() {
    return "f(x) = " + to_string(a) + "x^2 + " + to_string(b) + "x + " + to_string(c);
}