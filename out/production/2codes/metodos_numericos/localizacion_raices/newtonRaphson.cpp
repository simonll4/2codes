#include <iostream>
#include <math.h>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -6)
//////////////////////////////////
///VALOR INICIAL(por defecto UNO)
/////////////////////////////////
#define INICIAL 0.5

using namespace std;

double function(double);

double derivada(double);

///////////////////
///DEFINIR FUNCION
//////////////////
double function(double x) {
    return (2 * x )+ log10(x) - sin(3 * x);
}

///////////////
///derivada f(x)
///////////////
double derivada(double x) {
    return 2+ 1/x - 3 * cos(3*x);
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
        double lim =(3 * function(xViejo) - 4 * function(xViejo - 0.01) + function(xViejo - (2 * 0.01))) / (2 * 0.01);
        //double lim = (function(xViejo + (0.01)) - function(xViejo)) / (0.01); //limite original
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
         /*if (fabs(derivada(xViejo)) < 0.001) {
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