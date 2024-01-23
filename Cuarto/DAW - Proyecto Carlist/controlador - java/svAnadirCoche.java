package controlador;

import java.io.IOException;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.SQLException;
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
import javax.servlet.http.HttpSession;
import modelo.Coche;

@WebServlet(name = "svAnadirCoche", urlPatterns = {"/anadirCoche"})
public class svAnadirCoche extends HttpServlet {

    @Resource(name = "concesionarioConnectionPool")
    private javax.sql.DataSource concesionarioConnectionPool;

    Coche coche;
    Connection conn;
    PreparedStatement ps;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String nextPg = request.getServletPath();
        System.out.println("anadirCoche=>" + nextPg);
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
        HttpSession session = request.getSession();
        String rol = (String) session.getAttribute("rol");

        if ("admin".equals(rol)) {
            this.processRequest(request, response);
        } else {
            request.getRequestDispatcher("/WEB-INF/vistas/catalogo.jsp").forward(request, response);
        }

    }

    @Override
    protected void doPost(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        try {
            HttpSession session = request.getSession();
            String rol = (String) session.getAttribute("rol");

            if ("admin".equals(rol)) {
                System.out.println("AnadirCoche=> Rol: Admin");

                coche = new Coche();

                String marca = request.getParameter("marcaCoche");
                String modelo = request.getParameter("modeloCoche");
                String matricula = request.getParameter("matriculaCoche");
                String tamano = request.getParameter("tipoCoche");
                String str_kilometros = request.getParameter("kilometrosCoche");
                String combustible = request.getParameter("n_Combustible");

                System.out.println("===> Coche: " + marca + modelo + matricula + tamano + str_kilometros + combustible);

                int km = Integer.parseInt(str_kilometros);
                if (km < 0) {
                    throw new NumberFormatException();
                }

                coche.setMarca(marca);
                coche.setModelo(modelo);
                coche.setMatricula(matricula);
                coche.setTamano(tamano);
                coche.setKilometros(km);
                coche.setCombustible(combustible);

                Context c = new InitialContext();
                concesionarioConnectionPool = (javax.sql.DataSource) c.lookup("jdbc/myDatasource");
                conn = concesionarioConnectionPool.getConnection();
                System.out.println("Conexion Establecida");

                ps = conn.prepareStatement("INSERT INTO ROOT.COCHES (MARCA, MODELO, MATRICULA, TAMANO, KILOMETROS, COMBUSTIBLE, LIBRE) VALUES (?,?,?,?,?,?,?)");
                ps.setString(1, coche.getMarca());
                ps.setString(2, coche.getModelo());
                ps.setString(3, coche.getMatricula());
                ps.setString(4, coche.getTamano());
                ps.setInt(5, coche.getKilometros());
                ps.setString(6, coche.getCombustible());
                ps.setBoolean(7, true);

                ps.executeUpdate();

                ps.close();
                conn.close();
            } else {
                System.out.println("AnadirCoche=> Rol: otro");
            }
            request.getRequestDispatcher("/WEB-INF/vistas/catalogo.jsp").forward(request, response);

        } catch (NamingException | SQLException ex) {
            Logger.getLogger(svAnadirCoche.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

}
