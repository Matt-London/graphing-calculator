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
        virtual double trace(double x);
        virtual double *solve(double y);
        virtual void print_equation();


};

#endif