package controlador;

import java.io.IOException;
import java.security.MessageDigest;
import java.sql.Connection;
import java.sql.PreparedStatement;
import java.sql.ResultSet;
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
import modelo.Usuario;

@WebServlet(name = "svIniciarSesion", urlPatterns = {"/iniciarSesion"})
public class svIniciarSesion extends HttpServlet {

    @Resource(name = "concesionarioConnectionPool")
    private javax.sql.DataSource concesionarioConnectionPool;

    Connection conn;
    PreparedStatement ps;
    Usuario user;

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String nextPg = request.getServletPath();
        System.out.println("inicioSesion=>" + nextPg);
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
        String username = request.getParameter("loginUsuario");
        String pass = request.getParameter("loginContrasena");
        String rol = "";
        String query = "SELECT * FROM ROOT.USUARIOS WHERE USERNAME=? AND PASSWORD=?";
        try {

            Context c = new InitialContext();
            concesionarioConnectionPool = (javax.sql.DataSource) c.lookup("jdbc/myDatasource");
            conn = concesionarioConnectionPool.getConnection();

            ps = conn.prepareStatement(query);
            ps.setString(1, username);
            ps.setString(2, pass);

            try ( ResultSet rS = ps.executeQuery()) {
                if (rS.next()) {  //Hay al menos una tupla, luego user-pass existe
                    System.out.println("IniciarSesion=> Usuario existente");
                    rol = rS.getString("ROL");

                    HttpSession session = request.getSession();
                    session.setAttribute("usuario", username);
                    session.setAttribute("rol", rol);
                    System.out.println("Usuario: " + session.getAttribute("usuario") + "--Rol: " + session.getAttribute("rol"));

                } else {
                    System.out.println("IniciarSesion=> Credenciales incorrectas");
                }
            }
        } catch (SQLException e) {
            e.printStackTrace();
        } catch (NamingException ex) {
            Logger.getLogger(svIniciarSesion.class.getName()).log(Level.SEVERE, null, ex);
        }

        if (rol.equals("admin")) {
            request.getRequestDispatcher("/WEB-INF/vistas/anadirCoche.jsp").forward(request, response);
            this.processRequest(request, response);
        }
        else{
            this.processRequest(request, response);
        }
    }

    @Override
    public String getServletInfo() {
        return "Short description";
    }

}
