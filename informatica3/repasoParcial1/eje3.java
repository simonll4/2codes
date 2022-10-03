package informatica3.repasoParcial1;

/*
3. Escribir una función recursiva que tenga un parámetro que sea entero
    positivo y despliegue en la pantalla ese número de asteriscos: “*”, todos en
    una línea.
 */

public class eje3 {
    public static void main(String[] args) {
        int num = 5;

        try {
            printAsterick(num);
        }
        catch (Exception e){
            System.out.println("ERROR INESPERADO");
        }


    }

    public static void printAsterick(int n) throws Exception {
        if (n < 0) throw new Exception("Negative number");
        if(n > 0){
            System.out.print("*\t");
            printAsterick(n-1);
        }
    }
}
