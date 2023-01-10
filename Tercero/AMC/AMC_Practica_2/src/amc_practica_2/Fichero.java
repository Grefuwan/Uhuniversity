package amc_practica_2;

import Automatas.*;
import java.io.File;
import java.io.FileNotFoundException;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;
import javax.swing.JButton;
import javax.swing.JFileChooser;

/**
 *
 * @author Juan Garcia Villagran
 */
public class Fichero {

    File fichero;
    private Scanner scannerLectura;

    Set<String> estados, estadosFinales, estadosLambda;
    List<Transicion> listaTransicion;
    List<TransicionLambda> listaTransicionLambda;
    String estadoInicial;

    int contadorAFND = 0;

    public File seleccionaRutaArchivo() {
        JFileChooser fc = new JFileChooser();
        JButton open = new JButton();

        fc.setCurrentDirectory(new java.io.File("C:\\Users\\" + System.getProperty("user.name") + "\\Desktop"));
        fc.setDialogTitle("Selecciona el archivo a escoger");
        fc.setFileSelectionMode(JFileChooser.FILES_AND_DIRECTORIES); //
        if (fc.showOpenDialog(open) == JFileChooser.APPROVE_OPTION) {

        }

        fichero = fc.getSelectedFile();
        System.out.println("Archivo seleccionado: " + fc.getSelectedFile().getAbsolutePath());

        return fichero;
    }

    public String devuelveAutomata() {

        return "ESTADOS: " + estados
                + "\tEstado Inicial: " + estadoInicial
                + "\tEstados Finales: " + estadosFinales
                + "\tTransiciones: \n"
                + listaTransicion
                + listaTransicionLambda;
    }

    /**
     * Metodo que se encarga de extraer del fichero los datos para formar un AFD
     *
     * @param fich Fichero del que se extraen los datos
     *
     * @return Un objeto AFD con el que trabajar
     *
     * @throws Exception
     */
    public AFD ficheroCargaAFD(File fich) throws Exception {
        String tmp = "";
        estadoInicial = "";
        estados = new HashSet<>();
        estadosFinales = new HashSet<>();
        estadosLambda = new HashSet<>();
        listaTransicion = new ArrayList<>();
        listaTransicionLambda = new ArrayList<>();

        //Abre fichero
        try {
            scannerLectura = new Scanner(fich);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        //Lee fichero
        while (scannerLectura.hasNext()) {

            if (tmp.contentEquals("ESTADOS:")) {
                System.out.println("AFD Carga Estados");
                while (!tmp.contentEquals("INICIAL:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("INICIAL:")) {
                        break;
                    }
                    System.out.println(tmp);
                    estados.add(tmp);
                }
                System.out.println("AFD Estados Cargados");
            }

            if (tmp.contentEquals("INICIAL:")) {
                System.out.println("AFD Carga Estados Iniciales");
                while (!tmp.contentEquals("FINALES:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("FINALES:")) {
                        break;
                    }
                    estadoInicial = tmp;
                }
                System.out.println("AFD Estado Inicial Cargados");

            }

            if (tmp.contentEquals("FINALES:")) {
                System.out.println("AFD Carga Estados finales");
                while (!tmp.contentEquals("TRANSICIONES:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("TRANSICIONES:")) {
                        break;
                    }
                    estadosFinales.add(tmp);
                }
                System.out.println("AFD Estados Finales Cargados");
            }

            if (tmp.contentEquals("TRANSICIONES:")) {
                System.out.println("AFD Carga Transiciones");
                tmp = scannerLectura.nextLine();
                while (!tmp.contentEquals("FIN")) {
                    tmp = scannerLectura.nextLine();
                    if (tmp.contentEquals("FIN")) {
                        break;
                    }
                    String[] transi = tmp.split("\\s+");
                    System.out.println("Transicion: " + transi[0] + transi[1] + transi[2]);
                    listaTransicion.add(new Transicion(transi[0], transi[1], transi[2]));
                }
                System.out.println("AFD Transiciones Cargadas");
            }
            if (!tmp.contentEquals("FIN")) {
                tmp = scannerLectura.next();
            }
        }
        System.out.println("AFD Montado");
        return new AFD(estados, estadoInicial, estadosFinales, listaTransicion);

    }

    public AFND ficheroCargaAFND(File fich) throws Exception {

        String tmp = "";
        estadoInicial = "";
        estados = new HashSet<>();
        estadosFinales = new HashSet<>();
        estadosLambda = new HashSet<>();
        listaTransicion = new ArrayList<>();
        listaTransicionLambda = new ArrayList<>();

        //Abre fichero
        try {
            scannerLectura = new Scanner(fich);
        } catch (FileNotFoundException e) {
            e.printStackTrace();
        }

        //Lee fichero
        while (scannerLectura.hasNext()) {
            if (tmp.contentEquals("ESTADOS:")) {
                System.out.println("AFND Carga Estados");
                while (!tmp.contentEquals("INICIAL:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("INICIAL:")) {
                        break;
                    }
                    System.out.println(tmp);
                    estados.add(tmp);
                }
                System.out.println("AFND Estados Cargados");
            }

            if (tmp.contentEquals("INICIAL:")) {
                System.out.println("AFND Carga Estados Iniciales");
                while (!tmp.contentEquals("FINALES:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("FINALES:")) {
                        break;
                    }
                    estadoInicial = tmp;
                }
                System.out.println("AFND Estado Inicial Cargados");

            }

            if (tmp.contentEquals("FINALES:")) {
                System.out.println("AFND Carga Estados finales");
                while (!tmp.contentEquals("TRANSICIONES:")) {
                    tmp = scannerLectura.next();
                    if (tmp.contentEquals("TRANSICIONES:")) {
                        break;
                    }
                    estadosFinales.add(tmp);
                }
                System.out.println("AFND Estados Finales Cargados");
            }

            if (tmp.contentEquals("TRANSICIONES:")) {
                tmp = scannerLectura.nextLine();
                while (!tmp.contentEquals("FIN")) {
                    tmp = scannerLectura.nextLine();

                    if (tmp.contains("FIN")) {
                        break;
                    }

                    String[] elementos = tmp.split("\\s+");
                    System.out.println("Elementos AFND: " + elementos[0] + elementos[1] + elementos[2]);

                    if (tmp.contains("lambda")) {
                        String[] elemSinLambda = tmp.replaceAll("lambda", "").split("\\s+");
                        estadosLambda = new HashSet<>();
                        estadosLambda.addAll(Arrays.asList(elemSinLambda));
                        listaTransicionLambda.add(new TransicionLambda(elemSinLambda[0], estadosLambda));
                    }
                    else {
                        listaTransicion.add(new Transicion(elementos[0], elementos[1], elementos[2]));
                    }
                }
            }
            if (!tmp.contentEquals("FIN")) {
                tmp = scannerLectura.next();
            }
        }

        Set<String> estIni = new HashSet<>();
        estIni.add(estadoInicial);
        return new AFND(estados, estIni, estadosFinales, listaTransicion, listaTransicionLambda);

    }

}

