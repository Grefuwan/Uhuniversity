/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;

import Modelo.Conexion;
import Vista.VistaMensajes;
import Vista.VistaPrincipal;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

/**
 *
 * @author Grefuwan
 */
public class Controlador implements ActionListener{
    
    private Conexion conexion = null;
    private VistaPrincipal vPrinc = null;
    private VistaMensajes vMensaje = null;
    
    
    public Controlador(Conexion conectP)  {
        this.conexion = conectP;
        vMensaje = new VistaMensajes();
        
        //Mostrar la Ventana Principal (VistaPrincipal)
        vPrinc = new VistaPrincipal();

        //Gestionar el cierre de VistaPrincipal
        addListeners();
        
        vPrinc.setLocationRelativeTo(null);
        vPrinc.setVisible(true);
        
    }

    private void addListeners() {
       // vPrinc.jButton_Principal_Cerrar.addActionListener(this);
    }

    @Override
    public void actionPerformed(ActionEvent e) {
        switch (e.getActionCommand() ){
            case "Cerrar":
                    vPrinc.dispose();
                    System.exit(0);
                break;
        }
    }
    

}



