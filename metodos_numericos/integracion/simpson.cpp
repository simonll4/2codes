#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

///////////
/// funcion
///////////
double function(double x) {
    return pow(1-x,3);
}

//////////////////////////
/// limites de integracion
//////////////////////////
#define A -2
#define B -1

//////////////////
/// sub intervalos
//////////////////
#define POINTS 100

int main() {
    double sum;
    double h, a, b;
    double x;
    int n;
    a = A;
    b = B;
    n = POINTS;

    cout << "***********************" << endl;

    if (n % 2 == 0) {
        sum = function(a) + function(b);
        h = (b - a) / n;
        for (int index = 1; index < n / 2; index++) {
            x = a + 2 * index * h;
            sum = sum + 2 * function(x) + 4 * function(x - h);
        }
        sum = h * (sum + 4 * function(b - h)) / 3;
        cout << "(simpson)Resultado de la integral: " << fixed << setprecision(20) << sum << endl;
    } else {
        cout << "INGRESAR UN NUMERO DE INTERVALOS PARES" << endl;
    }

    return 0;
}