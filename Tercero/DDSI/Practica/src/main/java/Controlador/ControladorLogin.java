package Controlador;

import Modelo.Conexion;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import Vista.VistaLogin;
import Vista.VistaMensajes;

/**
 *
 * @author Grefuwan
 */
public class ControladorLogin implements ActionListener{
    
    private Conexion conexion = new Conexion();
    private VistaLogin vLogin = null;
    
    //private VistaMensajes vMens = new VistaMensajes();

    private SQLException sqlError;
    
    private boolean conexOK = false;
    
    //Constructor
    public ControladorLogin() throws SQLException{
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
                    //Instanciar un objeto de tipo Controlador (apartado 4)
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
            String service_bd = vLogin.jLabel_Service.getText();
            String u = vLogin.jLabel_Usuario.getText();
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
