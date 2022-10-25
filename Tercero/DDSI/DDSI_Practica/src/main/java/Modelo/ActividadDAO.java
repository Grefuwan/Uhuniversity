/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.util.ArrayList;
import javax.swing.JComboBox;
import javax.swing.table.DefaultTableModel;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

/**
 *
 * @author Grefuwan
 */
public class ActividadDAO {
    
    Conexion conexion   = null;
    Session sesion      = null;
    Actividad activ     = null;
    
    public ActividadDAO(Session c){
        this.sesion = c;
    }
    
    public ArrayList<Actividad> listaActividad(){
        String consult = "SELECT * FROM ACTIVIDAD ORDER BY IDACTIVIDAD";
        
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery(consult, Actividad.class);
        ArrayList<Actividad> actividades = (ArrayList<Actividad>) consulta.list();
        
        transaction.commit();
        
        return actividades;
    }
    
    public ArrayList<Object[]> listaActividadNombreID(){
        String consult = "SELECT NOMBRE, IDACTIVIDAD FROM ACTIVIDAD ORDER BY IDACTIVIDAD";
        
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery(consult, Actividad.class);
        ArrayList<Object[]> actividades = (ArrayList<Object[]>) consulta.list();
        
        transaction.commit();
        
        return actividades;
    }
    
    public ArrayList<String> listaNombreActividad() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT nombre FROM ACTIVIDAD A");
        ArrayList<String> actividades = (ArrayList<String>) consulta.list();
        
        transaction.commit();
        return actividades;
    }
    
    public ArrayList<Actividad> listaActividadPorLetra(String letra){
        Transaction transaction = sesion.beginTransaction();
        letra = letra + "%";
        Query consulta = sesion.createNativeQuery("SELECT * FROM ACTIVIDAD A"
            + "WHERE nombre LIKE :letra", Actividad.class).setParameter("letra", letra);
        ArrayList<Actividad> actividades = (ArrayList<Actividad>) consulta.list();
        
        transaction.commit();
        return actividades;
    }
    
    
    public ArrayList<Object[]> devolverSocios(String idActividad) {
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT S.NOMBRE, S.CORREO "
                + "FROM SOCIO S INNER JOIN REALIZA R ON S.NUMEROSOCIO = R.NUMEROSOCIO "
                + "WHERE R.IDACTIVIDAD =:idA").setParameter("idA", idActividad);
        ArrayList<Object[]> socios = (ArrayList<Object[]>) consulta.list();
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
    
    
    public String getIdActividad(String NombreActividad) {
        String consulta = "SELECT IDACTIVIDAD FROM ACTIVIDAD WHERE NOMBRE = :nombre";
        String idActividad = "";
        
        Query consult = sesion.createNativeQuery(consulta).setParameter("nombre", NombreActividad);
        
        ArrayList<String> idActividades = (ArrayList<String>) consult.list();
        
        idActividad = idActividades.get(0);

        return idActividad;
    }
        
    public void pintaTabla(DefaultTableModel Tabla, String Nombre, String Correo) {
        Object[] fila = new Object[2];

        fila[0] = Nombre;
        fila[1] = Correo;

        Tabla.addRow(fila);

    }
    
     
}
