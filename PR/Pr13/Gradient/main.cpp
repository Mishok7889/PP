//#include "print_compiler.hpp"
#include "gradient.h"
#include <iostream>
#include <fstream>
using namespace std;

ofstream out("output.txt");

int main()
{

    double x = -6, y = 1;
    double h = 0.05;
    double eps = 0.001;

    // Built in functions
    gradient_descent_f(&x, &y, h, eps);
    cout << "Found local minimum at (" << x << ", " << y << ")\n";
    
    // Polysemy functions, pointer parameters
    gradient_descent(&x, &y, h, eps, &f, &gx, &gy);
    cout << "Found local minimum at (" << x << ", " << y << ")\n";

    // Polysemy functions, reference parameters
    cout << "Found local minimum at (" << x << ", " << y << ")\n";
    gradient_descent(x, y, h, eps, &f, &gx, &gy);

    // Lambda functions, reference parameters
    gradient_descent(x, y, h, eps,
        [](double x, double y) {return x * x + 3 * sin(y); },
        [](double x, double y) {return 2 * x; },
        [](double x, double y) {return 3 * cos(y); });
    cout << "Found local minimum at (" << x << ", " << y << ")\n";

    // Universal solution R2
    R2 u{ -6,1 };
    cout << gradient_descent(u, h, eps,
        [](R2 u)->double {return u.x() * u.x() + 3 * sin(u.y()); },
        [](R2 u)->R2 {return{ 2 * u.x(), 3 * cos(u.y()) }; })
        << endl;
    {
        R2 u{ 1,1 };
        cout << gradient_descent(u, h, eps,
            [](R2 u)->double {return u.x() * u.x() + u.y()*u.y(); },
            [](R2 u)->R2 {return{ 2 * u.x(), 2*u.y() }; })
            << endl;
    }
    // Universal solution R3
    {
    R3 u{ -6,1,0 };
    cout << gradient_descent(u, h, eps,
        [](R3 u)->double {return u.x() * u.x() + 3 * sin(u.y()+2*u.z()); },
        [](R3 u)->R3{return{ 2 * u.x(), 3 * cos(u.y()), 2 }; })
        << endl;
    }
    return 0;
}
