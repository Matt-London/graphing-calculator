#ifndef POLYNOMIAL_GUARD
#define POLYNOMIAL_GUARD

#include <vector>
#include <cmath>
#include <iostream>

#include "Coordinate.hpp"
#include "Function.hpp"

using namespace std;

class Polynomial : public Function {
    private:
        int degree;
        vector<double> coefficients;

    public:
        // =============== Constructors ===============
        // Default
        Polynomial();

        // Takes vector
        Polynomial(vector<double> coefficients);


        // =============== Getters ===============
        int get_degree();
        vector<double> get_coefficients();


        // =============== Setters ===============
        void set_coefficients(vector<double> coefficients);


        // =============== Methods ===============
        // Takes a double and appends it to the coefficients
        void add_coefficient(double x);

        // Returns f(x) from x
        virtual double trace(double x);

        // Returns x from f(x)
        // double *solve(double y);

        // Prints in format f(x) = ...
        virtual void print_equation();



};

#endif