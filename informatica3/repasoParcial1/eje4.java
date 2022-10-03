package informatica3.repasoParcial1;

import informatica3.utils.*;

import java.util.ArrayList;
import java.util.List;

/*
4. Escribir un método que busque en una lista enlazada el valor V y lo mueva
    a la primera posición.
 */
public class eje4 {
    public static void main(String[] args) {
        List<Integer> list = new ArrayList<>();

        for (int i = 0; i < 10; i++) {
            list.add(i*2);
        }

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + "\t");
        }

        moveValue(list);

        System.out.print("\n");
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + "\t");
        }

    }

    public static void moveValue(List<Integer> list){
        int value = 8;
        Integer aux;

        for (int i = 0; i < list.size(); i++) {
            if(value == list.get(i).intValue()){
                aux = list.remove(i);
               list.add(0,aux);
            }
        }
    }

}
