function anadirCoche() {
    var marca = document.getElementById('id_marcaCoche').value;
    var msgErrorElemento = document.getElementById('id_msgErrorMarcaCoche');
    
    if (marca === 'nulo') {
        msgErrorElemento.textContent='Error: Seleccione una marca válida';
    } else {
        msgErrorElemento.textContent='';
    }
}