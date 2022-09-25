#include <iostream>
#include <math.h>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -10)

//////////////////////////////////
///VALOR INICIAL(por defecto UNO)
/////////////////////////////////
#define INICIAL 1

using namespace std;

double function(double);

double derivada(double);

// funcion a estudiar

double function(double x) {
    return 3 * x + sin(x) - exp(x);
}

double derivada(double x) {
    return cosh(10 / x) - x * sinh(10 / x) * (10 / pow(x, 2));
}

int main() {

    double xViejo = INICIAL;
    double xNuevo, eAproximado, ePorcentual = 0;
    double tolerancia = ERROR;
    int iteraciones = 0;

    do {
        ////////////////
        ///usando limite
        /////////////////
        double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01);
        if (fabs(lim) < 0.000001) {
            cout << "Warning: la derivada de la funcion es demasiano cercana a cero, probar con otro metodo" << endl;
            return 0;
        }
        xNuevo = xViejo - (function(xViejo) / lim);
        eAproximado = fabs(xNuevo - xViejo);
        ePorcentual = ((fabs(xNuevo - xViejo) / xNuevo) * 100);
        xViejo = xNuevo;
        iteraciones++;
        cout << iteraciones << endl;


        //////////////////////////
        ///usando funcion derivada
        //////////////////////////
        /* if (fabs(derivada(xViejo)) < 0.001) {
             cout << "Warning: la derivada de la funcion es demasiano cercana a cero, probar con otro metodo" << endl;
             return 0;
         }

         xNuevo = xViejo - (function(xViejo) / derivada(xViejo));
         eAproximado = fabs(xNuevo - xViejo);
         ePorcentual = ((fabs(xNuevo- xViejo)/xNuevo)*100);
         xViejo = xNuevo;
         iteraciones++;
         cout << iteraciones << endl;*/

    } while (eAproximado > tolerancia && iteraciones < 10000);

    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    cout << " function(xNuevo)=" << (int) function(xNuevo) << endl;
    cout << "Error porcentual: " << ePorcentual << endl;
    return 0;
}