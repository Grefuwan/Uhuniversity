/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import Vista.VistaMensajes;
import java.util.ArrayList;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;


/**
 *
 * @author Grefuwan
 */
public class SocioDAO {
    VistaMensajes vMens     = new VistaMensajes();
    Conexion conexion       = null;
    Session sesion          = null;
    Socio soci              = null;
    
    public SocioDAO(Session c){
        this.sesion = c;
    }
    
    public ArrayList<Socio> listaSocios() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery ("SELECT * FROM Socio S ORDER BY NUMEROSOCIO", Socio.class);
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();
        
        transaction.commit();
        return socios;
    }

    public ArrayList<Object[]> listaNombreDNISocios() throws Exception {    //Consulta que devuelve 2 campos de la tabla Socios
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT nombre, dni FROM Socio S");
        ArrayList<Object[]> socios = (ArrayList<Object[]>) consulta.list();
        
        transaction.commit();
        return socios;
    }
    
    public ArrayList<String> listaNombreSocios() throws Exception {         //Consulta que devuelve un unico campo de la tabla Socios
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery("SELECT nombre FROM Socio S");
        ArrayList<String> socios = (ArrayList<String>) consulta.list();
        
        transaction.commit();
        return socios;
    }
    
    public ArrayList<Socio> listaSocioPorLetra(String letra) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        letra = letra + "%";
        Query consulta = sesion.createNativeQuery("SELECT * FROM SOCIO S "
            + "WHERE nombre LIKE :letra", Socio.class).setParameter("letra", letra);
        ArrayList<Socio> socios = (ArrayList<Socio>) consulta.list();
        
        transaction.commit();
        return socios;
    }
   
    public void insertaSocio(Socio socio) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        try{
            sesion.save(socio);
        }
        catch (Exception e){
            vMens.MensajeError("Error", "Error al insertar socio");
            transaction.rollback();
        }
        transaction.commit();
    }  
    
    public void eliminaSocio(String codSocio) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        Socio socio = sesion.get(Socio.class, codSocio);
        sesion.delete(socio);
        transaction.commit();
    }
    
    public void actualizaSocio(String numSocio, String nombre, String dni, String fechaNacimiento, String telefono, String correo, String fechaEntrada, String categoria) throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        soci = sesion.get(Socio.class, numSocio);
        
        soci.setNumerosocio(numSocio);
        soci.setNombre(nombre);
        soci.setDni(dni);
        soci.setFechanacimiento(fechaNacimiento);
        soci.setFechaentrada(fechaEntrada);
        soci.setTelefono(telefono);
        soci.setCorreo(correo);
        soci.setCategoria(categoria);
        
        sesion.update(soci);
        transaction.commit();
    }
}
