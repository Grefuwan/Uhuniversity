package PCD_Practica1;

import java.util.Random;

public class UsaCola {

    public static void main(String[] args) throws Exception {

        Random r = new Random();
        r.setSeed(System.nanoTime());
        Cola col = new Cola(4);

        for (int i = 1; i <= 25; i++) {
            int j = r.nextInt(100);
            try {
                if ((j % 2) == 0) {
                    col.Acola(i);
                    System.out.println("Acola: " + i);
                    System.out.println("Cola: " + col.toString() + "\n");
                } else {
                    col.Desacola();
                    System.out.println("Desacola: " + i);
                    System.out.println("Cola: " + col.toString() + "\n");
                }

            } catch (Exception e) {
                System.out.println("Error: " + e.getMessage());
            }

        }

        System.out.println("Cola: " + col.toString());

    }

}
