#include <iostream>
#include <math.h>

#define MAXCOL 10
#define MAXROW 10
#define MAXITERATIONS pow(10,5)

using namespace std;

void readFile(double[MAXROW][MAXCOL], double[MAXROW], int *, int *);

void printMatrix(double[MAXROW][MAXCOL], double[MAXROW], int, int);

void diagonallyDominant(double[MAXROW][MAXCOL], int, int);

int main() {

    double matrix[MAXROW][MAXCOL];
    double b[MAXROW];
    int rows = 0;
    int columns = 0;

    readFile(matrix, b, &rows, &columns);
    printMatrix(matrix, b, rows, columns);

    //gaussSeidel
    double newX[MAXCOL] = {0};
    double oldX[MAXCOL] = {0};
    double tolerance = pow(10, -5) + 1;
    double e = 0;
    int iterations = 0;

    cout<<"********GAUSS-SEIDEL********"<<endl;
    diagonallyDominant(matrix, rows, columns);

    do {
        e = 0;
        iterations++;
        for (int indexA = 0; indexA < rows; ++indexA) {
            double sum = 0;
                for (int indexB = 0; indexB < rows ; ++indexB) {
                    if (indexA != indexB){
                        sum = sum + matrix[indexA][indexB] * oldX[indexB];
                    }
                }
                newX[indexA] = (b[indexA] - sum) / matrix[indexA][indexA];
                e = e + pow((newX[indexA] - oldX[indexA]), 2);
                oldX[indexA] = newX[indexA];

        }

        if (iterations == pow(10, MAXITERATIONS))
            cout << "Numero de iteraciones maximas alcanzadas" << endl;

    } while (e < tolerance || iterations > pow(10, MAXITERATIONS));

    cout<<"Conjunto solucion:"<<endl;
    for (int indexA = 0; indexA < rows; ++indexA) {
        printf("x%d = %lf\n", indexA + 1, newX[indexA]);
    }
    cout<<"Error:"<<e<<"\n"<<"Iteraciones:"<<iterations<<endl;

    return 0;
}

void readFile(double matrix[MAXROW][MAXCOL], double b[MAXROW], int *rows, int *columns) {
    FILE *file;
    char c;

    file = fopen("matrix.txt", "r");
    if (file == NULL) {
        puts("No se puede abrir el archivo");
    }

    while ((c = fgetc(file)) != EOF) {
        if (c == '\n') {
            *rows += 1;
        }
    }

    cout << "Filas:" << *rows << endl;

    //reseteamos el puntero del archivo
    rewind(file);

    //Cargo los datos leidos en el array
    int indexB;
    for (int indexA = 0; indexA < *rows; indexA++) {
        indexB = 0;
        do {
            fscanf(file, "%lf", &(matrix[indexA][indexB]));
            indexB++;
        } while ((c = fgetc(file)) != '\n');
    }

    *columns = indexB;
    cout << "Columnas: " << *columns << endl;

    //guardo los terminos independientes
    for (int indexA = 0; indexA < *rows; ++indexA) {
        b[indexA] = matrix[indexA][*columns - 1];
    }

    cout << "LOS TERMINOS INDEPENDIENTES DE LA MATRIZ SON:" << endl;
    for (int i = 0; i < *rows; i++) {
        printf("%lf ", b[i]);
        printf("\n");
    }

}

void printMatrix(double matrix[MAXROW][MAXCOL], double b[MAXROW], int rows, int columns) {
    printf("---------------MATRIZ AMPLIADA---------------\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            printf("%lf ", matrix[i][j]);
        }
        printf("%lf", b[i]);
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

void diagonallyDominant(double matrix[MAXROW][MAXCOL], int rows, int columns) {

    for (int indexA = 0; indexA < rows; indexA++) {
        double sum = 0;
        for (int indexB = 0; indexB < columns; indexB++) {
            if (indexA != indexB) {
                sum += matrix[indexA][indexB];
            }
        }
        if (!(matrix[indexA][indexA] > sum)) {
            printf("Warning: la matriz no es diagonalmente dominante\n");
            break;
        }
    }
}