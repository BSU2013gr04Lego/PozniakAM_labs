/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_5;

import java.util.ArrayList;
import java.util.Scanner;

/**
 *
 * @author krucios
 */
public class Main {
    private final FuelManager _fm;
    private boolean _start_flag;
    private ArrayList<SpaceShip> _ships;
    
    public Main() {
        this._start_flag = false;
        this._fm = new FuelManager();
        this._ships = new ArrayList<>();
    }
    
    private void initializeThreads(int count) {
        for (int i = 0; i < count; ++i) {
            _ships.add(new SpaceShip("PlanetExpress_" + i));
            _ships.get(i).setFuelManager(_fm);
            _ships.get(i).start();
        }
    }
    
    public Main(int fuel_count) {
        this._start_flag = false;
        _fm = new FuelManager(fuel_count);
    }
    
    public void run() {
        Scanner sc = new Scanner(System.in); 
        System.out.println("Please, enter SpaceShip count: ");
        int count = sc.nextInt();
        this.initializeThreads(count);
        this._start_flag = true;
        System.out.println("End of race");
    }
}
