package ejemplo.hilos;

public class EjemploHilos {

    public static void main(String[] args) throws InterruptedException {

        //HiloA h1 = new HiloA(1);
        //HiloA h2 = new HiloA(2);
        HiloB r3 = new HiloB(3);
        Thread h3 = new Thread(r3); //A un hilo vacío se le puede pasar un hilo runnable como parámetro
        Thread h4 = new Thread(r3);
        
        //Para que se ejecute de forma concurrente debo lanzar el metodo run, pero normal sería de forma secuencial
        //Para hacerlo de forma concurrente es:
        System.out.println("Comienzan los hilos");

        Thread yo = Thread.currentThread();
        System.out.println("Soy el hilo main"
                + " con ID: " + yo.getId()
                + " y nombre: " + yo.getName()
                + " y estado: " + yo.getState()
                + " y prioridad: " + yo.getPriority());
        //Como el main no extiende de Thread, hay que ponerle Thread.currentThread().

        //h1.start();
        //h2.start();
        h3.start();
        h4.start();

        //h1.join();
        //h2.join();
        h3.join();
        h4.join();
        
        System.out.println("Finalizan los hilos");

        //Si lo hubieramos hecho con el run, primero habria salido todo el h1, luego todo el h2 y por ultimo el "Finalizan los hilos"
        //Con los start, h1 y h2 se hacen concurrente con el hilo main; si pongo luego un 
        //      system.exit(0);
        //Tal como llega concurrente a system.exit(0) se cortan todos los hilos
        //Con los .join() hace que el hilo main se espere a que h1 y h2 terminen para continuar
    }

}
