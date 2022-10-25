//package pframe;
//
//public class Pruebas {
//
//    public static void main(String args[]) throws InterruptedException {
//
//        Recurso r = new Recurso();
//
//        //Sumador s1 = new Sumador(r, 0);
//        Thread h1 = new Thread(new Sumador(r, 0));  //Le tengo que pasar el runnable
//        Thread h2 = new Thread(new Sumador(r, 1));
//        Thread h3 = new Thread(new Sumador(r, 1));
//
//        //Lanzo los 3 hilos
//        h1.start();
//        h2.start();
//        h3.start();
//
//        //Espero a que acaben
//        h1.join();
//        h2.join();
//        h3.join();
//
//        int contadores[] = r.getContadores();
//        System.out.println("Contador 1 - " + contadores[0]);
//        System.out.println("Contador 2 - " + contadores[1]);
//    }
//}