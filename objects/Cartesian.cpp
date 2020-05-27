#include <iostream>
#include <string>

using namespace std;

class Cartesian {
    private:
        int height;
        int width;
        int yScale;
        int xScale;
        char *graph[][] = NULL;
    
    public:
        // ============= Constructors =================
        Cartesian(int h, int w) {
            height = h;
            width = w;
            char g[h][w];
            graph = &g;
        }

}