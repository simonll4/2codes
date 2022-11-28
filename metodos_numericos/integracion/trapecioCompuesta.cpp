#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

///////////////////////////////////
/// funcion
///////////////////////////////////
double function(double x) {
    return 3 * pow(x, 2) + 1;
}

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 1

///////////////////
/// sub intervalos
//////////////////
#define INTERVALS 10

int main() {
    double sum, h, a, b;
    a = A;
    b = B;

    cout << "***********************" << endl;
    h = (double) (b - a) / INTERVALS;
    sum = function(a) + function(b);
    for (int index = 1; index < INTERVALS; index++) {
        sum = sum + 2 * function(a + index * h);
    }
    sum = sum * (h / 2);

    cout << "(trapecio)Resultado de la integral : " << fixed << setprecision(10) << sum << endl;

    return 0;
}