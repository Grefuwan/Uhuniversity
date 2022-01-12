package Vista;
import java.sql.SQLException;
import javax.swing.*;

/**
 *
 * @author Grefuwan
 */
public class VistaMensajes {
    
    JOptionPane optPane = new JOptionPane();
    
    /*Esquema del JDialog*/
        //JOptionPane optionPane = new JOptionPane();
        //JDialog dialog = optionPane.createDialog(null, "Holiwis");
    
    
    public static void ConexCorrect(){
        //JDialog dialog = optPane.createDialog(null, "Conexión Correcta");
        JOptionPane.showMessageDialog(null, "Conexión Correcta", "Conexion Correctisisisisisima", JOptionPane.INFORMATION_MESSAGE);
        
        
    }
    
    public static void ConexError(SQLException sqle){
        String msg = "Error en la conexion. Revise los parámetros introducidos";
        String sqlEr = "\nCodigo: " + sqle.getErrorCode() + 
                        "\nSQL: "   + sqle.getSQLState()  +
                        "\nTexto: " + sqle.getMessage();
        String str = msg + sqlEr;
        JOptionPane.showMessageDialog(null, str, "Error Conexión", JOptionPane.INFORMATION_MESSAGE);
        //Poner el error de SQL de la captura de pantalla
            //(?)Vendria por parametro dicho error(?)
    }

    public static void Mensaje(String mens){
        String msg = mens;
        
        JOptionPane.showMessageDialog(null, msg);
    }

    /*public void Mensaje(String mens1, String mens2) {
        throw new UnsupportedOperationException("Not supported yet."); //To change body of generated methods, choose Tools | Templates.
    }*/
}
