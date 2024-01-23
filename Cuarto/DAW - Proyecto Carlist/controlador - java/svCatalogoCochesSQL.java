package controlador;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
import java.sql.SQLException;
import java.util.ArrayList;
import java.util.List;
import java.util.logging.Level;
import java.util.logging.Logger;
import javax.annotation.Resource;
import javax.naming.Context;
import javax.naming.InitialContext;
import javax.naming.NamingException;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;
import javax.sql.DataSource;
import modelo.Coche;

@WebServlet(name = "svCatalogoCochesSQL", urlPatterns = {"/svCatalogoCochesSQL"})
public class svCatalogoCochesSQL extends HttpServlet {

    @Resource(name = "concesionarioConnectionPool")
    private DataSource concesionarioConnectionPool;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String marca = request.getParameter("marca");

        List<Coche> coches = obtenerCochesBD(marca);

        // Construccion HTML Tabla
        StringBuilder tablaCatalogo = new StringBuilder("<table class='class_TablaCatalogo'  id='id_tablaCatalogo'>\n"
                + " <thead>\n"
                + " <th>Imagen</th>\n"
                + " <th>Marca</th>\n"
                + " <th>Modelo</th>\n"
                + " <th>Matricula</th>\n"
                + " <th>Tamaño</th>\n"
                + " <th>Kilometros</th>\n"
                + " <th>Combustible</th>\n"
                + " <th>Estado</th>\n"
                + " </thead>\n"
                + " \n"
                + " <tbody>");
        for (Coche coch : coches) {
            tablaCatalogo.append("<tr>")
                    .append("<td></td>")
                    .append("<td>").append(coch.getMarca()).append("</td>")
                    .append("<td>").append(coch.getModelo()).append("</td>")
                    .append("<td>").append(coch.getMatricula()).append("</td>")
                    .append("<td>").append(coch.getTamano()).append("</td>")
                    .append("<td>").append(coch.getKilometros()).append("</td>")
                    .append("<td>").append(coch.getCombustible()).append("</td>");
            if (coch.isLibre()) {
                tablaCatalogo.append("<td>Libre</td>");
            } else {
                tablaCatalogo.append("<td>Libre</td>");
            }
            tablaCatalogo.append("</tr>");
        }
        tablaCatalogo.append("</tbody>\n"
                + "      </table>");

        // Envia el HTML de la tabla como respuesta
        response.setContentType("text/html");
        response.getWriter().write(tablaCatalogo.toString());
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        processRequest(request, response);
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

    private List<Coche> obtenerCochesBD(String marca) {
        List<Coche> coches = new ArrayList<>();
        Connection conn;
        PreparedStatement ps;

        try {
            Context c = new InitialContext();
            concesionarioConnectionPool = (javax.sql.DataSource) c.lookup("jdbc/myDatasource");
            conn = concesionarioConnectionPool.getConnection();
            System.out.println("obtenerCochesBD=> Conexion Establecida");
            String consulta = "SELECT MARCA, MODELO, MATRICULA, TAMANO, KILOMETROS, COMBUSTIBLE, LIBRE FROM ROOT.COCHES";

            if ("all".equals(marca)) { // Todos los coches
            } else {
                consulta = consulta + " WHERE MARCA = '" + marca + "'";
            }
            System.out.println(consulta);
            ps = conn.prepareStatement(consulta);

            try ( ResultSet rS = ps.executeQuery()) {
                while (rS.next()) {
                    Coche coche = new Coche();
                    coche.setMarca(rS.getString("MARCA"));
                    coche.setModelo(rS.getString("MODELO"));
                    coche.setMatricula(rS.getString("MATRICULA"));
                    coche.setTamano(rS.getString("TAMANO"));
                    coche.setKilometros(rS.getInt("KILOMETROS"));
                    coche.setCombustible(rS.getString("COMBUSTIBLE"));
                    coche.setLibre(rS.getBoolean("LIBRE"));
                    coches.add(coche);

                    coche.toString();
                }
            }

            ps.close();
            conn.close();
        } catch (SQLException | NamingException ex) {
            Logger.getLogger(svAnadirCoche.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Coches=>" + coches.toString());
        return coches;
    }

}
