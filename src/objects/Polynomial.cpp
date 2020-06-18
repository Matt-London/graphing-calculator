#include "../../include/objects/Polynomial.hpp"

// =============== Constructors ===============
// Default
Polynomial::Polynomial() {
    degree = 0;
}

// Takes vector
Polynomial::Polynomial(vector<double> coefficients) {
    set_coefficients(coefficients);
}


// =============== Getters ===============
int Polynomial::get_degree() {
    return degree;
}

vector<double> Polynomial::get_coefficients() {
    return coefficients;
}


// =============== Setters ===============
void Polynomial::set_coefficients(vector<double> coefficients) {
    degree = 0;
    this->coefficients = coefficients;
    degree = coefficients.size();
}


// =============== Methods ===============
// Takes a double and appends it to the coefficients
void Polynomial::add_coefficient(double x) {
    coefficients.push_back(x);
    degree++;
}

// Returns f(x) from x
double Polynomial::trace(double x) {
    double yVal = 0;
    for(int i = 0; i < coefficients.size(); i++) {
        yVal += coefficients[i] * pow(x, i);
    }
    return yVal;
}

// Returns x from f(x)
// double *Polynomial::solve(double y);

// Prints in format f(x) = ...
void Polynomial::print_equation() {
    printf("f(x) = ");
    for(int i = coefficients.size() - 1; i >= 0; i--) {
        printf("+ %.2lfx^%d ", coefficients[i], i);
    }
    printf("\n");

    /* For the future
    printf("f(x) = ");

    for(int i = coefficients.size() - 1; i >= 0; i--) {
        if(coefficients[i] != 0 && coefficients[i] != 1) {
            if(i == coefficients.size() - 1) {
                if(coefficients[i] < 0) {
                    printf("-%.2lfx^%d ", coefficients[i], i);
                }
                else {
                    printf("%.2lfx^%d ", coefficients[i], i);
                }
            }
            else if(i == 1) {
                if(coefficients[i] > 0) {
                    printf("+ %.2lfx ", coefficients[i]);
                }
                else {
                    printf("- %.2lfx ", coefficients[i]);
                }
            }
            else if(i == 0) {
                if(coefficients[i] > 0) {
                    printf("+ %.2lf", coefficients[i]);
                }
                else {
                    printf("- %.2lf", coefficients[i]);
                }
            }
            else {
                if(coefficients[i] < 0) {
                    printf("- %.2lfx^%d ", coefficients[i], i);
                }
                else {
                    printf("+ %.2lfx^%d ", coefficients[i], i);
                }
            }
        }
        else if(coefficients[i] == 1) {
            if(i == coefficients.size() - 1) {
                if(coefficients[i] < 0) {
                    printf("-x^%d ", coefficients[i], i);
                }
                else {
                    printf("x^%d ", coefficients[i], i);
                }
            }
            else {
                if(coefficients[i] < 0) {
                        printf("- x^%d ", coefficients[i], i);
                }
                else {
                    printf("+ x^%d ", coefficients[i], i);
                }
            }
        }
    }
    printf("\n");
    */
}