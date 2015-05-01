/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package java_lab_4;

import java.io.IOException;
import java.util.Scanner;
import java.util.logging.Logger;
import java_lab_4.VM.Machine;
import java_lab_4.VM.VMException;

/**
 * main class
 * @author krucios
 */
public class Main {
    private final Logger log = Logger.getLogger("MainLogger");
    
    /**
     * 
     * @throws VMException
     * @throws IOException 
     */
    void main() throws VMException, IOException {
        log.info("Creating VM ...");
        Machine a = new Machine();
      
        /** PROGRAM DESCRIPTION
         * 
         * ,>,[-<-.>]
         * 
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
        Scanner scanner = new Scanner(System.in);
        String file_name;
        int ans = 1;
        while (ans != 3) {
            printMenu();
            ans = scanner.nextInt();
            switch (ans) {
                case 1:
                    log.info("=> New session mode");
                    System.out.println("***** Started new sessin *****\n"
                                     + "Please, input program. " 
                                     + "After, it will be executed\n");
                    String programm = scanner.nextLine();
                    programm = scanner.nextLine(); // 0_0
                    a.downloadProgram(programm);
                    log.info("=> Programm successfully dowlanded");
                    System.out.println("===> Programm successfully dowlanded");
                    try {
                        a.execute();
                    } catch (VMException | IOException e)
                    {
                        log.severe("Error: " + e.getMessage());
                    }
                    break;
                case 2:
                    log.info("=> Load from file mode");
                    System.out.println("Please, input file name:");
                    file_name = scanner.nextLine();
                    file_name = scanner.nextLine(); // 0_0
                    a.loadFromFile(file_name);
                    log.info("=> Programm successfully loaded");
                    System.out.println("===> Programm successfully loaded");
                    try {
                        a.execute();
                    } catch (VMException | IOException e)
                    {
                        log.severe("Error: " + e.getMessage());
                    }
                    break;
                case 3:
                    log.info("=> Save to file mode");
                    System.out.println("Please, input file name:");
                    file_name = scanner.nextLine();
                    file_name = scanner.nextLine(); // 0_0
                    a.saveToFile(file_name);
                    log.info("Programm successfully saved");
                    System.out.println("===> Programm successfully saved");
                    break;
                case 4:
                    log.info("Terminating pogram");
                    System.exit(0);
                    break;
                default:
                    log.warning("Unknown option, try again");
            }
        }
    }
    
    /**
     * Print console menu
     */
    public static void printMenu() {
        System.out.println("\n***** Welcome to BrainFUcker *****\n"
                           + "1) start new session\n"
                           + "2) load saved VM state\n"
                           + "3) save current VM state\n"
                           + "4) exit\n"
                           + "**********************************");
    }
}
