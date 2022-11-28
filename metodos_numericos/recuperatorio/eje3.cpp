#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x, double y) {
    return 3 * sqrt(y);
}

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 0
#define FINALX 1
#define INITIALY 1

//////////////////////////////
/// definir cant subIntervalos
//////////////////////////////
#define N 100

int main() {

    double x[N + 1], y[N + 1], h;

    x[0] = INITIALX;
    y[0] = INITIALY;
    h = (double) (FINALX - INITIALX) / N;

    ofstream file("board.txt");

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            x[i + 1] = x[i] + h;
            y[i + 1] = y[i] + h * function(x[i], y[i]);
            file << fixed << setprecision(10) << x[i] << "\t" << y[i] << "\t" << endl;
        } else {
            x[i + 1] = x[i] + h;
            y[i + 1] = y[i] + h * (2 * function(x[i], y[i]) - function(x[i - 1], y[i - 1]));
            file << fixed << setprecision(10) << x[i] << "\t" << y[i] << "\t" << endl;
        }
    }
    file << fixed << setprecision(10) << x[N] << "\t" << y[N] << "\t" << endl;
    file.close();
}