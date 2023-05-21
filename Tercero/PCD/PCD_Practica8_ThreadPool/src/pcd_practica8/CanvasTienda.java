/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
package pcd_practica8;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;
import java.awt.MediaTracker;
import java.awt.Toolkit;
import java.awt.image.BufferedImage;
import java.awt.image.ColorModel;
import java.net.URL;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Random;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.ImageIcon;

/**
 *
 * @author pedro
 */
public class CanvasTienda extends Canvas {

    private class encola {

        int id;
        char tipo;

        public encola(int elid, char eltipo) {
            this.id = elid;
            this.tipo = eltipo;
        }
    }

    private final List colacompra = new LinkedList();
    private final List colarepara = new LinkedList();
    private final MediaTracker dibu;
    Image compradorimg[] = new Image[7], repararimg[]= new Image[7], empleadoA, empleadoB;
    private final Random rnd = new Random(System.currentTimeMillis());
    encola vendedor, mecanico;

    /**
     * 
     * @param ancho del frame
     * @param alto del frame
     * @throws InterruptedException 
     */
    public CanvasTienda(int ancho, int alto) throws InterruptedException {

        super.setSize(ancho, alto);
        super.setBackground(Color.white);

        for (int i = 0; i < 7; i++) {
            System.out.println("image/espera" +String.valueOf(i+1) + ".jpg");
            compradorimg[i] = Toolkit.getDefaultToolkit().getImage(getClass().getResource("image/espera" + String.valueOf(i+1) + ".jpg"));
        }for (int i = 0; i < 7; i++) {
            System.out.println("image/ciclista" +String.valueOf(i+1) + ".jpg");
            repararimg[i] = Toolkit.getDefaultToolkit().getImage(getClass().getResource("image/ciclista" + String.valueOf(i+1) + ".jpg"));
        }
        empleadoA = Toolkit.getDefaultToolkit().getImage(getClass().getResource("image/mecanico1.jpg"));
        empleadoB = Toolkit.getDefaultToolkit().getImage(getClass().getResource("image/Vendedor1.jpg"));

        dibu = new MediaTracker(this);
        for (int i = 0; i < 7; i++) {
            dibu.addImage(compradorimg[i], i);
            dibu.waitForID(i);

        }for (int i = 0; i < 7; i++) {
            dibu.addImage(repararimg[i], i+7);
            dibu.waitForID(i+7);

        }
        
        dibu.addImage(empleadoA, 15);
        dibu.waitForID(15);
        dibu.addImage(empleadoB, 16);
        dibu.waitForID(16);
       
        vendedor = null;
        mecanico = null;

    }

    /**
     * Inserta el id en la cola indicada. 
     * @param donde puede ser 'C' para la cola de "compra"
     * o 'R' paera la cola de reparación
     * @param id que se inserta en la cola
     */
    public synchronized void inserta(char donde, int id) {
        encola nuevo = new encola(id, donde);
        if (donde == 'C') {
            colacompra.add(nuevo);
        } else {
            colarepara.add(nuevo);
        }
        this.repaint();
    }

    /** 
     * Elimina el id de la cola indicada
     * @param donde puede ser 'C' para la cola de "compra"
     * o 'R' paera la cola de reparación
     * @param id que se inserta en la cola
     */
    public synchronized void quita(char donde, int id) {
        List cola;
        if (donde == 'C') {
            cola = colacompra;
        } else {
            cola = colarepara;
        }

        Iterator iter = cola.iterator();
        int i = 0;
        while (iter.hasNext()) {
            encola e = (encola) iter.next();
            if (e.id == id) {
                break;
            }
            i++;
        }
        if (i < cola.size()) {
            cola.remove(i);
        }
        this.repaint();

    }

    /**
     * Pone a Comprar el id que se pasa
     * @param en_cual Si es 'V' lo coloca con el vendedor y si es 'M' lo coloca con el mecánico
     * @param id que se visualizará en el sitio
     */
    public synchronized void repara(char en_cual, int id) {
        if (en_cual == 'V') {
            vendedor = new encola(id, 'R');
        } else {
            mecanico = new encola(id, 'R');
        }

        this.repaint();
    }

