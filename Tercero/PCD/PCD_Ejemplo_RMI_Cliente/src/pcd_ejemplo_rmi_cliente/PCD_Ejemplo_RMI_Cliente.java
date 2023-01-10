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
     */
    public static void main(String[] args) throws RemoteException, NotBoundException, MalformedURLException {
        // TODO code application logic here

        IEjemplo objremoto = (IEjemplo) Naming.lookup("rmi://172.17.22.46:2022/ejemremoto");

        int v = objremoto.incrementa("Juan Garcia", 50);
        System.out.println("El contador remoto queda en: " + v);
    }

}

