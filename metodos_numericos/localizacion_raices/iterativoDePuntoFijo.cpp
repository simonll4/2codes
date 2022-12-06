#include <iostream>
#include <math.h>
#include <iomanip>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -12)

//////////////////////////////////
///VALOR INICIAL(por defecto cero)
/////////////////////////////////
#define INICIAL 0.5

using namespace std;

double funcion(double);

double derivada(double);

///////////////////////////////////////
///funcion g(x) (acordarse despejar x)
//////////////////////////////////////
double function(double x) {
    return pow(x,x- cos(x));
}

////////////////////
///derivada de g(x)
///////////////////
double derivada(double x) {
    return -cos(x) + exp(x) / 3;
}

int main() {

    double xViejo = INICIAL;
    double xNuevo, eAproximado, ePorcentual;
    double tolerancia = ERROR;
    int iteraciones = 0;

    do {

        //////////////////////////////////////////////////////////////////////////////////////////////
        ///usando limite
        //////////////////////////////////////////////////////////////////////////////////////////////
        double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01); //limite original
        //double lim =(function(xViejo+0.01)- function(xViejo - 0.01))/(2*0.01);
        //double lim = (3 * function(xViejo) - 4 * function(xViejo - 0.01) + function(xViejo - (2 * 0.01))) / (2 * 0.01);
        ///el valor de la funcion derivdada tiene que estar entre 0 y 1 si el motodo diverge
        if (fabs(lim) < 1) {
            xNuevo = function(xViejo);
            eAproximado = fabs(xNuevo - xViejo);
            xViejo = xNuevo;
        } else {
            cout << "Warning: el metodo diverge" << endl;
            return 0;
        }

        //////////////////////////////////////////////
        ///usando funcion derivada
        //////////////////////////////////////////////
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
    cout << "Raiz: " << fixed << setprecision(20) << xNuevo << "\nError: " << eAproximado << "\nIteraciones: "
         << iteraciones << endl;
    return 0;
}