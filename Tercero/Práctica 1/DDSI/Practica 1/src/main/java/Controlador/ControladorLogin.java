/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.Conexion;
import Vista.VistaConsola;
import java.sql.SQLException;
import java.util.logging.Level;
import java.util.logging.Logger;

/**
 *
 * @author Grefuwan
 */
public class ControladorLogin {
    private Conexion conexion = null;
    private boolean conexionOK;
    private boolean desconexionOK;
    private VistaConsola vista = new VistaConsola();
    
    public ControladorLogin(){
    
        //1. Conectarse a la BD
            conexionOK = conectar();
            //desconexionOK = desconectar();
        
    }
    
    public boolean conectar(){
        boolean resultado = false;
        
        try {
            conexion = new Conexion();
            vista.vistaConsolaLogin("Conexion correcta. Enhorabuena");
            resultado = true;
        } 
        catch (SQLException ex) {
            vista.vistaConsolaLogin("Error en la conexion", ex.getMessage()); //getMessage me muestra el error producido
        }
        
        return resultado;
    
    }
    
    /*public boolean desconectar(){
    
        //TODO
    }*/
    
}
