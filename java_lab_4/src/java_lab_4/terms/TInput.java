/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.terms;

import java.io.IOException;
import java_lab_4.VM.*;
import java.util.Scanner;
import java.util.logging.Logger;

/**
 * Input and save value to current memory cell
 * @author krucios
 */
public class TInput extends Term {
    private final Logger log = Logger.getLogger("MainLogger");
    
    public TInput(int pos) {
        super(pos);
    }
    
    /**
     * method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException
     * @throws IOException 
     */
    @Override
    public void execute(Machine a) throws VMException, IOException {
        log.finer("**** Input value");
        Scanner scn = new Scanner(System.in);
        assert a != null && scn != null;
        int temp = scn.nextInt();
        a.setCurMem(temp);
    }
}
