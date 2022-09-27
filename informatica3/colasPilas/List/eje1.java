package informatica3.colasPilas.List;

import java.util.*;

import informatica3.utils.*;


public class eje1 {

    public static void main(String[] args) {

        ListQueue<String> workDate = new ListQueue<>();
        Scanner console = new Scanner(System.in);
        int option;


        workDate.enqueue("Simon Llamosas");
        workDate.enqueue("Juan Carlos Rodriguez");
        workDate.enqueue("Carlos Rodrigues");

        System.out.println("APUNTADOR DE CITAS");

        try {
            do {
                menu();
                option = console.nextInt();
                switch (option) {
                    case 0:
                        break;
                    case 1:
                        showWorkDate(workDate);
                        break;
                    case 2:
                        addWorkDate(workDate);
                        break;
                    case 3:
                        deleteWorkDate(workDate);
                        break;
                    case 4:
                        workDate.makeEmpty();
                        break;
                    default:
                }
            } while (option != 0);
        } catch (Exception e) {
            System.out.println("Error inesperado");
        }

    }

    public static void menu() {
        System.out.println("\nINGRESE LA OPCION REQUERIDA");
        System.out.println("0)SALIR.");
        System.out.println("1)MOSTRAR COLA DE CITAS.");
        System.out.println("2)AGREGAR CITA.");
        System.out.println("3)ELIMINAR CITA.");
        System.out.println("4)VACIAR COLA.");
    }

    public static void showWorkDate(ListQueue<String> workDate) throws Exception {
        ArrayQueue<String> newQueue = new ArrayQueue<>();
        String aux;
        int num = 1;

        System.out.println((workDate.isEmpty() ? "***NO HAY CITAS***\n" : ""));

        while (!workDate.isEmpty()) {
            aux = workDate.dequeue();
            System.out.println("Cita " + num + ":" + aux);
            newQueue.enqueue(aux);
            num++;
        }

        while (!newQueue.isEmpty()) {
            workDate.enqueue(newQueue.dequeue());
        }

    }

    public static void addWorkDate(ListQueue<String> workDate) {
        Scanner console = new Scanner(System.in);

        System.out.println("INGRESE EL NOMBRE DEL CLIENTE QUE DESEA AGREGAR A LA COLA DE ESPERA: ");
        workDate.enqueue(console.nextLine());
    }

    public static void deleteWorkDate(ListQueue<String> workDate) throws Exception {
        ArrayQueue<String> auxQueue = new ArrayQueue<>();
        String aux;
        Scanner console = new Scanner(System.in);
        Scanner console1 = new Scanner(System.in);
        int option = 0;
        String name;

        System.out.println("1)CITA ATENTIDA\n2)CANCELAR UNA CITA");
        option = console.nextInt();

        switch (option) {
            case 1:
                workDate.dequeue();
                break;
            case 2:
                System.out.println("A QUIEN DESEA ELIMINAR DE LA COLA?");
                showWorkDate(workDate);
                name = console1.nextLine();
                name.toLowerCase().trim();

                while (!workDate.isEmpty()) {
                    aux = workDate.dequeue().toLowerCase().trim();
                    if (!aux.equals(name)) {
                        auxQueue.enqueue(aux);
                    }
                }

                while (!auxQueue.isEmpty()) workDate.enqueue(auxQueue.dequeue());

                break;
            default:
                System.out.println("OPCION INCORRECTA");
        }
    }
}
