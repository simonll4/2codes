#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x, double y) {
    return (2*x + 1)*sqrt(y);
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
    double x[N + 1], y[N + 1], k[5], h;
    x[0] = INITIALX;
    y[0] = INITIALY;
    h = (double) (FINALX - INITIALX) / N;

    ofstream file("rungeKuttaBoard.txt");
    if (!file.is_open()) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        k[1] = function(x[i], y[i]);
        k[2] = function(x[i] + h, y[i] + k[1] * h / 2);
        k[3] = function(x[i] + h / 2, y[i] + k[2] * h / 2);
        k[4] = function(x[i] + h, y[i] + k[3] * h);

        y[i + 1] = y[i] + h * (k[1] + 2 * k[2] + 2 * k[3] + k[4]) / 6;
        x[i + 1] = x[i] + h;

        file << x[i + 1] << "\t" << y[i + 1] << endl;
    }

    file.close();
}
