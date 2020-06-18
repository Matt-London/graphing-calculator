#ifndef COORDINATE_GUARD
#define COORDINATE_GUARD

#include <iostream>
#include <string>

using namespace std;

class Coordinate {
    private:
        double x;
        double y;

    public:
    
        // ================ Constructors ================
        Coordinate(double x, double y);
        Coordinate();

        // ================ Sets ================
        void set_x(double x);
        void set_y(double y);
        void set_coord(double x, double y);

        // ================ Gets ================
        double get_x();
        double get_y();

        // ============ Methods ===============
        bool equals(Coordinate b);

        // ================ Debug ================
        string print_pair();
};

#endif