/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import Vista.VistaMensajes;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;

/**
 *
 * @author Grefuwan
 */
public class MonitorDAO {
    VistaMensajes vMens = new VistaMensajes();
    Conexion conexion   = null;
    Session sesion      = null;
    Monitor monit       = null;
    
    public MonitorDAO (Session c){
        this.sesion = c;
    }
    
    public ArrayList<Monitor> listaMonitores(){
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery ("SELECT * FROM MONITOR M WHERE CODMONITOR !='M999' ORDER BY CODMONITOR", Monitor.class);
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
    
    public void insertarMonitor(Monitor monit) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        try{
            sesion.save(monit);
        }
        catch (Exception e){
            vMens.MensajeError("Error al insertar Monitor", e.getMessage());
            transaction.rollback();
        }        
        
        transaction.commit();
    }  
    
    
    public void borrarMonitor (String codMonitor) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        monit = sesion.get(Monitor.class, codMonitor);
        sesion.delete(monit);
        transaction.commit();
    }
    
    public void borrarMonitorComprobado (String codMonitor) throws Exception {
        //Comprueba que el Monitor a borrar no sea monitor de una actividad etc [Practica 4]
        Transaction transaction = null;
        
        try{
            Monitor mon = sesion.get(Monitor.class, codMonitor);
            
            if(mon.getActividadesResponsable().isEmpty() ){
                transaction = sesion.beginTransaction();
                sesion.delete(mon);
                transaction.commit();
            }
            
            else{
                Monitor sustituto = sesion.get(Monitor.class, "M999");
                if (sustituto == null){
                    sustituto = new Monitor("M999", "Responsable Genérico", "00000000A");
                    insertarMonitor(sustituto);
                }
                
                transaction = sesion.beginTransaction();
                Set<Actividad> actividadesResponsable = mon.getActividadesResponsable();

                Iterator<Actividad> iterador = actividadesResponsable.iterator();

                while (iterador.hasNext()) {
                    Actividad act = iterador.next();
                    act.setMonitorresponsable(sustituto);
                    sesion.save(act);
                }
                
                transaction.commit();
                
                transaction = sesion.beginTransaction();
                sesion.delete(mon);
                transaction.commit();
            }
        }
        
        catch(Exception e){
            transaction.rollback();
            //Logger.getLogger(MonitorDAO.class.getName()).log(Level.SEVERE, null, e);
            vMens.MensajeError("ERROR", e.getMessage());
        }
    }
    
    
    public void actualizarMonitor (String codigo, String nombre, String dni, String tlf, String correo, String fechInc, String nick) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        monit = sesion.get(Monitor.class, codigo);
        
        monit.setCodmonitor(codigo);
        monit.setNombre(nombre);
        monit.setDni(dni);
        monit.setTelefono(tlf);
        monit.setCorreo(correo);
        monit.setFechaentrada(fechInc);
        monit.setNick(nick);
        
        sesion.update(monit);
        transaction.commit();
    }
    
}