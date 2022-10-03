package informatica3.repasoParcial1;

/*
implemente una funcion recursiva que dado un array de caracteres indique cuantas vocales hay en un arreglp
 */
public class resursividadEj {


    public static void main(String[] args) {
        char[] array = {'h', 'o', 'l', 'a', 's','u','e','a'};
        int size = array.length;


        System.out.println("la cantidad de vocales es: " + cantidadVocales(array,size));


    }

    public static int cantidadVocales(char[] array, int size) {
        int n = 0;
        size--;

        //caso base
        if (size == 0) {
            if (array[0] == 'a' || array[0] == 'e' || array[0] == 'i' || array[0] == 'o' || array[0] == 'u') return 1;
            return 0;
        }
        //caso recursivo
        if (array[size] == 'a' || array[0] == 'e' || array[size] == 'i' || array[size] == 'o' || array[size] == 'u') n = 1;
        return n + cantidadVocales(array,size);
    }

}

