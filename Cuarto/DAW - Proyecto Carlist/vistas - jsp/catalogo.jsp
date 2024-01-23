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

        <form class="class_TablaCatalogo-Filtro" name="filtroForm" id="id_filtroForm" action="catalogo" method="POST">
            <label>Marca:</label>
            <select id="id_filtroMarcas" name="filtroMarca">
                <option value="all">Todas</option>
                <option value="opel">Opel</option>
                <option value="renault">Renault</option>
                <option value="citroen">Citroen</option>
                <option value="mercedes">Mercedes</option>
            </select>
            <input id="id_botonFiltrar" url="<%= request.getContextPath()%>" type="button" value="Filtrar" onclick="peticionAJAX()">

            <div id="id_tablaCatalogo">

            </div>
        </form>

        <div class="footer">
            Copyright ©. 2023 - Juan Garcia Villagran
        </div>

        <script>
            function peticionAJAX() {
                let marcaSeleccionada = document.getElementById("id_filtroMarcas").value;
                console.log(marcaSeleccionada);

                if (window.XMLHttpRequest) { // Navegadores actuales
                    xhr = new XMLHttpRequest();
                } else if (window.ActiveXObject) { // Antiguas versiones Internet Explorer
                    xhr = new ActiveXObject("Microsoft.XMLHTTP");
                }
                if (xhr === null) {
                    alert("Tu navegador no sirve ni pa estar escondío (no soporta AJAX)");
                    return false;
                } else {
                    var url = "/Carlist/svCatalogoCochesSQL?marca=" + marcaSeleccionada;
                    xhr.onreadystatechange;
                    xhr.open("GET", url, true);// Se define la petición (método y URL)
                    xhr.onload = () => {
                        if (xhr.readyState === xhr.DONE) {
                            if (xhr.status === 200) {
                                document.getElementById("id_tablaCatalogo").innerHTML = xhr.responseText;
                            }
                        }
                    };
                    xhr.send(null);// Se envía el cuerpo
                }
            }
        </script>
    </body>
</html>

