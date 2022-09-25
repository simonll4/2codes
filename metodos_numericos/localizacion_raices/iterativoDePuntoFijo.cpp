#include <iostream>
#include <math.h>
#include <stdlib.h>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -10)

//////////////////////////////////
///VALOR INICIAL(por defecto cero)
/////////////////////////////////
#define INICIAL 0

using namespace std;

double funcion(double);

double derivada(double);

///////////////
///funcion g(x)
///////////////
double function(double x) {
    return (-sin(x) + exp(x)) / 3;
}

///////////////
///derivada g(x)
///////////////
double derivada(double x) {
    return -cos(x) + exp(x) / 3;
}

int main() {

    double xViejo = INICIAL;
    double xNuevo, eAproximado, ePorcentual;
    double tolerancia = ERROR;
    int iteraciones = 0;

    do {

        ////////////////
        ///usando limite
        /////////////////
        double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01);
        if (fabs(lim) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        } else {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }

        /*//////////////////////////
        ///usando funcion derivada
        //////////////////////////
        if (fabs(derivada(xViejo)) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        } else {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }*/

        iteraciones++;
    } while (eAproximado > tolerancia);
    cout << "Raiz: " << xNuevo << "\nError: " << eAproximado << "\nIteraciones: " << iteraciones << endl;
    return 0;
}