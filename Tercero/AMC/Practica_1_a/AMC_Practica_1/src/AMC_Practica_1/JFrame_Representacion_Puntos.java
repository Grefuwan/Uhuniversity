package AMC_Practica_1;

import Algoritmos.Distancias;
import java.awt.*;
import java.io.File;
import java.util.ArrayList;
import javax.swing.JOptionPane;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

/**
 *
 * @author Grefuwan
 */
public class JFrame_Representacion_Puntos extends javax.swing.JFrame {

    /**
     * Creates new form JFrame_Representacion_arrPuntos
     */
    public JFrame_Representacion_Puntos() {
        initComponents();

    }

    ArrayList<Punto> arrPuntos = new ArrayList<>();
    ArrayList<Punto> solucion = new ArrayList<>();
    Fichero fich = new Fichero();
    String metodoSeleccionado = "";

    /**
     * This method is called from within the constructor to initialize the form.
     * WARNING: Do NOT modify this code. The content of this method is always
     * regenerated by the Form Editor.
     */
    @SuppressWarnings("unchecked")
    // <editor-fold defaultstate="collapsed" desc="Generated Code">//GEN-BEGIN:initComponents
    private void initComponents() {

        jPanel_Lienzo = new javax.swing.JPanel();
        jButton_Dibujar = new javax.swing.JButton();
        jComboBox_Metodos = new javax.swing.JComboBox<>();
        jButton_Salir = new javax.swing.JButton();
        jLabel1 = new javax.swing.JLabel();
        jButton_SeleccionArchivo = new javax.swing.JButton();
        jButton_Borrar = new javax.swing.JButton();
        jButton_Buscar = new javax.swing.JButton();
        jButton_PuntosAleatorios = new javax.swing.JButton();
        jPanel1 = new javax.swing.JPanel();
        jLabel_Solucion = new javax.swing.JLabel();
        jMenuBar1 = new javax.swing.JMenuBar();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setBackground(java.awt.Color.darkGray);
        setMinimumSize(new java.awt.Dimension(1024, 600));

        jPanel_Lienzo.setBackground(new java.awt.Color(204, 204, 204));
        jPanel_Lienzo.setPreferredSize(new java.awt.Dimension(500, 500));

        javax.swing.GroupLayout jPanel_LienzoLayout = new javax.swing.GroupLayout(jPanel_Lienzo);
        jPanel_Lienzo.setLayout(jPanel_LienzoLayout);
        jPanel_LienzoLayout.setHorizontalGroup(
            jPanel_LienzoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 500, Short.MAX_VALUE)
        );
        jPanel_LienzoLayout.setVerticalGroup(
            jPanel_LienzoLayout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 0, Short.MAX_VALUE)
        );

        jButton_Dibujar.setText("Dibujar");
        jButton_Dibujar.setMaximumSize(new java.awt.Dimension(130, 23));
        jButton_Dibujar.setMinimumSize(new java.awt.Dimension(130, 23));
        jButton_Dibujar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_DibujarActionPerformed(evt);
            }
        });

        jComboBox_Metodos.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "--Seleccione Método--", "Exhaustivo", "Divide y Vencerás", "Dijkstra" }));
        jComboBox_Metodos.setPreferredSize(new java.awt.Dimension(72, 23));
        jComboBox_Metodos.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBox_MetodosActionPerformed(evt);
            }
        });

        jButton_Salir.setText("Salir");
        jButton_Salir.setMaximumSize(new java.awt.Dimension(130, 23));
        jButton_Salir.setMinimumSize(new java.awt.Dimension(130, 23));
        jButton_Salir.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_SalirActionPerformed(evt);
            }
        });

        jLabel1.setHorizontalAlignment(javax.swing.SwingConstants.CENTER);
        jLabel1.setText("Método a Seleccionar");

        jButton_SeleccionArchivo.setText("Selecciona Archivo");
        jButton_SeleccionArchivo.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_SeleccionArchivoActionPerformed(evt);
            }
        });

        jButton_Borrar.setText("Borrar");
        jButton_Borrar.setMaximumSize(new java.awt.Dimension(130, 23));
        jButton_Borrar.setMinimumSize(new java.awt.Dimension(130, 23));
        jButton_Borrar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_BorrarActionPerformed(evt);
            }
        });

        jButton_Buscar.setText("Buscar");
        jButton_Buscar.setMaximumSize(new java.awt.Dimension(130, 23));
        jButton_Buscar.setMinimumSize(new java.awt.Dimension(130, 23));
        jButton_Buscar.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_BuscarActionPerformed(evt);
            }
        });

        jButton_PuntosAleatorios.setText("Generar Puntos Aleatorios");
        jButton_PuntosAleatorios.setMaximumSize(new java.awt.Dimension(130, 23));
        jButton_PuntosAleatorios.setMinimumSize(new java.awt.Dimension(130, 23));
        jButton_PuntosAleatorios.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jButton_PuntosAleatoriosActionPerformed(evt);
            }
        });

        jPanel1.setBackground(new java.awt.Color(204, 204, 204));

        jLabel_Solucion.setBackground(new java.awt.Color(0, 0, 0));
        jLabel_Solucion.setForeground(new java.awt.Color(51, 153, 255));

        javax.swing.GroupLayout jPanel1Layout = new javax.swing.GroupLayout(jPanel1);
        jPanel1.setLayout(jPanel1Layout);
        jPanel1Layout.setHorizontalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, jPanel1Layout.createSequentialGroup()
                .addContainerGap(javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                .addComponent(jLabel_Solucion, javax.swing.GroupLayout.PREFERRED_SIZE, 319, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addContainerGap())
        );
        jPanel1Layout.setVerticalGroup(
            jPanel1Layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addComponent(jLabel_Solucion, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, 158, Short.MAX_VALUE)
        );

        setJMenuBar(jMenuBar1);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addComponent(jPanel_Lienzo, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(48, 48, 48)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING, false)
                    .addGroup(layout.createSequentialGroup()
                        .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.TRAILING, false)
                            .addComponent(jComboBox_Metodos, 0, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                            .addComponent(jLabel1, javax.swing.GroupLayout.DEFAULT_SIZE, 130, Short.MAX_VALUE))
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton_Dibujar, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(javax.swing.GroupLayout.Alignment.TRAILING, layout.createSequentialGroup()
                        .addComponent(jButton_Buscar, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton_Borrar, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addGroup(layout.createSequentialGroup()
                        .addComponent(jButton_SeleccionArchivo)
                        .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                        .addComponent(jButton_Salir, javax.swing.GroupLayout.PREFERRED_SIZE, 130, javax.swing.GroupLayout.PREFERRED_SIZE))
                    .addComponent(jPanel1, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE)
                    .addComponent(jButton_PuntosAleatorios, javax.swing.GroupLayout.Alignment.TRAILING, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, Short.MAX_VALUE))
                .addContainerGap(225, Short.MAX_VALUE))
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGroup(layout.createSequentialGroup()
                .addGap(6, 6, 6)
                .addComponent(jPanel_Lienzo, javax.swing.GroupLayout.DEFAULT_SIZE, 459, Short.MAX_VALUE))
            .addGroup(layout.createSequentialGroup()
                .addGap(15, 15, 15)
                .addComponent(jLabel1)
                .addGap(6, 6, 6)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton_Dibujar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jComboBox_Metodos, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton_Buscar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                    .addComponent(jButton_Borrar, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addGap(18, 18, 18)
                .addComponent(jButton_PuntosAleatorios, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addGap(30, 30, 30)
                .addComponent(jPanel1, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE)
                .addPreferredGap(javax.swing.LayoutStyle.ComponentPlacement.RELATED, 70, Short.MAX_VALUE)
                .addGroup(layout.createParallelGroup(javax.swing.GroupLayout.Alignment.BASELINE)
                    .addComponent(jButton_SeleccionArchivo)
                    .addComponent(jButton_Salir, javax.swing.GroupLayout.PREFERRED_SIZE, javax.swing.GroupLayout.DEFAULT_SIZE, javax.swing.GroupLayout.PREFERRED_SIZE))
                .addContainerGap(42, Short.MAX_VALUE))
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jButton_DibujarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_DibujarActionPerformed
        // TODO add your handling code here:
        Graphics dibujaLienzo = jPanel_Lienzo.getGraphics();
        int coordXRescaled, coordYRescaled;
        int minX = 500, minY = 500, maxX = 0, maxY = 0;
        ArrayList<Punto> puntosRescalados = new ArrayList<>();

        if (arrPuntos.isEmpty()) {
            JOptionPane.showMessageDialog(rootPane, "Error: ArrayList de Puntos Vacío");
        }
        else {
            jPanel_Lienzo.paintComponents(dibujaLienzo);
            for (int i = 0; i < arrPuntos.size(); i++) {
                if ((int) arrPuntos.get(i).getX() > maxX) {
                    maxX = (int) arrPuntos.get(i).getX();
                }

                if ((int) arrPuntos.get(i).getY() > maxY) {
                    maxY = (int) arrPuntos.get(i).getY();
                }

                if ((int) arrPuntos.get(i).getX() < minX) {
                    minX = (int) arrPuntos.get(i).getX();
                }

                if ((int) arrPuntos.get(i).getY() < minY) {
                    minY = (int) arrPuntos.get(i).getY();
                }
            }

            for (int i = 0; i < arrPuntos.size(); i++) {
                coordXRescaled = (450 * ((int) arrPuntos.get(i).getX() - minX) / (maxX - minX));
                coordYRescaled = (450 * ((int) arrPuntos.get(i).getY() - minY) / (maxY - minY));
                System.out.println("Coordenadas del Punto P" + i + " reescaladas: [" + coordXRescaled + " , " + coordYRescaled + "]");

                puntosRescalados.add(new Punto((double) coordXRescaled, (double) coordYRescaled));

                puntosRescalados.get(i).dibujaPuntos(dibujaLienzo, puntosRescalados.get(i));
            }
        }


    }//GEN-LAST:event_jButton_DibujarActionPerformed


    private void jButton_SalirActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_SalirActionPerformed
        // TODO add your handling code here:
        System.exit(0);
    }//GEN-LAST:event_jButton_SalirActionPerformed

    private void jButton_SeleccionArchivoActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_SeleccionArchivoActionPerformed
        // TODO add your handling code here:
        File fichPuntos = fich.seleccionaRutaArchivo();

        try {
            arrPuntos = fich.puntosFichero(fichPuntos);
        } catch (Exception ex) {
            System.out.println("Error al Seleccionar Archivo");
        }
    }//GEN-LAST:event_jButton_SeleccionArchivoActionPerformed

    private void jButton_BorrarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_BorrarActionPerformed
        // TODO add your handling code here:
        validate();
        repaint();
    }//GEN-LAST:event_jButton_BorrarActionPerformed

    private void jComboBox_MetodosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox_MetodosActionPerformed
        // TODO add your handling code here:
        metodoSeleccionado = jComboBox_Metodos.getSelectedItem().toString();
    }//GEN-LAST:event_jComboBox_MetodosActionPerformed

    private void jButton_BuscarActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_BuscarActionPerformed
        // TODO add your handling code here:
        switch (metodoSeleccionado) {
            case ("Dijkstra"):
                System.out.println("Dijkstra Seleccionado");
                break;
            case ("Divide y Vencerás"):
                System.out.println("DyV Seleccionado");
                Algoritmos.Alg_DyV.minDistanTresPuntosDyV(arrPuntos);
                solucion = Algoritmos.Alg_DyV.convierteTrianguloArray();
                break;
            case ("Exhaustivo"):
                System.out.println("Exhaustivo Seleccionado");
                solucion = Algoritmos.Alg_Exhaustivo.minDistanTresPuntosExhaustivo(arrPuntos);
                break;
        }
        
        System.out.println("Solucion: " + solucion.toString());

        jLabel_Solucion.setText("Solucion: " + solucion.toString());
    }//GEN-LAST:event_jButton_BuscarActionPerformed

    private void jButton_PuntosAleatoriosActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jButton_PuntosAleatoriosActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jButton_PuntosAleatoriosActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        int ancho = 800, alto = 500;

        JFrame_Representacion_Puntos frame = new JFrame_Representacion_Puntos();

        frame.setVisible(true);
        frame.setSize(ancho, alto);
        frame.setLocation(200, 100);
        frame.setTitle("Práctica 1 AMC");

    }


    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton jButton_Borrar;
    public javax.swing.JButton jButton_Buscar;
    public javax.swing.JButton jButton_Dibujar;
    public javax.swing.JButton jButton_PuntosAleatorios;
    private javax.swing.JButton jButton_Salir;
    public javax.swing.JButton jButton_SeleccionArchivo;
    public javax.swing.JComboBox<String> jComboBox_Metodos;
    private javax.swing.JLabel jLabel1;
    public javax.swing.JLabel jLabel_Solucion;
    private javax.swing.JMenuBar jMenuBar1;
    private javax.swing.JPanel jPanel1;
    public javax.swing.JPanel jPanel_Lienzo;
    // End of variables declaration//GEN-END:variables
}

