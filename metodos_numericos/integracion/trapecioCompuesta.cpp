#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

////////////
/// funcion
////////////
double function(double x) {
    return sqrt(1 + pow(cos(x),2));
}

/////////////
// intervalos
/////////////
#define A 0
#define  B M_PI/4

/////////////////
// sub intervalos
////////////////
#define INTERVALS 5

int main() {
    double sum, h, a, b;
    a = A;
    b = B;

    cout << "***********************" << endl;

    sum = function(a) + function(b);
    h = (double) (b - a) / INTERVALS;

    for (int index = 1; index < INTERVALS; index++) {
        sum = sum + 2 * function(a + index * h);
    }
    sum = sum * (h / 2);

    cout << "(trapecio)Resultado de la integral : " << fixed << setprecision(10)<< sum << endl;

    return 0;
}