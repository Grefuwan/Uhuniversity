package pframe;

public class Recurso {

    private int[] contadores = {0, 0};

    private MiCanvas cv;
    
    public Recurso(MiCanvas cv){
        this.cv = cv;
    }
    
    public synchronized void incrementa(int cual) {
        //Decide qué contador de los 2 se incrementa
        contadores[cual]++;
        //Si lo dejo public void incrementa(int cual){}, los contadores no llegan al maximo, luego le tengo que poner Synchronized
        
        cv.representa(contadores);
    }

    public int[] getContadores() {
        return contadores;
    }
}
