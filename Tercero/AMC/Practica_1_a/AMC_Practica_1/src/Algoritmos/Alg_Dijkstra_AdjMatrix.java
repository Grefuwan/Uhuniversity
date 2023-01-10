package Algoritmos;

import AMC_Practica_1.Punto;
import java.util.*;

/**
 *
 * @author Grefuwan
 */
public final class Alg_Dijkstra_AdjMatrix {

    int num_Vertices; // = arrPuntos.size();

    private int[][] grafo;
    String retorno = "";

    public Alg_Dijkstra_AdjMatrix(ArrayList<Punto> arrPuntos, int source) {
        setNumVertices(arrPuntos);
        convierteArrListAArray(arrPuntos);
        
        alg_Dijkstra(grafo, source, arrPuntos);
    }

    public void setNumVertices(ArrayList<Punto> arrPuntos) {
        this.num_Vertices = arrPuntos.size();
        System.out.println("numVertices = " + num_Vertices);
    }

    //Encuentra el vértice con menor distancia
    private int minDistancia(int path_array[], Boolean sptSet[]) {
        int min = Integer.MAX_VALUE, min_index = -1;
        for (int v = 0; v < this.num_Vertices; v++) {
            if (sptSet[v] == false && path_array[v] <= min) {
                min = path_array[v];
                min_index = v;
            }
        }
        return min_index;
    }
    
    public String retornaString(){
        return retorno;
    }

    public void alg_Dijkstra(int graph[][], int src_node, ArrayList<Punto> arrPuntos) {
        
        setNumVertices(arrPuntos);
        int path_array[] = new int[arrPuntos.size()];   //Array Salida - Distancia más corta de src_node al nodo i
        convierteArrListAArray(arrPuntos);
        Boolean sptSet[] = new Boolean[arrPuntos.size()];   //SPT (Shortest Path Set) contiene los vertices que son más cortos

        for (int i = 0; i < arrPuntos.size(); i++) {
            path_array[i] = Integer.MAX_VALUE;
            sptSet[i] = false;
        }

        path_array[src_node] = 0;   //Distancia de un nodo a él mismo siempre es 0

        for (int count = 0; count < this.num_Vertices - 1; count++) {
            int u = minDistancia(path_array, sptSet);
            sptSet[u] = true;

            for (int v = 0; v < this.num_Vertices; v++) {
                if (!sptSet[v] && graph[u][v] != 0 && path_array[u] != Integer.MAX_VALUE && path_array[u] + graph[u][v] < path_array[v]) {
                    path_array[v] = path_array[u] + graph[u][v];
                }
            }
        }
        
        retorno = "<html><body>Vertex# \t Minimum Distance from Source: " + src_node;
        for (int i = 0; i < this.num_Vertices; i++) {
           retorno += "<br>" + i + " \t\t\t " + path_array[i];
        }
        
    }

    private void convierteArrListAArray(ArrayList<Punto> arrPuntos) {
        //Limpio grafo antes
        this.grafo = new int[arrPuntos.size()][arrPuntos.size()];
        for (int i = 0; i < arrPuntos.size(); i++) {
            for (int j = 0; j < arrPuntos.size(); j++) {
                this.grafo[i][j] = 0;
            }
        }
        
        for (int i = 0; i < arrPuntos.size(); i++) {
            for (int j = 0; j < arrPuntos.size(); j++) {
                if (i == j) {
                    this.grafo[i][j] = 0;
                }
                else {
                    this.grafo[i][j] = (int) Algoritmos.Distancias.distancia2(arrPuntos.get(i), arrPuntos.get(j));
                }
            }
        }
    }

}

