package informatica3.utils;

public class ArrayUtilSort<AnyType extends Comparable<? super AnyType>> {

    public void insertionSort(AnyType[] array) {

        AnyType aux;
        int indexB;

        for (int indexA = 1; indexA < array.length; indexA++) {
            aux = array[indexA];  // guardar temporalmente en memoria el elemento.
            indexB = indexA - 1; //tener el índice del elemento anterior.

            while (indexB >= 0 && aux.compareTo(array[indexB]) < 0) {
                array[indexB + 1] = array[indexB];
                indexB--;
            }
            array[indexB + 1] = aux; //ponemos el aux en el sitio en el que tiene que estar.
        }
    }

    public static void shellSort(int[] array) {

        int gap, indexA, indexB, temp;

        for (gap = array.length / 2; gap > 0; gap /= 2) {
            for (indexA = gap; indexA < array.length; indexA++) {
                for (indexB = indexA - gap; indexB >= 0 && array[indexB] > array[indexB + gap]; indexB -= gap) {
                    temp = array[indexB];
                    array[indexB] = array[indexB + gap];
                    array[indexB + gap] = temp;
                }
            }
        }

    }

    public static void quickSort(int[] array,int left,int right) {

        int temp;
        int i = left;
        int j = right;

        do {
            while (array[j] > array[i] && j > i) j--;
            {
                if (i < j) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    i++;
                }
            }
            while (array[i] < array[j] && i < j) i++;
            {
                if (i < j) {
                    temp = array[i];
                    array[i] = array[j];
                    array[j] = temp;
                    j--;
                }
            }

        } while (i < j);
        if(left<j)quickSort(array,left,j-1);
        if(i<right)quickSort(array,i+1,right);
    }

}
