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
    return exp(sqrt(1+x))* log(1+2* pow(x,2));
}

/////////////////////
///cantidad de puntos
/////////////////////
#define INTERVALS 6

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
