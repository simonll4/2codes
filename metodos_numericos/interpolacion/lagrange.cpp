#include <stdio.h>
#include <iostream>
#include <math.h>

#define MAXCOLUMNS 2
#define MAXROWS 10

using namespace std;

void readFile(double [MAXROWS][MAXCOLUMNS], int *);

void printMatrix(double [MAXROWS][MAXCOLUMNS], int);

double f(double);

int polynomial(double [MAXROWS][MAXCOLUMNS],int);

int main() {

    double array[MAXROWS][MAXCOLUMNS];
    int rows = 0;

    readFile(array, &rows);
    cout << "**********" << endl;
    printMatrix(array, rows);


    //lagrange
    double x;
    double e;

    cout << "Ingrese el valor a interpolar" << endl;
    cin >> x;

    double sum = 0;
    for (int indexA = 0; indexA < rows; indexA++) {
        double product = 1;
        for (int indexB = 0; indexB < rows; indexB++) {
            if (indexB != indexA) {
                product = product * ((x - array[indexA][0]) / (array[indexB][0] - array[indexA][0]));
            }
        }
        sum = sum + array[indexA][1] * product;
    }
    e = fabs(f(x) - sum);
    cout << "El valor interpolado para " << x << " es:" << sum << " con error: " << e << endl;

    polynomial(array,rows);

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

double f(double x) {
    return x + 2 / x;
}

int polynomial(double array[MAXROWS][MAXCOLUMNS] ,int rows){
    //polynomial
    double matrix[rows][rows];
    double b[rows];
    double x[rows];

    cout<<endl;
    cout<<"***********************************************"<<endl;
    for(int i = 0; i<rows; i++){
        for(int j = 0; j<rows;j++){
            matrix[i][j] = pow(array[i][0], j);
        }
        b[i] = array[i][1];
    }
    cout<<"***********************************************"<<endl;

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

    return 1;
}