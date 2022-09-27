#include <stdio.h>
#include <iostream>
#include <math.h>

using namespace std;

#define MAXCOLUMS 10
#define MAXROWS 10
#define MAXITERATIONS pow(10,5)

void readFile(double[MAXROWS][MAXCOLUMS], double[MAXROWS], int *, int *);

void printMatrix(double[MAXROWS][MAXCOLUMS], int, int);

void diagonallyDominant(double[MAXROWS][MAXCOLUMS], int, int);

void jacobi(double [MAXROWS][MAXCOLUMS], double [MAXROWS], int, int);

int main() {

    double matrix[MAXROWS][MAXCOLUMS];
    double b[MAXROWS];
    int rows = 0;
    int columns = 0;

    cout << "-------------" << endl;
    cout << "METODO JACOBI" << endl;
    cout << "-------------" << endl;

    readFile(matrix, b, &rows, &columns);
    cout << "---------------MATRIZ AMPLIADA---------------" << endl;
    printMatrix(matrix, rows, columns);
    cout << "---------------------------------------------" << endl;
    diagonallyDominant(matrix, rows, columns);
    jacobi(matrix, b, rows, columns);

    return 0;
}

void readFile(double matrix[MAXROWS][MAXCOLUMS], double b[MAXROWS], int *rows, int *columns) {
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

    //es para chequear el vector de terminos independientes
    /*cout<<endl<<"---------------------------------------------"<<endl;
    cout << "LOS TERMINOS INDEPENDIENTES DE LA MATRIZ SON:" << endl;
    for (int index = 0; index < *rows; index++) {
        cout<<b[index]<<"\t";
    }
    cout<<endl<<"---------------------------------------------"<<endl;
*/
}

void printMatrix(double matrix[MAXROWS][MAXCOLUMS], int rows, int columns) {

    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < columns; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        cout << endl;
    }
}

void diagonallyDominant(double matrix[MAXROWS][MAXCOLUMS], int rows, int columns) {

    for (int indexA = 0; indexA < rows; indexA++) {
        double sum = 0;
        for (int indexB = 0; indexB < rows; indexB++) {
            if (indexA != indexB) {
                sum = sum + fabs(matrix[indexA][indexB]);
            }
        }
        if (fabs(matrix[indexA][indexA] <= sum)) {
            printf("Warning: la matriz no es diagonalmente dominante\n");
            break;
        }
    }
}

void jacobi(double matrix[MAXROWS][MAXCOLUMS], double b[MAXROWS], int rows, int columns) {
    double oldX[MAXROWS] = {0};
    double newX[MAXROWS] = {0};
    double tolerance = pow(10, -11);
    double e;
    int iterations = 0;
    double criterioCorte = 0;

    do {
        e = 0;
        iterations++;
        for (int indexA = 0; indexA < rows; ++indexA) {

            double sum = 0;
            for (int indexB = 0; indexB < columns; ++indexB) {
                if (indexA != indexB) {
                    sum = sum + matrix[indexA][indexB] * oldX[indexB];
                }
            }
            newX[indexA] = (b[indexA] - sum) / matrix[indexA][indexA];
            e = e + pow((newX[indexA] - oldX[indexA]), 2);
            oldX[indexA] = newX[indexA];
        }

        e = sqrt(e);


        //criterio de corte general AX - B = 0;
        criterioCorte = 0;
        for (int indexA = 0; indexA < rows; ++indexA) {

            for (int indexB = 0; indexB < rows; ++indexB) {
                criterioCorte = criterioCorte + matrix[indexA][indexB] * newX[indexB] ;
            }
            criterioCorte = criterioCorte - b[indexA];
        }
        criterioCorte = fabs(criterioCorte);


    } while (criterioCorte != 0 && iterations < MAXITERATIONS);

    if (iterations == MAXITERATIONS) {
        cout << "FINALIZED: maxima iteraciones" << endl;
    }

    cout << "Conjunto solucion:" << endl;
    for (int indexA = 0; indexA < rows; ++indexA) {
        cout << "x" << indexA << "=" << newX[indexA] << endl;
    }
    cout << "Error:" << e << "\n" << "Iteraciones:" << iterations << endl;

}