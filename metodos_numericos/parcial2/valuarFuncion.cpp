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
    return log(x)*pow(x,2)+4*x;
}

/////////////////////
///cantidad de puntos
/////////////////////
#define INTERVALS 6

/////////////////////
/// definir intervalo
/////////////////////
#define A 2
#define B 3


int main() {
    cout << "xi\t\t\tyi" << endl;
    double a = A, b = B;
    double h;
    double num;
    h = (b - a) / INTERVALS;

    num = function(a);
    cout << fixed << setprecision(10) << a << "\t\t" << num << endl;
    for (int i = 0; i < INTERVALS; i++) {
        a = a + h;
        num = function(a);
        cout << fixed << setprecision(10) << a << "\t\t" << num;
        cout << endl;
    }

}
