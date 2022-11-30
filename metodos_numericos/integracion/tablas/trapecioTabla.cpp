#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

#define MAXROWS 10000 ///cantidad de datos que lee desde el archivo

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 0
#define B 1

///////////////////
/// sub intervalos
//////////////////
#define INTERVALS 6

void readFile(double x[MAXROWS]);

int main() {
    double sum, h, a, b;
    a = A;
    b = B;
    int intervals = INTERVALS;
    double array[MAXROWS] = {0};
    h = (double) (b - a) / intervals;

    readFile(array);

    cout << "********trapecio tabla ***************" << endl;

    sum = array[0] + array[INTERVALS];
    for (int index = 1; index < intervals; index++) {
        sum = sum + 2 * array[index];
    }
    sum = sum * (h / 2);

    cout << "(trapecio tabla)Resultado de la integral : " << fixed << setprecision(20) << sum << endl;

    return 0;
}

void readFile(double x[MAXROWS]) {
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
            }
        } while ((c = fgetc(fp)) != '\n');

    }

    columnas = j;

    printf("numero de columnas=%i\n\n", columnas);

    //imprimo la matriz para verificar que lo leyo correctamente

    printf("LOS ELEMENTOS DE LA TABLA SON:\n");

    for (i = 0; i < filas; i++) {
        printf("%lf \t", x[i]);
        printf("\n");
    }
}