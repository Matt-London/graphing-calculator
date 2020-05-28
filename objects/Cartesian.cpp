#include <iostream>
#include <string>

using namespace std;

class Cartesian {
    private:
        int height; // Height of graph in y axis
        int width; // Width of graph in x axis
        int yScale; // drawn units / representative units
        int xScale; // drawn units / representative units
        int yAxis; // Index of the y axis
        int xAxis; // Index of the x axis
        bool axis = true; // Show axis

        vector<vector<char>> graph;
        vector<Coordinate> plotted; // Lists all coordinates graphed
    
    public:
        // ================ Constructors ================
        Cartesian(int h, int w) {
            height = h;
            width = w;

            // Make it odd
            if(height % 2 == 0) {
                height++;
            }
            if(width % 2 == 0) {
                width++;
            }
            graph.resize(height, vector<char>(width));

            yAxis = height / 2;
            xAxis = width / 2;

            // Draw axis
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

        // ================ Methods ================
        void print_graph() {
            for(int i = 0; i < graph.size(); i++) {
                for(int j = 0; j < graph[0].size(); j++) {
                    printf("%c", graph[i][j]);
                }
                printf("\n");
            }
        }

        // Plot points
        //  Relative points on graph
        bool plot(double x, double y) {
            int xLoc = round(xAxis + x);
            int yLoc = round(yAxis - y);
            if((xLoc >= width || xLoc < 0) || (yLoc >= height || yLoc < 0)) {
                return false;
            }
            graph[yLoc][xLoc] = '*';
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
            bool trip = false;
            double m = eq.get_slope();
            double b = eq.get_yInt();

            for(int x = -1 * xAxis; x < xAxis; x++) {
                double y = (m * x) + b;
                plot(x, y);
            }
        }
        void plot(Quadratic eq) {
            double a = eq.get_a();
            double b = eq.get_b();
            double c = eq.get_c();

            for(int x = -1 * xAxis; x < xAxis; x++) {
                double y = (a * pow(x, (double) 2) + (b * x) + c);
                plot(x, y);
            }
        }

        // ================ Sets ================
        void set_height(int h) {
            height = h;
        }
        void set_width(int w) {
            width = w;
        }
        void set_axis(bool a) {
            axis = a;
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

};