#include <iostream>
#include <math.h>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -6)

//////////////////////////////////
///VALOR INICIAL(por defecto cero)
/////////////////////////////////
#define INICIAL 0.5

using namespace std;

double funcion(double);

double derivada(double);

///////////////
///funcion g(x)
///////////////
double function(double x) {
    return (-log10(x) + sin(3 * x)) / 2;
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
        double lim = (3 * function(xViejo) - 4 * function(xViejo - 0.01) + function(xViejo - (2 * 0.01))) / (2 * 0.01);
        //double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01); //limite original
        if (fabs(lim) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        } else {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }

        //////////////////////////
        ///usando funcion derivada
        //////////////////////////
        /*if (fabs(derivada(xViejo)) < 1) {
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