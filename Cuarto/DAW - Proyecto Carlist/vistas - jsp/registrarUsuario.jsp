<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
        <title>Carlist</title>
        <link href="css/estilo.css" rel="stylesheet" type="text/css"/>
    </head>

    <body>
        <nav>
            <div class="nav-bar">
                <span class="logo"><a href="/Carlist/home">Carlist</a></span>

                <div class="menu">
                    <ul class="nav-links">
                        <li><a href="/Carlist/home">Inicio</a></li>
                        <li><a href="/Carlist/catalogo">Coches</a></li>
                        <li><a href="/Carlist/iniciarSesion">Iniciar Sesion</a></li>    
                        <li><a href="/Carlist/anadirCoche">Añadir Coches</a></li>
                    </ul>
                </div>
            </div>
        </nav>

        <form class="formularioAnadir" id="formRegistroUsuario" action="registrarUsuario" method="POST">
            <table>
                <tr>
                    <td> Usuario: </td>
                    <td><input type="text" id="id_regUsuario" name="regUsuario" placeholder="Usuario" required></td>
                </tr>

                <tr>
                    <td>Contraseña: </td>
                    <td><input type="password" id="id_regContrasena" name="regContrasena" placeholder="Contraseña" required></td>
                </tr>
                <tr>
                    <td>Rol </td>
                    <td><select name="regRolUsuario" id="id_rolUsuario">
                            <option value="nulo">--Seleccione Modelo--</option>
                            <option value="admin">Admin</option>
                            <option value="cliente">Cliente</option>
                        </select> </td>
                </tr>

                <tr>
                    <td></td>
                    <td><input type="submit" value="Registrarse"></td>
                </tr>
            </table> 
        </form>

        <div class="footer">
            Copyright ©. 2023 - Juan Garcia Villagran
        </div>

    </body>
</html>
