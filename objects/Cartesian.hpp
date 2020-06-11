#ifndef CARTESIAN_GUARD
#define CARTESIAN_GUARD

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

#include "Coordinate.hpp"
#include "Function.hpp"
#include "Linear.hpp"
#include "Quadratic.hpp"


using namespace std;

class Cartesian {
    private:
        int height; // Height of graph in y axis
        int width; // Width of graph in x axis
        int yScale; // drawn units / representative units
        int xScale; // drawn units / representative units
        int yAxis; // Index of the y axis
        int xAxis; // Index of the x axis
        int coordLimit = 100; // Number of coords to plot of each equation
        bool axis = true; // Show axis

        vector<vector<char>> graph;
        vector<Coordinate> plotted; // Lists all coordinates graphed
        vector<Function> functions; // All graphed functions
    
    public:
        // ================ Constructors ================
        // Default
        Cartesian();

        // Takes height and width
        Cartesian(int h, int w);

        // ================ Methods ================
        // Prints graph to terminal
        void print_graph();

        // Check if a Coord is in plotted
        bool in_plotted(Coordinate a);

        // Update graph from plotted coordinates vector
        void update();

        // Rebuild graph size
        void resize();

        // Clear graph
        void reset();

        // Check if point is on a graph
        bool on_graph(Coordinate coord);
        bool on_graph(double x, double y);

        // Plot points
        //  Relative points on graph
        bool plot(double x, double y);
        bool plot(Coordinate point);

        // Exact points on vector
        bool vector_plot(Coordinate point);
        bool vector_plot(double x, double y);
        
        // Plot equations
        void plot(Linear eq);
        void plot(Quadratic eq);

        // ================ Sets ================
        void set_height(int h);
        void set_width(int w);
        void set_axis(bool a);
        void set_coord_limit(int lim);

        // Set y and x axis
        // user entered
        void set_offset(int y, int x);

        void set_offset();

        // program entered
        void set_axes(int y, int x);
        void set_axes();

        // ================ Gets ================
        int get_height();
        int get_width();
        int get_size();
        vector<vector<char>> get_graph();
        vector<Coordinate> get_plotted();

};

#endif