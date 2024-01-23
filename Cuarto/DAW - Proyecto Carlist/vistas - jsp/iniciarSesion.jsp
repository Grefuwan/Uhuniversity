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

        <form class ="formularioAnadir" id="formIniciarSesion"  method="POST" onsubmit="return validar(this);">
            <table>
                <tr>
                    <td> Usuario: </td>
                    <td><input type="text" id="id_loginUsuario" name="loginUsuario" placeholder="Usuario" required></td>
                </tr>

                <tr>
                    <td>Contraseña: </td>
                    <td><input type="password" id="id_loginContrasena" name="loginContrasena" placeholder="Contraseña" required></td>
                </tr>

                <tr>
                    <td></td>
                    <td><input type="submit" value="Iniciar Sesión"></td>
                </tr>

                <tr>
                    <td><label>¿Eres nuevo?</label></td>
                    <td><a href="/Carlist/registrarUsuario">Registrarse</a></td>
                </tr>
            </table>

        </form>

        <div class="footer">
            Copyright ©. 2023 - Juan Garcia Villagran
        </div>
        <script src="/Carlist/javascript/jsUsuarios.js" type="text/javascript"></script>
        <script src="https://kit.fontawesome.com/a076d05399.js"></script>
    </body>
</html>
