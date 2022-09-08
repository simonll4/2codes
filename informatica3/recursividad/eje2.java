package informatica3.recursividad;

import java.util.*;
import java.lang.Exception;

/*
1) (Visualización de la recursión ) Es interesante ver “en acción” a la recursión.
Modifique el método factrn ( factorial ) para que imprima su variable local y el
parámetro de llamada de la recursión. Por cada llamada recursiva, presente su salida
en una línea independiente y agregue un nivel de sangría. Haga su mejor esfuerzo
por hacer que la salida sea clara, interesante y significativa. Su meta aquí es diseñar
e implementar un formato de salida que ayude a la gente a entender mejor la
recursión. Tal vez desee agregar estas capacidades de presentación a los otros
ejercicios del práctico.
 */

public class eje2 {
    public static void main(String[] args) {
        Scanner console = new Scanner(System.in);
        int num;

        do {
            System.out.println("Ingrese valor para calcular su factorial(-1. salir): ");
            num = console.nextInt();

            if (num < -1) {
                try {
                    throw new Exception("No se puede ingresar numeros negativos");
                } catch (Exception e) {
                    throw new RuntimeException(e);
                }
            }

            System.out.println("Resultado: " + factorial(num));

        } while (num != -1);

    }

    static int factorial(int n) {
        //caso base
        if (n == 0) {
            return 1;
        }
        System.out.println("variable local: " + n);
        return (n * factorial(n - 1));
    }
}
