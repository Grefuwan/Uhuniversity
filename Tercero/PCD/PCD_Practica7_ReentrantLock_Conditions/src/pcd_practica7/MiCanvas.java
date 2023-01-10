package pcd_practica7;

import java.awt.*;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class MiCanvas extends Canvas {

    private final ArrayList<String> ColaEspera = new ArrayList<>();
    private final ArrayList<String> ColaLavando = new ArrayList<>();

    private String[] laterales = new String[2];
    private String central;

    public MiCanvas(int ancho, int alto) {
        super();
        this.setSize(ancho, alto);

        for (int i = 0; i < 3; i++) {
            ColaLavando.add("");
            System.out.println("Cola Lavando " + i + ": " + ColaLavando.get(i));
        }

        repaint();
    }

    @Override
    public void paint(Graphics g) {
        Image img = createImage(getWidth(), getHeight());
        Graphics og = img.getGraphics();

        int separacion = 0;

        Font f1 = new Font("Arial", Font.BOLD, 70);
        Font f2 = new Font("Arial", Font.BOLD, 30);

        og.setColor(Color.LIGHT_GRAY);
        og.setFont(f1);

        og.fillRect(50, 85, 100, 100);  //Tunel 1
        og.fillRect(200, 85, 100, 100); //Tunel 2
        og.fillRect(350, 85, 100, 100); //Tunel 3

        for (int i = 0; i < 10; i++) {
            og.fillRect(separacion + 100, 400, 100, 100);   //Huecos de la Cola de Espera
            separacion += 110;
        }

        og.setFont(f2);
        og.setColor(Color.black);

        separacion = 0;

        for (int i = 0; i < ColaEspera.size(); i++) {
            og.drawString(ColaEspera.get(i), separacion + 130, 450);    //Rellenamiento de la Cola de Espera
            separacion += 100;
        }

        if (!ColaLavando.isEmpty()) {
            if (!ColaLavando.get(0).isBlank()) {
                og.drawString(ColaLavando.get(0), 65, 95);
            }
            if (!ColaLavando.get(1).isBlank()) {
                og.drawString(ColaLavando.get(1), 215, 95);
            }
            if (!ColaLavando.get(2).isBlank()) {
                og.drawString(ColaLavando.get(2), 365, 95);
            }
        }

        og.setColor(Color.black);
        og.setFont(f1);
        og.drawString("Cola de Espera", 400, 600);

        g.drawImage(img, 0, 0, null);

        try {
            Thread.sleep(1000);
        } catch (InterruptedException ex) {
            Logger.getLogger(MiCanvas.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    public synchronized void representaCocheEspera(int idCoche) {
        ColaEspera.add("C [" + idCoche + "]");
        repaint();
    }

    public synchronized void representaFurgoEspera(int idFurgo) {
        ColaEspera.add("F [" + idFurgo + "]");
        repaint();
    }

    public synchronized void representaCocheLavando(int id) {
        ColaLavando.set(id % 3, "C [" + id + "]");
        ColaEspera.remove("C [" + id + "]");
        repaint();
    }

    public synchronized void borraCoche(int id) {
        ColaLavando.set(id % 3, "");
        repaint();
    }

    public synchronized void representaFurgoLavando(int id) {
        ColaLavando.set(id % 3, "F [" + id + "]");
        ColaEspera.remove("F [" + id + "]");
        repaint();
    }

    public synchronized void borraFurgo(int id) {
        ColaLavando.set(id % 3, "");
        repaint();
    }

}

