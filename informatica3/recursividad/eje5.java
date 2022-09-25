package informatica3.recursividad;

import java.util.*;

/*
Escriba un método recursivo que calcule el cociente de dos números enteros usando
restas sucesivas.
 */

public class eje5 {
    public static void main(String[] args) {

        Scanner console = new Scanner(System.in);
        int a, b, result ;

        System.out.println("----------------------------------------------");
        System.out.println("----MULTIPLICACION DE 2 NUMEROS RECURSIVA----");
        System.out.println("----------------------------------------------");
        System.out.println("----INGRESE----");
        System.out.println("DIVIDENDO: ");
        a = console.nextInt();
        console.reset();
        System.out.println("DIVISOR: ");
        b = console.nextInt();

        result = division(a, b);
        //System.out.println("El residuo de " + a + "/" + b + " es : " + result);
        System.out.println("El resultado de " + a + "/" + b + " es : " + result);

    }

    static int division(int a, int b) {

        //para que te tire el residuo
        //caso base
        //if (a < b) return a;
        //caso recursivo
        //return division(a-b,b);

        //calcular la division

        //caso base
        if (a < b) return 0;
        //caso recursivo
        return 1 + division(a - b, b);

    }
}
