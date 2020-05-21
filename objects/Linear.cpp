#include <iostream>
#include <string>

using namespace std;

class Linear {
    private:
        double m;
        double b;
        char sign;

        Coordinate one;
        Coordinate two;

        void solve(double x1, double y1, double x2, double y2) {
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

        void process_coordinates(Coordinate one, Coordinate two) {
            this->solve(one.get_x(), one.get_y(), two.get_x(), two.get_y());
        }
    
    public:

        //Constructors
        Linear() {
            m = 0;
            b = 0;
            sign = '+';
        }
        Linear(double m, double b) {
            this->m = m;
            this->b = b;
            if(b >= 0) {
                sign = '+';
            }
            else {
                sign = '-';
            }
        }
        Linear(Coordinate a, Coordinate b) {
            one = a;
            two = b;
            this->process_coordinates(a, b);
        }

        // Sets
        void set_slope(double slope) {
            m = slope;
        }
        void set_yInt(double yInt) {
            b = yInt;
            if(yInt >= 0) {
                sign = '+';
            }
            else {
                sign = '-';
            }
        }

        // Gets
        double get_slope() {
            return m;
        }
        double get_yInt() {
            return b;
        }
        char get_sign() {
            return sign;
        }

        // Debug
        string print_equation() {
            return "f(x) = " + to_string(m) + "x " + sign + " " + to_string(b);
        }

};