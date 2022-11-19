package pcd_practica5;

import static java.lang.Thread.sleep;
import java.util.Random;

/**
 *
 * @author Grefuwan
 */
public class JFrame_Generador extends javax.swing.JFrame {

    /**
     * Creates new form JFrame_Tunel
     */
    public JFrame_Generador() {
        initComponents();
    }

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 400, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 300, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) throws InterruptedException {
        int numVehiculos = 10;
        int turnoVehiculo = 0;
        Random r = new Random();
        r.setSeed(System.nanoTime());

        Thread[] vehiculo = new Thread[numVehiculos];

        JFrame_Generador jframe = new JFrame_Generador();
        jframe.setSize(1280, 768);
        MiCanvas cv = new MiCanvas(jframe.getWidth(), jframe.getHeight());
        Tunel t = new Tunel(cv);

        jframe.add(cv);
        jframe.setVisible(true);

        //Entrada vehiculos
        for (int i = 0; i < numVehiculos; i++) {
            turnoVehiculo = r.nextInt(10) + 1;

            if (turnoVehiculo < 7) {
                System.out.println("Crea Hilo Coche");
                vehiculo[i] = new Coche(t, cv);
            }

            else {
                System.out.println("Crea Hilo Furgo");
                vehiculo[i] = new Thread(new Furgo(t, cv));
            }

            vehiculo[i].start();
            System.out.println("Estado intermedio del Tunel: " + t.toString() + "\n");
            Thread.sleep((r.nextInt(2) + 1) * 1000);
        }

        //Salida vehiculos
        for (int i = 0; i < numVehiculos; i++) {
            System.out.println("Salida del vehiculo " + i);
            vehiculo[i].join();
        }

    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    // End of variables declaration//GEN-END:variables
}

