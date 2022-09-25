#include <stdio.h>
#include <iostream>
#include <math.h>

/////////////////////
///DEFINIR TOLERANCIA
/////////////////////
#define ERROR pow(10, -3)

#define MAXCOLUMNS 20
#define MAXROWS 20

using namespace std;

void readFile(double matrix[MAXROWS][MAXCOLUMNS], double b[MAXROWS], int *, int *);

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int, int);

int gaussianElimination(double [MAXROWS][MAXROWS], double [MAXROWS], double [MAXROWS], int, int);

int main() {

    double matrix[MAXROWS][MAXCOLUMNS];
    double b[MAXROWS];
    double x[MAXROWS];
    int columns = 0;
    int rows = 0;

    cout << "----------------------------" << endl;
    cout << "METODO ILIMINACION GAUSSIANA" << endl;
    cout << "----------------------------" << endl;

    readFile(matrix, b, &rows, &columns);

    cout << "---------------MATRIZ AMPLIADA---------------" << endl;
    printMatrix(matrix, rows, columns);
    gaussianElimination(matrix, b, x, rows, columns);

    return 0;
}

void readFile(double matrix[MAXROWS][MAXROWS], double b[MAXROWS], int *rows, int *columns) {
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

    //es para chequear el vector de terminos independientes
    /*cout<<endl<<"---------------------------------------------"<<endl;
    cout << "LOS TERMINOS INDEPENDIENTES DE LA MATRIZ SON:" << endl;
    for (int index = 0; index < *rows; index++) {
        cout<<b[index]<<"\t";
    }
    cout<<endl<<"---------------------------------------------"<<endl;
    */

}

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int rows, int columns) {

    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < columns; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        cout << endl;
    }

}

int gaussianElimination(double matrix[MAXROWS][MAXROWS], double b[MAXROWS], double x[MAXROWS], int rows, int columns) {

    double aux;
    double factor;
    float e = ERROR;

    //triangulacion superior
    for (int indexA = 0; indexA < rows - 1; indexA++) {
        //pivoteo
        int swap = 0;
        if (fabs(matrix[indexA][indexA]) < e) {
            for (int indexB = indexA + 1; indexB <= rows; indexB++) {
                if (fabs(matrix[indexB][indexA]) > fabs(matrix[indexA][indexA])) {
                    for (int indexC = indexA; indexC < columns; indexC++) {
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
    x[rows - 1] = b[rows - 1] / matrix[rows - 1][rows - 1];

    for (int indexA = rows - 2; indexA >= 0; indexA--) {
        suma = b[indexA];

        for (int indexB = indexA + 1; indexB <= rows - 1; indexB++) {
            suma -= matrix[indexA][indexB] * x[indexB];
        }
        x[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "----------" << endl;
    cout << "SOLUCIONES" << endl;
    cout << "----------";
    for (int index = 0; index <= rows - 1; index++) {
        cout << endl << "x" << index + 1 << "=" << x[index];
    }
    cout << endl;

    return 0;
}
