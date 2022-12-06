#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

//////////////////////////////
/// Definir cantidad de puntos
//////////////////////////////
#define SELECT 3

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 5

///////////////////
/// definir funcion
///////////////////
double function(double x, double v) {
    return 10 * exp(0.05 * v * pow(x, 0.02));
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
    double a, b, v;
    a = A;
    b = B;
    ofstream file("cuadraturaGauss.txt");

    v = 0;
    while (v <= 50) {
        switch (SELECT) {
            case 3:
                integral = ((b - a) / 2) *
                           (three[0] * function(((b - a) * three[3] + b + a) / 2, v) +
                            three[1] * function(((b - a) * three[4] + b + a) / 2, v) +
                            three[2] * function(((b - a) * three[5] + b + a) / 2, v));

                //cout << "(GaussLegendre)Resultado: " << fixed << setprecision(10) << integral << endl;
                file << v << "\t" << fixed << setprecision(10) << integral << "\t" << endl;
                break;
            default:
                cout << "ELECCION DE PUNTOS INVALIDA (entre 2 y 6 puntos, 1 para salir)" << endl;
                break;
        }
        v = v + 2.5;
    }
    file.close();
    return 0;
}