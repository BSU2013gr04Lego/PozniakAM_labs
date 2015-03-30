/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3.terms;

import java.io.IOException;
import java_lab_3.utils.Serializer;
import java_lab_3.VM.*;

/**
 *
 * @author krucios
 */
public abstract class Term {
    private int pos;
    
    public Term(int position) {
        this.pos = position;
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
