package PCD_Practica3;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;

/**
 *
 * @author Grefuwan
 */
public class CanvasCola extends Canvas {

    private int head, tail, capacidad, numelementos = 0;
    private Object[] datos = {0, 0, 0, 0};
    private String mensaje = "";

    //alto 400 -- ancho 600
    public CanvasCola(int capacidad, int ancho, int alto) {
        super();
        this.capacidad = capacidad;
        this.setSize(ancho, alto);
        this.setBackground(Color.lightGray);

    }

    @Override
    public void paint(Graphics g) {
        Font colCirc    = new Font("Algerian", Font.PLAIN, 20);
        Font contElems  = new Font("Arial", Font.BOLD, 15);
        Font numers     = new Font("Arial", Font.BOLD, 35);

        Image img = createImage(getWidth(), getHeight());
        Graphics og = img.getGraphics();

        og.setFont(colCirc);
        og.setColor(Color.BLACK);
        og.drawString("Cola Circular", 160, 50);

        og.setFont(contElems);
        og.drawString("Numero Elementos: " + numelementos, 160, 80);
        
        //og.drawRect(int x, int y, ancho, alto);
        og.drawRect(25, 200, 100, 100);
        og.drawRect(150, 200, 100, 100);
        og.drawRect(275, 200, 100, 100);
        og.drawRect(400, 200, 100, 100);

        og.setFont(new Font("Arial", Font.PLAIN, 20));
        og.drawString(mensaje, 160, 115);

        og.setFont(numers);
        //og.drawString(String, int X, int Y);
        og.drawString(datos[0 % 4].toString(), 45, 250);
        og.drawString(datos[1 % 4].toString(), 145, 250);
        og.drawString(datos[2 % 4].toString(), 270, 250);
        og.drawString(datos[3 % 4].toString(), 395, 250);

        g.drawImage(img, 0, 0, null);
    }

    /**
     * Invocado cada vez que se invoca el método repaint() de la clase Canvas.
     * Borra el canvas, lo repinta con el color de fondo e invoda al método
     * paint
     */
    @Override
    public void update(Graphics g) {
        paint(g);
    }

    public void avisa(String mensaje) {
        this.mensaje = mensaje;
        repaint();
    }

    public void representa(Object[] buf, int head, int tail, int numelementos) {
        this.datos = buf;
        this.head = head;
        this.tail = tail;
        this.numelementos = numelementos;
        repaint();
    }

}

