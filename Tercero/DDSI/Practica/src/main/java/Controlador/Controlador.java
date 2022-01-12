/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.*;
import Vista.*;

import java.awt.CardLayout;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.text.ParseException;
import java.text.SimpleDateFormat;
import java.util.ArrayList;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.Date;
import org.hibernate.Session;

/**
 *
 * @author Grefuwan
 */
public class Controlador implements ActionListener{
    
    private Conexion            conexion        = null;
    private Session             sesion          = null;
    private utilTablas          utTab           = null;
    private SimpleDateFormat    formatoFecha    = null;

    private VistaPrincipal      vPrinc          = null;
    private PanelVacio          vVac            = null;
    private VistaMensajes       vMensaje        = null;
    
    private VistaMonitores      vMon            = null;
    private MonitorDAO          monDao          = null;
    private Monitor             mon             = null;

    private VistaSocios         vSoc            = null;
    private SocioDAO            socDao          = null;
    private Socio               soc             = null;

    private VistaActividad      vAct            = null;
    private ActividadDAO        actDAO          = null;
    private Actividad           act             = null;
    
    
    public Controlador(Session conectP)  { //Instanciar todo lo creado arriba
        this.sesion = conectP;
        utTab        = new utilTablas();
        formatoFecha = new SimpleDateFormat("dd/MM/yyyy");
       
        vPrinc       = new VistaPrincipal();
        vVac         = new PanelVacio();
        vMensaje     = new VistaMensajes();

        vMon         = new VistaMonitores();
        monDao       = new MonitorDAO(conectP);
        mon          = new Monitor();
        
        vSoc         = new VistaSocios();
        socDao       = new SocioDAO(conectP);
        soc          = new Socio();
        
        vAct         = new VistaActividad();
        actDAO       = new ActividadDAO();
        act          = new Actividad();
        
        //Gestionar el cierre de VistaPrincipal
        addListeners();
        
        vPrinc.setLocationRelativeTo(null);
        vPrinc.setVisible(true);
        vPrinc.getContentPane().setLayout(new CardLayout());
        
        //Añado paneles
        vPrinc.add(vVac);
        vPrinc.add(vMon);
        vPrinc.add(vSoc);
        //vPrinc.add(vAct);
        vMon.setVisible(false);
        vSoc.setVisible(false);
        //vAct.setVisible(false);
        vVac.setVisible(true);  //Panel vacio para mostrar
        

    }

    private void addListeners() {   //A cada botón pulsable, añadirlo aquí
        //Vista Principal
            vPrinc.jMenuItem_SalirAplicacion.addActionListener(this);
            vPrinc.jMenuItem_GestionMonitores.addActionListener(this);
            vPrinc.jMenu_GestionSocios.addActionListener(this);
            vPrinc.jMenu_SociosPorActividad.addActionListener(this);
            
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
                    try {
                        vMonjTable_TablaMonitoresMouseClicked(evt); //Definido mas abajo
                    } catch (ParseException ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
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
                    try {
                        vSocTable_TablaSociosMouseClicked(evt); //Definido mas abajo
                    } catch (ParseException ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
            });
            
        //Vista Actividades
            //Botones------------------
            vAct.jButton_Exit.addActionListener(this);
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
                    vAct.setVisible(false);
                break;
                
            case "GestionSocios":
                    vVac.setVisible(false);
                    vMon.setVisible(false);
                    vSoc.setVisible(true);
                    vAct.setVisible(false);
                break;
            
            case "GestionSociosActividad":
                    //vVac.setVisible(false);
                    //vMon.setVisible(false);
                    //vSoc.setVisible(false);
                    vAct.setVisible(true);
                break;
            
            default:
                    vVac.setVisible(true);
                    vMon.setVisible(false);
                    vSoc.setVisible(false);
                    vAct.setVisible(false);
                break;

//---------------------Monitores---------------------
            case "InsertarMonitor":
                {
                    try {
                        insertarTablaMonitores();
                        pideMonitores();
                    }catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

            case "ActualizarMonitor":
                {
                    try {
                        actualizMonitor();
                        pideMonitores();
                    } catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

            case "EliminarMonitor":
                {
                    try {
                        borrarMonitor();
                        pideMonitores();
                    } catch (Exception ex) {
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
                
//---------------------Socios---------------------
            case "InsertarSocio":
                {
                    try {
                        insertarTablaSocios();
                        pideSocios();
                    } catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

            case "ActualizarSocio":
                {
                    try {
                        actualizSocio();
                        pideSocios();
                    } catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

            case "EliminarSocio":
                {
                    try {
                        borrarSocio();
                        pideSocios();
                    } catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

            case "VaciarTablaSocios":
                    utTab.vaciarTablaSocios();
                break;
                
            case "ListarSocios":
                {
                    try {
                        utTab.dibujarTablaSocios(vSoc);
                        pideSocios();
                    } catch (Exception ex) {
                        Logger.getLogger(Controlador.class.getName()).log(Level.SEVERE, null, ex);
                    }
                }
                break;

                
//---------------------Actividades---------------------
            case "SalirActividad":
                    vAct.setVisible(false);
                break;
                
        }
    }
    
    
    
    
    
    //----------------------------------------------------Monitores----------------------------------------------------
    private void pideMonitores() throws SQLException{
        ArrayList<Monitor> lMonitores = monDao.listaMonitores();
        utTab.vaciarTablaMonitores();
        utTab.rellenarTablaMonitores(lMonitores);
    }

    private void vMonjTable_TablaMonitoresMouseClicked(MouseEvent evt) throws ParseException{
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

    private void insertarTablaMonitores() throws Exception{
        String cod = vMon.jTextField_Codigo.getText();
        String nom = vMon.jTextField_Nombre.getText();
        String dni = vMon.jTextField_DNI.getText();
        String tlf = vMon.jTextField_Telefono.getText();
        String cor = vMon.jTextField_Correo.getText();
        
        String fec = "dd/MM/yyyy";
        Date fechaChooser = vMon.jDateChooser_Monitor.getDate();
        if (fechaChooser != null){
            fec = formatoFecha.format(fechaChooser);
            mon.setFechaentrada(fec);
        }
        //String fec = vMon.jTextField_FechaEntrada.getText();
        
        String nic = vMon.jTextField_Nick.getText();
        
        Monitor monitor = new Monitor(cod, nom, dni, tlf, cor, fec, nic);
        monDao.insertarMonitor(monitor);
    }
    
    private void borrarMonitor () throws SQLException, Exception{
        String codMonit = vMon.jTextField_Codigo.getText();
        monDao.borrarMonitor(codMonit);
    }
    
    private void actualizMonitor() throws Exception{
        String cod = vMon.jTextField_Codigo.getText();
        String nom = vMon.jTextField_Nombre.getText();
        String dni = vMon.jTextField_DNI.getText();
        String tlf = vMon.jTextField_Telefono.getText();
        String cor = vMon.jTextField_Correo.getText();
        
        String fec = null;
        Date fechaChooser = vMon.jDateChooser_Monitor.getDate();
        if (fechaChooser != null){
            fec = formatoFecha.format(fechaChooser);
        }
        //String fec = vMon.jTextField_FechaEntrada.getText();
        
        String nic = vMon.jTextField_Nick.getText();
        
        monDao.actualizarMonitor(cod, nom, dni, tlf, cor, fec, nic);
    }
    
    
    //----------------------------------------------------Socios----------------------------------------------------
    private void pideSocios() throws Exception{
        ArrayList<Socio> lSocios = socDao.listaSocios();
        utTab.vaciarTablaSocios();
        utTab.rellenarTablaSocios(lSocios);
    }
    
    private void vSocTable_TablaSociosMouseClicked(MouseEvent evt) throws ParseException{
        int fila = vSoc.jTable_TablaSocios.getSelectedRow();
        //TODO - Rellenar todos los textfields con los valores de las columnas
        //       de la fila que esté señalada en la tabla cuando se haga un click de ratón
        String numSoc   = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 0);
        String nombre   = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 1);
        String dni      = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 2);
        String fechNac  = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 3);
        String tlf      = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 4);
        String correo   = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 5);
        String fechEnt  = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 6);
        String categ    = (String) vSoc.jTable_TablaSocios.getValueAt(fila, 7);
        
        vSoc.jTextField_NumSocio.setText(numSoc);
        vSoc.jTextField_Nombre.setText(nombre);
        vSoc.jTextField_DNI.setText(dni);
        vSoc.jTextField_Telefono.setText(tlf);
        vSoc.jTextField_Correo.setText(correo);
        
        Date fechEntrada = formatoFecha.parse(fechEnt);
        vSoc.jDateChooser_FEntradaSocios.setDate(fechEntrada);
        
        Date fechNacim = formatoFecha.parse(fechNac);
        vSoc.jDateChooser_FNac_Socios.setDate(fechNacim);
        
        vSoc.jTextField_Categoria.setText(categ);
    }
    
