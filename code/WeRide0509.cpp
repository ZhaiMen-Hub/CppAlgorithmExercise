// find one root of the equation x^5 = x+1, use the newton's method

#include <iostream>
#include <cmath>

using namespace std;

double f(double x) {
    return pow(x, 5) - x - 1;
}

double df(double x) {
    return 5 * pow(x, 4) - 1;
}

double newton(double x0, double epsilon) {
    double x = x0;
    while (fabs(f(x)) > epsilon) {
        x = x - f(x) / df(x);
    }
    return x;
}

int main() {
    double x0 = 1.0;  // initial guess
    double epsilon = 1e-10;  // tolerance

    double root = newton(x0, epsilon);
    cout << "The root is: " << root << endl;

    return 0;
}

// // find a root of the equation lnx+x^2 =0, use the newton's method

// #include <iostream>
// #include <cmath>

// using namespace std;

// double f(double x) {
//     return log(x) + pow(x, 2);
// }

// double df(double x) {
//     return 1.0 / x + 2 * x;
// }

// double newton(double x0, double epsilon) {
//     double x = x0;
//     while (fabs(f(x)) > epsilon) {
//         x = x - f(x) / df(x);
//     }
//     return x;
// }

// int main() {
//     double x0 = 1.0;  // initial guess
//     double epsilon = 1e-10;  // tolerance

//     double root = newton(x0, epsilon);
//     cout << "The root is: " << root << endl;

//     return 0;
// }