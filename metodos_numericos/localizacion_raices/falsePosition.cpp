#include <iostream>
#include <math.h>
#include <iomanip>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -8)

/////////////////////
///DEFINIR INTERVALO
/////////////////////
#define A 0.6
#define B   1.3

using namespace std;

double function(double);

///////////////////
///DEFINIR FUNCION
//////////////////
double function(double x) {
    return -0.952854-0.206982 * x  + 2.12295 * pow(x,2);;
}

int main() {

    // intervalo que abarca la raiz
    double a = A;
    double b = B;

    double cn, cv;
    double eAproximado, ePorcentual = 0;
    double tolerancia = ERROR;
    int iteraciones = 0;

    cout << "FALSA POSICION" << endl;

    if (function(a) * function(b) < 0) {
        do {
            if (iteraciones == 0) {
                cv = a;
                cn = (function(b) * a - function(a) * b) / (function(b) - function(a));
                eAproximado = fabs(cn - cv);
                ePorcentual = fabs(eAproximado / cn) * 100;
            } else {
                if (function(a) * function(cn) < 0) {
                    b = cn;
                    cv = cn;
                    cn = (function(b) * a - function(a) * b) / (function(b) - function(a));
                    eAproximado = fabs(cn - cv);
                    ePorcentual = fabs(eAproximado / cn) * 100;
                } else if (function(b) * function(cn) < 0) {
                    a = cn;
                    cv = cn;
                    cn = (function(b) * a - function(a) * b) / (function(b) - function(a));
                    eAproximado = fabs(cn - cv);
                    ePorcentual = fabs(eAproximado / cn) * 100;
                } else {
                    break;
                }
            }
            iteraciones++;
        } while (eAproximado > tolerancia);
        cout << fixed << setprecision(20) << "Raiz: " << cn << "\nError aproximado: " << eAproximado
             << "\nError porcentual: " << ePorcentual
             << "\nIteraciones: " << iteraciones << endl;
        cout << "la funcion en dicho punto es: " << (int) function(cn) << endl;
    } else {
        cout << "La funcion no tiene raices o  la misma no se encuentra en el intervalo elegido" << endl;
    }

    return 0;
}