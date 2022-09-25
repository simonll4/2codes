package informatica3.utils;

public class utilSort<AnyType extends Comparable<? super AnyType>> {

    public void insertionSort(AnyType array[]) {

        AnyType aux;
        int indexB;

        for (int indexA = 1; indexA < array.length; indexA++) {
            aux = array[indexA];  // guardar temporalmente en memoria el elemento.
            indexB = indexA - 1; //tener el índice del elemento anterior.

            while(indexB >= 0 && aux.compareTo(array[indexB]) < 0 ){
                array[indexB + 1] = array[indexB];
                indexB--;
            }

            array[indexB + 1] = aux; //ponemos el aux en el sitio en el que tiene que estar.

        }
    }


}
