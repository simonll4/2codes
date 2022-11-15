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
#define POINTS 200

int main()
{
    double integral;
    double sum;
    double h;

    cout << "***********************" << endl;

    sum = function(A) + function(B);
    h = (B - A) / POINTS;

    for (int index = 1; index < POINTS; index++)
    {
        sum = sum + 2 * function(A + index * h);
    }
    sum = sum * (h / 2);

    cout << "Resultado de la integral: " << sum << endl;

    return 0;
}