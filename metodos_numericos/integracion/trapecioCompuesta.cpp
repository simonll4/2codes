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

    cout << "***********************" << endl;

    sum = function(A) + function(B);
    h = (B - A) / INTERVALS;

    for (int index = 1; index < INTERVALS; index++)
    {
        sum = sum + 2 * function(A + index * h);
    }
    sum = sum * (h / 2);

    cout << "Resultado de la integral: " << sum << endl;

    return 0;
}