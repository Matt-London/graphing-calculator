#include "../../include/objects/Function.hpp"

// ================ Constructors ================
// Default
Function::Function() {

}

// Takes type
Function::Function(int t) {
    type = t;
}

// ================ getters ===================
int Function::get_type() {
    return type;
}

// ================ Methods ===================
double Function::trace(double x) {return 0;}
double *Function::solve(double y) {return nullptr;}
void Function::print_equation() {}