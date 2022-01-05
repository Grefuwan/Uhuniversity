/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

import java.sql.CallableStatement;
import java.sql.SQLException;

/**
 *
 * @author Grefuwan
 */
public class ActividadDAO {
    
    Conexion conexion = null;
    CallableStatement stmt = null;
    
    
    public void procedureActividad() throws SQLException{
        
        String callProced = "{ call SociosXActividad    (?,"       //P1 - Entrada  -   ID Actividad
                                                       + "?) }";   //P2 - Salida   -   Cursor con Nombre y Correo de los socios inscritos a dicha actividad

        stmt = conexion.getConexion().prepareCall(callProced);
        stmt.executeUpdate();
    }
    
}
