// Se crea la instancia XMLHttpRequest
var xhr;

function peticionAJAX(url) {
    if (window.XMLHttpRequest) { // Navegadores actuales
        xhr = new XMLHttpRequest();
    } else if (window.ActiveXObject) { // Antiguas versiones Internet Explorer
        xhr = new ActiveXObject("Microsoft.XMLHTTP");
    }
    if (xhr === null) {
        alert("Tu navegador no sirve ni pa estar escondío (no soporta AJAX)");
        return false;
    } else {

        //var url = "/Carlist/catalogo";

        xhr.onreadystatechange = filtrarCatalogo(xhr);

        xhr.open("GET", url, true);// Se define la petición (método y URL)

        xhr.send(null);// Se envía el cuerpo
    }
}

function filtrarCatalogo(xhr) {
    if (xhr.readyState === 4) {
        if (xhr.status === 200) {
            document.getElemenyById("id_tablaCatalogo").innerHTML = xhr.responseText;
        } else {
            alert("ERROR - Peticion Ajax");
            console.log("Error en Peticion AJAX. Estado: " + xhr.status + ". Mensaje: " + xhr.statusText);
        }
    }
}