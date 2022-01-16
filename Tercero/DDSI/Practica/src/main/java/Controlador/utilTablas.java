/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.Socio;
import Modelo.Monitor;
import Vista.VistaActividad;
import Vista.VistaMonitores;
import Vista.VistaSocios;
import java.util.ArrayList;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;

/**
 *
 * @author Grefuwan
 */
public class utilTablas {
    
    //----------------------------------------------------Monitor----------------------------------------------------
    public DefaultTableModel modeloTablaMonitor = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    public void dibujarTablaMonitores(VistaMonitores vMonitor){
        vMonitor.jTable_TablaMonitores.setModel(modeloTablaMonitor);
        
        String[] columntasTabla = {"Código", "Nombre", "DNI", "Teléfono", "Correo", "Fecha Incorporación", "Nick"};
        modeloTablaMonitor.setColumnIdentifiers(columntasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vMonitor.jTable_TablaMonitores.getTableHeader().setResizingAllowed(false);
        vMonitor.jTable_TablaMonitores.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Para fijar el ancho de las columnas
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(0).setPreferredWidth(40);     //Codigo
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(1).setPreferredWidth(240);    //Nombre
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(2).setPreferredWidth(70);     //DNI
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(3).setPreferredWidth(70);     //Telefono
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(4).setPreferredWidth(200);    //Correo
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(5).setPreferredWidth(150);    //Fecha Incorporacion
        vMonitor.jTable_TablaMonitores.getColumnModel().getColumn(6).setPreferredWidth(60);     //Nick
    }
   
    //Mostrar los datos de la tabla MONITOR
    public void rellenarTablaMonitores(ArrayList<Monitor> monitores){
        Object[] fila = new Object[7];
        int numRegistros = monitores.size();
        for (int i = 0; i < numRegistros; i++){
            fila[0] = monitores.get(i).getCodmonitor();     //Cod Monitor
            fila[1] = monitores.get(i).getNombre();         //Nombre
            fila[2] = monitores.get(i).getDni();            //DNI
            fila[3] = monitores.get(i).getTelefono();       //Telefono
            fila[4] = monitores.get(i).getCorreo();         //Correo
            fila[5] = monitores.get(i).getFechaentrada();   //Fecha Entrada
            fila[6] = monitores.get(i).getNick();           //Nick
            modeloTablaMonitor.addRow(fila);
        }
    }
    
    //Vaciar el contenido de la tabla MONITOR
    public void vaciarTablaMonitores(){
        while ( modeloTablaMonitor.getRowCount() > 0)
            modeloTablaMonitor.removeRow(0);
    }
    
    
    //----------------------------------------------------Socios----------------------------------------------------
    public DefaultTableModel modeloTablaSocios = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    public void dibujarTablaSocios (VistaSocios vSoc){
        vSoc.jTable_TablaSocios.setModel(modeloTablaSocios);
        
        String[] columnasTabla = {"Nº. Soc", "Nombre", "DNI", "Fecha Nacimiento", "Telefono", "Correo", "Fecha Entrada" , "Categoria"};
        modeloTablaSocios.setColumnIdentifiers(columnasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vSoc.jTable_TablaSocios.getTableHeader().setResizingAllowed(false);
        vSoc.jTable_TablaSocios.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Para fijar el ancho de las columnas
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(0).setPreferredWidth(60);    //Num Socio
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(1).setPreferredWidth(200);   //Nombre
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(2).setPreferredWidth(90);    //DNI
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(3).setPreferredWidth(90);    //Fecha Nacimiento
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(4).setPreferredWidth(115);   //Telefono
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(5).setPreferredWidth(170);   //Correo
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(6).setPreferredWidth(90);    //Fecha Entrada
        vSoc.jTable_TablaSocios.getColumnModel().getColumn(7).setPreferredWidth(70);    //Categoria
    }
    
    public void rellenarTablaSocios(ArrayList<Socio> socios){
        Object[] fila = new Object[8];
        int numRegistros = socios.size();
        for (int i = 0; i < numRegistros; i++){
            fila[0] = socios.get(i).getNumerosocio();       //Num Socio
            fila[1] = socios.get(i).getNombre();            //Nombre
            fila[2] = socios.get(i).getDni();               //DNI
            fila[3] = socios.get(i).getFechanacimiento();   //Fecha Nacimiento
            fila[4] = socios.get(i).getTelefono();          //Telefono
            fila[5] = socios.get(i).getCorreo();            //Correo
            fila[6] = socios.get(i).getFechaentrada();      //Fecha Entrada
            fila[7] = socios.get(i).getCategoria();         //Categoria
            modeloTablaSocios.addRow(fila);
        }
    }
    
    public void vaciarTablaSocios(){
        while (modeloTablaSocios.getRowCount() > 0)
            modeloTablaSocios.removeRow(0);
    }


    //--------------------------------------------------Actividad---------------------------------------------------
    public DefaultTableModel modeloTablaActividad = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    public void dibujarTablaSociosxActiv(VistaActividad vAct){
        vAct.jTable_Actividad.setModel(modeloTablaActividad);
        
        String[] columnasTabla = {"Nombre Socio", "Correo"};
        modeloTablaActividad.setColumnIdentifiers(columnasTabla);
        
        //Para no permitir el redimensionamiento de las columnas con el ratón
        vAct.jTable_Actividad.getTableHeader().setResizingAllowed(false);
        vAct.jTable_Actividad.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        //Para fijar el ancho de las columnas
        vAct.jTable_Actividad.getColumnModel().getColumn(0).setPreferredWidth(75);
        vAct.jTable_Actividad.getColumnModel().getColumn(1).setPreferredWidth(75);
    }
    
    public void rellenarTablaSociosxActiv(ArrayList<Object[]> socios){
        Object[] fila = new Object[2];
        int numRegistros = socios.size();
        for (int i = 0; i < numRegistros; i++){
            fila[0] = socios.get(i)[0];
            fila[1] = socios.get(i)[1];
            modeloTablaActividad.addRow(fila);
        }
    }
    
    public void vaciarTablaActividad(){
        while (modeloTablaActividad.getRowCount() > 0)
            modeloTablaActividad.removeRow(0);
    }
}
