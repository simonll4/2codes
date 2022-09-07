#include <stdio.h>
#include <math.h>

using namespace std;

#define MAXCOL 10
#define MAXROW 10
#define MAXITERATIONS pow(10,5)

void readTxt(double[MAXROW][MAXCOL], double[MAXROW], int *, int *);
void printMatrix(double[MAXROW][MAXCOL], double[MAXROW], int, int);
void diagonallyDominant(double[MAXROW][MAXCOL],int,int);

int main()
{

    double matrix[MAXROW][MAXCOL];
    double b[MAXROW];
    int rows = 0;
    int columns = 0;

    // leer matriz del archivo matrix.txt
    readTxt(matrix, b, &rows, &columns);
    // mostrar matriz ingresada
    printMatrix(matrix, b, rows, columns);

    // metodo jacobi
    double newX[MAXCOL] = {0};
    double oldX[MAXCOL] = {0};
    double tolerance = pow(10, -5) + 1;
    double e;
    int iterations = 0;

    diagonallyDominant(matrix,rows,columns);

    do
    {
        iterations++;
        e = 0;
        for (int indexA = 0; indexA < rows; ++indexA)
        {
            double sum = 0;
            for (int indexB = 0; indexB < columns; ++indexB)
            {
                if (indexA != indexB)
                    sum = (sum + matrix[indexA][indexB] * oldX[indexB]);
            }
            newX[indexA] =  (b[indexA] - sum)/(matrix[indexA][indexA]);
            e = e + pow(newX[indexA] - oldX[indexA],2);
            oldX[indexA] = newX[indexA];
        }
        e = sqrt(e);

        if (iterations == pow(10, MAXITERATIONS))
            printf("Numero de iteraciones maximas alcanzadas");

    } while (e > tolerance || iterations > MAXITERATIONS);

    printf("Conjunto solucion: \n");
    for (int indexA = 0; indexA < rows; ++indexA)
    {
        printf("x%d = %lf\n", indexA + 1, newX[indexA]);
    }
    printf("Error: %lf\nIteraciones: %d", e, iterations);

    return 0;
}

void readTxt(double matrix[MAXROW][MAXCOL], double b[MAXROW], int *rows, int *columns) {
    FILE *readPtr;
    int j, i, n;
    float k;
    readPtr = fopen("matrix.txt", "r");
    fscanf(readPtr, "%d", &n);
    *rows = n;
    *columns = n;
    for (i = 0; i < *rows; i++) {
        for (j = 0; j < *columns; j++) {
            fscanf(readPtr, "%f", &k);
            matrix[i][j] = k;
        }
        fscanf(readPtr, "%f", &k);
        b[i] = k;
    }
    fclose(readPtr);

}

void printMatrix(double matrix[MAXROW][MAXCOL], double b[MAXROW], int rows, int columns) {
    printf("---------------MATRIZ AMPLIADA---------------\n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            printf("%lf ", matrix[i][j]);
        }
        printf("%lf", b[i]);
        printf("\n");
    }
    printf("---------------------------------------------\n");
}

void diagonallyDominant(double matrix[MAXROW][MAXCOL],int rows,int columns)
{

    for (int indexA = 0; indexA < rows; indexA++)
    {
        double sum = 0;
        for (int indexB = 0; indexB < columns; indexB++)
        {
            if (indexA != indexB)
            {
                sum += matrix[indexA][indexB];
            }
        }
        if (!(matrix[indexA][indexA] > sum))
        {
            printf("Warning: la matriz no es diagonalmente dominante\n");
            break;
        }
    }
}