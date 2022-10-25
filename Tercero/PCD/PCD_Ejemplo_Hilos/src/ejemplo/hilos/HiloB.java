package ejemplo.hilos;

public class HiloB implements Runnable {

    private int id;
    private int suma = 0;

    public HiloB(int id) {
        this.id = id;
        Thread.currentThread().setPriority(id);
        //Prioridad va de 1 a 10
    }

    @Override
    public void run() {
        Thread yo = Thread.currentThread();
        for (int i = 0; i < 10; i++) {
            
            suma++;
            System.out.println("Soy el hilo: " + id
                    + " con ID: " + yo.getId()
                    + " y nombre: " + yo.getName()
                    + " y estado: " + yo.getState()
                    + " y prioridad: " + yo.getPriority());
           
        }
        System.out.println("Suma: " + suma);

    }
}
