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

////////////////////
/// definir derivada
////////////////////
double derivate(double x, double y) {
    return -2 * y;
}

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 0
#define FINALX 2
#define INITIALY 1

//////////////////////////////
/// definir cant subIntervalos
//////////////////////////////
#define N 10

int main() {
    double h, x, y, e;
    ofstream file("board.txt");
    h = (FINALX - INITIALX) / N;

    if (!file.is_open())cout << "ERROR AL ABRIR ARCHIVO" << endl;


    for (int index = 0; index < N; ++index) {
        if (index == 0) {
            y = INITIALY + h * function(INITIALX, INITIALY);
            x = INITIALX + h;
            e = pow(h, 2) * derivate(INITIALX, INITIALY) / 2;
        } else {
            e = pow(h, 2) * derivate(x, y) / 2;
            y = y + h * function(x, y);
            x = x + h;
        }
        file << x << "\t" << y << "\t" << e << "\t" << endl;

    }
    file.close();
}