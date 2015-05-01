/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4;

import java.io.IOException;
import java.util.logging.FileHandler;
import java.util.logging.Level;
import java.util.logging.Logger;
import java.util.logging.SimpleFormatter;
import java_lab_4.VM.VMException;
import sun.util.logging.PlatformLogger;

/**
 * main class
 * @author krucios
 */
public class java_lab_4 {
    
    /**
     * @param args the command line arguments
     * @throws java_lab_4.VM.VMException
     * @throws java.io.IOException
     */
    public static void main(String[] args) throws VMException, IOException { 
        Logger logger = Logger.getLogger("MainLogger");  
        FileHandler fh; 
        try {  
            // This block configure the logger with handler and formatter  
            fh = new FileHandler("./VM_log.log");  
            logger.addHandler(fh);
            SimpleFormatter formatter = new SimpleFormatter();  
            fh.setFormatter(formatter);  
            
            logger.setLevel(Level.FINEST);
            
            // the following statement is used to log any messages  
            logger.info("File logging started");  

        } catch (SecurityException | IOException e) {  
        }  
        Main a = new Main();
        a.main();
    }
   
}
