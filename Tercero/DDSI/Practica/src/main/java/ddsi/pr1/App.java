/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ddsi.pr1;

import Controlador.ControladorLogin;
import java.sql.SQLException;

/**
 *
 * @author Grefuwan
 */
public class App {
    
    
    public static void main(String[] args) {
        try {
        
            ControladorLogin cLogin = new ControladorLogin();
            
        }catch(SQLException e){
        
            System.out.println("Error conexion");
            
        }
        
        
    }
    
    
    
}
