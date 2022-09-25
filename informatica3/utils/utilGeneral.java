package informatica3.utils;

public class utilGeneral<AnyType> {

    public void printArray(AnyType array[]) {

        for (int i = 0; i < array.length; i++) {
            System.out.print(array[i] + "\t");
        }

    }

}
