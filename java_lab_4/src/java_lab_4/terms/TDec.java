/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.util.logging.Logger;
import java_lab_4.VM.*;
import java_lab_4.VM.VMException;

/**
 * decrease current memory cell of VM
 * @author krucios
 */
public class TDec extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TDec(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override
    public void execute(Machine a) throws VMException {
        log.finer("**** Decrease value");
        assert a != null;
        a.setCurMem(a.getCurMem() - 1);
    }
}
