#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 2

///////////////////
/// sub intervalos
//////////////////
#define INTERVALS 8

int main() {
    double sum, h, a, b;
    a = A;
    b = B;
    int intervals = INTERVALS;
    double array[] = {0,0.4135,1.02433,1.81275,3.117,4.834166667,7.6125,11.3505,14.164};
    h = (double) (b - a) / intervals;

    cout << "********trapecio tabla ***************" << endl;

    sum = array[0] + array[INTERVALS];
    for (int index = 1; index < intervals; index++) {
        sum = sum + 2 * array[index];
    }
    sum = sum * (h / 2);

    cout << "(trapecio tabla)Resultado de la integral : " << fixed << setprecision(10) << sum << endl;

    return 0;
}