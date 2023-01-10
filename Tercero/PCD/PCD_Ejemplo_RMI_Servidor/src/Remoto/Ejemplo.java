package Remoto;

import IRemoto.IEjemplo;
import java.rmi.server.UnicastRemoteObject;
import java.rmi.RemoteException;

/**
 *
 * @author Grefuwan
 */
public class Ejemplo extends UnicastRemoteObject implements IEjemplo {

    private volatile int contador;

    public Ejemplo(int vInicial) throws RemoteException {
        super();
        contador = vInicial;
    }

    public synchronized int incrementa(String quien, int valor) {
        contador += valor;
        System.out.println(quien + " incrementa el contador en " + valor + " y queda: " + contador
                + "desde el hilo " + Thread.currentThread().getId());
        return contador;
    }

}

