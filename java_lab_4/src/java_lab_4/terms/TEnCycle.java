/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.util.ArrayList;
import java.util.logging.Logger;
import java_lab_4.VM.Machine;
import java_lab_4.VM.VMException;

/**
 * End of cycle term
 * @author krucios
 */
public class TEnCycle extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TEnCycle(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     */
    @Override
    public void execute(Machine a) throws VMException {
        log.finer("**** End of cycle");
        assert a != null;
        if (a.getCurMem() != 0) {
            ArrayList<Term> prog = a.getProgram();
            int balance = 0;
            for (int i = this.getPos(); i >= 0; --i) {
                switch (prog.get(i).getClass().getName()) {
                    case "java_lab_4.terms.TStCycle":
                        balance++;
                        break;
                    case "java_lab_4.terms.TEnCycle":
                        balance--;
                        break;
                }

                if (balance == 0) {
                    a.set_I_P(i - 1);
                    break;
                }
            }
            assert(balance == 0);
        }
    }
}
