package pframe;

import java.awt.Canvas;
import java.awt.Color;
import java.awt.Font;
import java.awt.Graphics;
import java.awt.Image;

public class MiCanvas extends Canvas {

    private int contadores[] = {0,0};
    
    
    public MiCanvas(int ancho, int alto) {
        super();
        this.setSize(ancho, alto);
        this.setBackground(Color.LIGHT_GRAY);
    }

    public void representa(int[] contadores) {
        this.contadores = contadores;
        repaint();  //Borra lo que hay y vuelve a invocar el paint
            //repaint -> update -> borrar y paint
    }

    @Override
    public void update(Graphics g){
        paint(g);
    }
    
    @Override
    public void paint(Graphics g) {

        //Cambiar la fuente
        Font f1 = new Font("Arial", Font.BOLD + Font.ITALIC, 20);
        Font f2 = new Font("Algerian", Font.BOLD + Font.CENTER_BASELINE, 20);
        
        Image img = createImage(getWidth(), getHeight());   //Crea una Imagen del ancho y alto del Canvas
        Graphics og = img.getGraphics();  //Obtengo la capacidad de pintar en la imagen, lo pinto en ella y LUEGO plasmo la imagen

        //Color de la letra -> g.setcolor( ) - Va a pintar del color que le ponga todo lo que le siga hasta el proximo g.setColor()
        //Fuentes   -> g.setFont(fuente) - Igual que arriba
        //Cuadrado  -> g.drawRect(posX, posY, Ancho, Alto)  //  g.fillRect
        //Circulo   -> g.drawOval(posX, posY, Ancho, Alto)  //  g.fillOval
        og.setColor(Color.RED);
        og.setFont(f1);
        og.drawString("Contador 1 = " + contadores[0], 100, 50);
        og.fillRect(50, 30, 20, 30); //Dibuja un rectángulo

        og.setColor(Color.BLUE);
        og.setFont(f2);
        og.drawString("Contador 2 = " + contadores[1], 100, 100);
        og.fillOval(50, 80, 20, 30);
        
        g.drawImage(img, 0, 0, null);
    }
}
