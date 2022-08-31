package informatica3.recursividad;

import java.util.*;

public class Main {

    public static void main(String[] args){

        int option;
        Scanner console = new Scanner(System.in);

        
        do{
            System.out.println();
            System.out.println("---------------------------------");
            System.out.println("INGRESE EL NUMERO DEL EJERCICIO");
            System.out.println("---------------------------------");
            option = console.nextInt();
            switch(option){
                case 0:
                    break;
                case 1:
                
                    break;
                case 2:

                    break;
                case 3:
                    break;
                default:
                    System.out.println("EJERCICIO SIN HACER O NUMERO INVALIDO");
            }
        }while(option!=0);



        console.close();
    }

}
