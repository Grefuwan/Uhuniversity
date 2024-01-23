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

@WebServlet(name = "svCatalogoCoches", urlPatterns = {"/catalogo"})
public class svCatalogoCoches extends HttpServlet {

    @Resource(name = "concesionarioConnectionPool")
    private DataSource concesionarioConnectionPool;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String nextPg = request.getServletPath();
        System.out.println("Catalogo=>" + nextPg);
        String vista;

        if (nextPg == null) {
            vista = "/WEB-INF/vistas/home.jsp";
        } else {
            switch (nextPg) {
                case "/home":
                    vista = "/WEB-INF/vistas/home.jsp";
                    break;
                case "/catalogo":
                    vista = "/WEB-INF/vistas/catalogo.jsp";
                    break;
                case "/iniciarSesion":
                    vista = "/WEB-INF/vistas/iniciarSesion.jsp";
                    break;
                case "/anadirCoche":
                    vista = "/WEB-INF/vistas/anadirCoche.jsp";
                    break;
                case "/registrarUsuario":
                    vista = "/WEB-INF/vistas/registrarUsuario.jsp";
                    break;
                default:
                    vista = "/WEB-INF/vistas/home.jsp";
                    break;
            }
        }
        request.getRequestDispatcher(vista).forward(request, response);
    }

    @Override
    protected void doGet(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

        this.processRequest(request, response);
    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {

    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

    private List<Coche> obtenerCochesBD() {
        List<Coche> coches = new ArrayList<>();
        Connection conn;
        PreparedStatement ps;

        try {
            Context c = new InitialContext();
            concesionarioConnectionPool = (javax.sql.DataSource) c.lookup("jdbc/myDatasource");
            conn = concesionarioConnectionPool.getConnection();

            System.out.println("obtenerCochesBD=> Conexion Establecida");

            ps = conn.prepareStatement("SELECT MARCA, MODELO, MATRICULA, TAMANO, KMS, COMBUSTIBLE FROM ROOT.COCHES");

            try ( ResultSet rS = ps.executeQuery()) {
                while (rS.next()) {
                    Coche coche = new Coche();
                    coche.setMarca(rS.getString("MARCA"));
                    coche.setModelo(rS.getString("MODELO"));
                    coche.setMatricula(rS.getString("MATRICULA"));
                    coche.setTamano(rS.getString("TAMANO"));
                    coche.setKilometros(rS.getInt("KMS"));
                    coche.setCombustible(rS.getString("COMBUSTIBLE"));
                    coches.add(coche);

                    coche.toString();
                }
                ps.close();
                conn.close();
            }
        } catch (SQLException | NamingException ex) {
            Logger.getLogger(svAnadirCoche.class.getName()).log(Level.SEVERE, null, ex);
        }
        System.out.println("Coches=>" + coches.toString());

        return coches;
    }

}
