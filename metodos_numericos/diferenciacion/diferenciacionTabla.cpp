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
#define INTERVALS 6

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 2
#define FINALX 3

int main(int argc, char *argv[]) {
    int n = INTERVALS;
    double derivative = 0;
    double arrayX[] = {2,2.1666666667,2.3333333333	,2.5000000000,2.6666666667,2.8333333333,3.0000000000};
    double arrayY[] = {10.7725887222,12.2963636420,13.9463994621,15.7268170742,17.6414524659,19.6938936063,21.8875105980};
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

