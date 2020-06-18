#ifndef FUNCTION_GUARD
#define FUNCTION_GUARD

class Function {
    protected:
        int type; // Holds degree

    public:
        // ================ Constructors ================
        Function();
        Function(int t);

        // ================ getters ================
        int get_type();

        // ================ Methods ================
        double trace(double x);
        double *solve(double y);
        void print_equation();


};

#endif