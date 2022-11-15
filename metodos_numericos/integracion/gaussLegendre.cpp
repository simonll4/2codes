#include <iostream>
#include <math.h>
#include <iomanip>

//////////////////////////////
/// Definir cantidad de puntos
//////////////////////////////
#define SELECT 4

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 1

///////////////////
/// definir funcion
///////////////////
double function(double x) {
    return 9*pow(x,2);
}

using namespace std;

int main() {

    double two[] = {1, 1, -0.577350269, 0.577350269};
    double three[] = {0.5555556, 0.8888889, 0.5555556, -0.774596669, 0.0, 0.774596669};
    double four[] = {0.3478548, 0.6521452, 0.6521452, 0.3478548, -0.861136312, -0.339981044, 0.339981044, 0.861136312};
    double five[] = {0.2369269, 0.4786287, 0.5688889, 0.4786287, 0.2369269, -0.906179846, -0.538469310, 0.0,
                     0.538469310, 0.906179846};
    double six[] = {0.1713245, 0.3607616, 0.4679139, 0.4679139, 0.3607616, 0.1713245, -0.932469514, -0.661209386,
                    -0.238619186, 0.238619186, 0.661209386, 0.932469514};

    double integral = 0;
    double a, b;
    a = A;
    b = B;

    switch (SELECT) {
        case 1:
            break;
        case 2:
            integral = ((b - a) / 2) *
                       (two[0] * function(((b - a) * two[2] + b + a) / 2) +
                        two[1] * function(((b - a) * two[3] + a + b) / 2));
            cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
            break;
        case 3:
            integral = ((b - a) / 2) *
                       (three[0] * function(((b - a) * three[3] + b + a) / 2) +
                        three[1] * function(((b - a) * three[4] + b + a) / 2) +
                        three[2] * function(((b - a) * three[5] + b + a) / 2));
            cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
            break;
        case 4:
            integral = ((b - a) / 2) *
                       (four[0] * function(((b - a) * four[4] + b + a) / 2) +
                        four[1] * function(((b - a) * four[5] + b + a) / 2) +
                        four[2] * function(((b - a) * four[6] + b + a) / 2) +
                        four[3] * function(((b - a) * four[7] + b + a) / 2));
            cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
            break;
        case 5:
            integral = ((b - a) / 2) *
                       (five[0] * function(((b - a) * five[5] + b + a) / 2) +
                        five[1] * function(((b - a) * five[6] + b + a) / 2) +
                        five[2] * function(((b - a) * five[7] + b + a) / 2) +
                        five[3] * function(((b - a) * five[8] + b + a) / 2) +
                        five[4] * function(((b - a) * five[9] + b + a) / 2));
            cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
            break;
        case 6:
            integral = ((b - a) / 2) *
                       (six[0] * function(((b - a) * six[6] + b + a) / 2) +
                        six[1] * function(((b - a) * six[7] + b + a) / 2) +
                        six[2] * function(((b - a) * six[8] + b + a) / 2) +
                        six[3] * function(((b - a) * six[9] + b + a) / 2) +
                        six[4] * function(((b - a) * six[10] + b + a) / 2) +
                        six[5] * function(((b - a) * six[11] + b + a) / 2));
            cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
            break;
        default:
            cout << "ELECCION DE PUNTOS INVALIDA (entre 2 y 6 puntos, 1 para salir)" << endl;
            break;
    }

    return 0;
}