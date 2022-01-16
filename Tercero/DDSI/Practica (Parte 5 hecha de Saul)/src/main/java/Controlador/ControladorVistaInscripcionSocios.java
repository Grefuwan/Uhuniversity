/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package Controlador;

import Modelo.Actividad;
import Modelo.ActividadDAO;
import Modelo.Socio;
import Modelo.SocioDAO;
import Vista.VistaActividad;
import Vista.VistaInscripcionesSocioActividad;
import Vista.VistaMensajes;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.Set;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.swing.JComboBox;
import javax.swing.JFrame;
import javax.swing.JTable;
import javax.swing.table.DefaultTableModel;
import org.hibernate.Session;
import org.hibernate.Transaction;

/**
 *
 * @author SaulRC1
 */
public class ControladorVistaInscripcionSocios {

    private VistaInscripcionesSocioActividad vAdministrarSocios;
    private Session conexion;
    private ArrayList<Socio> listaSocios;
    private Socio socioSeleccionado;
    private VistaMensajes vMens = new VistaMensajes();

    public DefaultTableModel modeloTablaAdministrarSocios = new DefaultTableModel() {
        @Override
        public boolean isCellEditable(int row, int column) {
            return false;
        }
    };

    public ControladorVistaInscripcionSocios(Session conexion) throws Exception {
        this.conexion = conexion;
        this.vAdministrarSocios = new VistaInscripcionesSocioActividad();
        this.vAdministrarSocios.setDefaultCloseOperation(JFrame.DISPOSE_ON_CLOSE);
        this.vAdministrarSocios.setTitle("Administrar Socios");
        this.vAdministrarSocios.setVisible(true);

        SocioDAO socios = new SocioDAO(this.conexion);

        ArrayList<Actividad> listaActividades;

        vAdministrarSocios.jTable_Inscripciones.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent evt) {
                tblAdministrarSocios_mouseClicked(evt);
            }
        });

        vAdministrarSocios.jButton_DarAltaInscripcion.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent evt) {
                btnAlta_mouseClicked(evt);
            }
        });

        vAdministrarSocios.jButton_DarBajaInscripcion.addMouseListener(new MouseAdapter() {
            @Override
            public void mouseClicked(MouseEvent evt) {
                btnBaja_mouseClicked(evt);
            }
        });

        try {
            listaSocios = socios.listaSocios();
            this.dibujarTablaAdministrarSocios();
            this.rellenarTablaAdministrarSocios(listaSocios);

        } catch (SQLException ex) {
            Logger.getLogger(ControladorVistaInscripcionSocios.class.getName()).log(Level.SEVERE, null, ex);
        }

    }

    public void dibujarTablaAdministrarSocios() {
        vAdministrarSocios.jTable_Inscripciones.setModel(modeloTablaAdministrarSocios);
        String[] columnasTabla = {"Numero de Socio", "Nombre de Socio", "Codigo de Actividad", "Nombre de Actividad"};
        modeloTablaAdministrarSocios.setColumnIdentifiers(columnasTabla);
        vAdministrarSocios.jTable_Inscripciones.getTableHeader().setResizingAllowed(false);
        vAdministrarSocios.jTable_Inscripciones.setAutoResizeMode(JTable.AUTO_RESIZE_LAST_COLUMN);
    }

    public void vaciarTablaActividades() {
        while (modeloTablaAdministrarSocios.getRowCount() > 0) {
            modeloTablaAdministrarSocios.removeRow(0);
        }
    }

    public void rellenarTablaAdministrarSocios(ArrayList<Socio> Socios) {

        Object[] fila = new Object[4];
        Set<Actividad> actividades;

        for (int i = 0; i < Socios.size(); i++) {
            System.out.println(Socios.get(i).getNumerosocio());
            Socio socio = this.conexion.get(Socio.class, Socios.get(i).getNumerosocio());
            if (!socio.getActividades().isEmpty()) {
                actividades = socio.getActividades();
                Iterator<Actividad> iteradorActividades = actividades.iterator();

                while (iteradorActividades.hasNext()) {
                    fila[0] = Socios.get(i).getNumerosocio();
                    fila[1] = Socios.get(i).getNombre();
                    Actividad act = iteradorActividades.next();
                    fila[2] = act.getIdactividad();
                    fila[3] = act.getNombre();

                    modeloTablaAdministrarSocios.addRow(fila);
                }
            } else {
                fila[0] = Socios.get(i).getNumerosocio();
                fila[1] = Socios.get(i).getNombre();
                fila[2] = "NO INSCRITO";
                fila[3] = "NO INSCRITO";
                modeloTablaAdministrarSocios.addRow(fila);
            }

        }

    }

    private void tblAdministrarSocios_mouseClicked(MouseEvent evt) {
        int fila = vAdministrarSocios.jTable_Inscripciones.getSelectedRow();

        String seleccionado = "[" + vAdministrarSocios.jTable_Inscripciones.getValueAt(fila, 0)
                + "] " + vAdministrarSocios.jTable_Inscripciones.getValueAt(fila, 1);

        String codigo = (String) vAdministrarSocios.jTable_Inscripciones.getValueAt(fila, 0);

        vAdministrarSocios.jTextField_SocioSeleccionado.setText(seleccionado);

        socioSeleccionado = this.conexion.get(Socio.class, codigo);

        this.rellenaComboBox();

    }

    private void btnAlta_mouseClicked(MouseEvent evt) {
        Transaction transaction = this.conexion.beginTransaction();
        try {
            String idAct = (String) vAdministrarSocios.jComboBox_Alta.getSelectedItem();
            idAct = idAct.split(" ")[0];
            System.out.println("ID ACTIVIDAD: " + idAct);
            Actividad actividad = this.conexion.get(Actividad.class, idAct);
            actividad.addSocio(socioSeleccionado);
            this.conexion.save(actividad);
            transaction.commit();

            this.vaciarTablaActividades();
            SocioDAO socios = new SocioDAO(this.conexion);
            this.rellenarTablaAdministrarSocios(socios.listaSocios());
            this.rellenaComboBox();
        } catch (Exception e) {
            vMens.MensajeError("Error al insertar socio", e.getMessage() );

            transaction.rollback();
        }

    }

    private void btnBaja_mouseClicked(MouseEvent evt) {
        Transaction transaction = this.conexion.beginTransaction();
        try {
            String idAct = (String) vAdministrarSocios.jComboBox_Baja.getSelectedItem();
            idAct = idAct.split(" ")[0];
            System.out.println("ID ACTIVIDAD: " + idAct);
            Actividad actividad = this.conexion.get(Actividad.class, idAct);
            
            actividad.eliminaSocio(socioSeleccionado);
            this.conexion.save(actividad);
            transaction.commit();

            this.vaciarTablaActividades();
            SocioDAO socios = new SocioDAO(this.conexion);
            this.rellenarTablaAdministrarSocios(socios.listaSocios());
            this.rellenaComboBox();
        } catch (Exception e) {
            vMens.MensajeError("Ha ocurrido un error", e.getMessage());
            transaction.rollback();
        }
    }

    private void rellenaComboBox() {
        ActividadDAO act = new ActividadDAO(this.conexion);
        Set<Actividad> actividadesSocio = socioSeleccionado.getActividades();
        Iterator<Actividad> iteradorActividades = actividadesSocio.iterator();
        ArrayList<Actividad> listaActividades = act.listaActividad();

        vAdministrarSocios.jComboBox_Alta.removeAllItems();
        vAdministrarSocios.jComboBox_Baja.removeAllItems();

        System.out.println("Lista Actividades Totales ");
        System.out.println(listaActividades);

        System.out.println("\nLista Actividades Socio");
        System.out.println(actividadesSocio);

        while (iteradorActividades.hasNext()) {
            Actividad aux = iteradorActividades.next();
            vAdministrarSocios.jComboBox_Baja.addItem(aux.getIdactividad() + " " + aux.getNombre());
            listaActividades.remove(aux);
        }

        for (int i = 0; i < listaActividades.size(); i++) {
            vAdministrarSocios.jComboBox_Alta.addItem(listaActividades.get(i).getIdactividad() + " " + listaActividades.get(i).getNombre());
        }
    }

}
