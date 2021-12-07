/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.sql.Statement;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class MonitorDAO {
    Conexion conexion = null;
    PreparedStatement ps = null;
    
    public MonitorDAO (Conexion c){
        this.conexion = c;
    }
    
    public ArrayList<Monitor> listaMonitores() throws SQLException{
        ArrayList listaMonitores = new ArrayList();
        
        String consulta = "SELECT * FROM MONITOR";
        ps = conexion.getConexion().prepareStatement(consulta);
        ResultSet rs = ps.executeQuery();
        
        while (rs.next()){
            Monitor monitor = new Monitor (rs.getString(1), rs.getString(2),
                                    rs.getString(3), rs.getString(4), rs.getString(5), 
                                    rs.getString(6), rs.getString(7));
            listaMonitores.add(monitor);
        }
        
        return listaMonitores;
    }
    
    
    public ArrayList<Monitor> listaMonitorPorLetra(String letra)throws SQLException{
        ArrayList listaMonitores = new ArrayList();
        
        String consulta = "SELECT * FROM MONITOR WHERE nombre LIKE ?";
        ps = conexion.getConexion().prepareStatement(consulta);
        letra = letra + "%";
        ps.setString(1, letra);
        ResultSet rs = ps.executeQuery();
        while (rs.next()){
            Monitor monitor = new Monitor (rs.getString(1), rs.getString(2),
                                    rs.getString(3), rs.getString(4), rs.getString(5), 
                                    rs.getString(6), rs.getString(7));
            listaMonitores.add(monitor);
        }
        
        return listaMonitores;
    }
    
    public void insertarMonitor(String codigo, String nombre, String dni, String tlf, String correo, String fechInc, String nick) throws SQLException{
        
        String consulta = "INSERT INTO MONITOR VALUES(   ?,"    //Codigo
                                                    +   "?,"    //Nombre
                                                    +   "?,"    //DNI
                                                    +   "?,"    //Num Telefono
                                                    +   "?,"    //Correo
                                                    +   "?,"    //Fecha Incorporacion
                                                    +   "?)";   //Nick
    
        PreparedStatement stmt = conexion.getConexion().prepareStatement(consulta);

        stmt.setString(1, codigo);
        stmt.setString(2, nombre);
        stmt.setString(3, dni);
        stmt.setString(4, tlf);
        stmt.setString(5, correo);
        stmt.setString(6, fechInc);
        stmt.setString(7, nick);
        
        stmt.executeUpdate();
    }
    
    public void borrarMonitor (String codMon) throws SQLException{
        String borrado = "DELETE FROM MONITOR WHERE CODMONITOR=?";
        
        PreparedStatement stmt = conexion.getConexion().prepareStatement(borrado);
        
        stmt.setString(1, codMon);
        
        stmt.executeUpdate();
    }
    
    
    public void actualizarMonitor (String codigo, String nombre, String dni, String tlf, String correo, String fechInc, String nick) throws SQLException{
        String actualizar = "UPDATE MONITOR SET NOMBRE = ?,"
                                            +   "DNI = ?,"
                                            +   "TELEFONO = ?,"
                                            +   "CORREO = ?,"
                                            +   "FECHAENTRADA = ?,"
                                            +   "NICK = ?"
                + "WHERE CODMONITOR = ?";
        
        PreparedStatement stmt = conexion.getConexion().prepareStatement(actualizar);
        
        stmt.setString(1, nombre);
        stmt.setString(2, dni);
        stmt.setString(3, tlf);
        stmt.setString(4, correo);
        stmt.setString(5, fechInc);
        stmt.setString(6, nick);
        stmt.setString(7, codigo);
        
        stmt.executeUpdate();
    }
}
