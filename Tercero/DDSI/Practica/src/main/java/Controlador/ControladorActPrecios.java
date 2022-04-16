/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Controlador;
import Modelo.Actividad;
import Modelo.ActividadDAO;
import Modelo.Socio;
import Vista.VistaActualizacionPrecios;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.hibernate.Session;
import org.hibernate.Transaction;
import org.hibernate.query.Query;
/**
 *
 * @author Grefuwan
 */
public class ControladorActPrecios {
    
    Session sesion = null;
    private int preciomodif = 0;
    VistaActualizacionPrecios vActPrec = new VistaActualizacionPrecios();
    
    public ControladorActPrecios(Session c){
        this.sesion = c;
    }
    
    public ArrayList<Object[]> listaNombreActividad() throws Exception {
        Transaction transaction = sesion.beginTransaction();
        
        Query consulta = sesion.createNativeQuery("SELECT IDACTIVIDAD, NOMBRE, PRECIOBASEMES FROM ACTIVIDAD A");
        ArrayList<Object[]> actividades = (ArrayList<Object[]>) consulta.list();
        
        transaction.commit();
        return actividades;
    }
    
    //----------------------------------Util Tablas-----------------------------------
    public DefaultTableModel modeloTablaActualizacionPrecio = new DefaultTableModel(){
        @Override
        public boolean isCellEditable(int row, int column){
            return false;
        }
    };
    
    
    public void dibujarTablaActualizacionPrecio(VistaActualizacionPrecios vActPrec){
        vActPrec.jTable_ActualizaPrecios.setModel(modeloTablaActualizacionPrecio);
        
        String[] columnasTabla = {"Codigo", "Nombre", "Precio"};
        modeloTablaActualizacionPrecio.setColumnIdentifiers(columnasTabla);
        
        vActPrec.jTable_ActualizaPrecios.getTableHeader().setResizingAllowed(false);
        vActPrec.jTable_ActualizaPrecios.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
        
        vActPrec.jTable_ActualizaPrecios.getColumnModel().getColumn(0).setPreferredWidth(60);     //CodActiv
        vActPrec.jTable_ActualizaPrecios.getColumnModel().getColumn(1).setPreferredWidth(200);    //Nombre Activ
        vActPrec.jTable_ActualizaPrecios.getColumnModel().getColumn(2).setPreferredWidth(60);     //Precio
    }
    
    
    public void rellenarTablaActualizPrecio(){
        Object[] fila = new Object[3];
        
        Transaction transaction = sesion.beginTransaction();
        Query consulta = sesion.createNativeQuery ("SELECT IDACTIVIDAD, NOMBRE, PRECIOBASEMES FROM ACTIVIDAD A");
        ArrayList<Object[]> activs = (ArrayList<Object[]>) consulta.list();
        
        for (int i = 0; i < activs.size(); i++){
                    fila[0] = activs.get(i)[0];
                    fila[1] = activs.get(i)[1];
                    fila[2] = activs.get(i)[2];
                    modeloTablaActualizacionPrecio.addRow(fila);
                }
        transaction.commit();
    }
    
    private void vaciarTablaActPrecios(){
        while (modeloTablaActualizacionPrecio.getRowCount() > 0)
            modeloTablaActualizacionPrecio.removeRow(0);
    }
    
    public void modifPrecio(int variacion){
        int newPrecio = 0;
        ActividadDAO actDAO = new ActividadDAO(sesion);
        ArrayList<Actividad> listActivs = actDAO.listaActividad();
        for (Actividad actIt : listActivs){
            newPrecio = variacion + actIt.getPreciobasemes();
            actIt.setPreciobasemes(newPrecio);
        }
        
        vaciarTablaActPrecios();
        rellenarTablaActualizPrecio();
    }
    
}
