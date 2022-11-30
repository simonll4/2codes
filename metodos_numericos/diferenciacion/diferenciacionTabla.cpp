#include <stdio.h>
#include <iostream>
#include <fstream>
#include <math.h>
#include <iomanip>

#define MAXROWS 10000 ///cantidad de datos que lee desde el archivo

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
#define FINALX 1

void readFile(double x[MAXROWS], double y[MAXROWS]);

int main(int argc, char *argv[]) {
    int n = INTERVALS;
    double derivative = 0;
    double arrayX[MAXROWS] = {0};
    double arrayY[MAXROWS] = {0};
    double h = (double) (FINALX - INITIALX) / INTERVALS;
    ofstream file("board.txt");


    readFile(arrayX, arrayY);

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

void readFile(double x[MAXROWS], double y[MAXROWS]) {
    FILE *fp;
    fp = fopen("nodes.txt", "r");
    if (fp == NULL) {
        puts("No se puede abrir el archivo");
    }

    //contador de filas
    int filas = 0;
    char c;
    int maxValues = 0;
    int columnas;

    while ((c = fgetc(fp)) != EOF) {
        if (c == '\n') {
            filas++;
        }
    }

    printf("numero de filas=%i\n", filas);

    //resetear el puntero
    rewind(fp);


    //Cargo los datos leidos en el array
    int xi = 0;
    int yi = 0;
    int j = 0;
    int i;
    for (i = 0; i < filas; i++) {
        j = 0;

        do {
            if (j == 0) {
                fscanf(fp, "%lf", &(x[xi]));
                xi++;
                j++;
            } else {
                fscanf(fp, "%lf", &(y[yi]));
                yi++;
            }
        } while ((c = fgetc(fp)) != '\n');

    }

    columnas = j;

    printf("numero de columnas=%i\n\n", columnas);

    //imprimo la matriz para verificar que lo leyo correctamente

    printf("LOS ELEMENTOS DE LA TABLA SON:\n");

    for (i = 0; i < filas; i++) {
        printf("%lf \t %lf", x[i], y[i]);
        printf("\n");
    }


}

