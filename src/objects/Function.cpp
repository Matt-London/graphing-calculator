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
