#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define MAXCOLUMNS 2
#define MAXCOLUMNS2 2
#define MAXROWS 10

using namespace std;

void readFile(double [MAXROWS][MAXCOLUMNS], int *);

void printMatrix(double [MAXROWS][MAXCOLUMNS], int);

void assembleMatrix(double [MAXROWS][MAXCOLUMNS], double [MAXROWS][MAXCOLUMNS2], double [MAXROWS], int, int);

int main(void) {

    double nodes[MAXROWS][MAXCOLUMNS];
    int rows = 0;
    double matrix[MAXROWS][MAXCOLUMNS2];
    double b[MAXROWS];
    double x[MAXROWS];

    readFile(nodes, &rows);
    cout << "**********" << endl;
    printMatrix(nodes, rows);

    //regresion polinomica
    int degree;
    int flag;

    do {
        cout << endl;
        cout << "**************************************************************" << endl;
        cout << "Ingresar grado del polinomio" << endl;
        cin >> degree;

        if (rows < degree + 1) {
            cout << "La regresion no es posible para el polinomio deseado" << endl;
            flag = 1;
        } else
            flag = 0;
    } while (flag == 1);

    assembleMatrix(nodes, matrix, b, rows, degree);

    //eliminacion gaussiana
    int aux;
    double factor;
    float e = pow(10, -10);

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
        for (int indexB = 0; indexB < rows - 1; indexB++) {
            cout << matrix[indexA][indexB] << " ";
        }
        cout << b[indexA] << endl;
    }

    //sustitucion regresiva
    double suma;
    double finalX[degree+1]; //vector de soluciones

    finalX[degree] = b[degree] / matrix[degree][degree];

    for (int indexA = degree - 1; indexA >= 0; indexA--) {
        suma = b[indexA];
        for (int j = indexA + 1; j <= degree - 1; j++) {
            suma -= matrix[indexA][j] * x[j];
        }
        finalX[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "********Soluciones********" << endl;
    for (int i = 0; i <= degree- 1; i++)
        cout << endl << "x" << i + 1 << "=" << finalX[i];
    cout << endl;

    //imprimo el polinomio
    cout << "POLINOMIO" << endl;
    int exponente=0;
    for(int i=0; i<=degree; i++)
    {
        if(exponente==0)
            cout << finalX[i];
        else{
            if(finalX[i]>=0)
                cout << " + " << finalX[i] << " " << "X^" << exponente << " ";
            else
                cout << finalX[i] << " " << "X^" << exponente << " ";
        }
        exponente++;
    }

    cout << endl << endl;


    return 0;
}

void readFile(double array[MAXROWS][MAXCOLUMNS], int *rows) {
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
            fscanf(file, "%lf", &(array[indexA][indexB]));
            indexB++;
        } while ((c = fgetc(file)) != '\n');
    }

}

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int rows) {
    cout << "LOS ELEMENTOS DE LA MATRIZ SON:" << endl;
    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < MAXCOLUMNS; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        printf("\n");
    }
}

void assembleMatrix(double nodes[MAXROWS][MAXCOLUMNS], double matrix[MAXROWS][MAXCOLUMNS2], double b[MAXROWS], int rows,
                    int degree) {

    for (int i = 0; i < degree; ++i) {
        double sumxy = 0;
        for (int j = 0; j < rows; ++j) {
            sumxy = sumxy + pow(nodes[j][0], i) * nodes[j][1];
        }
        b[i] = sumxy;
        for (int j = 0; j < degree; ++j) {
            double sumx = 0;
            for (int k = 0; k < rows; ++k) {
                sumx = sumx + pow(nodes[k][0], i + j);
            }
            matrix[i][j] = sumx;
        }
    }

    //imprimo matriz
    cout << endl << "Matriz de Vandermonde" << endl;
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << " ---> " << b[i];
        cout << endl;
    }


}