#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double function(double);

// funcion a estudiar
double function(double x) {
    return -0.3+(((log(x)-(1-1/x))/(log(x)+3*(1-1/x)/2)));
}

int main() {

    //definir funcion e intervalo para el metodo

    // intervalo que abarca la raiz
    double a = 1;
    double b = 6;

    double cn, cv;
    double eAproximado, ePorcentual = 0;
    double tolerancia = pow(10, -5);
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
                }
                else{
                    break;
                }
            }
            iteraciones++;
        } while (eAproximado > tolerancia);
        cout << "Raiz: " << cn << "\nError aproximado: " << eAproximado << "\nError porcentual: " << ePorcentual
             << "\nIteraciones: " << iteraciones << endl;
        cout << "la funcion en dicho punto es: " <<(int) function(cn) << endl;
    } else {
        cout << "La funcion no tiene raices o  la misma no se encuentra en el intervalo elegido" << endl;
    }

    return 0;
}