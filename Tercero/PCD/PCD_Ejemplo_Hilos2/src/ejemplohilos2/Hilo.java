package ejemplohilos2;

public class Hilo extends Thread {

    //Recurso r = new Recurso();
        //Si lo pongo ahi, crea 2 objetos, luego los contadores serán distintos; lo tengo que instanciar en la main
        // y lo paso como parametro aqui al constructor. De esta forma habré creado 1 Recurso en la main con 2 hilos
    private Recurso r;
    
    public Hilo(Recurso r){
        this.r = r;
    }
    
    
    @Override
    public void run() {
        for (int i = 0; i < 100; i++) {
            r.incrementa();

        }
        
        r.verContador();
    }

}
