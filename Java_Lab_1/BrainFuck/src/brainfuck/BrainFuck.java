/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package brainfuck;

import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintStream;

class BFI {
    // FIELDS
    
    private final InputStream consoleReader;
    private final PrintStream consoleWriter;
    
    public BFI(InputStream in, PrintStream out)
    {
        consoleReader = in;
        consoleWriter = out;
        consoleWriter.print("Hello, i would fuck you brain!\n"
                           +"===================\n");
    }
    
    public char readSymbol() throws IOException {
        return (char) consoleReader.read();
    }
    
    public void writeSymbol(char s) throws IOException {
        consoleWriter.print(s);
    }
    
    public void teminate() {
        consoleWriter.print("\n===================\nGood bye!\n");
    }
}

/**
 *
 * @author krucios
 */
public class BrainFuck {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        BFI BF = new BFI(System.in, System.out);
        char s = BF.readSymbol();
        
        BF.writeSymbol(s);
        BF.teminate();
    }
    
}
