#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAXCOLUMNS 2
#define MAXROWS 20

using namespace std;

double function(double);

void readFile(double [MAXROWS][MAXCOLUMNS], int *);

void printMatrix(double [MAXROWS][MAXCOLUMNS], int);

void polynomialMatrix(double [MAXROWS][MAXCOLUMNS], double [MAXROWS][MAXROWS], double [MAXROWS], int);

int gaussianElimination(double [MAXROWS][MAXROWS], double [MAXROWS], double [MAXROWS], int);

void printPolynomial(double [MAXROWS], int);

int main() {

    double nodes[MAXROWS][MAXCOLUMNS];
    int rows = 0;
    double matrix[MAXROWS][MAXROWS];
    double b[MAXROWS];
    double x[MAXROWS];
    double value;
    double e;


    cout << "--------------------------------" << endl;
    cout << "METODO DE INTERPOLACION LAGRANGE" << endl;
    cout << "--------------------------------" << endl;
    readFile(nodes, &rows);
    printMatrix(nodes, rows);
    cout << "Ingrese el valor a interpolar: " << endl;
    cin >> value;


    //calculo del Cnk
    double sum = 0;
    for (int indexA = 0; indexA < rows; indexA++) {
        double product = 1;
        for (int indexB = 0; indexB < rows; indexB++) {
            if (indexB != indexA) {
                product = product * ((value - nodes[indexA][0]) / (nodes[indexB][0] - nodes[indexA][0]));
            }
        }
        sum = sum + nodes[indexA][1] * product;
    }
    e = fabs(function(value) - sum);
    cout << "El valor interpolado para " << value << " es:" << sum << " con error: " << e << endl;

    polynomialMatrix(nodes, matrix, b, rows);
    gaussianElimination(matrix, b, x, rows);
    printPolynomial(x, rows);


    return 0;
}

/////////////////
//DEFINIR FUNCION
/////////////////
double function(double x) {
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

void printMatrix(double matrix[MAXROWS][MAXCOLUMNS], int rows) {
    cout << "LOS NODOS SON:" << endl;
    for (int indexA = 0; indexA < rows; indexA++) {
        for (int indexB = 0; indexB < MAXCOLUMNS; indexB++) {
            cout << matrix[indexA][indexB] << "\t";
        }
        printf("\n");
    }
}

void polynomialMatrix(double nodes[MAXROWS][MAXCOLUMNS], double matrix[MAXROWS][MAXROWS], double b[MAXROWS], int rows) {

    //genero matriz con el sistema de ecuaciones
    cout << endl;
    cout << "***********************************************" << endl;
    for (int index = 0; index < rows; index++) {
        for (int j = 0; j < rows; j++) {
            matrix[index][j] = pow(nodes[index][0], j);
        }
        b[index] = nodes[index][1];
    }
    cout << "***********************************************" << endl;

}

int gaussianElimination(double matrix[MAXROWS][MAXROWS], double b[MAXROWS], double x[MAXROWS], int rows) {

    double aux;
    double factor;
    float e = pow(10, -10);

    //triangulacion superior
    for (int indexA = 0; indexA < rows - 1; indexA++) {
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
                cout << "Warning: no se puede resolver, es un sistema singular" << endl;
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
    x[rows - 1] = b[rows - 1] / matrix[rows - 1][rows - 1];

    for (int indexA = rows - 2; indexA >= 0; indexA--) {
        suma = b[indexA];

        for (int indexB = indexA + 1; indexB <= rows - 1; indexB++) {
            suma -= matrix[indexA][indexB] * x[indexB];
        }
        x[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "********Soluciones********" << endl;
    for (int index = 0; index <= rows - 1; index++)
        cout << endl << "x" << index + 1 << "=" << x[index];
    cout << endl;

}

void printPolynomial(double x[MAXROWS], int rows) {

    //impresion del polinomio de resultados
    cout << "POLINOMIO" << endl;
    int exponente = 0;
    for (int index = 0; index <= rows - 1; index++) {
        if (exponente == 0)
            cout << x[index];
        else {
            if (x[index] >= 0)
                cout << " + " << x[index] << " " << "X^" << exponente << " ";
            else
                cout << x[index] << " " << "X^" << exponente << " ";
        }
        exponente++;
    }

    cout << endl << endl;
}
