/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java_lab_3.VM.*;
import java_lab_3.VM.VMException;

/**
 *
 * @author krucios
 */
public class TDec extends Term {
    public TDec(int pos) {
        super(pos);
    }
    
    @Override
    public void execute(Machine a) throws VMException {
        a.setCurMem(a.getCurMem() - 1);
    }
}
