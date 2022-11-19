package Algoritmos;

import AMC_Practica_1.Punto;
import static Algoritmos.Distancias.distancia3;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class Alg_Dijkstra {

    public int numDistancias;
    public int distancia[];     //Vector para almacenar las distancias
    public int costo[][];       //Matriz cuadrada
    public Punto nodos[];         //Matriz para almacenar todos los nodos

    public Alg_Dijkstra(int numDistancias) {    //numDistancias será el numero de nodos del fichero
        this.numDistancias = numDistancias;
        this.distancia = new int[numDistancias];
        this.costo = new int[numDistancias][numDistancias];
    }

    public void creaMatricesDijkstra(ArrayList<Punto> arrPuntos) {
        ArrayList<Integer> arrDistancias = new ArrayList();
        this.nodos = new Punto[arrPuntos.size()];

        //Añado todas las distancias a distancia[]
        for (int i = 0; i < arrPuntos.size(); i++) {
            for (int j = 0; j < arrPuntos.size(); j++) {
                for (int k = 0; k < arrPuntos.size(); k++) {
                    arrDistancias.add(i, (int) distancia3(arrPuntos.get(i), arrPuntos.get(j), arrPuntos.get(k)));
                }
            }
        }

        for (int i = 0; i < arrDistancias.size(); i++) {
            distancia[i] = arrDistancias.get(i);
        }

        //Añado todos los nodos ordenados de izq a dcha por el eje X
        //QuickSort de los nodos por la coord X-------------------------------------------
        for (int i = 0; i < arrPuntos.size(); i++) {
            nodos[i] = arrPuntos.get(i);
        }

    }

    //Método que calcula la distancia más corta
    public void calc(int n, int origen) {
        int flag[] = new int[n + 1];
        int i, k, c, minimo;
        int minpos = 1;

        for (i = 1; i <= n; i++) {
            flag[i] = 0;
            this.distancia[i] = this.costo[origen][i];
        }

        c = 2;
        while (c <= n) {
            minimo = 99;
            for (k = 1; k <= n; k++) {
                if (this.distancia[k] < minimo && flag[k] != 1) {
                    minimo = this.distancia[i];
                    minpos = k;
                }
            }

            flag[minpos] = 1;
            c++;

            for (k = 1; k <= n; k++) {
                if (this.distancia[minpos] + this.costo[minpos][k] < this.distancia[k] && flag[k] != 1) {
                    this.distancia[k] = this.distancia[minpos] + this.costo[minpos][k];
                }
            }
        }
    }

}

