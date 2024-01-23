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
import modelo.Usuario;

@WebServlet(name = "svRegistrarUsuario", urlPatterns = {"/registrarUsuario"})
public class svRegistrarUsuario extends HttpServlet {

    @Resource(name = "concesionarioConnectionPool")
    private javax.sql.DataSource concesionarioConnectionPool;

    Connection conn;
    PreparedStatement ps;
    Usuario user;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String nextPg = request.getServletPath();
        System.out.println("registrarUsuario=>" + nextPg);
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
        try {
            user = new Usuario();

            String username = request.getParameter("regUsuario");
            String password = request.getParameter("regContrasena");
            String rol = request.getParameter("regRolUsuario");

            user.setUsername(username);
            user.setPassword(password);
            user.setRol(rol);

            Context c = new InitialContext();
            concesionarioConnectionPool = (javax.sql.DataSource) c.lookup("jdbc/myDatasource");
            conn = concesionarioConnectionPool.getConnection();
            System.out.println("Conexion Establecida - svRegistrarUsuario");

            ps = conn.prepareStatement("INSERT INTO ROOT.USUARIOS (USERNAME, PASSWORD, ROL) VALUES (?,?,?)");
            ps.setString(1, username);
            ps.setString(2, password);
            ps.setString(3, rol);

            ps.executeUpdate();

            ps.close();
            conn.close();

            System.out.println("Usuario Registrado - svRegistrarUsuario");

            request.getRequestDispatcher("/WEB-INF/vistas/iniciarSesion.jsp").forward(request, response);

        } catch (NamingException | SQLException ex) {
            Logger.getLogger(svAnadirCoche.class.getName()).log(Level.SEVERE, null, ex);
        }
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

}
