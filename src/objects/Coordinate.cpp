#include "../../include/objects/Coordinate.hpp"

// ================ Constructors ================
// x and y
Coordinate::Coordinate(double x, double y) {
    this->x = x;
    this->y = y;
}
// Default
Coordinate::Coordinate() {
    x = 0;
    y = 0;
}

// ============ Methods ===============
bool Coordinate::equals(Coordinate b) {
    if(this->x == b.get_x() && this->y == b.get_y()) {
        return true;
    }
    return false;
}

// ================ Sets ================
void Coordinate::set_x(double x) {
    this->x = x;
}
void Coordinate::set_y(double y) {
    this->y = y;
}
void Coordinate::set_coord(double x, double y) {
    this->x = x;
    this->y = y;
}

// ================ Gets ================
double Coordinate::get_x() {
    return x;
}
double Coordinate::get_y() {
    return y;
}

// ================ Debug ================
string Coordinate::print_pair() {
    return "(" + to_string(x) + ", " + to_string(y) + ")";
}