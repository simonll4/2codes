#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x, double y) {
    return -2 * x * y;
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
    double x[N + 1], y[N + 1], yt, h;

    x[0] = INITIALX;
    y[0] = INITIALY;
    h = (double) (FINALX - INITIALX) / N;

    ofstream file("heunBoard.txt");
    if (!file.is_open()) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        x[i + 1] = x[i] + h;
        yt = y[i] + h * function(x[i], y[i]);
        y[i + 1] = y[i] + h * ((function(x[i], y[i]) + function(x[i + 1], yt)) / 2);

        file << x[i + 1] << "\t" << y[i + 1] << endl;
    }

    file.close();
}