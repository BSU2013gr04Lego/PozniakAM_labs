/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4;

/**
 * Common class for all objects/ Perform transcendent comparison
 * @author krucios
 */
public class TEObject {
    /**
     * method for comparing 2 objects
     * @param a TEObject
     * @param b TEObject
     * @return boolean
     */
    public static boolean isEqual(TEObject a, TEObject b) {
        if (a == b)
            return true;
        if (a == null || b == null)
            return false;
        if (a.getClass() == b.getClass())
            return a.isEqual(b);
        return a.isEqual(b) && b.isEqual(a);
    }
    
    /**
     * method for comparing this with other object
     * @param obj TEObject
     * @return always return true
     */
    public boolean isEqual(TEObject obj) {
        return true;
    }
}
