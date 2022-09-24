#include <iostream>
#include <math.h>

#define MAXCOLUMS 10
#define MAXROWS 10
#define MAXITERATIONS pow(10,5)

using namespace std;

void readFile(double[MAXROWS][MAXCOLUMS], double[MAXROWS], int *, int *);

void printMatrix(double[MAXROWS][MAXCOLUMS], int, int);

void diagonallyDominant(double[MAXROWS][MAXCOLUMS], int, int);

void gaussSeidel(double [MAXROWS][MAXCOLUMS], double [MAXROWS], int, int);

int main() {

    double matrix[MAXROWS][MAXCOLUMS];
    double b[MAXROWS];
    int rows = 0;
    int columns = 0;

    cout << "-------------------" << endl;
    cout << "METODO GAUSS-SEIDEL" << endl;
    cout << "-------------------" << endl;

    readFile(matrix, b, &rows, &columns);
    printMatrix(matrix, rows, columns);
    gaussSeidel(matrix, b, rows, columns);

    return 0;
}

void readFile(double matrix[MAXROWS][MAXCOLUMS], double b[MAXROWS], int *rows, int *columns) {
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

void gaussSeidel(double m[MAXROWS][MAXCOLUMS], double b[MAXROWS], int rows, int columns) {
    double xv[MAXROWS] = {0, 0, 0, 0, 0};
    double xn[MAXROWS] = {0, 0, 0, 0, 0};
    double tolerance = pow(10, -3);
    double error = 0;
    int iterations = 0;
    double cte = 0;

    printf("Ingrese el coeficiente de relajacion\n");
    scanf("%lf", &cte);

    //Diagonalmente dominante
    for (int i = 0; i < rows; i++) {
        double sum = 0;
        for (int j = 0; j < columns; j++) {
            if (i != j) {
                sum = sum + fabs(m[i][j]);
            }
        }
        if (fabs(m[i][i]) <= sum) {
            printf("La matriz no es diagonalmente dominante\n");
            break;
        }
    }

    do {
        error = 0;
        iterations++;
        for (int i = 0; i < rows; ++i) {
            double sum = 0;
            for (int j = 0; j < columns; ++j) {
                if (i != j) {
                    sum = sum + m[i][j] * xv[j];
                }
            }
            xn[i] = (b[i] - sum) / m[i][i];
            error = error + pow((xn[i] - xv[i]), 2);
            xn[i] = cte * xn[i] + (1 - cte) * xv[i];
            xv[i] = xn[i];
        }

        error = sqrt(error);

        if (iterations == 9999) {
            printf("Numero maximo de iteraciones alcanzado\n");
        }

    } while (error > tolerance && iterations < 10000);

    printf("Conjunto solucion: \n");
    for (int i = 0; i < rows; ++i) {
        printf("x%d = %lf\n", i + 1, xn[i]);
    }
    printf("Error: %lf\nIteraciones: %d", error, iterations);

}
