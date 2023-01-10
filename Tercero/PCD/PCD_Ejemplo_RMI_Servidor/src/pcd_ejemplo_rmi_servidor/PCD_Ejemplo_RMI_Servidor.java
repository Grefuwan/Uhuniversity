package pcd_ejemplo_rmi_servidor;

import Remoto.Ejemplo;
import java.io.IOException;
import java.rmi.RemoteException;

import java.rmi.registry.Registry;
import java.rmi.registry.LocateRegistry;
/**
 *
 * @author Grefuwan
 */
public class PCD_Ejemplo_RMI_Servidor {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws RemoteException, IOException {

        Ejemplo e = new Ejemplo(0);

        int v = e.incrementa("main", 7);
        System.out.println("Main Invocador: he incrementado y vale " + v);

        //Creo el servidor
        //Creo el registro: guarda peticiones de acceso
        Registry reg = LocateRegistry.createRegistry(2022);
        reg.rebind("ejemremoto", reg);

        System.out.println("Pulsa intro para terminar");
        System.in.read();
        System.exit(0);

    }

}

