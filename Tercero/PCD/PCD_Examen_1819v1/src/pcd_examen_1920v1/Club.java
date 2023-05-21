/*
 * Click nbfs://nbhost/SystemFileSystem/Templates/Licenses/license-default.txt to change this license
 * Click nbfs://nbhost/SystemFileSystem/Templates/Classes/Class.java to edit this template
 */
package pcd_examen_1920v1;

import java.util.Random;


/**
 *
 * @author Grefuwan
 */
public class Club implements Runnable {

    private final int id;
    private final Piscina p;

    Random r = new Random();

    public Club(Piscina p, int id) {
        this.id = id;
        this.p = p;
    }

    @Override
    public void run() {
        try {
            r.setSeed(System.currentTimeMillis());

            System.out.println("Club: " + id);
            p.EntraClub();

            Thread.sleep((r.nextInt(4) + 3) * 1000);

            System.out.println("Sale Club: " + id);
            p.SaleClub();
        } catch (InterruptedException ex) {
        }

    }

}

