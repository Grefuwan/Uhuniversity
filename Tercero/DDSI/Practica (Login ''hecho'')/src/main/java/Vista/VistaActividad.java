/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JFrame.java to edit this template
 */
package Vista;

/**
 *
 * @author Grefuwan
 */
public class VistaActividad extends javax.swing.JFrame {

    /**
     * Creates new form VistaActividad
     */
    public VistaActividad() {
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

        jScrollPane1 = new javax.swing.JScrollPane();
        jTable_Actividad = new javax.swing.JTable();
        jButton_ThrowProced = new javax.swing.JButton();
        jButton_Exit = new javax.swing.JButton();
        jComboBox_IDActivity = new javax.swing.JComboBox<>();
        jTextField_IDActivity = new javax.swing.JTextField();

        setDefaultCloseOperation(javax.swing.WindowConstants.EXIT_ON_CLOSE);
        getContentPane().setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jTable_Actividad.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null},
                {null, null, null, null}
            },
            new String [] {
                "Title 1", "Title 2", "Title 3", "Title 4"
            }
        ));
        jScrollPane1.setViewportView(jTable_Actividad);

        getContentPane().add(jScrollPane1, new org.netbeans.lib.awtextra.AbsoluteConstraints(40, 20, 900, 250));

        jButton_ThrowProced.setText("Lanzar Procedimiento");
        getContentPane().add(jButton_ThrowProced, new org.netbeans.lib.awtextra.AbsoluteConstraints(270, 430, -1, -1));

        jButton_Exit.setText("Salir");
        jButton_Exit.setActionCommand("SalirActividad");
        getContentPane().add(jButton_Exit, new org.netbeans.lib.awtextra.AbsoluteConstraints(570, 430, -1, -1));

        jComboBox_IDActivity.setModel(new javax.swing.DefaultComboBoxModel<>(new String[] { "Item 1", "Item 2", "Item 3", "Item 4" }));
        jComboBox_IDActivity.addContainerListener(new java.awt.event.ContainerAdapter() {
            public void componentAdded(java.awt.event.ContainerEvent evt) {
                jComboBox_IDActivityComponentAdded(evt);
            }
        });
        jComboBox_IDActivity.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jComboBox_IDActivityActionPerformed(evt);
            }
        });
        getContentPane().add(jComboBox_IDActivity, new org.netbeans.lib.awtextra.AbsoluteConstraints(320, 330, -1, -1));

        jTextField_IDActivity.setText("ID Actividad");
        jTextField_IDActivity.addActionListener(new java.awt.event.ActionListener() {
            public void actionPerformed(java.awt.event.ActionEvent evt) {
                jTextField_IDActivityActionPerformed(evt);
            }
        });
        getContentPane().add(jTextField_IDActivity, new org.netbeans.lib.awtextra.AbsoluteConstraints(520, 330, 180, -1));

        pack();
    }// </editor-fold>//GEN-END:initComponents

    private void jComboBox_IDActivityComponentAdded(java.awt.event.ContainerEvent evt) {//GEN-FIRST:event_jComboBox_IDActivityComponentAdded
        // TODO add your handling code here:
    }//GEN-LAST:event_jComboBox_IDActivityComponentAdded

    private void jComboBox_IDActivityActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jComboBox_IDActivityActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jComboBox_IDActivityActionPerformed

    private void jTextField_IDActivityActionPerformed(java.awt.event.ActionEvent evt) {//GEN-FIRST:event_jTextField_IDActivityActionPerformed
        // TODO add your handling code here:
    }//GEN-LAST:event_jTextField_IDActivityActionPerformed

    /**
     * @param args the command line arguments
     */
    public static void main(String args[]) {
        /* Set the Nimbus look and feel */
        //<editor-fold defaultstate="collapsed" desc=" Look and feel setting code (optional) ">
        /* If Nimbus (introduced in Java SE 6) is not available, stay with the default look and feel.
         * For details see http://download.oracle.com/javase/tutorial/uiswing/lookandfeel/plaf.html 
         */
        try {
            for (javax.swing.UIManager.LookAndFeelInfo info : javax.swing.UIManager.getInstalledLookAndFeels()) {
                if ("Nimbus".equals(info.getName())) {
                    javax.swing.UIManager.setLookAndFeel(info.getClassName());
                    break;
                }
            }
        } catch (ClassNotFoundException ex) {
            java.util.logging.Logger.getLogger(VistaActividad.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (InstantiationException ex) {
            java.util.logging.Logger.getLogger(VistaActividad.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (IllegalAccessException ex) {
            java.util.logging.Logger.getLogger(VistaActividad.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        } catch (javax.swing.UnsupportedLookAndFeelException ex) {
            java.util.logging.Logger.getLogger(VistaActividad.class.getName()).log(java.util.logging.Level.SEVERE, null, ex);
        }
        //</editor-fold>

        /* Create and display the form */
        java.awt.EventQueue.invokeLater(new Runnable() {
            public void run() {
                new VistaActividad().setVisible(true);
            }
        });
    }

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton jButton_Exit;
    public javax.swing.JButton jButton_ThrowProced;
    public javax.swing.JComboBox<String> jComboBox_IDActivity;
    private javax.swing.JScrollPane jScrollPane1;
    public javax.swing.JTable jTable_Actividad;
    public javax.swing.JTextField jTextField_IDActivity;
    // End of variables declaration//GEN-END:variables
}
