package AMC_Practica_1;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Graphics;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class MiCanvas extends Canvas {

    public MiCanvas() {
        super();
        this.setSize(390, 390);
    }

    @Override
    public void paint(Graphics g) {

        super.paint(g);
        this.setBackground(Color.WHITE);
        
        g.setColor(Color.BLACK);
        Punto pA = new Punto(16.47, 36.10);
        Punto pB = new Punto(16.47, 54.44);
        Punto pC = new Punto(20.09, 92.54);
        Punto pD = new Punto(22.39, 93.37);
        Punto pE = new Punto(25.23, 97.24);
        Punto pF = new Punto(22.00, 36.05);
        Punto pG = new Punto(19.41, 37.12);
        Punto pH = new Punto(20.47, 97.02);
        Punto pI = new Punto(17.20, 96.29);
        Punto pM = new Punto(04.15, 16.32);
        Punto pJ = new Punto(16.30, 97.22);
        Punto pK = new Punto(14.05, 98.12);
        //Varios arrPuntos inventados

        ArrayList<Punto> arrPuntos = new ArrayList<>();

        arrPuntos.add(pA);
        arrPuntos.add(pB);
        arrPuntos.add(pC);
        arrPuntos.add(pD);
        arrPuntos.add(pE);
        arrPuntos.add(pF);
        arrPuntos.add(pG);
        arrPuntos.add(pH);
        arrPuntos.add(pI);
        arrPuntos.add(pJ);
        arrPuntos.add(pK);
        arrPuntos.add(pM);

        for (int i = 0; i < arrPuntos.size(); i++) {
            g.drawOval((int) arrPuntos.get(i).getPuntoX(), (int) arrPuntos.get(i).getPuntoY(), 3, 3);
        }

    }
    
    
}
