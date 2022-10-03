package informatica3.repasoParcial1;

import java.util.*;

import informatica3.utils.*;

/*
2. Escriba una función void recursiva que reciba como parámetro solo un
entero positivo n y que despliegue todos los enteros impares menores a n.
 */


public class eje2 {
    public static void main(String[] args) {
        int num = 21;

        printMinorsOdd(num);

    }

    public static void printMinorsOdd(int num) {
        if(num%2==1)num--;
        //caso base
        if (num == 0) ;
        //caso recursivo
        else {
            if (num % 2 == 0) num--;{
                System.out.println(num);
            }
            printMinorsOdd(num - 1);
        }
    }

}


