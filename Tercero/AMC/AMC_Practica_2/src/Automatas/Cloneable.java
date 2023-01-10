/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Interface.java to edit this template
 */
package Automatas;

/**
 *
 * @author Juan Garcia Villagran
 */
public interface Cloneable {

    /**
     * Determina si un estado es final o no
     * @param estado Estado a comprobar
     * @return Devuelve si es final o no
     */
    public abstract boolean esFinal(String estado); //true si estado es un estado final

    /**
     * Determina si una cadena es reconocida o no
     * @param cadena Cadena de transiciones a comprobar
     * @return  Devuelve si la cadena es correcta o no
     */
    public abstract boolean reconocer(String[] cadena); //true si la cadena es reconocida

    /**
     * Muestra las transiciones y los estados finales
     * @return Devuelve la impresion del objeto
     */
    @Override
    public abstract String toString(); //muestra las transiciones y estados finales

}

