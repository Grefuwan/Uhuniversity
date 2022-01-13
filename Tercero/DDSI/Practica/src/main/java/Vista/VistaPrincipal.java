/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package Vista;

/**
 *
 * @author Grefuwan
 */
public class VistaPrincipal extends javax.swing.JFrame {

    /**
     * Creates new form VistaPrincipal
     */
    public VistaPrincipal() {
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

        jMenuBar_VistaPrincipal = new javax.swing.JMenuBar();
        jMenu_Salir = new javax.swing.JMenu();
        jMenuItem_SalirAplicacion = new javax.swing.JMenuItem();
        jMenu_Monitores = new javax.swing.JMenu();
        jMenuItem_GestionMonitores = new javax.swing.JMenuItem();
        jMenu_Socios = new javax.swing.JMenu();
        jMenu_GestionSocios = new javax.swing.JMenuItem();
        jMenu_Actividad = new javax.swing.JMenu();
        jMenu_SociosPorActividad = new javax.swing.JMenuItem();
        jMenu_SociosInscritos = new javax.swing.JMenuItem();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        setPreferredSize(new java.awt.Dimension(1100, 750));

        jMenu_Salir.setText("Salir");

        jMenuItem_SalirAplicacion.setText("Salir de la aplicación");
        jMenuItem_SalirAplicacion.setActionCommand("SalirAplicacion");
        jMenuItem_SalirAplicacion.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jMenuItem_SalirAplicacionActionPerformed(evt);
            }
        });
        jMenu_Salir.add(jMenuItem_SalirAplicacion);

        jMenuBar_VistaPrincipal.add(jMenu_Salir);

        jMenu_Monitores.setText("Monitores");

        jMenuItem_GestionMonitores.setText("Gestión de Monitores");
        jMenuItem_GestionMonitores.setActionCommand("GestionMonitores");
        jMenuItem_GestionMonitores.addContainerListener(new java.awt.event.ContainerAdapter() {
            public void componentAdded(java.awt.event.ContainerEvent evt) {
                jMenuItem_GestionMonitoresComponentAdded(evt);
            }
        });
        jMenu_Monitores.add(jMenuItem_GestionMonitores);

        jMenuBar_VistaPrincipal.add(jMenu_Monitores);

        jMenu_Socios.setText("Socios");

        jMenu_GestionSocios.setText("Gestión de Socios");
        jMenu_GestionSocios.setActionCommand("GestionSocios");
        jMenu_Socios.add(jMenu_GestionSocios);

        jMenuBar_VistaPrincipal.add(jMenu_Socios);

        jMenu_Actividad.setText("Actividad");

        jMenu_SociosPorActividad.setText("Socios por Actividad");
        jMenu_SociosPorActividad.setActionCommand("GestionSociosActividad");
        jMenu_Actividad.add(jMenu_SociosPorActividad);

        jMenu_SociosInscritos.setText("Socios Inscritos");
        jMenu_SociosInscritos.setActionCommand("GestionSociosActividad");
        jMenu_Actividad.add(jMenu_SociosInscritos);

        jMenuBar_VistaPrincipal.add(jMenu_Actividad);

        setJMenuBar(jMenuBar_VistaPrincipal);

        javax.swing.GroupLayout layout = new javax.swing.GroupLayout(getContentPane());
        getContentPane().setLayout(layout);
        layout.setHorizontalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 850, Short.MAX_VALUE)
        );
        layout.setVerticalGroup(
            layout.createParallelGroup(javax.swing.GroupLayout.Alignment.LEADING)
            .addGap(0, 480, Short.MAX_VALUE)
        );

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jMenuItem_SalirAplicacionActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jMenuItem_SalirAplicacionActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuItem_SalirAplicacionActionPerformed

    private void jMenuItem_GestionMonitoresComponentAdded(java.awt.event.ContainerEvent evt) {//GEN-FIRST:event_jMenuItem_GestionMonitoresComponentAdded
        // TODO add your handling code here:
    }//GEN-LAST:event_jMenuItem_GestionMonitoresComponentAdded

    /**
     * @param args the command line arguments
     */
    

    // Variables declaration - do not modify//GEN-BEGIN:variables
    private javax.swing.JMenuBar jMenuBar_VistaPrincipal;
    public javax.swing.JMenuItem jMenuItem_GestionMonitores;
    public javax.swing.JMenuItem jMenuItem_SalirAplicacion;
    public javax.swing.JMenu jMenu_Actividad;
    public javax.swing.JMenuItem jMenu_GestionSocios;
    public javax.swing.JMenu jMenu_Monitores;
    public javax.swing.JMenu jMenu_Salir;
    public javax.swing.JMenu jMenu_Socios;
    public javax.swing.JMenuItem jMenu_SociosInscritos;
    public javax.swing.JMenuItem jMenu_SociosPorActividad;
    // End of variables declaration//GEN-END:variables
}
