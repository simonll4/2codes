#include <iostream>
#include <math.h>

//////////////////////////////
/// Definir cantidad de puntos
//////////////////////////////
#define SELECT 2

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 0.5

///////////////////
/// definir funcion
///////////////////
double function(double x) {
    return 2 * pow(x, 3);
}

using namespace std;

int main() {

    double two[] = {1, 1, -0.577350269, 0.577350269};
    double three[] = {0.5555556, 0.8888889, 0.5555556, -0.774596669, 0.0, 0.774596669};
    double four[] = {0.3478548, -0.861136312, 0.6521452, 0.339981044, 0.6521452, 0.339981044, 0.3478548, 0.861136312};
    double five[] = {0.2369269, 0.4786287, 0.5688889, 0.4786287, 0.2369269, -0.906179846, -0.538469310, 0.0,
                     0.538469310, 0.906179846};
    double six[] = {0.1713245, 0.3607616, 0.4679139, 0.4679139, 0.3607616, 0.1713245, -0.932469514, -0.661209386,
                    -0.238619186, 0.238619186, 0.661209386, 0.932469514};

    double integral = 0;

    switch (SELECT) {
        case 1:
            break;
        case 2:
            integral = ((B - A) / 2) *
                       (two[0] * function(((B - A) * two[2] + B + A) / 2) +
                        two[1] * function(((B - A) * two[3] + A + B) / 2));
            cout << "Resultado: " << integral << endl;
            break;
        case 3:
            integral = ((A - B) / 2) *
                       (three[0] * function(((B - A) * three[3] + B + A) / 2) +
                        three[1] * function(((B - A) * three[4] + B + A) / 2) +
                        three[2] * function(((B - A) * three[5] + B + A) / 2));
            cout << "Resultado: " << integral << endl;
            break;
        case 4:
            integral = ((B - A) / 2) *
                       (four[0] * function(((B - A) * four[4] + B + A) / 2) +
                        four[1] * function(((B - A) * four[5] + B + A) / 2) +
                        four[2] * function(((B - A) * four[6] + B + A) / 2) +
                        four[3] * function(((B - A) * four[7] + B + A) / 2));
            cout << "Resultado: " << integral << endl;
            break;
        case 5:
            integral = ((B - A) / 2) *
                       (five[0] * function(((B - A) * five[5] + B + A) / 2) +
                        five[1] * function(((B - A) * five[6] + B + A) / 2) +
                        five[2] * function(((B - A) * five[7] + B + A) / 2) +
                        five[3] * function(((B - A) * five[8] + B + A) / 2) +
                        five[4] * function(((B - A) * five[9] + B + A) / 2));
            cout << "Resultado: " << integral << endl;
            break;
        case 6:
            integral = ((B - A) / 2) *
                       (six[0] * function(((B - A) * six[6] + B + A) / 2) +
                        six[1] * function(((B - A) * six[7] + B + A) / 2) +
                        six[2] * function(((B - A) * six[8] + B + A) / 2) +
                        six[3] * function(((B - A) * six[9] + B + A) / 2) +
                        six[4] * function(((B - A) * six[10] + B + A) / 2) +
                        six[5] * function(((B - A) * six[11] + B + A) / 2));
            cout << "Resultado: " << integral << endl;
            break;
        default:
            cout << "ELECCION DE PUNTOS INVALIDA (entre 2 y 6 puntos, 1 para salir)" << endl;
            break;
    }

    return 0;
}