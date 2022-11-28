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
#define A 2
#define B 3

/////////////////////////////////
/// sub intervalos (debe ser par)
/////////////////////////////////
#define INTERVALS 6

int main() {
    double sum;
    double h;
    int n = INTERVALS;
    double array[] = {8.7638668179, 9.5090695446, 10.2873818569, 11.0814470330, 11.8977505605, 12.7280640885,
                      13.5852295041};
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