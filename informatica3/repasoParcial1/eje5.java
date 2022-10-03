package informatica3.repasoParcial1;

/*7. Implementar una función recursiva que sea capaz de sumar los n elementos
        de un arreglo v de enteros solo si el valor es mayor a p
*/

public class eje5 {

    public static void main(String[] args) {
        Integer[] integers = {4, 5, 7, 8, 2, 6, 4, 10, 9, 3};
        Integer sum;
        int size = integers.length;
        int value = 63;

        sum = sumIntegers(integers, size);
        System.out.print(value < sum ? "la suma es: " + sum : "P es mas grande que la suma");


    }

    public static int sumIntegers(Integer[] array, int size) {
        //caso base
        if (size == 0) return array[0];
        //caso recursivo
        return array[size - 1] + sumIntegers(array, size - 1);
    }

}
