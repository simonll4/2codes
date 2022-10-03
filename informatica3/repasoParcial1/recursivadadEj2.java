package informatica3.repasoParcial1;

import informatica3.utils.*;

/*
    escribir una funcion recursiva que ordene de menor a mayor un arreglo de enteros.colocar el primer
    elemento mas pequenio en la primera ubicacion.luego ordenar el resto del arreglo con llamada recursiva
 */

public class recursivadadEj2 {

    public static void main(String[] args) {
        int[] array = {4, 2, 1, 5, 6, 10, 25, 3,4,5,4,4,4,4,1,2,3,6,8,99,525,45};

        UtilGeneral.printArrayInt(array);
        orderArray(array, array.length);
        System.out.println("\n");
        UtilGeneral.printArrayInt(array);

    }

    public static void orderArray(int[] array, int size) {
        int swap ;

        //caso base
        if (size == 1) ;
        else {
            //caso recursivo
            for (int index = 0; index < size - 1; index++) {
                if (array[index] > array[index + 1]) {
                    swap = array[index];
                    array[index] = array[index + 1];
                    array[index + 1] = swap;
                }
            }
            orderArray(array, size - 1);
        }

    }

}
