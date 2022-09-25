#include <iostream>
#include <math.h>

using namespace std;

double funcion(double);

// funcion a estudiar
double funcion(double x) {
    return x * cosh(10 / x) - x - 6;
}

int main() {
    double xNuevo, eAproximado;
    double xViejo = 9;
    double xViejoViejo = 7;
    double tolerancia = pow(10, -5);
    int iteraciones = 0;

    do {
        xNuevo = xViejo - (funcion(xViejo) * (xViejoViejo - xViejo)) / (funcion(xViejoViejo) - funcion(xViejo));
        eAproximado = fabs(xNuevo - xViejo);
        xViejoViejo = xViejo;
        xViejo = xNuevo;
        iteraciones++;
    } while (eAproximado > tolerancia || iteraciones > 10000);

    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    return 0;
}