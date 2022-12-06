#include <iostream>
#include <math.h>
#include <iomanip>

using namespace std;

/////////////////////////////////////////////////////////////////////////////
///en el archivo solo poner puntos a integrar, la imagen(valor de la funcion)
/////////////////////////////////////////////////////////////////////////////
#define MAXROWS 10000 ///cantidad de datos que lee desde el archivo
//////////////////////////////////
/// metodo de simpson con tabla
/////////////////////////////////

//////////////////////////
/// limites de integracion
//////////////////////////
#define A 1
#define B 2

/////////////////////////////////
/// sub intervalos (debe ser par)
/////////////////////////////////
#define INTERVALS 10

void readFile(double x[MAXROWS]);

int main() {
    double sum;
    double h;
    int n = INTERVALS;
    double array[MAXROWS] = {0};
    double a = A;
    double b = B;

    cout << "************simpson tabla***********" << endl;

    readFile(array);

    if (n % 2 == 0) {
        sum = array[0] + array[n];
        h = (b - a) / n;
        for (int index = 1; index < n / 2; index++) {
            sum = sum + 2 * array[2 * index] + 4 * array[2 * index - 1];
        }
        sum = h * (sum + 4 * array[n - 1]) / 3;
        cout << "(simpson tabla)Resultado de la integral: " << fixed << setprecision(20) << sum << endl;
    } else {
        cout << "INGRESAR UN NUMERO DE INTERVALOS PARES" << endl;
    }

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