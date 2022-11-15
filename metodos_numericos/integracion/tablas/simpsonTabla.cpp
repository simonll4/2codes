#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//////////////////////////////////
/// metodo de simpson con tabla
/////////////////////////////////

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 1

///////////////////
/// sub intervalos
//////////////////
#define POINTS 8

int main() {
    double sum;
    double h;
    int n = POINTS;
    double array[] = {-0.0937500000, 0.0468750000, 0.5625000000, 1.2656250000, 2.2500000000, 3.5156250000, 5.0625000000,
                      6.7968750000, 8.9062500000};
    double a = A;
    double b = B;

    cout << "************simpson tabla***********" << endl;

    if (n % 2 == 0) {
        sum = array[0] + array[n];
        h = (b - a) / n;
        for (int index = 1; index < n / 2; index++) {
            sum = sum + 2 * array[2 * index] + 4 * array[2 * index - 1];
        }
        sum = h * (sum + 4 * array[n - 1]) / 3;
        cout << "(simpson tabla)Resultado de la integral: " << fixed << setprecision(20) << sum << endl;
    } else {
        cout << "INGRESAR UN NUMERO DE INTERVALOS PARES" << endl;
    }

    return 0;
}