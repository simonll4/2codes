#include <iostream>

using namespace std;

#define MAXCOLUMS 15
#define MAXROWS 15

void writeFile(double[MAXROWS][MAXROWS], double[MAXROWS]);

int main() {

    double matrix[MAXROWS][MAXCOLUMS] = {0};
    double b[MAXROWS];
    int left = 0;
    int medium = 1;
    int right = 2;

    for (int indexA = 0; indexA < MAXROWS; indexA++) {
        if (indexA == 0) {
            matrix[indexA][left] = 1;
            matrix[MAXROWS - 1][MAXROWS - 1] = 1;
        } else if (indexA < MAXROWS-1) {
            matrix[indexA][left] = 1;
            matrix[indexA][medium] = -2;
            matrix[indexA][right] = 1;
            left++;
            medium++;
            right++;
        }
        b[indexA] = 1;
    }

    for (int indexA = 0; indexA < MAXROWS; ++indexA) {
        for (int indexB = 0; indexB < MAXROWS; ++indexB) {
            cout << matrix[indexA][indexB] << "\t";
        }
        cout << b[indexA];
        cout << endl;
    }

    writeFile(matrix, b);


    return 0;
}

void writeFile(double matrix[MAXROWS][MAXCOLUMS], double b[MAXROWS]) {

    FILE *readPtr;
    int j, i, n;
    double k;
    readPtr = fopen("matrixBuild.txt", "w");
    for (i = 0; i < MAXROWS; i++) {
        for (j = 0; j < MAXCOLUMS; j++) {
            fprintf(readPtr, "%lf\t", matrix[i][j]);
        }
        fprintf(readPtr, "%lf\n", b[i]);
    }
    fclose(readPtr);


}
