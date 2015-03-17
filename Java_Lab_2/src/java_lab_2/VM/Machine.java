/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_2.VM;

import java.io.IOException;
import java_lab_2.VM.*;
import java_lab_2.terms.*;
import java.util.ArrayList;

/**
 *
 * @author krucios
 */
public class Machine {
    public static int mem_size = 30000;
    
    private int[] memory;
    private int I_M;
    
    private ArrayList<Term> program;
    private int I_P;
    
    public Machine() {
        memory = new int[mem_size];
        program = new ArrayList<Term>();
        I_M = 0;
    }
    
    public void execute() throws VMException, IOException {
        for (Term i : this.program) {
            i.execute(this);
        }
    }
    
    // ===== Memory Control
    public void set_I_M(int I_M) throws VMException {
        if (I_M < 0 || mem_size < I_M)
            throw new VMException("Range error");
        
        this.I_M = I_M;
    }
    
    public int get_I_M() {
        return I_M;
    }
    
    public void setCurMem(int val) throws VMException {
        if (val < 0 || 255 < val)
            throw new VMException("Incorrect value. Value must be in range [0 .. 255]");
        
        memory[I_M] = val;
    }
    
    public int getCurMem() {
        return memory[I_M];
    }
    
    // ==== Program Control
    public void setCurTerm(Term term) {
        program.set(I_P, term);
    }
    
    public Term getCurTerm() {
        return program.get(I_P);
    }
    
    public void set_I_P(int I_P) throws VMException {
        if (I_P < 0 || program.size() < I_P)
            throw new VMException("Index out of avaliable range");
        
        this.I_P = I_P;
    }
    
    public int get_I_P() {
        return I_P;
    }
    
    public void downloadProgram(String program) throws VMException {
        for(int i = 0; i < program.length(); ++i) {
            switch(program.charAt(i)) {
                case '>':
                    this.program.add(new TNext());
                    break;
                case '<':
                    this.program.add(new TPrev());
                    break;
                case '+':
                    this.program.add(new TInc());
                    break;
                case '-':
                    this.program.add(new TDec());
                    break;
                case '.':
                    this.program.add(new TPrint());
                    break;
                case ',':
                    this.program.add(new TInput());
                    break;
                case '[':
                    break;
                case ']':
                    break;
                default:
                    throw new VMException("Unknown symbol " + program.charAt(i));
            }
        }
    }
}
