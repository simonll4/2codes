package informatica3.recursividad;



/*
Escriba un método recursivo que imprima los elementos de un arreglo en orden
inverso.
 */

public class eje6 {
    public static void main(String[] args) {

        Integer array[] = {0,1, 2, 3, 4, 5, 6, 7, 8, 9};
        int length = array.length;

        System.out.println("----ARRAY----");
        for (int index = 0; index < array.length; index++) {
            System.out.print(array[index] + "\t");
        }
        System.out.println();
        System.out.println("ARREGLO EN ORDEN INVERSO");
        printInverse(array,length-1);

    }

    static void printInverse(Integer []array,int length){

        //caso base
        if(length == 0) System.out.print(array[0]);
        //caso recursivo
        else{
            System.out.print(array[length] + "\t");
            printInverse(array,length-1);
        }

    }
}
