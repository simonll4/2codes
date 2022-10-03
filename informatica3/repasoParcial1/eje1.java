package informatica3.repasoParcial1;

import informatica3.utils.*;

import java.util.*;


/*
1. Hacer un método que reciba una lista y una pila, el método deberá
    modificar la lista original, eliminando las posiciones indicadas por cada nodo
    de la pila.
    Lista -> 2 ->4 ->6 ->8 ->9 ->3
    Pila -> 2 5
    Lista nueva-> 2 ->4 ->8 ->9
 */

public class eje1 {

    public static void main(String[] args) {
        ArrayStack<Integer> stack = new ArrayStack<>();
        List<Integer> list = new ArrayList<>();

        list.add(2);
        list.add(4);
        list.add(6);
        list.add(8);
        list.add(9);
        list.add(3);
        stack.push(2);
        stack.push(5);

        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + "\t");
        }
        System.out.print("\n");


        try {
            modifyList(list, stack);
        } catch (Exception e) {
            System.out.print("\nERROR INESPERADO");
        }
        for (int i = 0; i < list.size(); i++) {
            System.out.print(list.get(i) + "\t");
        }


    }

    public static void modifyList(List<Integer> list, ArrayStack<Integer> stack) throws Exception {
        list.remove(stack.topAndPop().intValue());
        list.remove(stack.topAndPop().intValue());


    }
}
