package informatica3.recursividad;

import java.util.*;

/*
Escriba un método recursivo que calcule el producto de dos números enteros usando
sumas sucesivas.
 */

public class eje4 {
    public static void main(String[] args) {

        Scanner console = new Scanner(System.in);
        int a, b, result = 0;

        System.out.println("----------------------------------------------");
        System.out.println("----MULTIPLICACION DE 2 NUMEROS RECURSIVA----");
        System.out.println("----------------------------------------------");
        System.out.println("----INGRESE----");
        System.out.println("Numero 1: ");
        a = console.nextInt();
        console.reset();
        System.out.println("Numero 2: ");
        b = console.nextInt();

        result = multiplication(a, b);
        System.out.println("Resulrado de " + a + "X" + b + " es : " + result);


    }

    static int multiplication(int a, int b) {

        //caso base
        if (b == 0) return 0;

        //caso recursivo
        return a + multiplication(a, b - 1);
    }

}
