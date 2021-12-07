/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import Vista.VistaMonitores;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Grefuwan
 */
public class utilTablas {
    
    public DefaultTableModel modeloTablaMonitores = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    
    public void dibujarTablaMonitores(VistaMonitores vMonitor){
        vMonitor.jTable_TablaMonitores.setModel(modeloTablaMonitores);
        
        String[] columntasTabla = {"Código", "Nombre", "DNI", "Teléfono", "Correo", "Fecha Incorporación", "Nick"};
        modeloTablaMonitores.setColumnIdentifiers(columntasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vMonitor.jTable_TablaMonitores.getTableHeader().setResizingAllowed(false);
        vMonitor.jTable_TablaMonitores.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Para fijar el ancho de las columnas
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(0).setPreferredWidth(40);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(1).setPreferredWidth(240);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(2).setPreferredWidth(70);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(3).setPreferredWidth(70);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(4).setPreferredWidth(200);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(5).setPreferredWidth(150);
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(6).setPreferredWidth(60);
    }
    
    //Mostrar los datos de la tabla MONITOR
    public void rellenarTablaMonitores(ArrayList<Monitor> monitores){
        Object[] fila = new Object[7];
        int numRegistros = monitores.size();
        for (int i = 0; i < numRegistros; i++){
            fila[0] = monitores.get(i).getCodMonitor();
            fila[1] = monitores.get(i).getNombre();
            fila[2] = monitores.get(i).getDni();
            fila[3] = monitores.get(i).getTelefono();
            fila[4] = monitores.get(i).getCorreo();
            fila[5] = monitores.get(i).getFechaEntrada();
            fila[6] = monitores.get(i).getNick();
            modeloTablaMonitores.addRow(fila);
        }
    }
    
    //Vaciar el contenido de la tabla MONITOR
    public void vaciarTablaMonitores(){
        while (modeloTablaMonitores.getRowCount() > 0)
            modeloTablaMonitores.removeRow(0);
    }
    
    
    //Repetir esos 3 metodos para Socio y para Actividad----------------------------------------------------
}
