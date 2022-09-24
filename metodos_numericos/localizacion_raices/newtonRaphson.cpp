#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double function(double);

double derivada(double);

// funcion a estudiar

double function(double x) {
    return x * cosh(10 / x) - x - 6;
}

double derivada(double x) {
    return cosh(10 / x) - x * sinh(10 / x) * (10 / pow(x, 2));
}

int main() {
    double xViejo = 5;
    double xNuevo, eAproximado, ePorcentual = 0;
    double tolerancia = pow(10, -4);
    int iteraciones = 0;

    do {

        /*double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01);
        if (fabs(lim) < 0.000001) {
            cout << "Warning: la derivada de la funcion es demasiano cercana a cero, probar con otro metodo" << endl;
            return 0;
        }*/

        if (fabs(derivada(xViejo)) < 0.001) {
            cout << "Warning: la derivada de la funcion es demasiano cercana a cero, probar con otro metodo" << endl;
            return 0;
        }

        xNuevo = xViejo - (function(xViejo) / derivada(xViejo));
        eAproximado = fabs(xNuevo - xViejo);
        ePorcentual = ((fabs(xNuevo- xViejo)/xNuevo)*100);
        xViejo = xNuevo;
        iteraciones++;
        cout << iteraciones << endl;

    } while (eAproximado > tolerancia && iteraciones < 10000);

    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    cout << " function(xNuevo)=" << (int) function(xNuevo) << endl;
    cout << "Error porcentual: " << ePorcentual << endl;
    return 0;
}