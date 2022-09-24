#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAXCOLUMNS 10
#define MAXROWS 10

using namespace std;

void readFile(double matrix[MAXROWS][MAXCOLUMNS], double b[MAXROWS], int *, int *);

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int *, int *);

int main() {

    double matrix[MAXROWS][MAXCOLUMNS];
    double b[MAXROWS];
    int columns = 0;
    int rows = 0;
    int aux;
    double factor;
    float e = pow(10, -10);

    readFile(matrix, b, &rows, &columns);
    printMatrix(matrix, &rows, &columns);

    //triangulacion superior
    for (int indexA = 0; indexA < rows - 1; indexA++) {

        //pivoteo
        int swap = 0;
        if (fabs(matrix[indexA][indexA]) < e) {
            for (int indexB = indexA + 1; indexB <= rows - 1; indexB++) {
                if (fabs(matrix[indexB][indexA]) > e) {
                    for (int indexC = indexA; indexC <= rows - 1; indexC++) {
                        aux = matrix[indexA][indexC];
                        matrix[indexA][indexC] = matrix[indexB][indexC];
                        matrix[indexB][indexC] = aux;
                    }
                    aux = b[indexA];
                    b[indexA] = b[indexB];
                    b[indexB] = aux;
                    swap = 1;
                    break;
                }
            }
            if (swap == 0) {
                cout << "Warning: sistema singular, no se puede resolver" << endl;
                return 0;
            } else
                cout << "Pivoteo concretado " << endl;
        }

        for (int indexB = indexA + 1; indexB <= rows - 1; indexB++) {
            factor = (-matrix[indexB][indexA]) / (matrix[indexA][indexA]);
            for (int indexC = indexA; indexC <= rows - 1; indexC++)
                matrix[indexB][indexC] = matrix[indexB][indexC] + factor * matrix[indexA][indexC];
            b[indexB] = b[indexB] + factor * b[indexA];
        }
    }

    //imprime matrix triangular
    cout << endl << "La Matriz triangular superior quedo: " << endl;
    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < columns - 1; indexB++) {
            cout << matrix[indexA][indexB] << " ";
        }
        cout << b[indexA] << endl;
    }

    //sustitucion regresiva
    double suma;
    double x[rows];

    x[rows - 1] = b[rows - 1] / matrix[rows - 1][rows - 1];
    for (int indexA = rows - 2; indexA >= 0; indexA--) {
        suma = b[indexA];
        for (int j = indexA + 1; j <= rows - 1; j++) {
            suma -= matrix[indexA][j] * x[j];
        }
        x[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "********Soluciones********" << endl;
    for (int i = 0; i <= rows - 1; i++)
        cout << endl << "x" << i + 1 << "=" << x[i];
    cout << endl;

    return 0;
}

void readFile(double matrix[MAXROWS][MAXROWS], double b[MAXROWS], int *rows, int *columns) {
    FILE *file;
    char c;

    file = fopen("nodes.txt", "r");
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

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int *rows, int *columns) {
    cout << "LOS ELEMENTOS DE LA MATRIZ SON:" << endl;
    for (int indexA = 0; indexA < *rows; indexA++) {
        for (int indexB = 0; indexB < *columns; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        printf("\n");
    }
}