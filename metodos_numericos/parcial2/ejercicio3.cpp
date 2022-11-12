#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x, double y) {
    return (4 * x * y) / (1 + pow(x, 2));
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

    ofstream file("eulerBoard.txt");
    if (!file.is_open()) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        if (i == 0) {
            y[i + 1] = y[i] + h * function(x[i], y[i]);
            x[i + 1] = x[i] + h;
            file << x[i] << "\t" << y[i] << "\t" << endl;
        } else {
            x[i + 1] = x[i] + h;
            y[i + 1] = y[i] + h * (2 * function(x[i], y[i]) - function(x[i - 1], y[i - 1]));
            file << x[i] << "\t" << y[i] << "\t" << endl;
        }
    }

    file << x[N] << "\t" << y[N] << "\t" << endl;
    file.close();

}