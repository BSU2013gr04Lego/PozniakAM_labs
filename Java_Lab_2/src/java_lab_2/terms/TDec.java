/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_2.terms;

import java_lab_2.VM.*;
import java_lab_2.VM.VMException;

/**
 *
 * @author krucios
 */
public class TDec implements Term {
    @Override
    public void execute(Machine a) throws VMException {
        a.setCurMem(a.getCurMem() - 1);
    }
}
