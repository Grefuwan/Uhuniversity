package pcd_practica5;

/**
 *
 * @author Grefuwan
 */
public class Tunel {

    char lateralIzq = 'L';
    char centro = 'L'; //L - Libre || C - Coche || F - Furgo
    char lateralDcha = 'L';
    
    private MiCanvas cv;
    
    public Tunel(MiCanvas cv) {
        this.cv = cv;
    }

    /**
     *
     * @return Devuelve la posición donde ha entrado el coche
     *
     * @throws InterruptedException
     */
    public synchronized char entraCoche(int id) throws InterruptedException {
        while (lateralIzq != 'L' && centro != 'L' && lateralDcha != 'L') {
            wait();
        }

        if (centro == 'L') {
            centro = 'C';
            cv.insertaCoche(id, centro);
            return 'C';
        }
        else if (lateralIzq == 'L') {
            lateralIzq = 'C';
            cv.insertaCoche(id, lateralIzq);
            return 'I';
        }
        else {
            lateralDcha = 'C';
            cv.insertaCoche(id, lateralDcha);
            return 'D';
        }

    }

    /**
     *
     * @param donde
     */
    public synchronized void saleCoche(char donde) {
        switch (donde) {
            case 'I' ->
                lateralIzq = 'L';
            case 'D' ->
                lateralDcha = 'L';
            default ->
                centro = 'L';
        }

        notifyAll();
    }

    /**
     *
     * @return @throws InterruptedException
     */
    public synchronized char entraFurgo(int id) throws InterruptedException {
        while (centro != 'L' && lateralIzq != 'L' && lateralDcha != 'L') {
            wait();
        }

        if (centro == 'L') { //Si el centro está Libre
            if (lateralIzq == 'L') {        //Si el lateralIzq está Libre
                lateralIzq = 'F';               //lateralIzq <- Furgo
                cv.insertaFurgo(id, lateralIzq);
                return 'I';
            }
            else if (lateralDcha == 'L') {  //Si el lateralDcha está libre
                lateralDcha = 'F';              //lateralDcha <- Furgo
                cv.insertaFurgo(id, lateralDcha);
                return 'D';
            }
            else if (centro == 'L' && (lateralIzq != 'F' || lateralDcha != 'F')) {  //Si el centro está Libre y los laterales NO son Furgo
                centro = 'F';                                                           //Centro <- Furgo
                cv.insertaFurgo(id, centro);
                return 'C';
            }
        }
        return 0;
    }

    public synchronized void saleFurgo(char donde) {
        switch (donde) {
            case 'I' ->
                lateralIzq = 'L';
            case 'D' ->
                lateralDcha = 'L';
            default ->
                centro = 'L';
        }

        notifyAll();
    }

    @Override
    public String toString() {

        return "Tunel actual: [" + this.lateralDcha + "] -- [" + this.centro + "] -- [" + this.lateralIzq + "]";
    }

}

