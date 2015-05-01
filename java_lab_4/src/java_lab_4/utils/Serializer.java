/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4.utils;

import java.nio.ByteBuffer;

/**
 * class for serialization POD types
 * @author krucios
 */
public class Serializer {
    /**
     * serialization for int
     * @param a any integer
     * @return byte[] 
     */
    public static byte[] serializeInt(int a) {
        ByteBuffer buffer = ByteBuffer.allocate(4);
        buffer.putInt(a);
        return buffer.array();
    }
    
}
