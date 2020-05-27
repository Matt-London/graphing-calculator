#include <iostream>
#include <string>

using namespace std;

class Coordinate {
    private:
        double x;
        double y;

    public:
    
        // ================ Constructors ================
        Coordinate(double x, double y) {
            this->x = x;
            this->y = y;
        }
        Coordinate() {
            x = 0;
            y = 0;
        }

        // ================ Sets ================
        void set_x(double x) {
            this->x = x;
        }
        void set_y(double y) {
            this->y = y;
        }
        void set_coord(double x, double y) {
            this->x = x;
            this->y = y;
        }

        // ================ Gets ================
        double get_x() {
            return x;
        }
        double get_y() {
            return y;
        }

        // ============ Methods ===============
        bool equals(Coordinate b) {
            if(this->x == b.get_x() && this->x == b.get_y()) {
                return true;
            }
            return false;
        }

        // ================ Debug ================
        string print_pair() {
            return "(" + to_string(x) + ", " + to_string(y) + ")";
        }
};



