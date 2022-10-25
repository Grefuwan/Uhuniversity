package ejemplohilos2;

public class Recurso {

    private int contador = 0;

    //Metodos que manipulan ese contador
    public void incrementa() {  //Acola
        contador++;
        
        //System.out.println("El hilo " + Thread.currentThread().getId() + " incrementa");
    }

    public void decrementa() { //Desacola
        contador--;
    }

    public void verContador() { //GetNum
        System.out.println("Contador = " + contador);
    }

}
