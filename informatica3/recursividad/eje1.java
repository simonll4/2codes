package informatica3.recursividad;

import java.util.*;

//Cree el metodo int factorial(int n) que realice el calculo del factorial de n de manera recursiva.

public class eje1 {

    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        int num;
        do {
            System.out.println("Ingrese valor para calcular su factorial(-1. salir): ");
            num = console.nextInt();

            if (num > 0) {
                System.out.println("Resultado: " + factorial(num));
            }

        } while (num != -1);

    }

    static int factorial(int n) {
        //caso base
        if (n == 0) {
            return 1;
        }

        return (n * factorial(n - 1));
    }
}


