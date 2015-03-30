/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_3;

import java.io.IOException;
import java_lab_3.VM.Machine;
import java_lab_3.VM.VMException;
import java.nio.file.Path;
import java.nio.file.Paths;
import java.nio.file.Files;

/**
 *
 * @author krucios
 */
public class main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws VMException, IOException {
        Machine a = new Machine();
        a.downloadProgram(",>,[-<-.>]");
        /** PROGRAM DESCRIPTION
         * Input: 2 numbers
         *        1 (initial) - initial character
         *        2 (count)   - count of characters to be printed
         * 
         * Output: Char sequence, which contain (count) symbols with (initial) 
         *         as first symbol.
         * 
         * Example: 70 10
         * 
         * Output: E D C B A @ ? > = <
         */
        a.execute();
        System.out.print("\n");
        
        Path path = Paths.get("save.bfvm");
        byte[] serialized_vm = a.serialize(); 
        Files.write(path, serialized_vm);
        
        System.out.println("...... Deserialize ..........");
        
        Machine b = new Machine();
        b.deserialize(Files.readAllBytes(path));
        b.set_I_P(0);
        b.execute();
    }
}
