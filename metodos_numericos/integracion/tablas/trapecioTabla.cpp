#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

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
    double sum, h, a, b;
    a = A;
    b = B;
    int intervals = POINTS;
    double array[] = {-0.0937500000, 0.0468750000, 0.5625000000, 1.2656250000, 2.2500000000, 3.5156250000, 5.0625000000,
                      6.7968750000, 8.9062500000};
    h = (double) (b - a) / intervals;

    cout << "********trapecio tabla ***************" << endl;

    sum = array[0] + array[POINTS];
    for (int index = 1; index < intervals; index++) {
        sum = sum + 2 * array[index];
    }
    sum = sum * (h / 2);

    cout << "(trapecio tabla)Resultado de la integral : " << fixed << setprecision(10) << sum << endl;

    return 0;
}