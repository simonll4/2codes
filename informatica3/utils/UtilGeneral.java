package informatica3.utils;

public class UtilGeneral<AnyType> {

    public void printArray(AnyType[] array) {

        for (AnyType i: array) {
            System.out.print(i + "\t");
        }

        /*for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }*/

    }
    static public void printArrayInt(int[] array) {

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }

    }

}
