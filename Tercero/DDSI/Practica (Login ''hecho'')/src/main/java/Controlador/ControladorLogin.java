package Controlador;

import Modelo.Conexion;
import Modelo.HibernateUtil;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import java.sql.SQLException;
import Vista.VistaLogin;
import Vista.VistaMensajes;
import Vista.VistaPrincipal;
import org.hibernate.Session;

/**
 *
 * @author Grefuwan
 */
public class ControladorLogin implements ActionListener{
    
    private Controlador control     = null;
    private Conexion conexion       = null;
    private VistaLogin vLogin       = null;
    //private VistaPrincipal vPrinc   = null;
    private Session sesion          = null;
    private VistaMensajes vMens     = null;
    
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
        vMens = new VistaMensajes();
        
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
                sesion = conectar();
                if (sesion != null) {
                    //vMens.Mensaje("info", "Conexión correcta con Hibernate");
                    vLogin.dispose();
                    control = new Controlador(sesion);
                    //public Controlador(Conexion conectP) 
                }
                //else vMens.Mensaje("error", "Error en la conexión con Hibernate. Revise los valores de conexión");
                break;
                
            case "SalirDialogoConexion":
                vLogin.dispose();
                System.exit(0);
                break;
        }   
    }

//------------------------------------Conectar JDBC------------------------------------
    /*public Conexion conectar(){
        
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
    }*/

//------------------------------------Conectar Hibernate------------------------------------
    public Session conectar(){
        String server = (String) (vLogin.jComboBox_Server.getSelectedItem());
        String ip = vLogin.jTextField_IP.getText();
        String service_bd = vLogin.jTextField_Service.getText();
        String u = vLogin.jTextField_Usuario.getText();
        String p = new String (vLogin.jPasswordField1.getPassword());

        if (server == "MySQL")
            server = "mysql";
        else if (server == "Oracle")
            server = "oracle";
        
        if ("oracle".equals(server) && "172.17.20.39".equals(ip) && "etsi".equals(service_bd) && "DDSI_012".equals(u) && "DDSI_012".equals(p))
            sesion = HibernateUtil.getSessionFactory().openSession();
        return(sesion);

    }

}