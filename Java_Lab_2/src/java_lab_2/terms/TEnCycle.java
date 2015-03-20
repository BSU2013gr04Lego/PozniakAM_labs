/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_2.terms;

import java.util.ArrayList;
import java_lab_2.VM.Machine;
import java_lab_2.VM.VMException;

/**
 *
 * @author krucios
 */
public class TEnCycle extends Term {
    public TEnCycle(int pos) {
        super(pos);
    }
    
    @Override
    public void execute(Machine a) throws VMException {
        if (a.getCurMem() != 0) {
            ArrayList<Term> prog = a.getProgram();
            int balance = 0;
            for (int i = this.getPos(); i >= 0; --i) {
                if (prog.get(i).getClass().getName() == "java_lab_2.terms.TStCycle") {
                    balance++;
                } else if (prog.get(i).getClass().getName() == "java_lab_2.terms.TEnCycle") {
                    balance--;
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
