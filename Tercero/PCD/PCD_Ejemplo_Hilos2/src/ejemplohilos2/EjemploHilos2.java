package ejemplohilos2;

public class EjemploHilos2 {

    public static void main(String[] args) throws InterruptedException {

        Recurso r = new Recurso();

        r.incrementa();
        r.incrementa();
        
        Hilo h1 = new Hilo(r);
        Hilo h2 = new Hilo(r);

        h1.start();
        h2.start();

        h1.join();
        h2.join();
        
        r.verContador();

    }

}
