#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

#define MAXSIZE 500

//////////////////////
/// definir funciones
/////////////////////
double function1(double x, double y1, double y2, double y3) {
    return -y1 * x + 4 * sin(x);
}

double function2(double x, double y1, double y2, double y3) {
    return -y1 + 4 * cos(x);
}

double function3(double x, double y1, double y2, double y3) {
    return 0;
}
/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX 0
#define FINALX 2
#define INITIALY1 0
#define INITIALY2 0
#define INITIALY3 0

//////////////////////////////
/// definir cant subIntervalos
//////////////////////////////
#define N 100

int main() {
    double x[MAXSIZE], y1[MAXSIZE], y2[MAXSIZE], y3[MAXSIZE], k1[3], k2[3], k3[3], k4[3], h;

    x[MAXSIZE - 1] = 1;
    x[0] = INITIALX;
    y1[0] = INITIALY1;
    y2[0] = INITIALY2;
    y3[0] = INITIALY3;
    int n = N;
    h = (double )(FINALX-INITIALX) / n;

    ofstream file("rk4Board.txt");

    for (int i = 1; i < n + 1; ++i) {
        x[i] = x[0] + i * h;

        k1[0] = function1(x[i - 1], y1[i - 1], y2[i - 1], y3[i - 1]);
        k1[1] = function2(x[i - 1], y1[i - 1], y2[i - 1], y3[i - 1]);
        k1[2] = function3(x[i - 1], y1[i - 1], y2[i - 1], y3[i - 1]);

        k2[0] = function1(x[i - 1] + h / 2., y1[i - 1] + k1[0] * h / 2., y2[i - 1] + k1[1] * h / 2.,
                          y3[i - 1] + k1[2] * h / 2.);
        k2[1] = function2(x[i - 1] + h / 2., y1[i - 1] + k1[0] * h / 2., y2[i - 1] + k1[1] * h / 2.,
                          y3[i - 1] + k1[2] * h / 2.);
        k2[2] = function3(x[i - 1] + h / 2., y1[i - 1] + k1[0] * h / 2., y2[i - 1] + k1[1] * h / 2.,
                          y3[i - 1] + k1[2] * h / 2.);

        k3[0] = function1(x[i - 1] + h / 2., y1[i - 1] + k2[0] * h / 2., y2[i - 1] + k2[1] * h / 2.,
                          y3[i - 1] + k2[2] * h / 2.);
        k3[1] = function2(x[i - 1] + h / 2., y1[i - 1] + k2[0] * h / 2., y2[i - 1] + k2[1] * h / 2.,
                          y3[i - 1] + k2[2] * h / 2.);
        k3[2] = function3(x[i - 1] + h / 2., y1[i - 1] + k2[0] * h / 2., y2[i - 1] + k2[1] * h / 2.,
                          y3[i - 1] + k2[2] * h / 2.);

        k4[0] = function1(x[i - 1] + h / 2., y1[i - 1] + k3[0] * h, y2[i - 1] + k3[1] * h, y3[i - 1] + k3[2] * h);
        k4[1] = function2(x[i - 1] + h / 2., y1[i - 1] + k3[0] * h, y2[i - 1] + k3[1] * h, y3[i - 1] + k3[2] * h);
        k4[2] = function3(x[i - 1] + h / 2., y1[i - 1] + k3[0] * h, y2[i - 1] + k3[1] * h, y3[i - 1] + k3[2] * h);

        y1[i] = y1[i - 1] + h * (k1[0] + 2. * k2[0] + 2. * k3[0] + k4[0]) / 6.;
        y2[i] = y2[i - 1] + h * (k1[1] + 2. * k2[1] + 2. * k3[1] + k4[1]) / 6.;
        y3[i] = y3[i - 1] + h * (k1[2] + 2. * k2[2] + 2. * k3[2] + k4[2]) / 6.;

       file << x[i] << "\t" << y1[i] << "\t" << y2[i] << "\t" << y3[i] << "\t" << endl;
       //file << x[i] << "\t" << y2[i]<<endl;
    }
    file.close();

    return 0;
}