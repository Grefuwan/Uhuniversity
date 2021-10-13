/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.sql.Connection;
import java.sql.DriverManager;
import java.sql.SQLException;

/**
 *
 * @author Grefuwan
 */
public class Conexion {
    Connection conexion = null;
    
    public Conexion() throws SQLException{
        String cadenaConexion = "jdbc:oracle:thin:@172.17.20.75:1521:rabida";
        String usuario = "DDSI_012";
        String password = "DDSI_012";
        
        conexion = DriverManager.getConnection(cadenaConexion, usuario, password);
    
    }
    
    public Connection getConexion(){
        return (conexion);
    }
    
    public void desconexion(){
        //ToDo
    }
}
