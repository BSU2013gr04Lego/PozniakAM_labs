/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.util.logging.Logger;
import java_lab_4.VM.*; 

/**
 * Move memory position right for 1 cell
 * @author krucios
 */
public class TNext extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TNext(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override 
    public void execute(Machine a) throws VMException {
        log.finer("**** Next memory cell");
        assert a != null;
        a.set_I_M(a.get_I_M() + 1);
    }
}
