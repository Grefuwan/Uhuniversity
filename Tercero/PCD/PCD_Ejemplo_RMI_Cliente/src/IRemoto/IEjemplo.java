package IRemoto;

import java.rmi.Remote;
import java.rmi.RemoteException;
/**
 *
 * @author Grefuwan
 */
public interface IEjemplo extends Remote{

    public int incrementa(String quien, int valor) throws RemoteException;

}

