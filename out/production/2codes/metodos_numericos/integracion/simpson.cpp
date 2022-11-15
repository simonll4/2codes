#include <iostream>
#include <math.h>

using namespace std;

///////////
// funcion
///////////
double function(double x)
{
    return sin(x);
}

/////////////
// intervalos
/////////////
#define A 0
#define B M_PI

/////////////////
// sub intervalos
////////////////
#define INTERVALS 200

int main()
{
    double integral;
    double sum;
    double h;
    double x;

    cout << "***********************" << endl;

    if (INTERVALS % 2 == 0)
    {
        sum = function(A) + function(B);
        h = (B - A) / INTERVALS;
        for (int index = 1; index < INTERVALS / 2; index++)
        {
            x = A + 2 * index * h;
            sum = sum + 2 * function(x) + 4 * function(x - h);
        }
        sum = (h / 3) * (sum + 4 * function(B - h));
        cout << "Resultado de la integral: " << sum << endl;
    }
    else
    {
        cout << "INGRESAR UN NUMERO DE INTERVALOS PARES" << endl;
    }

    return 0;
}