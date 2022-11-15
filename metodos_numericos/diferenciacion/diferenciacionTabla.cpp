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
#define POINTS 8

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 0
#define FINALX 1

int main(int argc, char *argv[]) {
    int n = POINTS;
    double derivative = 0;
    double arrayX[] = {0, 0.125, 0.25, 0.375, 0.5, 0.625, 0.75, 0.875, 1};
    double arrayY[] = {1, 1.0058593750, 1.046875, 1.1582031250, 1.375, 1.7324218750, 2.265625, 3.0097656250, 4};
    double h = (double) (FINALX - INITIALX) / POINTS;
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

