#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

#define MAXCOLUMNS 2
#define MAXCOLUMNS2 10
#define MAXROWS 10

using namespace std;

void readFile(double [MAXROWS][MAXCOLUMNS], int *);

void printMatrix(double [MAXROWS][MAXCOLUMNS], int);

void assembleMatrix(double [MAXROWS][MAXCOLUMNS], double [MAXROWS][MAXCOLUMNS2], double [MAXROWS], int, int);

int gaussianElimination(double [MAXROWS][MAXCOLUMNS2], double [MAXROWS], double [MAXROWS], int);

void printPolynomial(double [MAXROWS], int);

void details(double [MAXROWS][MAXCOLUMNS],double [MAXROWS],int,int);

int main(void) {

    double nodes[MAXROWS][MAXCOLUMNS];
    int rows = 0;
    double matrix[MAXROWS][MAXCOLUMNS2];
    double b[MAXROWS];
    double x[MAXROWS];
    int flag = 1;
    int degree = 0;

    readFile(nodes, &rows);
    printMatrix(nodes, rows);

    //ingresar el grado del polinomio correcto
    do {
        cout << endl;
        cout << "**************************************************************" << endl;
        cout << "Ingresar grado del polinomio: " << endl;
        cin >> degree;

        if (rows < degree + 1) {
            cout << "La regresion no es posible para el polinomio deseado" << endl;
            flag = 1;
        } else
            flag = 0;
    } while (flag == 1);

    //armar matriz
    assembleMatrix(nodes, matrix, b, rows, degree);
    gaussianElimination(matrix, b, x, degree);
    printPolynomial(x, degree);
    details(nodes,x,rows,degree);

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
    double s;
    for (int i = 0; i <= degree; i++) {
        for (int j = 0; j <= degree; j++) {
            s = 0;
            for (int k = 0; k < rows; k++)
                s = s + pow(nodes[k][0], j + i);
            matrix[i][j] = s;
        }
        s = 0;
        for (int k = 0; k < rows; k++)
            s = s + (pow(nodes[k][0], i) * nodes[k][1]);
        b[i] = s;
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

int gaussianElimination(double matrix[MAXROWS][MAXCOLUMNS2], double b[MAXROWS], double x[MAXROWS], int rows) {
    //eliminacion gaussiana

    int aux;
    double factor;
    float e = pow(10, -9);

    //triangulacion superior
    for (int indexA = 0; indexA <= rows; indexA++) {

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
    //double finalX[rows + 1];

    x[rows] = b[rows] / matrix[rows][rows];

    for (int indexA = rows - 1; indexA >= 0; indexA--) {
        suma = b[indexA];

        for (int j = indexA + 1; j <= rows; j++) {
            suma -= matrix[indexA][j] * x[j];
        }

        x[indexA] = (suma) / matrix[indexA][indexA];
    }

    cout << endl << "********Soluciones********" << endl;
    for (int i = 0; i <= rows; i++)
        cout << endl << "x" << i << "=" << x[i];
    cout << endl;

    return 0;
}

void printPolynomial(double x[MAXROWS], int degree) {

    cout << endl << endl;
    cout << "POLINOMIO" << endl;
    int exponente = 0;
    for (int i = 0; i <= degree; i++) {
        if (exponente == 0)
            cout << x[i];
        else {
            if (x[i] >= 0)
                cout << " + " << x[i] << " " << "X^" << exponente << " ";
            else
                cout << x[i] << " " << "X^" << exponente << " ";
        }
        exponente++;
    }

}

void details(double nodes[MAXROWS][MAXCOLUMNS],double x[MAXROWS],int rows,int degree){
    cout << endl << endl;

    //Validaciones!! =)
    double syx;	//desviacion estandar-(error estandar estimado)
    double sr;	//error, residuo - (suma de los cuadrados de los residuos)
    double st;	//error medio- (suma total de los cuadrados)
    double r2;	//coeficiente de determinacion
    double r;	//coeficiente de correlacion
    double ymedia;	//media de y
    double s;

    //calculo de media de y
    ymedia=0;
    for(int i=0; i<rows; i++)
        ymedia = ymedia + nodes[i][1];
    ymedia = ymedia / rows;

    //calculo del error medio
    st=0;
    for(int i=0; i<rows; i++)
        st=st + pow( nodes[i][0]-ymedia ,2);

    //calculo del error-residuo
    sr=0;
    for(int i=0; i<rows; i++){
        s=0;
        for(int j=0; j<=degree; j++){
            s = s + ( x[j] * pow( nodes[i][0] ,j) );
        }
        sr=sr + pow((nodes[i][1]-s),2);
    }

    //calculo del error estandar estimado (desviacion estandar)
    syx = sqrt( sr / ( (double)rows-(degree+1) ) );


    //calculo del coeficiente de determinacion
    r2=(st-sr)/st;

    //calculo del coeficiente de correlacion
    r=sqrt(r2);

    //Impresion de los resultados!!!
    cout << endl << "Error/Residuo (suma de cuadrados de los residuos): " << sr ;
    cout << endl << "Desviacion estandar (Error estandar estimado): " << syx;
    cout << endl << "Error medio (suma total de cuadrados): " << st;
    cout << endl << "Coeficiente de determinacion: " << r2;
    cout << endl << "Coeficiente de correlacion: " << r;

    cout << endl << endl;
}