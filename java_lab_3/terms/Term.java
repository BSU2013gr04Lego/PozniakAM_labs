/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java.io.IOException;
import java_lab_3.utils.Serializer;
import java_lab_3.VM.*;

import java_lab_3.TEObject;

/**
 *
 * @author krucios
 */
public abstract class Term extends TEObject {
    private int pos;
    
    public Term(int position) {
        this.pos = position;
    }
    
    @Override
    public boolean isEqual(TEObject obj) {
        Term that = (Term) obj;
        if (that == null)
            return false;
        return super.isEqual(that) && (this.pos == that.pos);
    }
    
    public int getPos() {
        return pos;
    }
    
    /* SERIALIZATION */
    public byte[] serialize() {
        return Serializer.serializeInt(pos);
    }
    
    public abstract void execute(Machine a) throws VMException, IOException;
}
