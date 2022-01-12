/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.sql.SQLException;
import java.util.ArrayList;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

/**
 *
 * @author Grefuwan
 */
public class MonitorDAO {
    Conexion conexion   = null;
    Session sesion      = null;
    
    public MonitorDAO (Conexion c){
        this.conexion = c;
    }
    
    public ArrayList<Monitor> listaMonitores() throws SQLException{
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery ("SELECT * FROM MONITOR M", Monitor.class);
        ArrayList<Monitor> monitores = (ArrayList<Monitor>) consulta.list();
        
        transaction.commit();
        return monitores;
    }
    
    public ArrayList<String> listaNombreMonitores() throws Exception {         //Consulta que devuelve un unico campo de la tabla Socios
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT nombre FROM MONITOR M");
        ArrayList<String> monitores = (ArrayList<String>) consulta.list();
        
        transaction.commit();
        return monitores;
    }
    
    public ArrayList<Monitor> listaMonitorPorLetra(String letra)throws SQLException{
        Transaction transaction = sesion.beginTransaction();
        letra = letra + "%";
        Query consulta = sesion.createNativeQuery("SELECT * FROM MONITOR M"
            + "WHERE nombre LIKE :letra", Monitor.class).setParameter("letra", letra);
        ArrayList<Monitor> monitores = (ArrayList<Monitor>) consulta.list();
        
        transaction.commit();
        return monitores;
    }
    
    public void insertarMonitor(Monitor monitor) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        sesion.save(monitor);
        transaction.commit();
    }  
    
    
    public void borrarMonitor (String codMonitor) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Monitor monitor = sesion.get(Monitor.class, codMonitor);
        sesion.delete(monitor);
        transaction.commit();
    }
    
    
    public void actualizarMonitor (Monitor monitor) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        sesion.save(monitor);
        transaction.commit();
    }
}
