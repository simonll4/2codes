package informatica3.recursividad;

import java.util.*;
import java.lang.Exception;

/*Escribir un método power (base, exponente) que, al llamarla, devuelva baseexponente
Por ejemplo, power ( 3,4 ) = 3 * 3 * 3 * 3. Suponga que exponente es un entero
mayor o igual que 1.
 */

public class eje3 {
    public static void main(String[] args) {
        Scanner console1 = new Scanner(System.in);
        Scanner console2 = new Scanner(System.in);
        int base;
        int exponent;

        do {
            System.out.println("**************METODO POWER**************");
            System.out.println("[ingresar (-1) para salir en la base o exponente] ");
            System.out.println("BASE: ");
            base = console1.nextInt();

            if (base > -1) {
                System.out.println("EXPONENTE: ");
                exponent = console2.nextInt();
                if (exponent == -1) break;

                if (exponent < -1) {
                    try {
                        throw new Exception("No se puede ingresar exponente negativo");
                    } catch (Exception e) {
                        throw new RuntimeException(e);
                    }
                }
                System.out.println("Resultado: " + power(base, exponent));
            }

        } while (base != -1);


    }

    static int power(int base, int exponent) {
        if (exponent == 0) {
            return 1;
        }
        return base * power(base, exponent - 1);
    }
}

