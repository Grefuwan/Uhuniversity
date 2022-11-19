package pcd_practica6;

import java.awt.*;
import static java.lang.Thread.sleep;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class MiCanvas extends Canvas {

    private final ArrayList<String> ColaEspera;
    private final ArrayList<String> ColaMaleta;

    private final ArrayList<String> ColaMano;
    private final ArrayList<String> ColaPerros;
    private String viMal;
    private String viMan;
    private int numPerros;
    public int numMaleta;

    private Image imgMaleta, imgMano, imgGalleta, imgPerro;

    public MiCanvas(int ancho, int alto) {
        super();
        this.setSize(ancho, alto);

        imgMaleta = Toolkit.getDefaultToolkit().getImage(getClass().getResource("imagenes/equipajeMaleta.png"));
        imgMano = Toolkit.getDefaultToolkit().getImage(getClass().getResource("imagenes/equipajeMano.png"));
        imgGalleta = Toolkit.getDefaultToolkit().getImage(getClass().getResource("imagenes/galleta.png"));
        imgPerro = Toolkit.getDefaultToolkit().getImage(getClass().getResource("imagenes/perro.png"));

        ColaEspera = new ArrayList();
        ColaMaleta = new ArrayList();
        ColaMano = new ArrayList();
        ColaPerros = new ArrayList();
        viMal = null;
        viMan = null;
        numPerros = 0;

        repaint();
    }

    @Override
    public void paint(Graphics g) {
        Image img = createImage(getWidth(), getHeight());
        Graphics og = img.getGraphics();

        Font f2 = new Font("Arial", Font.BOLD, 30);
        Font f3 = new Font("Arial", Font.BOLD + Font.CENTER_BASELINE, 18);

        og.setColor(Color.black);
        og.setFont(f2);
        og.drawString("Rayos X Maletas", 50, 85);
        og.drawString("Rayos X Mano", 500, 85);
        og.drawString("Cola Viajeros", 95, 500);
        og.drawString("Perros Policía", 800, 85);

        og.setColor(Color.lightGray);
        og.fillRect(50, 100, 100, 100);     //RX Maleta
        og.fillRect(175, 100, 100, 100);    //RX Maleta
        og.fillRect(500, 100, 100, 100);    //RX Mano
        og.fillRect(800, 100, 100, 100);    //Perro 1
        og.fillRect(915, 100, 100, 100);    //Perro 2

        int separacion = 0;

        og.setFont(f3);
        og.setColor(Color.blue);
        for (int i = 0; i < ColaEspera.size(); i++) {
            og.drawString(ColaEspera.get(i), separacion + 130, 550);
            separacion += 100;
        }

        for (int i = 0; i < ColaMaleta.size(); i++) {
            if (numMaleta == 0) {
                og.drawString(ColaMaleta.get(i), 65, 130);
                og.drawImage(imgMaleta, 65, 150, null);
            }
            if (numMaleta == 1) {
                og.drawString(ColaMaleta.get(i), 190, 130);
                og.drawImage(imgMaleta, 190, 150, null);
            }
        }

        for (int i = 0; i < ColaMano.size(); i++) {
            og.drawString(ColaMano.get(i), 515, 130);
            og.drawImage(imgMano, 515, 150, null);
        }

        for (int i = 0; i < ColaPerros.size(); i++) {
            if (numPerros == 1) {
                og.drawString(ColaPerros.get(i), 815, 130);
            }
            if (numPerros == 0) {
                og.drawString(ColaPerros.get(i), 930, 130);
            }
        }

        g.drawImage(img, 0, 0, null);
    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    public void llegaViajeroMaleta(int idMaleta) {
        ColaEspera.add("VMal[" + idMaleta + "]");
        repaint();
    }

    public void insertaMaletaRayos(int idMaleta, int numMaleta) {
        viMal = "VMal[" + idMaleta + "]";
        this.numMaleta = numMaleta;
        ColaEspera.remove(viMal);
        ColaMaleta.add(viMal);
        repaint();
    }

    public void llegaViajeroMano(int idMano) {
        ColaEspera.add("VMano[" + idMano + "]");
        repaint();
    }

    public void insertaManoRayos(int idMano) {
        viMan = "VMano[" + idMano + "]";
        ColaEspera.remove(viMan);
        ColaMano.add(viMan);
        repaint();
    }

    public void pintaPerros(int numPerro) {
        numPerros = numPerro;
        ColaPerros.add(viMal);
        repaint();
    }

    public void borraMaleta() throws InterruptedException {
        sleep(1000);
        ColaMaleta.remove(0);
        repaint();
    }

    public void borraMano() throws InterruptedException {
        sleep(1000);
        ColaMano.remove(0);
        repaint();
    }

    public void borraPerros() throws InterruptedException {
        sleep(1200);
        ColaPerros.remove(0);
        repaint();
    }

    public void pintaGalleta() {
        repaint();
    }

}

