/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class SocioDAO {
    Conexion conexion = null;
    PreparedStatement ps = null;
    
    public SocioDAO(Conexion c){
        this.conexion = c;
    }
    
    public ArrayList<Socio> listaSocios() throws SQLException{
        ArrayList listaSocios = new ArrayList();
        
        String consulta = "SELECT * FROM SOCIO";
         ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while (rs.next()){
            Socio socio = new Socio (rs.getString(1), rs.getString(2),
                                    rs.getString(3), rs.getString(4), rs.getString(5), 
                                    rs.getString(6), rs.getString(7), rs.getString(8));
            listaSocios.add(socio);
        }
        
        return listaSocios;
    }
    
    public ArrayList<Socio> listaSocioPorLetra(String letra)throws SQLException{
        ArrayList listaSocios = new ArrayList();
        
        String consulta = "SELECT * FROM SOCIO WHERE nombre LIKE ?";
        ps = conexion.getConexion().prepareStatement(consulta);
        letra = letra + "%";
        ps.setString(1, letra);
        ResultSet rs = ps.executeQuery();
        while (rs.next()){
            Socio socio = new Socio (rs.getString(1), rs.getString(2),
                                    rs.getString(3), rs.getString(4), rs.getString(5), 
                                    rs.getString(6), rs.getString(7), rs.getString(8));
            listaSocios.add(socio);
        }
        
        return listaSocios;
    }
    
    public void insertarSocio(String numSocio, String nombre, String dni, String fechaNacimiento, String telefono, String correo, String fechaEntrada, String categoria) throws SQLException{
        
        String consulta = "INSERT INTO SOCIO VALUES (   ?,"     //NumSocio
                                                    +   "?,"    //Nombre
                                                    +   "?,"    //DNI
                                                    +   "?,"    //Fecha Nacimiento
                                                    +   "?,"    //Telefono
                                                    +   "?,"    //Correo
                                                    +   "?,"    //Fecha Entrada
                                                    +   "?)";   //Codigo
    
        PreparedStatement stmt = conexion.getConexion().prepareStatement(consulta);

        stmt.setString(1, numSocio);
        stmt.setString(2, nombre);
        stmt.setString(3, dni);
        stmt.setString(4, fechaNacimiento);
        stmt.setString(5, telefono);
        stmt.setString(6, correo);
        stmt.setString(7, fechaEntrada);
        stmt.setString(8, categoria);
        
        stmt.executeUpdate();
    }
    
    public void borrarSocio (String codSocio) throws SQLException{
        String borrado = "DELETE FROM SOCIO WHERE NUMEROSOCIO=?";
        
        PreparedStatement stmt = conexion.getConexion().prepareStatement(borrado);
        
        stmt.setString(1, codSocio);
        
        stmt.executeUpdate();
    }
    
    public void actualizarSocio(String numSocio, String nombre, String dni, String fechaNacimiento, String telefono, String correo, String fechaEntrada, String categoria) throws SQLException{
            String consulta = "UPDATE MONITOR SET   (   ?,"     //Nombre
                                                    +   "?,"    //DNI
                                                    +   "?,"    //Fecha Nacimiento
                                                    +   "?,"    //Telefono
                                                    +   "?,"    //Correo
                                                    +   "?,"    //Fecha Entrada
                                                    +   "?)"   //Codigo
                    + "WHERE NUMEROSOCIO = ?";   
    
        PreparedStatement stmt = conexion.getConexion().prepareStatement(consulta);

        stmt.setString(1, numSocio);
        stmt.setString(2, nombre);
        stmt.setString(3, dni);
        stmt.setString(4, fechaNacimiento);
        stmt.setString(5, telefono);
        stmt.setString(6, correo);
        stmt.setString(7, fechaEntrada);
        stmt.setString(8, categoria);

        stmt.executeUpdate();
    }
}
