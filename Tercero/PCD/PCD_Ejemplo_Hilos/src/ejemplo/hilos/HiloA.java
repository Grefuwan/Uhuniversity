package ejemplo.hilos;

public class HiloA extends Thread {

    private int id;

    public HiloA(int id) {
        this.id = id;
        setPriority(id);
        //Prioridad va de 1 a 10
    }

    @Override
    public void run() {
        for (int i = 0; i < id * 5; i++) {
            System.out.println("Soy el hilo: " + id
                    + " con ID: " + getId()
                    + " y nombre: " + getName()
                    + " y estado: " + getState()
                    + " y prioridad: " + getPriority());
            try {
                Thread.sleep(1000);
            } catch (InterruptedException ex) {
            }
        }

    }
}