    private void insertarTablaSocios() throws Exception{
        String numSoc   = vSoc.jTextField_NumSocio.getText();
        String nombre   = vSoc.jTextField_Nombre.getText();
        String dni      = vSoc.jTextField_DNI.getText();
        String tlf      = vSoc.jTextField_Telefono.getText();
        String correo   = vSoc.jTextField_Correo.getText();
        String categ    = vSoc.jTextField_Categoria.getText();
        
        String fecEnt = "dd/MM/yyyy";
        Date fechUno = vSoc.jDateChooser_FEntradaSocios.getDate();
        if (fechUno != null){
            fecEnt = formatoFecha.format(fechUno);
            soc.setFechaentrada(fecEnt);
        }
        
        String fecNac = "dd/MM/yyyy";
        Date fechDos = vSoc.jDateChooser_FNac_Socios.getDate();
        if (fechDos != null){
            fecNac = formatoFecha.format(fechDos);
            soc.setFechanacimiento(fecNac);
        }
        Socio socio;
        socio = new Socio(numSoc, nombre, dni, tlf, correo, categ, fecEnt, fecNac);
        socDao.insertaSocio(socio);
    }

    private void borrarSocio() throws Exception{
        String numSoc = vSoc.jTextField_NumSocio.getText();
        socDao.eliminaSocio(numSoc);
    }
    
    private void actualizSocio() throws Exception{
        String numSoc   = vSoc.jTextField_NumSocio.getText();
        String nombre   = vSoc.jTextField_Nombre.getText();
        String dni      = vSoc.jTextField_DNI.getText();
        String tlf      = vSoc.jTextField_Telefono.getText();
        String correo   = vSoc.jTextField_Correo.getText();
        String categ    = vSoc.jTextField_Categoria.getText();
        
        String fecEnt = "dd/MM/yyyy";
        Date fechUno = vSoc.jDateChooser_FEntradaSocios.getDate();
        if (fechUno != null){
            fecEnt = formatoFecha.format(fechUno);
            soc.setFechaentrada(fecEnt);
        }
        
        String fecNac = "dd/MM/yyyy";
        Date fechDos = vSoc.jDateChooser_FNac_Socios.getDate();
        if (fechDos != null){
            fecNac = formatoFecha.format(fechDos);
            soc.setFechanacimiento(fecNac);
        }
        
        socDao.actualizaSocio(numSoc, nombre, dni, tlf, correo, categ, fecEnt, fecNac);
        
    }
}
