#include <math.h>
#include <iostream>
#include <iomanip>

using namespace std;

/*
 * esta funcion sirve para valuar una serie de puntos equiespaciados, desde un x inicial a un x final.
 */

/////////////////////
/// funcion a valuar
////////////////////
double function(double x) {
    return 3 * pow(x, 3) + 1;
}

/////////////////////
///cantidad de puntos
/////////////////////
#define POINTS 9

/////////////////////
/// definir intervalo
/////////////////////
#define A 0
#define B 1


int main() {
    cout << "xi\t\t\tyi" << endl;
    double a = A, b = B;
    double h;
    double num;
    h = (b - a) / POINTS;

    num = function(a);
    cout << fixed << setprecision(10) << a << "\t\t" << num << endl;
    for (int i = 0; i < POINTS; i++) {
        a = a + h;
        num = function(a);
        cout << fixed << setprecision(10) << a << "\t\t" << num;
        cout << endl;
    }

}
