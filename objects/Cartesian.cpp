#include <iostream>
#include <string>

using namespace std;

class Cartesian {
    private:
        int height;
        int width;
        int yScale;
        int xScale;
        int yAxis;
        int xAxis;
        bool axis = true;
        vector<vector<char>> graph;
    
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
        bool plot(Coordinate point) {
            int x = point.get_x();
            int y = point.get_y();
            int xLoc = xAxis + x;
            int yLoc = yAxis - y;
            if((xLoc > width || xLoc < 0) || (yLoc > height || yLoc < 0)) {
                return false;
            }
            graph[yLoc][xLoc] = '*';
            // cout << yLoc << " " << xLoc;
            return true;
        }

        // ================ Sets ================
        void set_height(int h) {
            height = h;
        }
        void set_width(int w) {
            width = w;
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