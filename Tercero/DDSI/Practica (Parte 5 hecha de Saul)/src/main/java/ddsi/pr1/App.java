/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package ddsi.pr1;

import Controlador.ControladorLogin;
import java.sql.SQLException;
import javax.swing.UIManager;
import javax.swing.UIManager.LookAndFeelInfo;

/**
 *
 * @author Grefuwan
 */
public class App {
    
    
    public static void main(String[] args) {
        try {
            for (LookAndFeelInfo info : UIManager.getInstalledLookAndFeels() ){
                if ("Nimbus".equals(info.getName() ) ){
                    UIManager.setLookAndFeel(info.getClassName() );
                    break;
                }
            }            
        } catch(Exception e){
            //Si Nimbus no está disponible, poner la GUI con otra interfaz
            System.out.println("Error conexion");
        }
       
        ControladorLogin cLogin = new ControladorLogin();
       
    }
    
}
