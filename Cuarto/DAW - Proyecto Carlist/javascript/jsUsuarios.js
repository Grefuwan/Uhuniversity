function comprobarRegistroBD() {
    var ok = false;
    
    var msg = 'ERROR: ';
    
    var user = document.getElemenyById("id_regUsuario");
    var pswrd = document.getElemenyById("id_regContrasena");
    
    if (user==='' | pswrd ===''){
        msg = msg + 'Todos los campos son obligatorios';
    }
    
    if (!ok)
        alert(msg);
    
    return ok;
}