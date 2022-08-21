#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double funcion(double);
double derivada(double);

// funcion a estudiar

double funcion(double x)
{
    return (-pow(x, 2)) + 4;
}

double derivada(double x)
{
    return ((funcion(x + 0.001) - funcion(x)) / 0.001);
}

int main()
{
    double xViejo = 0;
    double xNuevo, eAproximado, ePorcentual;
    double tolerancia = pow(10, -5);
    int iteraciones = 0;

    do
    {
        if (fabs(derivada(xViejo)) < 1)
        {
            xNuevo = funcion(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        }
        else
        {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }
        iteraciones++;
    } while (eAproximado > tolerancia);
    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    return 0;
}