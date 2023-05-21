package Algoritmos;

import AMC_Practica_1.Punto;
import AMC_Practica_1.Triangulo;
import java.util.ArrayList;

/**
 *
 * @author Grefuwan
 */
public class Alg_DyV {

    private static Triangulo tMinimo;
    public static ArrayList<Punto> solucion = new ArrayList();
    private static Triangulo tIzq, tDcha, tMin;

    public static Triangulo minDistanTresPuntosDyV(ArrayList<Punto> arrPuntos) {
        arrPuntos = Distancias.quicksort(arrPuntos);
        Triangulo result = minDistanTresPuntosDyVRecurs(arrPuntos, 0, arrPuntos.size() - 1);
        return result;
    }

    public static Triangulo minDistanTresPuntosDyVRecurs(ArrayList<Punto> arrPuntos, int izq, int dcha) {

        if (dcha - izq + 1 <= 6) {
            return new Triangulo(arrPuntos.get(0), arrPuntos.get(1), arrPuntos.get(2));
        }
        else {
            int m = (izq + dcha) / 2;
            System.out.println("m: " + m);

            tIzq = minDistanTresPuntosDyVRecurs(arrPuntos, izq, m);
            tDcha = minDistanTresPuntosDyVRecurs(arrPuntos, m + 1, dcha);
            tMin = tDcha;

            if (tIzq.sumaLadoMenores() <= tDcha.sumaLadoMenores()) {
                tMin = tIzq;
            }

            int x = 0;
            for (x = m + 1; x <= dcha; x++) {
                if (arrPuntos.get(x).getX() - arrPuntos.get(m).getX() > tMin.sumaLadoMenores()) {
                    break;
                }
            }

            int y = 0;
            for (y = m; y >= izq; y--) {
                if (arrPuntos.get(m + 1).getX() - arrPuntos.get(y).getX() > tMin.sumaLadoMenores()) {
                    break;
                }
            }

            Triangulo aux = null;
            for (int si = y + 1; si <= m; si++) {
                for (int sj = m + 1; sj <= x - 1; sj++) {
                    for (int sk = sj + 1; sk <= x - 1; sk++) {
                        aux = new Triangulo(arrPuntos.get(si), arrPuntos.get(sj), arrPuntos.get(sk));
                        if (aux.sumaLadoMenores() <= tMin.sumaLadoMenores()) {
                            tMin = aux;
                        }
                    }
                }
            }

            for (int sii = m + 1; sii <= x - 1; sii++) {
                for (int sjj = y + 1; sjj <= m; sjj++) {
                    for (int skk = sjj + 1; skk <= m; skk++) {
                        aux = new Triangulo(arrPuntos.get(sii), arrPuntos.get(sjj), arrPuntos.get(skk));
                        if (aux.sumaLadoMenores() <= tMin.sumaLadoMenores()) {
                            tMin = aux;
                        }
                    }
                }
            }
            tMinimo = tMin;

        }
        return tMinimo;

    }

    public static ArrayList<Punto> convierteTrianguloArray() {
        solucion.add(0, tMinimo.getA());
        solucion.add(1, tMinimo.getB());
        solucion.add(2, tMinimo.getC());

        return solucion;
    }

}

