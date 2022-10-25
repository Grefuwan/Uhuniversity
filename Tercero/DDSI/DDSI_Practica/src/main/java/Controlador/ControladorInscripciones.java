/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.Actividad;
import Modelo.ActividadDAO;
import Modelo.Socio;
import Vista.VistaInscripciones;
import Vista.VistaMensajes;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import javax.swing.JComboBox;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

/**
 *
 * @author Grefuwan
 */
public class ControladorInscripciones {
    
    //---------------------------------InscripcionDAO---------------------------------
    private Session sesion = null;
    private VistaMensajes vMens = new VistaMensajes();
    
    
    public ControladorInscripciones(Session sesion){
        this.sesion = sesion;
    }
    
    
    public ArrayList<Socio> SociosInscritosActividad(){
        Transaction transaction = sesion.beginTransaction();
        Socio soc;
        Query consulta = sesion.createNativeQuery ("SELECT * FROM Socio S ORDER BY NUMEROSOCIO", Socio.class);
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();
        
        for (int i = 0; i < socios.size(); i++){
            soc = socios.get(i);
            System.out.println(soc.getNombre());
            Set<Actividad> actividades = soc.getActividades();
            for (Actividad actividad : actividades ) {
                System.out.println(actividad.getNombre());
            }
        }
        transaction.commit();
        return socios;
    }
    
    
    public void ActividadComboBox (JComboBox combBox){
        String consult = "SELECT NOMBRE FROM ACTIVIDAD";
        combBox.removeAllItems();
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery(consult);
        ArrayList<String> nombreActividades = (ArrayList<String>) consulta.list();
        
        for (int i = 0; i < nombreActividades.size(); i++) {
            combBox.addItem(nombreActividades.get(i));
        }
        transaction.commit();
    }
    
    
    
    //----------------------------------Util Tablas-----------------------------------
    public DefaultTableModel modeloTablaInscripcion = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    
    public void dibujarTablaInscripcion(VistaInscripciones vInsc){
        vInsc.jTable_Inscripciones.setModel(modeloTablaInscripcion);
        
        String[] columnasTabla = {"ID Socio", "Nombre Socio", "ID Actividad", "Nombre Actividad"};
        modeloTablaInscripcion.setColumnIdentifiers(columnasTabla);
        
        vInsc.jTable_Inscripciones.getTableHeader().setResizingAllowed(false);
        vInsc.jTable_Inscripciones.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        vInsc.jTable_Inscripciones.getColumnModel().getColumn(0).setPreferredWidth(60);     //ID Socio
        vInsc.jTable_Inscripciones.getColumnModel().getColumn(1).setPreferredWidth(200);    //Nombre Socio
        vInsc.jTable_Inscripciones.getColumnModel().getColumn(2).setPreferredWidth(60);     //ID Actividad
        vInsc.jTable_Inscripciones.getColumnModel().getColumn(3).setPreferredWidth(200);    //Nombre Actividad
    }
    
    
    public void rellenarTablaInscritosNoParam(){
        Object[] fila = new Object[4];
        Set<Actividad> actividades;
        
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery ("SELECT * FROM Socio S ORDER BY NUMEROSOCIO", Socio.class);
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();
        
        for (Socio socIt : socios){
            if ( !socIt.getActividades().isEmpty() ){
                actividades = socIt.getActividades();
                Iterator<Actividad> iterActivs = actividades.iterator();
                while(iterActivs.hasNext()){
                    fila[0] = socIt.getNumerosocio();
                    fila[1] = socIt.getNombre();
                    Actividad act = iterActivs.next();
                    fila[2] = act.getIdactividad();
                    fila[3] = act.getNombre();
                    modeloTablaInscripcion.addRow(fila);
                }
            }
            else{
                fila[0] = socIt.getNumerosocio();
                fila[1] = socIt.getNombre();
                fila[2] = "No Inscrito";
                fila[3] = "No Inscrito";
                modeloTablaInscripcion.addRow(fila);
            }
        }
        transaction.commit();
    }
    
    
    public void vaciarTablaInscripcion(){
        while (modeloTablaInscripcion.getRowCount() > 0)
            modeloTablaInscripcion.removeRow(0);
    }
    
    
    public void darAltaParam(int filaSelected, String numSocSelec, String activSelec){
        Transaction transaction = sesion.beginTransaction();

        try{
            ActividadDAO actD = new ActividadDAO(sesion);                           //Creo una ActividadDAO
            String idActivSelected = actD.getIdActividad(activSelec);               //Obtengo la ID de la Actividad
            
            Socio socio = sesion.get(Socio.class, numSocSelec);                     //Obtengo el Socio
            Actividad actividad = sesion.get(Actividad.class, idActivSelected );    //Obtengo la Actividad

            actividad.addSocio(socio);          //Añado el Socio a la Actividad
            sesion.save(actividad);
            transaction.commit();

            vaciarTablaInscripcion();           //Actualizo la Tabla
            rellenarTablaInscritosNoParam();
        }
        catch(Exception e){
            vMens.MensajeError("Error al dar de alta un socio", e.getMessage());
            transaction.rollback();
        }
    }
    
    public void darBajaParam(int filaSelected, String numSocSelec, String activSelec){
        Transaction transaction = sesion.beginTransaction();

        try{
            ActividadDAO actD = new ActividadDAO(sesion);                           //Creo una ActividadDAO
            String idActivSelected = actD.getIdActividad(activSelec);               //Obtengo la ID de la Actividad
            
            Socio socio = sesion.get(Socio.class, numSocSelec);                     //Obtengo el Socio
            Actividad actividad = sesion.get(Actividad.class, idActivSelected );    //Obtengo la Actividad

            actividad.eliminaSocio(socio);      //Elimino el Socio a la Actividad
            sesion.save(actividad);
            transaction.commit();

            vaciarTablaInscripcion();           //Actualizo la Tabla
            rellenarTablaInscritosNoParam();
        }
        catch(Exception e){
            vMens.MensajeError("Error al dar de alta un socio", e.getMessage());
            transaction.rollback();
        }
    }

}
