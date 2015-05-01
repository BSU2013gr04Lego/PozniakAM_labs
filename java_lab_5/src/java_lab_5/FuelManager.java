/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_5;

/**
 *
 * @author krucios
 */
public class FuelManager {
    private volatile int _fuel_count;
    private static int DEFAULT_FUEL_COUNT = 1000000;
    
    public FuelManager() {
        _fuel_count = DEFAULT_FUEL_COUNT;
    }
    
    public FuelManager(int fuel_count) {
        _fuel_count = fuel_count;
    }
    
    public int getFuel() {
        _fuel_count--;
        return 1;
    }
    
    public boolean isEmpty() {
        return this._fuel_count == 0;
    }
}
