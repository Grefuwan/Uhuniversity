package pframe;

public class Sumador implements Runnable {

    MiCanvas cv;
    private Recurso r = new Recurso(cv);
    private int cual;

    public Sumador(Recurso r, int cual) {
        this.r = r;
        this.cual = cual;
    }

    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            r.incrementa(cual);
            try {
                Thread.sleep(100);
            } catch (InterruptedException ex) {

            }
        }
    }
}
