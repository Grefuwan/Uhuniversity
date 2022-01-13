/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.ActividadDAO;
import Vista.VistaActividad;
import javax.swing.JComboBox;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Grefuwan
 */
public class ControladorActividades {
    VistaActividad vAct     = null;
    Session sesion          = null;
    
    
    public void llenaComboBox(JComboBox combBox){
        ActividadDAO actDAO = new ActividadDAO(sesion);
        Transaction trans = sesion.beginTransaction();
        
        String activs = "SELECT A.NOMBRE FROM ACTIVIDAD A ORDER BY A.NOMBRE ASC";
        
        vAct.jComboBox_IDActivity.addItem(activs);
        
    }
}
