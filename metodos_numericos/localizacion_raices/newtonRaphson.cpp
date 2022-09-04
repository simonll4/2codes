#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double funcion(double);
double derivada(double);

// funcion a estudiar

double funcion(double x)
{
    return pow(x, 3) - x - 1;
}

double derivada(double x)
{
    return (3 * pow(x, 2)) - 1;
}

int main()
{
    double xViejo = 1;
    double xNuevo, eAproximado, ePorcentual;
    double tolerancia = pow(10, -5);
    int iteraciones = 0;

    do
    {
        if (derivada(xViejo) < 0.0004)
        {
            cout << "Warning: la derivada de la funcion es demasiano cercana a cero, probar con otro metodo" << endl;
            return 0;
        }

        xNuevo = xViejo - (funcion(xViejo) / derivada(xViejo));
        eAproximado = fabs(xNuevo - xViejo);
        xViejo = xNuevo;
        iteraciones++;

    } while (eAproximado > tolerancia || iteraciones > 10000);

    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    cout << " f(xNuevo)=" << funcion(xNuevo) << endl;
    return 0;
}