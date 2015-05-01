/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.VM;

import java.util.ArrayList;
import java_lab_4.terms.Term;
import java_lab_4.terms.TInc;
import org.junit.After;
import org.junit.AfterClass;
import org.junit.Before;
import org.junit.BeforeClass;
import org.junit.Test;
import static org.junit.Assert.*;

/**
 *
 * @author krucios
 */
public class MachineTest {
    
    public MachineTest() {
    }

    /**
     * Test of execute method, of class Machine.
     * @throws java.lang.Exception
     */
    @Test
    public void testExecute() throws Exception {
        System.out.println("execute");
        Machine instance = new Machine();
        instance.downloadProgram("+++[-]");
        instance.execute();
    }

    /**
     * Test of saveToFile method, of class Machine.
     * @throws java.lang.Exception
     */
    @Test
    public void testSaveToFile() throws Exception {
        System.out.println("saveToFile");
        String file_name = "test_save.bfvm";
        Machine instance = new Machine();
        instance.saveToFile(file_name);
    }

    /**
     * Test of set_I_M method, of class Machine.
     */
    @Test
    public void testSet_I_M() {
        System.out.println("set_I_M");
        int I_M = 152;
        Machine instance = new Machine();
        instance.set_I_M(I_M);
    }

    /**
     * Test of get_I_M method, of class Machine.
     */
    @Test
    public void testGet_I_M() {
        System.out.println("get_I_M");
        Machine instance = new Machine();
        int expResult = 0;
        int result = instance.get_I_M();
        assertEquals(expResult, result);
        
        expResult = 42;
        instance.set_I_M(expResult);
        result = instance.get_I_M();
        assertEquals(expResult, result);
    }

    /**
     * Test of setCurMem method, of class Machine.
     */
    @Test
    public void testSetCurMem() {
        System.out.println("setCurMem");
        int val = 152;
        Machine instance = new Machine();
        instance.setCurMem(val);
        int result = instance.getCurMem();
        assertEquals(val, result);
    }

    /**
     * Test of getCurMem method, of class Machine.
     */
    @Test
    public void testGetCurMem() {
        System.out.println("getCurMem");
        Machine instance = new Machine();
        int expResult = 0;
        int result = instance.getCurMem();
        assertEquals(expResult, result);
        
        expResult = 12;
        instance.setCurMem(expResult);
        result = instance.getCurMem();
        assertEquals(expResult, result);
        
        expResult = 200;
        instance.setCurMem(expResult);
        result = instance.getCurMem();
        assertEquals(expResult, result);
        
    }

    /**
     * Test of setCurTerm method, of class Machine.
     * @throws java_lab_4.VM.VMException
     */
    @Test
    public void testSetCurTerm() throws VMException {
        System.out.println("setCurTerm");
        Machine instance = new Machine();
        
        Term term = new TInc(0);
        instance.downloadProgram("+"); // It needed for setCurTerm
        instance.setCurTerm(term);
    }

    /**
     * Test of getCurTerm method, of class Machine.
     * @throws java_lab_4.VM.VMException
     */
    @Test
    public void testGetCurTerm() throws VMException {
        System.out.println("getCurTerm");
        Machine instance = new Machine();
        Term expResult = null;
        Term result = instance.getCurTerm();
        assertEquals(expResult, result);
        
        expResult = new TInc(0);
        instance.downloadProgram("+");
        instance.setCurTerm(expResult);
        result = instance.getCurTerm();
        assertEquals(expResult, result);
    }

    /**
     * Test of set_I_P method, of class Machine.
     * @throws java.lang.Exception
     */
    @Test
    public void testSet_I_P() throws Exception {
        System.out.println("set_I_P");
        int I_P = 0;
        Machine instance = new Machine();
        instance.set_I_P(I_P);
        
        I_P = 3;
        instance.downloadProgram("++++"); // it needed for set_I_P
        instance.set_I_P(I_P);
        int result = instance.get_I_P();
        assertEquals(I_P, result);
    }

    /**
     * Test of get_I_P method, of class Machine.
     * @throws java_lab_4.VM.VMException
     */
    @Test
    public void testGet_I_P() throws VMException {
        System.out.println("get_I_P");
        Machine instance = new Machine();
        int expResult = 7;
        instance.downloadProgram("++++++++"); // It needed for set_I_P
        instance.set_I_P(expResult);
        int result = instance.get_I_P();
        assertEquals(expResult, result);
    }

    /**
     * Test of getProgram method, of class Machine.
     */
    @Test
    public void testGetProgram() {
        System.out.println("getProgram");
        Machine instance = new Machine();
        ArrayList<Term> expResult = new ArrayList<Term>();
        ArrayList<Term> result = instance.getProgram();
        assertEquals(expResult, result);
    }

    /**
     * Test of downloadProgram method, of class Machine.
     * @throws java.lang.Exception
     */
    @Test
    public void testDownloadProgram() throws Exception {
        System.out.println("downloadProgram");
        String program = "+..--";
        Machine instance = new Machine();
        instance.downloadProgram(program);
    }  
}
