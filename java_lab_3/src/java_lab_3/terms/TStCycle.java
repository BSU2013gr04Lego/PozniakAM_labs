/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java_lab_3.VM.*;
import java.util.ArrayList;

/**
 *
 * @author krucios
 */
public class TStCycle extends Term {
    public TStCycle(int pos) {
        super(pos);
    }
    
    @Override
    public void execute(Machine a) throws VMException {
        if (a.getCurMem() == 0) {
            ArrayList<Term> prog = a.getProgram();
            int balance = 0;
            for (int i = this.getPos(); i < prog.size(); ++i) {
                if (prog.get(i).getClass().getName() == "java_lab_3.terms.TStCycle") {
                    balance++;
                } else if (prog.get(i).getClass().getName() == "java_lab_3.terms.TEnCycle") {
                    balance--;
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
