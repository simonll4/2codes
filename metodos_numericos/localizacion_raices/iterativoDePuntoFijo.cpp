#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double funcion(double);

double derivada(double);

// funcion a estudiar
double function(double x) {
    return pow(x, x - cos(x));
}

double derivada(double x) {
    return -(x * cos(-x)) * pow(x, x - cos(x) - 1) * 1 + sin(x);
}

int main() {
    double xViejo = 0;
    double xNuevo, eAproximado, ePorcentual;
    double tolerancia = pow(10, -5);
    int iteraciones = 0;

    do {
        /*double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01);
        if (fabs(lim) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        }*/
        if (fabs(derivada(xViejo)) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        } else {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }
        iteraciones++;
    } while (eAproximado > tolerancia);
    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    return 0;
}