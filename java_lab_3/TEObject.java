/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3;

/**
 *
 * @author krucios
 */
public class TEObject {
    public static boolean isEqual(TEObject a, TEObject b) {
        if (a == b)
            return true;
        if (a == null || b == null)
            return false;
        if (a.getClass() == b.getClass())
            return a.isEqual(b);
        return a.isEqual(b) && b.isEqual(a);
    }
    
    public boolean isEqual(TEObject obj) {
        return true;
    }
}
