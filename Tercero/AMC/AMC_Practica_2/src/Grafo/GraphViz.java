package Grafo;

import Automatas.*;
import java.awt.Component;
import java.util.Set;
import java.io.*;
import java.util.HashSet;
import javax.swing.JFileChooser;

/**
 *
 * @author Juan Garcia Villagran
 */
public class GraphViz {

    static Set<String> estadosFinales = new HashSet<>();
    static Set<String> estados = new HashSet<>();
    static String textoFichero = "";

    public static void cargaEstadosAFD(AFD estadosAFD) {
        if (!estados.isEmpty() || !estadosFinales.isEmpty()) {
            estados.clear();
            estadosFinales.clear();
        }

        for (String ests : estadosAFD.getEstados()) {
            estados.add(ests);
            if (estadosAFD.esFinal(ests)) {
                estadosFinales.add(ests);
            }
        }

        System.out.println("GraphViz Estados:" + estados);
        System.out.println("GraphViz Estados Finales:" + estadosFinales);
    }

    public static void cargaEstadosAFND(AFND estadosAFND) {
        if (!estados.isEmpty() || !estadosFinales.isEmpty()) {
            estados.clear();
            estadosFinales.clear();
        }

        for (String ests : estadosAFND.getEstados()) {
            estados.add(ests);
            if (estadosAFND.esFinal(ests)) {
                estadosFinales.add(ests);
            }
        }
    }

    public static void cargaTextoAFD(String origen, String transicion, String destino) {
        textoFichero += origen + " -> " + destino.replaceAll("[^a-zA-Z0-9\\s]", "") + "[label = " + transicion + "]\n";
    }

    public static void cargaTextoAFNDNormal(String origen, String transicion, String destino) {
        textoFichero += origen + " -> " + destino.replaceAll("[^a-zA-Z0-9\\s]", "") + "[label = " + transicion + "]\n";
    }

    public static void cargaTextoAFNDLambda(String origen, String transicion, Set<String> destino) {
        textoFichero += origen + " -> " + destino.toArray()[1] + "[label = " + transicion + "]\n";
    }

    public static void generaDot(Component panelPadre) throws InterruptedException {
        try {
            System.out.println("GeneraDot Estados Finales: " + estadosFinales);
            String txt = """
                         digraph L {
                         fontname="Helvetica, Arial, sans-serif" 
                         node [fontname ="Helvetica, Arial, sans-serif" ]
                         edge [fontname ="Helvetica, Arial, sans-serif" ]
                         rankdir = LR;
                         node [shape = doublecircle]; """ + estadosFinales.toString().replaceAll("[^a-zA-Z0-9\\s]", "") + "\n"
                    + "node [shape = circle]; \n"
                    + textoFichero //Representacion AFD/ AFND
                    + "}";
            textoFichero = "";  //Limpio el GraphViz Dot
            System.out.println("TXT generaDot: " + txt);

            try ( FileWriter graphDot = new FileWriter(System.getProperty("user.home") + "\\Desktop\\graphDot.dot")) {
                graphDot.write(txt);
            }

            JFileChooser jfc = new JFileChooser();
            jfc.setCurrentDirectory(new java.io.File("C:\\Users\\" + System.getProperty("user.name") + "\\Desktop"));
            jfc.showOpenDialog(panelPadre);
            System.out.println("JFC Dot: " + jfc.getSelectedFile().getAbsolutePath());
            Runtime.getRuntime().exec("cmd /c start cmd.exe /K \" dot -Tpng " + jfc.getSelectedFile().getAbsolutePath() + " -o C:/Users/" + System.getProperty("user.name") + "/Desktop/grafo.png && exit  \" ");

            //dot -Tpng grafo.txt -o grafo.png
        } catch (IOException e) {
            e.printStackTrace();
            System.out.println("ERROR: GraphViz.generaDot");
        }

        /*EJEMPLO - https://graphviz.org/Gallery/directed/fsm.html
        digraph L {fontname="Helvetica, Arial, sans-serif" 
            node [fontname ="Helvetica, Arial, sans-serif" ]
            edge [fontname ="Helvetica, Arial, sans-serif" ]
            rankdir = LR;
            node [shape = doublecircle]; Q3;
            node [shape = circle];
            Q1 -> Q2[label = a];
            Q1 -> Q3[label = b];
            Q1 -> Q4[label = c];
            Q2 -> Q3[label = b];
            Q4 -> Q5[label = b];
            Q5 -> Q3[label = a]}
         */
    }

}

