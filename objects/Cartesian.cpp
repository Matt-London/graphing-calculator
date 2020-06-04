#include <iostream>
#include <string>
#include <algorithm>

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
        Cartesian() {
            height = 0;
            width = 0;
            set_axes();
            resize();
            reset();
        }
        Cartesian(int h, int w) {
            height = h;
            width = w;

            set_axes();

            // Build graph size
            resize();

            // Draw axis
            reset();
        }

        // ================ Methods ================
        void print_graph() {
            for(int i = 0; i < graph.size(); i++) {
                for(int j = 0; j < graph[0].size(); j++) {
                    printf("%c", graph[i][j]);
                }
                printf("\n");
            }
        }

        // Check if a Coord is in plotted
        bool in_plotted(Coordinate a) {
            for(int i = 0; i < plotted.size(); i++) {
                if(plotted[i].equals(a)) {
                    return true;
                }
            }
            return false;
        }

        // Update graph from plotted coordinates vector
        void update() {
            resize();
            set_axes(yAxis, xAxis);
            reset();
            for(int i = 0; i < plotted.size(); i++) {
                plot(plotted[i]);
            }
        }

        // Rebuild graph size
        void resize() {
            graph.clear();
            // Make it odd
            if(height % 2 == 0) {
                height++;
            }
            if(width % 2 == 0) {
                width++;
            }
            graph.resize(height, vector<char>(width));

        }

        // Clear graph
        void reset() {
            if(axis) {
                for(int i = 0; i < graph.size(); i++) {
                    for(int j = 0; j < graph[0].size(); j++) {
                        if(i == yAxis && j == xAxis) {
                            graph[i][j] = '+';
                        }
                        else if(i == yAxis) {
                            graph[i][j] = '-';
                        }
                        else if(j == xAxis) {
                            graph[i][j] = '|';
                        }
                        else {
                            graph[i][j] = ' ';
                        }
                    }
                }
            }
            else {
                for(int i = 0; i < graph.size(); i++) {
                    for(int j = 0; j < graph[0].size(); j++) {
                        graph[i][j] = ' ';
                    }
                }
            }
        }

        // Check if point is on a graph
        bool on_graph(Coordinate coord) {
            return on_graph(coord.get_x(), coord.get_y());
        }
        bool on_graph(double x, double y) {
            int xLoc = round(xAxis + x);
            int yLoc = round(yAxis - y);
            if((xLoc >= width || xLoc < 0) || (yLoc >= height || yLoc < 0)) {
                return false;
            }
            return true;
        }

        // Plot points
        //  Relative points on graph
        bool plot(double x, double y) {
            Coordinate coord(x, y);
            int xLoc = round(xAxis + x);
            int yLoc = round(yAxis - y);

            if(!in_plotted(coord)) {
                plotted.push_back(coord);
            }

            if(!on_graph(x, y)) {
                return false;
            }

            if(graph[yLoc][xLoc] != '*') {
                graph[yLoc][xLoc] = '*';
            }
            // cout << yLoc << " " << xLoc;
            return true;
        }
        bool plot(Coordinate point) {
            int x = point.get_x();
            int y = point.get_y();
            return plot(x, y);
        }

        // Exact points on vector
        bool vector_plot(Coordinate point) { // Discouraged use
            int x = point.get_x();
            int y = point.get_y();
            return vector_plot(x, y);
        }
        bool vector_plot(double x, double y) {
            if((x >= width || x < 0) || (y >= height || y < 0)) {
                return false;
            }
            graph[y][x];
            return true;
        }
        
        // Plot equations
        void plot(Linear eq) { // Void?
            functions.push_back(eq); // Add to registry
            double m = eq.get_slope();
            double b = eq.get_yInt();

            for(int x = -1 * coordLimit / 2; x < coordLimit / 2; x++) {
                double y = (m * x) + b;
                plot(x, y);
            }
        }
        void plot(Quadratic eq) {
            functions.push_back(eq); // Add to registry
            double a = eq.get_a();
            double b = eq.get_b();
            double c = eq.get_c();

            for(int x = -1 * coordLimit / 2; x < coordLimit / 2; x++) {
                double y = (a * pow(x, (double) 2) + (b * x) + c);
                plot(x, y);
            }
        }

        // ================ Sets ================
        void set_height(int h) {
            height = h;
            set_axes();
            update();
        }
        void set_width(int w) {
            width = w;
            set_axes();
            update();
        }
        void set_axis(bool a) {
            axis = a;
            update();
        }
        void set_coord_limit(int lim) {
            coordLimit = lim;
            update();
        }

        // Set y and x axis
        // user entered
        void set_offset(int y, int x) {
            set_axes(y, x);
            update();
        }

        void set_offset() { // default
            set_axes();
            update();
        }

        // program entered
        void set_axes(int y, int x) {
            yAxis = y;
            xAxis = x;
        }
        void set_axes() {
            yAxis = height / 2;
            xAxis = width / 2;
        }

        // ================ Gets ================
        int get_height() {
            return height;
        }
        int get_width() {
            return width;
        }
        int get_size() {
            return height * width;
        }
        vector<vector<char>> get_graph() {
            return graph;
        }
        vector<Coordinate> get_plotted() {
            return plotted;
        }

};