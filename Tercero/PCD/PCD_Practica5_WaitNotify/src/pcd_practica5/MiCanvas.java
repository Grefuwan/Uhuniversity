package pcd_practica5;

import java.awt.*;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class MiCanvas extends Canvas {

    private ArrayList<String> ColaEspera;

    private String Coche;
    private String Furgo;

    private char donde;

    public MiCanvas(int ancho, int alto) {
        super();

        ColaEspera = new ArrayList<>();
        Coche = null;
        Furgo = null;

        this.setSize(ancho, alto);
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

        og.fillRect(50, 85, 100, 100);
        og.fillRect(200, 85, 100, 100);
        og.fillRect(350, 85, 100, 100);

        for (int i = 0; i < 10; i++) {
            og.fillRect(separacion + 100, 400, 100, 100);
            separacion += 110;
        }

        og.setFont(f2);
        og.setColor(Color.black);

        separacion = 0;

        for (int i = 0; i < ColaEspera.size(); i++) {
            og.drawString(ColaEspera.get(i), separacion + 130, 450);
            separacion += 100;
        }

        if (Coche != null || Furgo != null) {

            if (donde == 'I' && Coche != null) {
                og.drawString(Coche, 50, 85);
            }
            else if (donde == 'C' && Coche != null) {
                og.drawString(Coche, 200, 85);
            }
            else if (donde == 'D' && Coche != null) {
                og.drawString(Coche, 350, 85);
            }

            else if (donde == 'I' && Furgo != null) {
                og.drawString(Furgo, 50, 85);
            }
            else if (donde == 'C' && Furgo != null) {
                og.drawString(Furgo, 200, 85);
            }
            else if (donde == 'D' && Furgo != null) {
                og.drawString(Furgo, 350, 85);
            }
        }

        og.setColor(Color.black);
        og.setFont(f1);
        og.drawString("Cola de Espera", 400, 600);

        g.drawImage(img, 0, 0, null);
    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    public synchronized void representaCoche(int idCoche) {
        ColaEspera.add("C [" + idCoche + "]");
        repaint();
    }

    public synchronized void representaFurgo(int idFurgo) {
        ColaEspera.add("F [" + idFurgo + "]");
        repaint();
    }

    public synchronized void insertaCoche(int id, char donde) {
        Coche = "C [" + id + "]";
        this.donde = donde;
        ColaEspera.remove("C [" + id + "]");
        repaint();
    }

    public synchronized void borraCoche() {
        Coche = null;
        repaint();
    }

    public synchronized void insertaFurgo(int id, char donde) {
        Furgo = "F [" + id + "]";
        this.donde = donde;
        ColaEspera.remove("F [" + id + "]");
        repaint();
    }

    public synchronized void borraFurgo() {
        Furgo = null;
        repaint();
    }

}

