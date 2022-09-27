package informatica3.ordenamiento;

import informatica3.utils.*;

public class Main {

    public static void main(String[] args) {
        Integer[] array1 = {10, 9, 14, 54, 2, 1, 3, 4};
        Character[] array2 = {'g', 'e', 'a', 'c', 'f', 'b' };

        ArrayUtilSort<Integer> orderIteger = new ArrayUtilSort<>();
        ArrayUtilSort<Character> orderCharacter = new ArrayUtilSort<>();


        UtilGeneral<Integer> printInteger = new UtilGeneral<>();
        UtilGeneral<Character> printCharacter = new UtilGeneral<>();


        System.out.print("\nARREGLO\n");
        printInteger.printArray(array1);
        orderIteger.insertionSort(array1);
        System.out.println("\nARREGLO ORDENADO");
        printInteger.printArray(array1);

        System.out.print("\nARREGLO\n");
        printCharacter.printArray(array2);
        orderCharacter.insertionSort(array2);
        System.out.println("\nARREGLO ORDENADO");
        printCharacter.printArray(array2);

        int[] array3 = {2,8,1,6,4,12,45,3};
        System.out.print("\nARREGLO\n");
        UtilGeneral.printArrayInt(array3);
        ArrayUtilSort.shellSort(array3);
        System.out.println("\nARREGLO ORDENADO");
        UtilGeneral.printArrayInt(array3);

        int[] array4 = {2,8,1,4,87,45,6,4,12,45};
        System.out.print("\nARREGLO\n");
        UtilGeneral.printArrayInt(array4);
        ArrayUtilSort.quickSort(array4,0,9);
        System.out.println("\nARREGLO ORDENADO");
        UtilGeneral.printArrayInt(array4);


    }
}
