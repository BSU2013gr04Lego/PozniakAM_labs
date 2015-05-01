/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.VM;

/**
 * Common exception for all VM errors
 * @author krucios
 */
public class VMException extends Exception {
    /**
     * constructor
     * @param message description of exception 
     */
    public VMException(String message) {
        super(message);
    }
}
