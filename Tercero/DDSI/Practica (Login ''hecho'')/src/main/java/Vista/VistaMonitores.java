/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/GUIForms/JPanel.java to edit this template
 */
package Vista;

/**
 *
 * @author Grefuwan
 */
public class VistaMonitores extends javax.swing.JPanel {

   
    public VistaMonitores() {
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

        jLabel_Codigo = new javax.swing.JLabel();
        jLabel_Nombre = new javax.swing.JLabel();
        jLabel_DNI = new javax.swing.JLabel();
        jLabel_telefono = new javax.swing.JLabel();
        jLabel_Correo = new javax.swing.JLabel();
        jLabel_FechaEntrada = new javax.swing.JLabel();
        jLabel_Nick = new javax.swing.JLabel();
        jTextField_Nick = new javax.swing.JTextField();
        jTextField_Codigo = new javax.swing.JTextField();
        jTextField_Nombre = new javax.swing.JTextField();
        jTextField_DNI = new javax.swing.JTextField();
        jTextField_Telefono = new javax.swing.JTextField();
        jTextField_Correo = new javax.swing.JTextField();
        jButton_Insertar = new javax.swing.JButton();
        jButton_Actualizar = new javax.swing.JButton();
        jButton_Eliminar = new javax.swing.JButton();
        jButton_VaciarTabla = new javax.swing.JButton();
        jButton_ListarMonitores = new javax.swing.JButton();
        jScrollPane2 = new javax.swing.JScrollPane();
        jTable_TablaMonitores = new javax.swing.JTable();
        jDateChooser_Monitor = new com.toedter.calendar.JDateChooser();

        setMinimumSize(new java.awt.Dimension(1080, 1500));
        setLayout(new org.netbeans.lib.awtextra.AbsoluteLayout());

        jLabel_Codigo.setText("Código");
        add(jLabel_Codigo, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 350, -1, -1));

        jLabel_Nombre.setText("Nombre");
        add(jLabel_Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 400, -1, -1));

        jLabel_DNI.setText("DNI");
        add(jLabel_DNI, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 450, -1, -1));

        jLabel_telefono.setText("Teléfono");
        add(jLabel_telefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(70, 500, -1, -1));

        jLabel_Correo.setText("Correo");
        add(jLabel_Correo, new org.netbeans.lib.awtextra.AbsoluteConstraints(580, 350, -1, 29));

        jLabel_FechaEntrada.setText("Fecha de Entrada");
        add(jLabel_FechaEntrada, new org.netbeans.lib.awtextra.AbsoluteConstraints(580, 400, -1, 29));

        jLabel_Nick.setText("Nick");
        add(jLabel_Nick, new org.netbeans.lib.awtextra.AbsoluteConstraints(580, 450, -1, 18));
        add(jTextField_Nick, new org.netbeans.lib.awtextra.AbsoluteConstraints(730, 450, 200, -1));
        add(jTextField_Codigo, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 350, 200, -1));
        add(jTextField_Nombre, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 400, 200, -1));
        add(jTextField_DNI, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 450, 200, -1));
        add(jTextField_Telefono, new org.netbeans.lib.awtextra.AbsoluteConstraints(200, 500, 200, -1));
        add(jTextField_Correo, new org.netbeans.lib.awtextra.AbsoluteConstraints(730, 350, 200, -1));

        jButton_Insertar.setText("Insertar");
        jButton_Insertar.setActionCommand("InsertarMonitor");
        add(jButton_Insertar, new org.netbeans.lib.awtextra.AbsoluteConstraints(550, 550, 110, -1));

        jButton_Actualizar.setText("Actualizar");
        jButton_Actualizar.setActionCommand("ActualizarMonitor");
        add(jButton_Actualizar, new org.netbeans.lib.awtextra.AbsoluteConstraints(700, 550, 110, -1));

        jButton_Eliminar.setText("Eliminar");
        jButton_Eliminar.setActionCommand("EliminarMonitor");
        add(jButton_Eliminar, new org.netbeans.lib.awtextra.AbsoluteConstraints(850, 550, 110, -1));

        jButton_VaciarTabla.setText("Vaciar Tabla");
        jButton_VaciarTabla.setActionCommand("VaciarTablaMonitor");
        add(jButton_VaciarTabla, new org.netbeans.lib.awtextra.AbsoluteConstraints(605, 610, 120, -1));

        jButton_ListarMonitores.setText("Listar Monitores");
        jButton_ListarMonitores.setActionCommand("ListarMonitores");
        add(jButton_ListarMonitores, new org.netbeans.lib.awtextra.AbsoluteConstraints(755, 610, 150, -1));

        jTable_TablaMonitores.setModel(new javax.swing.table.DefaultTableModel(
            new Object [][] {
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null},
                {null, null, null, null, null, null, null}
            },
            new String [] {
                "Def1", "Def2", "Def3", "Def4", "Def5", "Def6", "Def7"
            }
        ));
        jScrollPane2.setViewportView(jTable_TablaMonitores);

        add(jScrollPane2, new org.netbeans.lib.awtextra.AbsoluteConstraints(50, 30, 920, 280));
        add(jDateChooser_Monitor, new org.netbeans.lib.awtextra.AbsoluteConstraints(730, 400, 200, -1));
    }// </editor-fold>//GEN-END:initComponents

    // Variables declaration - do not modify//GEN-BEGIN:variables
    public javax.swing.JButton jButton_Actualizar;
    public javax.swing.JButton jButton_Eliminar;
    public javax.swing.JButton jButton_Insertar;
    public javax.swing.JButton jButton_ListarMonitores;
    public javax.swing.JButton jButton_VaciarTabla;
    public com.toedter.calendar.JDateChooser jDateChooser_Monitor;
    public javax.swing.JLabel jLabel_Codigo;
    public javax.swing.JLabel jLabel_Correo;
    public javax.swing.JLabel jLabel_DNI;
    public javax.swing.JLabel jLabel_FechaEntrada;
    public javax.swing.JLabel jLabel_Nick;
    public javax.swing.JLabel jLabel_Nombre;
    public javax.swing.JLabel jLabel_telefono;
    private javax.swing.JScrollPane jScrollPane2;
    public javax.swing.JTable jTable_TablaMonitores;
    public javax.swing.JTextField jTextField_Codigo;
    public javax.swing.JTextField jTextField_Correo;
    public javax.swing.JTextField jTextField_DNI;
    public javax.swing.JTextField jTextField_Nick;
    public javax.swing.JTextField jTextField_Nombre;
    public javax.swing.JTextField jTextField_Telefono;
    // End of variables declaration//GEN-END:variables

}