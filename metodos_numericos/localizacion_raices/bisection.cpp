#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -8)

/////////////////////
///DEFINIR INTERVALO
/////////////////////
#define A 0.5
#define B 1.5

double function(double);

///////////////////
///DEFINIR FUNCION
//////////////////
double function(double x) {
    return -15.3315 + 58.6035793651 *x -74.2201984127*pow(x,2)  + 30.9503968254*pow(x,3) ;
}

int main() {

    // intervalo que abarca la raiz
    double a = A;
    double b = B;

    double cn, cv;
    double eAproximado, ePorcentual = 0;
    double tolerancia = ERROR;
    int iteraciones = 0;

    cout << "BISECCION" << endl;

    if (function(a) * function(b) < 0) {
        do {
            if (iteraciones == 0) {
                cn = (a + b) / 2;
                cv = a;
                eAproximado = fabs(cn - cv);
                ePorcentual = fabs(eAproximado / cn) * 100;
            } else {
                if (function(a) * function(cn) < 0) {
                    b = cn;
                    cv = cn;
                    cn = (a + b) / 2;
                    eAproximado = fabs(cn - cv);
                    ePorcentual = (eAproximado / cn) * 100;
                } else if (function(b) * function(cn) < 0) {
                    a = cn;
                    cv = cn;
                    cn = (a + b) / 2;
                    eAproximado = fabs(cn - cv);
                    ePorcentual = (eAproximado / cn) * 100;
                } else {
                    break;
                }
            }
            iteraciones++;
        } while (eAproximado > tolerancia);
        cout  << fixed << setprecision(20)<< "Raiz: "  << fixed << setprecision(20)<< cn << "\nError aproximado: " << eAproximado << "\nError porcentual: " << ePorcentual
             << "\nIteraciones: " << iteraciones << endl;
        cout << "la funcion en dicho punto es: " << (int) function(cn) << endl;
    } else {
        cout << "La funcion no tiene raices o  la misma no se encuentra en el intervalo elegido" << endl;
    }

    return 0;
}