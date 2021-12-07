/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import javax.swing.*;

import Modelo.Conexion;
import Modelo.Monitor;
import Modelo.MonitorDAO;
import Modelo.utilTablas;
import Vista.PanelVacio;
import Vista.VistaMensajes;
import Vista.VistaMonitores;
import Vista.VistaPrincipal;
import Vista.VistaSocios;
import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.table.DefaultTableModel;
import java.util.Date;

/**
 *
 * @author Grefuwan
 */
public class Controlador implements ActionListener{
    
    private Conexion        conexion    = null;
    private VistaPrincipal  vPrinc      = null;
    private VistaMensajes   vMensaje    = null;
    private VistaMonitores  vMon        = null;
    private VistaSocios     vSoc        = null;
    private PanelVacio      vVac        = null;
    private MonitorDAO      monDao      = null;
    private utilTablas      utTab       = null;
    
    public Controlador(Conexion conectP)  {
        this.conexion = conectP;
        
        //Instanciar todo lo creado arriba
        vPrinc      = new VistaPrincipal();
        vMensaje    = new VistaMensajes();
        vMon        = new VistaMonitores();
        vSoc        = new VistaSocios();
        vVac        = new PanelVacio();
        monDao      = new MonitorDAO(conectP);
        utTab       = new utilTablas();
        
        SimpleDateFormat formatoFecha = new SimpleDateFormat("dd/MM/yyyy");
        //Gestionar el cierre de VistaPrincipal
        addListeners();
        
        vPrinc.setLocationRelativeTo(null);
        vPrinc.setVisible(true);
        vPrinc.getContentPane().setLayout(new CardLayout());
        
        //Añado paneles
        vPrinc.add(vVac);
        vPrinc.add(vMon);
        vPrinc.add(vSoc);
        vMon.setVisible(false);
        vSoc.setVisible(false);
        vVac.setVisible(true);  //Panel vacio para mostrar
        

    }

    private void addListeners() {   //A cada botón pulsable, añadirlo aquí
        //Vista Principal
            vPrinc.jMenuItem_SalirAplicacion.addActionListener(this);
            vPrinc.jMenuItem_GestionMonitores.addActionListener(this);
            vPrinc.jMenu_GestionSocios.addActionListener(this);
            
        //Vista Monitor
            //Botones------------------
            vMon.jButton_Insertar.addActionListener(this);
            vMon.jButton_Actualizar.addActionListener(this);
            vMon.jButton_Eliminar.addActionListener(this);
            vMon.jButton_VaciarTabla.addActionListener(this);
            vMon.jButton_ListarMonitores.addActionListener(this);
            //Click raton--------------
            vMon.jTable_TablaMonitores.addMouseListener(new MouseAdapter() {
                public void mouseClicked(MouseEvent evt){
                    vMonjTable_TablaMonitoresMouseClicked(evt); //Definido mas abajo
                }
            });
            
        //Vista Socios
            //Botones------------------
            vSoc.jButton_Insertar.addActionListener(this);
            vSoc.jButton_Actualizar.addActionListener(this);
            vSoc.jButton_Eliminar.addActionListener(this);
            vSoc.jButton_VaciarTabla.addActionListener(this);
            vSoc.jButton_ListarSocios.addActionListener(this);
            //Click raton--------------
            vSoc.jTable_TablaSocios.addMouseListener(new MouseAdapter() {
                public void mouseClicked(MouseEvent evt){
                    vMonjTable_TablaMonitoresMouseClicked(evt); //Definido mas abajo
                }
            });
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand() ){
            case "SalirAplicacion":
                    vPrinc.dispose();
                    System.exit(0);
                break;
                
            case "GestionMonitores":
                    vVac.setVisible(false);
                    vMon.setVisible(true);
                    vSoc.setVisible(false);
                break;
                
            case "GestionSocios":
                    vVac.setVisible(false);
                    vMon.setVisible(false);
                    vSoc.setVisible(true);
                break;
                
            case "InsertarMonitor":
            {
                try {
                    insertarTablaMonitores();
                    pideMonitores();
                } catch (SQLException ex) {
                    Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                }
            }
                break;

                
            case "ActualizarMonitor":
                {
                    try {
                        actualizMonitor();
                        pideMonitores();
                    } catch (SQLException ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }

                break;

                
            case "EliminarMonitor":
                {
                    try {
                        borrarMonitor();
                        pideMonitores();
                    } catch (SQLException ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                
                break;

            
            case "VaciarTablaMonitor":
                    utTab.vaciarTablaMonitores();
                break;
            
            case "ListarMonitores":
                    try{
                        utTab.dibujarTablaMonitores(vMon);
                        pideMonitores();
                    } catch(SQLException ex){
                        //vMensaje.Mensaje("error", "Error en la peticion\n" + ex.getMessage() );
                    }
                break;
            
        }
    }
    
    private void pideMonitores() throws SQLException{
        ArrayList<Monitor> lMonitores = monDao.listaMonitores();
        utTab.vaciarTablaMonitores();
        utTab.rellenarTablaMonitores(lMonitores);
    }

    private void vMonjTable_TablaMonitoresMouseClicked(MouseEvent evt){
        int fila = vMon.jTable_TablaMonitores.getSelectedRow();
        //TODO - Rellenar todos los textfields con los valores de las columnas
        //       de la fila que esté señalada en la tabla cuando se haga un click de ratón
        String codigo   = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 0);
        String nombre   = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 1);
        String dni      = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 2);
        String tlf      = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 3);
        String correo   = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 4);
        String fechInc  = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 5);
        String nick     = (String) vMon.jTable_TablaMonitores.getValueAt(fila, 6);
        
        vMon.jTextField_Codigo.setText(codigo);
        vMon.jTextField_Nombre.setText(nombre);
        vMon.jTextField_DNI.setText(dni);
        vMon.jTextField_Telefono.setText(tlf);
        vMon.jTextField_Correo.setText(correo);
        
        //vMon.jTextField_FechaEntrada.setText(fechInc);
        Date fechaChooser = formatoFecha.parse(fechInc);
        vMon.jDateChooser_Monitor.setDate(fechaChooser);
        
        vMon.jTextField_Nick.setText(nick);
        
    }

    private void insertarTablaMonitores() throws SQLException{
        String cod = vMon.jTextField_Codigo.getText();
        String nom = vMon.jTextField_Nombre.getText();
        String dni = vMon.jTextField_DNI.getText();
        String tlf = vMon.jTextField_Telefono.getText();
        String cor = vMon.jTextField_Correo.getText();
        String fec = vMon.jTextField_FechaEntrada.getText();
        String nic = vMon.jTextField_Nick.getText();
        
        monDao.insertarMonitor(cod, nom, dni, tlf, cor, fec, nic);
    }
    
    private void borrarMonitor () throws SQLException{
        String codMonit = vMon.jTextField_Codigo.getText();
        monDao.borrarMonitor(codMonit);
    }
    
    private void actualizMonitor() throws SQLException{
        String cod = vMon.jTextField_Codigo.getText();
        String nom = vMon.jTextField_Nombre.getText();
        String dni = vMon.jTextField_DNI.getText();
        String tlf = vMon.jTextField_Telefono.getText();
        String cor = vMon.jTextField_Correo.getText();
        String fec = vMon.jTextField_FechaEntrada.getText();
        String nic = vMon.jTextField_Nick.getText();
        
        monDao.actualizarMonitor(cod, nom, dni, tlf, cor, fec, nic);
    }
}
