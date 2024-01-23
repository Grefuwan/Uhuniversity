package controlador;

import java.io.IOException;
import javax.servlet.RequestDispatcher;
import javax.servlet.ServletException;
import javax.servlet.annotation.WebServlet;
import javax.servlet.http.HttpServlet;
import javax.servlet.http.HttpServletRequest;
import javax.servlet.http.HttpServletResponse;

@WebServlet(name = "svHome", urlPatterns = {"/home"})
public class svHome extends HttpServlet {

    protected void processRequest(HttpServletRequest request, HttpServletResponse response) throws ServletException, IOException {
        String nextPg = request.getServletPath();
        System.out.println("Home=>" + nextPg);
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
                case "iniciarSesion":
                    vista = "/WEB-INF/vistas/iniciarSesion.jsp";
                    break;
                case "anadirCoche":
                    vista = "/WEB-INF/vistas/anadirCoche.jsp";
                    break;
                case "registrarUsuario":
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

}
