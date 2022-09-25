package informatica3.ordenamiento;

import informatica3.utils.*;

public class Main {

    public static void main(String[] args) {
        Integer[] array1 = {10, 9, 14, 54, 2, 1, 3, 4};
        Character[] array2 = {'g', 'e', 'a', 'c', 'f', 'b' };

        utilSort<Integer> orderOne = new utilSort<>();
        utilSort<Character> orderTwo = new utilSort<>();
        utilGeneral<Integer> printOne = new utilGeneral<>();
        utilGeneral<Character> printTwo = new utilGeneral<>();


        System.out.print("\nARREGLO\n");
        printOne.printArray(array1);
        orderOne.insertionSort(array1);
        System.out.println("\nARREGLO ORDENADO");
        printOne.printArray(array1);

        System.out.print("\nARREGLO\n");
        printTwo.printArray(array2);
        orderTwo.insertionSort(array2);
        printTwo.printArray(array2);

    }
}
