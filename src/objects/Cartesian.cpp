#include "../../include/objects/Cartesian.hpp"


// ================ Constructors ================
// Default
Cartesian::Cartesian() {
    height = 0;
    width = 0;
    set_axes();
    resize();
    reset();
}

// Takes height and width
Cartesian::Cartesian(int h, int w) {
    height = h;
    width = w;

    set_axes();

    // Build graph size
    resize();

    // Draw axis
    reset();
}

// ================ Methods ================
// Prints graph to terminal
void Cartesian::print_graph() {
    for(int i = 0; i < graph.size(); i++) {
        for(int j = 0; j < graph[0].size(); j++) {
            printf("%c", graph[i][j]);
        }
        printf("\n");
    }
}

// Check if a Coord is in plotted
bool Cartesian::in_plotted(Coordinate a) {
    for(int i = 0; i < plotted.size(); i++) {
        if(plotted[i].equals(a)) {
            return true;
        }
    }
    return false;
}

// Update graph from plotted coordinates vector
void Cartesian::update() {
    resize();
    set_axes(yAxis, xAxis);
    reset();
    for(int i = 0; i < plotted.size(); i++) {
        plot(plotted[i]);
    }
}

// Rebuild graph size
void Cartesian::resize() {
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
void Cartesian::reset() {
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
bool Cartesian::on_graph(Coordinate coord) {
    return on_graph(coord.get_x(), coord.get_y());
}
bool Cartesian::on_graph(double x, double y) {
    int xLoc = round(xAxis + x);
    int yLoc = round(yAxis - y);
    if((xLoc >= width || xLoc < 0) || (yLoc >= height || yLoc < 0)) {
        return false;
    }
    return true;
}

// Plot points
//  Relative points on graph
bool Cartesian::plot(double x, double y) {
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
bool Cartesian::plot(Coordinate point) {
    int x = point.get_x();
    int y = point.get_y();
    return plot(x, y);
}

// Exact points on vector
bool Cartesian::vector_plot(Coordinate point) { // Discouraged use
    int x = point.get_x();
    int y = point.get_y();
    return vector_plot(x, y);
}
bool Cartesian::vector_plot(double x, double y) {
    if((x >= width || x < 0) || (y >= height || y < 0)) {
        return false;
    }
    graph[y][x];
    return true;
}

// Plot equations
void Cartesian::plot(Function &eq) {
    for(int x = -1 * coordLimit / 2; x < coordLimit / 2; x++) {
        double y = eq.trace(x);
        plot(x, y);
    }
}

// ================ Sets ================
void Cartesian::set_height(int h) {
    height = h;
    set_axes();
    update();
}
void Cartesian::set_width(int w) {
    width = w;
    set_axes();
    update();
}
void Cartesian::set_axis(bool a) {
    axis = a;
    update();
}
void Cartesian::set_coord_limit(int lim) {
    coordLimit = lim;
    update();
}

// Set y and x axis
// user entered
void Cartesian::set_offset(int y, int x) {
    set_axes(y, x);
    update();
}

void Cartesian::set_offset() { // default
    set_axes();
    update();
}

// program entered
void Cartesian::set_axes(int y, int x) {
    yAxis = y;
    xAxis = x;
}
void Cartesian::set_axes() {
    yAxis = height / 2;
    xAxis = width / 2;
}

// ================ Gets ================
int Cartesian::get_height() {
    return height;
}
int Cartesian::get_width() {
    return width;
}
int Cartesian::get_size() {
    return height * width;
}
vector<vector<char>> Cartesian::get_graph() {
    return graph;
}
vector<Coordinate> Cartesian::get_plotted() {
    return plotted;
}