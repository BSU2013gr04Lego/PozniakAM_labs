/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java.io.IOException;
import java_lab_3.VM.*;
import java.util.Scanner;

/**
 *
 * @author krucios
 */
public class TInput extends Term {
    public TInput(int pos) {
        super(pos);
    }
    
    @Override
    public void execute(Machine a) throws VMException, IOException {
        Scanner scn = new Scanner(System.in);
        int temp = scn.nextInt();
        a.setCurMem(temp);
    }
}
