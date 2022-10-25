package PCD_Practica1;

public class UsaCola {

    public static void main(String[] args) throws Exception {

        int tamaño = 3;
        Cola col = new Cola(tamaño);

        for (int i = 0; i < 10; i++) {
            int j = (int) Math.round(Math.random());
            System.out.println("Numero: " + j);
            if (j == 0) {
                col.Acola(i);
                System.out.println("Acola: " + i);
                System.out.println("Cola: " + col.toString() + "\n");

            } else {
                col.Desacola();
                System.out.println("Desacola: " + i);
                System.out.println("Cola: " + col.toString() + "\n");

            }
        }

        System.out.println("Cola: " + col.toString());

    }

}
