/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.util.logging.Logger;
import java_lab_4.VM.*;

/**
 * Print current value of current memory cell
 * @author krucios
 */
public class TPrint extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TPrint(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override
    public void execute(Machine a) throws VMException {
        log.finer("**** Print actual value");
        assert a != null;
        char c = (char) a.getCurMem();
        System.out.print(c + " ");
    }
}
