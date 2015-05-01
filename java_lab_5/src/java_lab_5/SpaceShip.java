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
public class SpaceShip extends Thread {
    private FuelManager _fm;
    private int _distance;
    private boolean _isRun; 
    private boolean _terminateFlag;
    private String _name;

    public SpaceShip(String name) {
        this._terminateFlag = false;
        this._distance = 0;
        this._isRun = false;
        this._fm = null;
        this._name = name;
    }
    
    /**
     * Main thread method
     */
    @Override
    public void run() {
        this._isRun = true;
        while (!this._fm.isEmpty()) {
            this._distance += this._fm.getFuel();
        }
        this._isRun = false;
        while (!this._terminateFlag) {
        }
    }
    
    public void setFuelManager(FuelManager fm) {
        _fm = fm;
    }
    
    public void terminate() {
        this._terminateFlag = true;
    }
    
    public boolean isRun() {
        return this._isRun;
    }
}
