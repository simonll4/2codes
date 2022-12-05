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

    sum = 0;
    h = (double) (b - a) / INTERVALS;

    double sum1 = 0;
    double sum2 = 0;
    for (int i = 0; i < INTERVALS; ++i) {
        sum1 = sum1 + h * function(a + i * h);
        sum2 = sum2 + h * (function(a + (i + 1) * h) - function(a + i * h));
    }
    sum = sum1 + sum2 / 2;

    //sum = function(a) + function(b);
    /*for (int index = 1; index < INTERVALS; index++) {
        sum = sum + 2 * function(a + index * h);
    }
    sum = sum * (h / 2);*/

    cout << "(metodo ejercicio 2)Resultado de la integral : " << fixed << setprecision(10) << sum << endl;

    return 0;
}