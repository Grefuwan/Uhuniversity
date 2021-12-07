/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package Modelo;

/**
 *
 * @author Grefuwan
 */
public class Monitor {
    String codMonitor;
    String nombre;
    String dni;
    String telefono;
    String correo;
    String fechaEntrada;
    String nick;
    
    //Constructor por defecto
    public Monitor(){
        codMonitor      = null;
        nombre          = null;
        dni             = null;
        telefono        = null;
        correo          = null;
        fechaEntrada    = null;
        nick            = null;
    };
    
    //Constructor con parametros
    public Monitor(String codMonitor, String nombre, String dni, String telefono, String correo, String fechaEntrada, String nick){
        this.codMonitor     = codMonitor;
        this.nombre         = nombre;
        this.dni            = dni;
        this.telefono       = telefono;
        this.correo         = correo;
        this.fechaEntrada   = fechaEntrada;
        this.nick           = nick;
    }

    public String getCodMonitor() {
        return codMonitor;
    }

    public String getNombre() {
        return nombre;
    }

    public String getDni() {
        return dni;
    }

    public String getTelefono() {
        return telefono;
    }

    public String getCorreo() {
        return correo;
    }

    public String getFechaEntrada() {
        return fechaEntrada;
    }

    public String getNick() {
        return nick;
    }

    public void setCodMonitor(String codMonitor) {
        this.codMonitor = codMonitor;
    }

    public void setNombre(String nombre) {
        this.nombre = nombre;
    }

    public void setDni(String dni) {
        this.dni = dni;
    }

    public void setTelefono(String telefono) {
        this.telefono = telefono;
    }

    public void setCorreo(String correo) {
        this.correo = correo;
    }

    public void setFechaEntrada(String fechaEntrada) {
        this.fechaEntrada = fechaEntrada;
    }

    public void setNick(String nick) {
        this.nick = nick;
    }
    
    
}
