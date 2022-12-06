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
    double x[MAXSIZE], y1[MAXSIZE], y2[MAXSIZE], y3[MAXSIZE], h;

    x[MAXSIZE - 1] = 1;
    x[0] = INITIALX;
    y1[0] = INITIALY1;
    y2[0] = INITIALY2;
    y3[0] = INITIALY3;
    int n = N;
    h = (double)(FINALX - INITIALX) / n;

    ofstream file("eulerBoard.txt");

    file<<"\tx\t\t\ty1\t\t\ty2\t\t\ty3\n";
    for (int i = 0; i < n + 1; ++i) {

        x[i + 1] = x[i] + h;
        y1[i + 1] = y1[i] + h * function1(x[i], y1[i], y2[i], y3[i]);
        y2[i + 1] = y2[i] + h * function2(x[i], y1[i], y2[i], y3[i]);
        y3[i + 1] = y3[i] + h * function3(x[i], y1[i], y2[i], y3[i]);
        file << x[i] << "\t" << y1[i] << "\t" << y2[i] << "\t" << y3[i] << "\t" << endl;
        //file << x[i] << "\t" << y2[i]<<endl;
    }


    file.close();

    return 0;
}