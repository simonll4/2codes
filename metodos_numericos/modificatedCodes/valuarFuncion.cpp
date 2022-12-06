#include <iostream>
#include <math.h>
#include <iomanip>
#include <fstream>

using namespace std;

///////////////////
/// definir funcion
///////////////////
double function(double x) {
    return 50.3515 + 2.23494 * x + 0.107135 * pow(x, 2) - 0.00104323 * pow(x, 3) + 5.2883e-05 * pow(x, 4);
}

int main() {

    cout<< function(47.2981);

}
