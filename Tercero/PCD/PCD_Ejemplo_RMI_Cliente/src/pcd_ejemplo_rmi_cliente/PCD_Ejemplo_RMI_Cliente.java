package pcd_ejemplo_rmi_cliente;

import IRemoto.IEjemplo;
import java.net.MalformedURLException;
import java.rmi.Naming;
import java.rmi.NotBoundException;
import java.rmi.RemoteException;

/**
 *
 * @author Grefuwan
 */
public class PCD_Ejemplo_RMI_Cliente {

    /**
     * @param args the command line arguments
     * @throws java.rmi.RemoteException
     * @throws java.rmi.NotBoundException
     * @throws java.net.MalformedURLException
     */
    public static void main(String[] args) throws RemoteException, NotBoundException, MalformedURLException {
        // TODO code application logic here

        IEjemplo objremoto = (IEjemplo) Naming.lookup("rmi://127.0.0.1:2022/ejemremoto");

        int v = objremoto.incrementa("Juan Garcia", 50);
        System.out.println("El contador remoto queda en: " + v);
    }

}

