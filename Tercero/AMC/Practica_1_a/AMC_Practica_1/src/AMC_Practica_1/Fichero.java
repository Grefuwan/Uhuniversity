package AMC_Practica_1;

import java.io.File;
import java.util.ArrayList;
import java.util.Scanner;
import javax.swing.*;

/**
 *
 * @author Grefuwan
 */
public class Fichero {

    File fichero;
    private Scanner scannerLectura;

    public Fichero() {

    }

    public File seleccionaRutaArchivo() {
        JFileChooser fc = new JFileChooser();
        JButton open = new JButton();

        fc.setCurrentDirectory(new java.io.File("C:\\Users\\Grefuwan\\Desktop"));
        fc.setDialogTitle("Selecciona el archivo a escoger");
        fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES); //
        if (fc.showOpenDialog(open) == JFileChooser.APPROVE_OPTION) {

        }

        fichero = fc.getSelectedFile();
        System.out.println("Archivo seleccionado: " + fc.getSelectedFile().getAbsolutePath());

        return fichero;
    }

    public ArrayList<Punto> puntosFichero(File fich) throws Exception {

        String numPunto = "";
        String cordX = "";
        String cordY = "";
        String tmp = "";

        ArrayList<Punto> mapa = new ArrayList();
        //Map<Integer, Punto> mapa = new HashMap<>();

        //Abre el Fichero
        try {
            scannerLectura = new Scanner(fich);
        } catch (Exception e) {
            throw new Exception("Error: Abrir fichero");
        }

        //Lee el Fichero
        while (scannerLectura.hasNext()) {
            tmp = scannerLectura.next();
            if (tmp.contentEquals("NODE_COORD_SECTION")) {
                while (!tmp.contentEquals("EOF")) {
                    numPunto = scannerLectura.next();

                    if (numPunto.contentEquals("EOF")) {
                        break;
                    }

                    cordX = scannerLectura.next();
                    cordY = scannerLectura.next();

                    System.out.println("Punto " + numPunto + ": [" + cordX + " , " + cordY + "]");

                    //Rescalado de puntos para que entre en el canvas
                    
                    mapa.add(new Punto(Double.parseDouble(cordX), Double.parseDouble(cordY)));

                }
            }

        }
        System.out.println("ArrayList de Puntos: " + mapa.toString());

        //Cierra el Fichero
        scannerLectura.close();
        System.out.println("Fichero Cerrado");
        return mapa;
    }

}