    /**
     * Pone a reparar el id que se pasa
     * @param en_cual Si es 'V' lo coloca con el vendedor y si es 'M' lo coloca con el mecánico
     * @param id que se visualizará en el sitio
     */
    public synchronized void compra(char en_cual, int id) {
        if (en_cual == 'V') {
            vendedor = new encola(id, 'C');
        } else {
            mecanico = new encola(id, 'C');
        }

        this.repaint();
    }

    /** 
     * Quita de comprar o reparar el id que se pasa
     * @param en_cual Si es 'V' lo quita del vendedor y si es 'M' lo quita del mecanico
     * @param id 
     */
    public void finalizado(char en_cual, int id) {
        if (en_cual == 'V') {
            vendedor = null;
        } else {
            mecanico = null;
        }
        repaint();

    }

    @Override
    public void update(Graphics g) {
        paint(g);
    }

    @Override
    public synchronized void paint(Graphics g) {
        BufferedImage imagen = new BufferedImage(getWidth(), getHeight(), ColorModel.OPAQUE);
        Font f1 = new Font("Arial", Font.BOLD, 12);
        Font f2 = new Font("Sans", Font.BOLD, 20);
        Graphics gbuf = imagen.getGraphics();
        gbuf.setColor(Color.GRAY);
        gbuf.fillRect(0, 0, getWidth(), getHeight());
        gbuf.setFont(f1);

        gbuf.setColor(Color.white);
        gbuf.fillRect(40, 20, getWidth() - 80, 100);
        gbuf.drawString("Cola de VENTAS", 40, 15);

        gbuf.setColor(Color.white);
        gbuf.fillRect(40, 140, (getWidth() - 100) / 2, 250);
        gbuf.setFont(f2);
        gbuf.setColor(Color.BLUE);
        gbuf.drawString("MECANICO", 230, 200);
        gbuf.drawImage(empleadoA, 230, 220, null);

        gbuf.setColor(Color.white);
        gbuf.fillRect(getWidth() / 2 + 10, 140, (getWidth() - 100) / 2, 250);
        gbuf.setColor(Color.RED);
        gbuf.drawString("VENDEDOR", getWidth() / 2 + 230, 200);
        gbuf.drawImage(empleadoB, 600, 220, null);

        gbuf.setFont(f1);
        gbuf.setColor(Color.white);
        gbuf.fillRect(40, 420, getWidth() - 80, 100);
        gbuf.drawString("Cola de REPARACION", 40, 415);

        gbuf.setColor(Color.black);

        Iterator iter = colacompra.iterator();
        int i = 0;
        while (iter.hasNext()) {
            encola e = (encola) iter.next();
            gbuf.drawString("     " + e.id + "   ", 60 + 70 * i, 40);
            gbuf.drawImage(compradorimg[e.id%7], 60 + 70 * i, 40, null);
            i++;
        }

        iter = colarepara.iterator();
        i = 0;
        while (iter.hasNext()) {
            encola e = (encola) iter.next();
            gbuf.drawString("     " + e.id + "   ", 60 + 70 * i, 440);
            gbuf.drawImage(repararimg[e.id%7], 60 + 70 * i, 440, null);
            i++;
        }

        if (mecanico != null) {
            if (mecanico.tipo == 'C') {
                gbuf.drawString("     " + mecanico.id + "   ", 60, 230);
                gbuf.drawImage(compradorimg[mecanico.id%7], 60, 230, null);
            } else {
                gbuf.drawString("     " + mecanico.id + "   ", 60, 230);
                gbuf.drawImage(repararimg[mecanico.id%7], 60, 230, null);

            }
        }

        if (vendedor != null) {
            if (vendedor.tipo == 'C') {
                gbuf.drawString("     " + vendedor.id + "   ", 450, 230);
                gbuf.drawImage(compradorimg[vendedor.id%7], 450, 230, null);
            } else {
                gbuf.drawString("     " + vendedor.id + "   ", 450, 230);
                gbuf.drawImage(repararimg[vendedor.id%7], 450, 230, null);

            }
        }

        g.drawImage(imagen, 0, 0, this);
        try {
            Thread.sleep(10);
        } catch (InterruptedException ex) {
            Logger.getLogger(CanvasTienda.class.getName()).log(Level.SEVERE, null, ex);
        }

    }
}
