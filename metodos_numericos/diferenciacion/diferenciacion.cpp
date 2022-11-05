#include <iostream>
#include <fstream>
#include <math.h>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x) {
    return pow(1-x,3);
}

/////////////////////
/// definir intervalo
/////////////////////
#define INITIALX -2
#define FINALX 1

///////////////////////
/// definir cant puntos
///////////////////////
#define POINTS 2

void firstOrder();

void secondOrder();

void thirdOrder();

void fourthOrder();

int main() {
    int option;

    cout << "0-salir\n1-Primer Orden\n2-Segundo Orden\n3-Tercer Orden\n4-Cuarto Orden" << endl;
    cin >> option;
    switch (option) {
        case 0:
            break;
        case 1:
            firstOrder();
            break;
        case 2:
            secondOrder();
            break;
        case 3:
            thirdOrder();
            break;
        case 4:
            fourthOrder();
            break;
        default:
            cout << "OPCION INGRESADA INCORRECTA" << endl;
            break;
    }


    return 0;
}

void firstOrder() {
    double h = (double)(FINALX - INITIALX) / POINTS;
    double derivative;
    double x;
    ofstream file("board.txt");

    if (!file.is_open())cout << "ERROR AL ABRIR ARCHIVO" << endl;
    //esquema hacia adelante
    for (int i = 0; i < 2; ++i) {
        x = INITIALX + i * h;
        derivative = (-function(x + 2 * h) + 4 * function(x + h) - 3 * function(x)) / (2 * h);
        file << x << "\t" << derivative << endl;
    }


    //esquema centrado
    for (int i = 2; i < POINTS - 1; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-function(x + 2 * h) + 8 * function(x + h) - 8 * function(x - h) + function(x - 2 * h)) / (12 * h);
        file << x << "\t" << derivative << endl;
    }

    //esquema hacia atras
    for (int i = POINTS - 1; i < POINTS + 1; ++i) {
        x = INITIALX + i * h;
        derivative = (3 * function(x) - 4 * function(x - h) + function(x - 2 * h)) / (2 * h);
        file << x << "\t" << derivative << endl;
    }

    file.close();
}

void secondOrder() {
    double h = (double)(FINALX - INITIALX) / POINTS;
    double derivative;
    double x;
    ofstream file("board.txt");

    if (!file.is_open())cout << "ERROR AL ABRIR ARCHIVO" << endl;

    for (int i = 0; i < 3; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-function(x + 3 * h) + 4 * function(x + 2 * h) - 5 * function(x + h) + 2 * function(x)) / (pow(h, 2));
        file << x << "\t" << derivative << endl;
    }

    for (int i = 2; i < POINTS - 1; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-function(x + 2 * h) + 8 * function(x + h) - 8 * function(x - h) + function(x - 2 * h)) / (12 * h);
        file << x << "\t" << derivative << endl;
    }

    for (int i = POINTS - 1; i < POINTS + 1; ++i) {
        x = INITIALX + i * h;
        derivative = (2 * function(x) - 5 * function(x - h) + 4 * function(x - 2 * h) -
                      function(x - 3 * h) / (pow(h, 2)));
        file << x << "\t" << derivative << endl;
    }
    file.close();

}

void thirdOrder() {
    double h = (double)(FINALX - INITIALX) / POINTS;
    double derivative;
    double x;
    ofstream file("board.txt");

    if (!file.is_open())cout << "ERROR AL ABRIR ARCHIVO" << endl;

    for (int i = 0; i < 3; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-3 * function(x + 4 * h) + 14 * function(x + 3 * h) - 24 * function(x + 2 * h) + 18 * function(x + h) -
                 5 * function(x)) /
                (2 * pow(h, 3));
        file << x << "\t" << derivative << endl;
    }

    for (int i = 3; i < POINTS - 2; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-function(x + 3 * h) + 8 * function(x + 2 * h) - 13 * function(x + h) + 13 * function(x - h) -
                 8 * function(x - 2 * h) + function(x - 3 * h)) /
                (8 * pow(x, 3));
        file << x << "\t" << derivative << endl;
    }

    for (int i = POINTS - 2; i < POINTS + 1; ++i) {
        x = INITIALX + i * h;
        derivative =
                (5 * function(x) - 18 * function(x - h) + 24 * function(x - 2 * h) - 14 * function(x - 3 * h) +
                 3 * function(x - 4 * h)) / (2 * pow(h, 3));
        file << x << "\t" << derivative << endl;
    }
    file.close();
}

void fourthOrder() {
    double h = (double)(FINALX - INITIALX) / POINTS;
    double derivative;
    double x;
    ofstream file("board.txt");

    if (!file.is_open())cout << "ERROR AL ABRIR ARCHIVO" << endl;

    for (int i = 0; i < 3; ++i) {
        x = INITIALX + i * h;
        derivative = (-2 * function(x + 5 * h) + 11 * function(x + 4 * h) - 24 * function(x + 3 * h) +
                      26 * function(x + 2 * h) - 14 * function(x + h) +
                      3 * function(x)) / (pow(h, 4));;
        file << x << "\t" << derivative << endl;
    }

    for (int i = 3; i < POINTS - 2; ++i) {
        x = INITIALX + i * h;
        derivative =
                (-function(x + 3 * h) + 12 * function(x + 2 * h) - 39 * function(x + h) + 56 * function(x) -
                 39 * function(x - h) + 12 * function(x - 2 * h) -
                 function(x - 3 * h)) / (6 * pow(h, 4));;
        file << x << "\t" << derivative << endl;
    }

    for (int i = POINTS - 2; i < POINTS + 1; ++i) {
        x = INITIALX + i * h;
        derivative = (3 * function(x) - 14 * function(x - h) + 26 * function(x - 2 * h) - 24 * function(x - 3 * h) +
                      11 * function(x - 4 * h) -
                      2 * function(x - 5 * h)) / (pow(h, 4));;
        file << x << "\t" << derivative << endl;
    }
    file.close();
}

