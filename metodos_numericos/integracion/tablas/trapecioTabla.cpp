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
#define INTERVALS 5

int main() {
    double sum, h, a, b;
    a = A;
    b = B;
    int intervals = INTERVALS;
    double array[] = {0,0.52798,1.82369,4.656,9.79198,18};
    h = (double) (b - a) / intervals;

    cout << "********trapecio tabla ***************" << endl;

    sum = array[0] + array[INTERVALS];
    for (int index = 1; index < intervals; index++) {
        sum = sum + 2 * array[index];
    }
    sum = sum * (h / 2);

    cout << "(trapecio tabla)Resultado de la integral : " << fixed << setprecision(20) << sum << endl;

    return 0;
}