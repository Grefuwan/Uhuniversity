/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.Actividad;
import Modelo.Socio;
import Vista.VistaCuotas;
import java.util.Iterator;
import java.util.Set;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author Grefuwan
 */
public class ControladorCuotas {
    Session sesion = null;
    VistaCuotas vCuot = new VistaCuotas();
    
    public ControladorCuotas(Session c){
        this.sesion = c;
    }
    
    public void verCuota (String codSocioParam){
        Socio socit = sesion.get(Socio.class, codSocioParam);   //Obtengo el Socio
        
        int numActivs = 0;
        int cuotaTotal = 0;
        
        Set<Actividad> actividades = socit.getActividades();        //Obtengo sus actividades
        Iterator<Actividad> iterActivs = actividades.iterator();
        
        for (Actividad a : actividades ){
            numActivs++;
            cuotaTotal += a.getPreciobasemes();
        }
        System.out.println("codSocioParam: " + codSocioParam);
        System.out.println("NumeroActividades: " + numActivs);
        System.out.println("Cuota: " + cuotaTotal + "\n\n");

        
        vCuot.jLabel_CuotaMensualModif.setText( String.valueOf(cuotaTotal) );
        vCuot.jLabel_NumActivsModf.setText( String.valueOf(numActivs) );
        
    }
}
