#include "../../include/objects/Linear.hpp"

// PRIVATE
// Takes x,y nums
void Linear::solve(double x1, double y1, double x2, double y2) {
    double slope = (y2 - y1) / (x2 - x1);
    double yInt = y1 - (slope * x1);
    m = slope;
    b = yInt;
    if(b >= 0) {
        sign = '+';
    }
    else {
        sign = '-';
    }
}

// Takes Coords to pull x, y
void Linear::process_coordinates(Coordinate one, Coordinate two) {
    this->solve(one.get_x(), one.get_y(), two.get_x(), two.get_y());
}


// PUBLIC
// ================ Constructors ================
// Default
Linear::Linear() {
    m = 0;
    b = 0;
    sign = '+';
}

// m and b
Linear::Linear(double m, double b) {
    this->m = m;
    this->b = b;
    if(b >= 0) {
        sign = '+';
    }
    else {
        sign = '-';
    }
}

// Two coords
Linear::Linear(Coordinate a, Coordinate b) {
    one = a;
    two = b;
    this->process_coordinates(a, b);
}

// ================ Sets ================
void Linear::set_slope(double slope) {
    m = slope;
}
void Linear::set_yInt(double yInt) {
    b = yInt;
    if(yInt >= 0) {
        sign = '+';
    }
    else {
        sign = '-';
    }
}

// ================ Gets ================
double Linear::get_slope() {
    return m;
}
double Linear::get_yInt() {
    return b;
}
char Linear::get_sign() {
    return sign;
}

// =============== Methods ================
// By m and b
bool Linear::equals(Linear a) {
    if(m == a.get_slope() && b == a.get_yInt()) {
        return true;
    }
    return false;
}

// Returns f(x) from x
double Linear::trace(double x) {
    return (m * x) + b;
}

// returns x from f(x)
double *Linear::solve(double y) {
    static double x[1];
    x[0] = (y - b) / m;
    return x;
}

// ================ Debug ===================
// Print f(x) = mx + b
string Linear::print_equation() {
    return "f(x) = " + to_string(m) + "x " + sign + " " + to_string(b);
}