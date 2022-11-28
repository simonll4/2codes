#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

///////////////////////////////////
/// funcion
///////////////////////////////////
double function(double x) {
    return (6*pow(x,2))+1;
}

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0

///////////////////
/// sub intervalos
//////////////////
#define INTERVALS 5

int main() {
    double sum, h, a, b;
    double array[] = {0,0.4,0.8,1.2,1.6,2};
    double arrayF[100] = {0};
    a = A;

    arrayF[0] = 0;

    for (int j = 0; j < INTERVALS; j++) {
        b = array[j+1];
        h = (double) (b - a) / INTERVALS;
        sum = function(a) + function(b);
        for (int index = 1; index < INTERVALS; index++) {
            sum = sum + 2 * function(a + index * h);
        }
        sum = sum * (h / 2);
        arrayF[j+1]=sum;
    }


    double sum1 = 0;
    double bNuevo = 2;
    double hNuevo;
    hNuevo=(double) (bNuevo - a) / INTERVALS;

    sum1 = arrayF[0] + arrayF[INTERVALS];
    for (int index = 1; index < INTERVALS; index++) {
        sum1 = sum1 + 2 * arrayF[index];
    }
    sum1 = sum1 * (hNuevo / 2);

    cout << "Resultado de la integral : " << fixed << setprecision(20) << sum1 << endl;

    return 0;
}