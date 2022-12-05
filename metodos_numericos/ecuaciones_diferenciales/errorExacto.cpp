#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;


//////////////////////////////////////////////////////////////////////////////////////////
///cargar puntos X e Y en errorExactoValores(los obtenidos en el metodo de diferenciacion)
//////////////////////////////////////////////////////////////////////////////////////////

#define MAXROWS 100000 ///cantidad de datos que lee desde el archivo
#define MAXCOLUMNS 2

///////////////////////////////////
/// definir funcion con Y despejada
///////////////////////////////////
double function(double x) {
    return pow(x / 2 + pow(x, 2) / 4 + 1, 2);
}

void readFile(double [MAXROWS][MAXCOLUMNS], int *);

int main() {

    double matrix[MAXROWS][MAXCOLUMNS];
    int rows = 0;
    ofstream file("errorExactoResultados.txt");

    readFile(matrix, &rows);


    cout << "valores de los datos ingresados" << endl;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < MAXCOLUMNS; ++j) {
            cout << matrix[i][j] << "\t";
        }
        cout << endl;
    }
    cout << "valores de los datos ingresados" << endl;

    file << "Punto" << "\t\t" << "VALOR EXACTO"<< "\t\t" << "ERORR EXACTO" << endl;

    double value = 0;
    for (int i = 0; i < rows; ++i) {
        value = fabs(function(matrix[i][0]) - matrix[i][1]);
        file << matrix[i][0] << "\t\t" << function(matrix[i][0]) << "\t\t" << value << endl;
    }

    file.close();

}

void readFile(double array[MAXROWS][MAXCOLUMNS], int *rows) {
    FILE *file;
    char c;

    file = fopen("errorExactoValores.txt", "r");
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