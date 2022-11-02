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
    double x[N + 1], y[N + 1], ym, xm, h;
    x[0] = INITIALX;
    y[0] = INITIALY;
    h = (double) (FINALX - INITIALX) / N;

    ofstream file("puntoMedioBoard.txt");
    if (!file.is_open()) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return 1;
    }

    for (int i = 0; i < N; i++) {
        xm = x[i] + h / 2;
        ym = y[i] + h / 2 * function(x[i], y[i]);
        y[i + 1] = y[i] + h * function(xm, ym);
        x[i + 1] = x[i] + h;
        file << x[i + 1] << "\t" << y[i + 1] << endl;
    }

    file.close();
}