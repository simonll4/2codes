#include <iostream>
#include <math.h>
#include <stdlib.h>

using namespace std;

double funcion(double);

// funcion a estudiar
double funcion(double x)
{
    return 2 * x - 4;
}

int main()
{

    // intervalo que abarca la raiz
    double a = 1;
    double b = 4;

    double cn, cv;
    double eAproximado, ePorcentual = 0;
    double tolerancia = pow(10, -5);
    int iteraciones = 0;

    if (funcion(a) * funcion(b) < 0)
    {
        do
        {
            if (iteraciones == 0)
            {
                cv = a;
                cn = (a + b) / 2;
                eAproximado = fabs(cn - cv);
                ePorcentual = (eAproximado / cn) * 100;
            }
            else
            {
                if (funcion(a) * funcion(cn) < 0)
                {
                    b = cn;
                    cv = cn;
                    cn = (a + b) / 2;
                    eAproximado = fabs(cn - cv);
                    ePorcentual = (eAproximado / cn) * 100;
                }
                else
                {
                    a = cn;
                    cv = cn;
                    cn = (a + b) / 2;
                    eAproximado = fabs(cn - cv);
                    ePorcentual = (eAproximado / cn) * 100;
                }
            }
            iteraciones++;
        } while (eAproximado > tolerancia);
    }
    else
    {
        cout << "La funcion no tiene raices o  la misma no se encuentra en el intervalo elegido" << endl;
    }

    cout << "Raiz: " << cn << "\nError aproximado: " << eAproximado << "\nError porcentual: " << ePorcentual << "\nIteraciones: " << iteraciones << endl;

    return 0;
}