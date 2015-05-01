/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java_lab_4.VM.*;
import java.util.ArrayList;
import java.util.logging.Logger;

/**
 * Start cycle term
 * @author krucios
 */
public class TStCycle extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TStCycle(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override
    public void execute(Machine a) throws VMException {
        log.finer("**** Start cycle");
        assert a != null;
        if (a.getCurMem() == 0) {
            ArrayList<Term> prog = a.getProgram();
            int balance = 0;
            for (int i = this.getPos(); i < prog.size(); ++i) {
                if (null != prog.get(i).getClass().getName()) switch (prog.get(i).getClass().getName()) {
                    case "java_lab_4.terms.TStCycle":
                        balance++;
                        break;
                    case "java_lab_4.terms.TEnCycle":
                        balance--;
                        break;
                }

                if (balance == 0) {
                    a.set_I_P(i);
                    break;
                }
            }
            assert(balance == 0);
        }
    }
}
