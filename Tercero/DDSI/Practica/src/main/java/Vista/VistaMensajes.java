package Vista;
import javax.swing.JOptionPane;

/**
 *
 * @author Grefuwan
 */
public class VistaMensajes {
    
    public static void MensajeError(String Texto, String mensaje){
        
        JOptionPane.showMessageDialog(null, Texto + "\n" + mensaje, "Error", 0);
        
    }
    
    public static void MensajeInfo(String texto){
        JOptionPane.showMessageDialog(null, texto);
    }
}
