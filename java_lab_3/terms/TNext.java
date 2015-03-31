/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java_lab_3.terms.Term;
import java_lab_3.VM.*; 

/**
 *
 * @author krucios
 */
public class TNext extends Term {
    public TNext(int pos) {
        super(pos);
    }
    
    @Override 
    public void execute(Machine a) throws VMException {
        a.set_I_M(a.get_I_M() + 1);
    }
}
