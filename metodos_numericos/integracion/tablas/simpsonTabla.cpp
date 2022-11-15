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
#define B 2

/////////////////////////////////
/// sub intervalos (debe ser par)
/////////////////////////////////
#define INTERVALS 8

int main() {
    double sum;
    double h;
    int n = INTERVALS;
    double array[] = {0,0.4135,1.02433,1.81275,3.117,4.834166667,7.6125,11.3505,14.164};
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