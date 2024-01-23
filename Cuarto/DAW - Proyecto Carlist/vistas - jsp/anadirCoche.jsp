<%@page contentType="text/html" pageEncoding="UTF-8"%>
<!DOCTYPE html>

<html>
    <head>
        <meta http-equiv="Content-Type" content="text/html; charset=utf-8"/>
        <title>Carlist</title>
        <link href="css/estilo.css" rel="stylesheet" type="text/css"/>
        <link href='https://unpkg.com/boxicons@2.1.4/css/boxicons.min.css' rel='stylesheet'>

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

        <!-- Parte de Añadir Coche -->
        <form class ="formularioAnadir" name="nmFormAnadirCoche" id="formAnadirCoche" action="anadirCoche" method="POST" onsubmit="return validar(this);">
            <table>
                <tr>
                    <td><label for="id_marcaCoche"> Marca:</label></td>  
                    <td><select name="marcaCoche" id="id_marcaCoche" onchange="anadirCoche()">
                            <option value="nulo">--Seleccione Marca--</option>
                            <option value="opel">Opel</option>
                            <option value="renault">Renault</option>
                            <option value="citroen">Citroen</option>
                            <option value="mercedes">Mercedes</option>
                        </select></td>
                    <td> <label id="id_msgErrorMarcaCoche"></label> </td>
                </tr>

                <tr>
                    <td> <label for="id_ModeloCoche"> Modelo: </label> </td>
                    <td> <input type="text" id="id_ModeloCoche" name="modeloCoche" required> </td>
                </tr>

                <tr>
                    <td> <label for="id_MatriculaCoche">Matricula: </label> </td>
                    <td> <input type="text" id="id_MatriculaCoche" name="matriculaCoche" placeholder="0000-AAA" pattern="[0-9]{4}-[A-Z]{3}" required> </td>
                </tr>

                <tr>
                    <td>Tipo: </td>
                    <td><select name="tipoCoche" id="id_tipoCoche">
                            <option value="nulo">--Seleccione Modelo--</option>
                            <option value="pequeno">Pequeño</option>
                            <option value="suv">SUV</option>
                            <option value="comercial">Comercial</option>
                            <option value="furgoneta">Furgoneta</option>
                            <option value="lujo">Lujo</option>
                        </select> </td>
                </tr>

                <tr>
                    <td><label for="id_KilometrosCoche">Kilometros: </label></td>
                    <td><input type="number" id="id_KilometrosCoche" name="kilometrosCoche" min="0" pattern="[0-9]"></td>
                </tr>

                <tr>
                    <td>Combustible: </td>
                    <td>
                        <input type="radio" id="id_combustibleGasoil" name="n_Combustible" value="Gasoil">
                        <label for="id_combustibleGasoil">Gasoil</label>
                        <input type="radio" id="id_combustibleGasolina" name="n_Combustible" value="Gasolina">
                        <label for="id_combustibleGasolina">Gasolina</label>
                        <input type="radio" id="id_combustibleHibrido" name="n_Combustible" value="Hibrido">
                        <label for="id_combustibleHibrido">Híbrido</label>
                        <input type="radio" id="id_combustibleElectrico" name="n_Combustible" value="Electrico">
                        <label for="id_combustibleElectrico">Eléctrico</label>
                    </td>
                </tr>

                <tr>
                    <td></td>
                    <td><input type="submit" value="Guardar coche"></td>
                </tr>

            </table>
        </form>


        <div class="footer">
            Copyright ©. 2023/24 - Juan Garcia Villagran
        </div>
        
        <script src="/Carlist/javascript/jsAnadirCoche.js" type="text/javascript"></script>
        <script src="https://kit.fontawesome.com/a076d05399.js"></script>
    </body>
</html>
