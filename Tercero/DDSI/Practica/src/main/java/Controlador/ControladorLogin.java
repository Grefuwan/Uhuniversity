package Controlador;

import Modelo.HibernateUtil;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;
import Vista.VistaLogin;
import Vista.VistaMensajes;
import org.hibernate.Session;

/**
 *
 * @author Grefuwan
 */
public class ControladorLogin implements ActionListener{
    
    private Controlador control     = null;
    private VistaLogin vLogin       = null;
    private Session sesion          = null;
    private VistaMensajes vMens     = null;
        
    public ControladorLogin(){
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
                    vMens.MensajeInfo( "Conexión correcta con Hibernate");
                    vLogin.dispose();
                    control = new Controlador(sesion);
                }
                else vMens.MensajeError("error", "Error en la conexión con Hibernate. Revise los valores de conexión");
                break;
                
            case "SalirDialogoConexion":
                vLogin.dispose();
                System.exit(0);
                break;
        }   
    }

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
        
        if ("oracle".equals(server) && "172.17.20.75".equals(ip) && "rabida".equals(service_bd) && "DDSI_012".equals(u) && "DDSI_012".equals(p))
            sesion = HibernateUtil.getSessionFactory().openSession();
        return(sesion);

    }

}
