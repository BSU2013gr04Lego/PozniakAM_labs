/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.util.logging.Logger;
import java_lab_4.terms.Term;
import java_lab_4.VM.*;
import java_lab_4.VM.VMException;

/**
 * Increasing current memory cell of VM
 * @author krucios
 */
public class TInc extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TInc(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override
    public void execute(Machine a) throws VMException {
        log.finer("**** Increase value");
        a.setCurMem(a.getCurMem() + 1);
    }
}
