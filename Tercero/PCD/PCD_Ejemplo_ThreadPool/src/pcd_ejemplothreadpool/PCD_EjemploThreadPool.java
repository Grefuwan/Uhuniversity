package pcd_ejemplothreadpool;

import java.util.concurrent.ExecutionException;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.Future;

/**
 *
 * @author Grefuwan
 */
public class PCD_EjemploThreadPool {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws InterruptedException, ExecutionException {

        //Se crea el ThreadPool
        ExecutorService thp = Executors.newFixedThreadPool(3);
        Future<Integer>[] f = new Future[5];

        //Mando la Tarea i al ThreadPool -- No habria que hacer el start()
        for (int i = 0; i < 5; i++) {
            thp.submit(new HiloR(i));
            f[i] = thp.submit(new HiloC(i));   // Es para que no se quede esperando a que el HiloC calcule el id*10;
        }

        for (int i = 0; i < 5; i++) {
            System.out.println("El hilo devuelve: " + f[i].get());

        }

        //Para que se apague el ThreadPool -- No equivale a un join() ya que si pongo un sout abajo, el sout se va a ejecutar lo primero
        //                                      El join() esperaba a los hilos para seguir ejecutando; el shutdown no
        thp.shutdown(); //      --  No atiende más de las que tiene
        //thp.shutdownNow();    --  Corta todo que se está atendiendo y no atiende nada más
    }

}

