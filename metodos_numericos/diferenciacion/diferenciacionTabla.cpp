#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

using namespace std;

////////////////////////////////////////////////
/// metodo derivada primera (orden 1) con tabla
///////////////////////////////////////////////

/////////////////////
///cantidad de puntos
/////////////////////
#define INTERVALS 8

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 0
#define FINALX 2

int main(int argc, char *argv[]) {
    int n = INTERVALS;
    double derivative = 0;
    double arrayX[] = {0,0.25,0.5,0.75,1,1.25,1.5,1.75,2};
    double arrayY[] = {1,1.384,1.849,2.417,3.118,3.99,5.082,6.527,8.189};
    double h = (double) (FINALX - INITIALX) / INTERVALS;
    ofstream file("board.txt");

    file << "DIFERENCIACION TABLA" << endl;
    if (!file.is_open()) {
        cout << "ERROR AL ABRIR ARCHIVO" << endl;
    } else {
        for (int i = 0; i < 2; ++i) {
            derivative = (-arrayY[i + 2] + 4 * arrayY[i + 1] - 3 * arrayY[i]) / (2 * h);
            file << fixed << setprecision(10) << arrayX[i] << "\t" << derivative << endl;
        }

        for (int i = 2; i < n - 1; ++i) {
            derivative = (-arrayY[i + 2] + 8 * arrayY[i + 1] - 8 * arrayY[i - 1] + arrayY[i - 2]) / (12 * h);
            file << fixed << setprecision(10) << arrayX[i] << "\t" << derivative << endl;
        }

        for (int i = n - 1; i < n + 1; ++i) {
            derivative = (3 * arrayY[i] - 4 * arrayY[i - 1] + arrayY[i - 2]) / (2 * h);
            file << fixed << setprecision(10) << arrayX[i] << "\t" << derivative << endl;
        }
    }

}

