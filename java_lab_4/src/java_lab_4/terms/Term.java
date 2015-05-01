/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

package java_lab_4.terms;

import java.io.IOException;
import java.util.logging.Logger;
import java_lab_4.utils.Serializer;
import java_lab_4.VM.*;

import java_lab_4.TEObject;

/**
 * Common class for all terms
 * @author krucios
 */
public abstract class Term extends TEObject {
    private final Logger log = Logger.getLogger("MainLogger");
    private int pos;
   
    /**
    * constructor
    * @param position  position of term in program
    */ 
    public Term(int position) {
        assert pos >= 0; // position can not be negative
        log.finer("Creating new term on position " + position);
        this.pos = position;
    }
    
    /**
     * method for comparing this with other TEObject
     * @param obj any derived object from TEObject
     * @return boolean. True if obj equal with this
     */
    @Override
    public boolean isEqual(TEObject obj) {
        Term that = (Term) obj;
        if (that == null) 
            return false;
        return super.isEqual(that) && (this.pos == that.pos);
    }
    
    /**
     * get position of term in program
     * @return int position of term in program
     */
    public int getPos() {
        assert pos >= 0;
        return pos;
    }
    
    /* ====== SERIALIZATION ====== */
    
    /**
     * serialize term
     * @return byte[] serialized object
     */
    public byte[] serialize() {
        log.finer("Serialize term");
        return Serializer.serializeInt(pos);
    }
    
    /**
     * abstract method for performing term actions
     * @param a VM on which should be executed this term
     * @throws VMException 
     * @throws IOException 
     */
    public abstract void execute(Machine a) throws VMException, IOException;
}
