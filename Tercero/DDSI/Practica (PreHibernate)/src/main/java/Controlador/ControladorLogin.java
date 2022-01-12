package Controlador;

import Modelo.Conexion;
import Controlador.Controlador;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import Vista.VistaLogin;
import Vista.VistaMensajes;
import Vista.VistaPrincipal;

/**
 *
 * @author Grefuwan
 */
public class ControladorLogin implements ActionListener{
    
    private Controlador control     = null;
    private Conexion conexion       = null;
    private VistaLogin vLogin       = null;
    private VistaPrincipal vPrinc   = null;
    
    //private VistaMensajes vMens = new VistaMensajes();

    private SQLException sqlError;
    
    private boolean conexOK = false;
    
    //Constructor
    public ControladorLogin(){
        /*
        System.out.println("Voy a conectar con la BD\n");
        conexion.getConexion();
        
        System.out.println("Voy a desconectar de la BD\n");
        conexion.desconexion();
        */
        vLogin = new VistaLogin();
        
        addListeners();
        
        vLogin.setLocationRelativeTo(null); //Coloca la ventana en el centro de la pantalla
        vLogin.setVisible(true);            //Hace visible la ventana

    }

    
    private void addListeners(){
        vLogin.jButton_Conectar.addActionListener(this);
        vLogin.jButton_Salir.addActionListener(this);
    }
    
    
    @Override
    public void actionPerformed (ActionEvent e){
    
        switch ( e.getActionCommand() ) {
            case "Conectar":
                Conexion conexionOK = conectar();
                if (conexOK){
                    System.out.println("Conexion Correcta\n");
                    VistaMensajes.ConexCorrect();
                    vLogin.dispose();
                    control = new Controlador(conexionOK);
                }
                else{
                    VistaMensajes.ConexError(sqlError);
                }
                break;
            case "SalirDialogoConexion":
                vLogin.dispose();
                System.exit(0);
                break;
        }   
    }

    
    public Conexion conectar(){
        
        //Tengo que guardar todo lo que introduzco en la Vista en Strings que voy creando
            //para luego hacer una conexion con el constructor
        try{
            String server = (String) (vLogin.jComboBox_Server.getSelectedItem());
            String ip = vLogin.jTextField_IP.getText();
            String service_bd = vLogin.jTextField_Service.getText();
            String u = vLogin.jTextField_Usuario.getText();
            String p = new String (vLogin.jPasswordField1.getPassword());

            if (server == "MySQL") server = "mysql";
            else if (server == "Oracle") server = "oracle";
            
            conexion = new Conexion (server, ip, service_bd, u, p);
            
            conexOK = true;
            
        }catch (SQLException sqle){
            sqlError = sqle;
            String mensaje = (  "Codigo: "  + sqle.getErrorCode()   + 
                                "\nSQL: "   + sqle.getSQLState()    +
                                "\nTexto: " + sqle.getMessage()     );
            System.out.println("\nSe ha producido un error con " + mensaje);
        }
        return (conexion);
    }
    


    
}
