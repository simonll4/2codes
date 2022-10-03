#include <iostream>
#include <math.h>

using namespace std;

#define MAXCOLUMNS 2
#define MAXROWS 20


void readFile(double [MAXROWS][MAXCOLUMNS], int *);

void printNodes(double [MAXROWS][MAXCOLUMNS], int);

void assembleMatrix(double [MAXROWS][MAXCOLUMNS], double [MAXROWS][MAXROWS], double [MAXROWS], int);

void printMatrix(double matrix[MAXROWS][MAXROWS],double [MAXROWS] , int, int);

int gaussianElimination(double [MAXROWS][MAXROWS], double [MAXROWS], double [MAXROWS], int);

int main() {

    double nodes[MAXROWS][MAXCOLUMNS] = {0};
    int rows = 0;
    double matrix[MAXROWS][MAXROWS] = {0};
    double b[MAXROWS] = {0};
    double z[MAXROWS] = {0};


    readFile(nodes, &rows);
    printNodes(nodes, rows);
    assembleMatrix(nodes, matrix, b, rows);
    printMatrix(matrix,b, 4 * rows, 4 * rows);
    gaussianElimination(matrix,b,z,rows);

    return 0;
}

void readFile(double array[MAXROWS][MAXCOLUMNS], int *rows) {
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
            fscanf(file, "%lf", &(array[indexA][indexB]));
            indexB++;
        } while ((c = fgetc(file)) != '\n');
    }

}

void printNodes(double matrix[MAXROWS][MAXCOLUMNS], int rows) {
    cout << "LOS NODOS SON:" << endl;
    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < MAXCOLUMNS; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        printf("\n");
    }
}

void printMatrix(double matrix[MAXROWS][MAXROWS],double b[MAXROWS], int rows, int columns) {

    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < columns; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        cout << b[indexA] << endl;
    }

}


void assembleMatrix(double nodes[MAXROWS][MAXCOLUMNS], double matrix[MAXROWS][MAXROWS], double b[MAXROWS], int rows) {

    ///construccion de las primeras 2n ecuaciones(imagen de la funcion)
    for (int indexA = 0; indexA < rows; ++indexA) {
        for (int indexB = 0; indexB <= 3; ++indexB) {
            matrix[2 * indexA][4 * indexA + indexB] = pow(nodes[indexA][0], 3 - indexB);
            matrix[2 * indexA + 1][4 * indexA + indexB] = pow(nodes[indexA + 1][0], 3 - indexB);
        }
        b[2 * indexA] = nodes[indexA][1];
        b[2 * indexA + 1] = nodes[indexA + 1][1];
    }

    ///construccion de las primeras n-1 ecuaciones(derivadas primeras)
    for (int indexA = 2 * rows; indexA <= (3 * rows - 2); ++indexA) {
        for (int indexB = 0; indexB <= rows - 2; ++indexB) {
            for (int indexC = 0; indexC < 2; ++indexC) {
                matrix[indexA][4 * indexB + indexC] = (3 - indexC) * pow(nodes[indexB + 1][0], 2 - indexC);
                matrix[indexA][4 * (indexB + 1) + indexC] = (3 - indexC) * pow(nodes[indexB + 1][0], 2 - indexC);
            }
        }
        b[indexA] = 0;
    }

    ///derivadas segundas
    for (int indexA = 3 * rows - 1; indexA <= (4 * rows - 3); ++indexA) {
        for (int indexB = 0; indexB <= rows - 2; ++indexB) {
            matrix[indexA][4 * indexB] = 6 * nodes[indexB + 1][0];
            matrix[indexA][4 * indexB + 1] = 2;
            matrix[indexA][4 * indexB + 4] = (-6 * nodes[indexB + 1][0]);
            matrix[indexA][4 * indexB + 5] = (-2);
        }
        b[indexA] = 0;
    }
}

int gaussianElimination(double matrix[MAXROWS][MAXROWS], double b[MAXROWS], double x[MAXROWS], int rows) {
    //eliminacion gaussiana

    double aux;
    double factor;
    float e = pow(10, -3);

    //triangulacion superior
    for (int indexA = 0; indexA <= rows; indexA++) {

        //pivoteo
        int swap = 0;
        if (fabs(matrix[indexA][indexA]) < e) {

            for (int indexB = indexA + 1; indexB <= rows - 1; indexB++) {

                if (fabs(matrix[indexB][indexA]) > fabs(matrix[indexA][indexA])) {

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
                return 1;
            } else
                cout << "Pivoteo concretado " << endl;
        }

        for (int indexB = indexA + 1; indexB <= rows; indexB++) {
            factor = (-matrix[indexB][indexA]) / (matrix[indexA][indexA]);

            for (int indexC = indexA; indexC <= rows; indexC++)
                matrix[indexB][indexC] = matrix[indexB][indexC] + factor * matrix[indexA][indexC];
            b[indexB] = b[indexB] + factor * b[indexA];
        }
    }

    //imprime matrix triangular
    cout << endl << "La Matriz triangular superior quedo: " << endl;
    for (int indexA = 0; indexA <= rows; indexA++) {

        for (int indexB = 0; indexB <= rows; indexB++) {
            cout << matrix[indexA][indexB] << " ";
        }
        cout << b[indexA] << endl;
    }

    //sustitucion regresiva
    double suma;
    x[rows] = b[rows] / matrix[rows][rows];

    for (int indexA = rows - 1; indexA >= 0; indexA--) {
        suma = b[indexA];

        for (int indexB = indexA + 1; indexB <= rows; indexB++) {
            suma -= matrix[indexA][indexB] * x[indexB];
        }

        x[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "********Soluciones********" << endl;
    for (int index = 0; index <= rows; index++)
        cout << endl << "x" << index << "=" << x[index];
    cout << endl;

    return 0;
}
