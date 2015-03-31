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
import java.util.Scanner;

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
                    System.out.println("***** Started new sessin *****\n"
                                     + "Please, input program. " 
                                     + "After, it will be executed\n");
                    String programm = scanner.nextLine();
                    programm = scanner.nextLine(); // 0_0
                    a.downloadProgram(programm);
                    System.out.println("===> Programm successfully dowlanded");
                    a.execute();
                    break;
                case 2:
                    System.out.println("Please, input file name:");
                    file_name = scanner.nextLine();
                    file_name = scanner.nextLine(); // 0_0
                    a.loadFromFile(file_name);
                    System.out.println("===> Programm successfully loaded");
                    a.execute();
                    break;
                case 3:
                    System.out.println("Please, input file name:");
                    file_name = scanner.nextLine();
                    file_name = scanner.nextLine(); // 0_0
                    a.saveToFile(file_name);
                    System.out.println("===> Programm successfully saved");
                    break;
                case 4:
                    System.exit(0);
                    break;
                default:
                    System.out.println("Wrong input, try again");
            }
        }
    }
    
    public static void printMenu() {
        System.out.println("\n***** Welcome to BranFUcker *****\n"
                           + "1) start new session\n"
                           + "2) load saved VM state\n"
                           + "3) save current VM state\n"
                           + "4) exit\n"
                           + "*********************************");
    }
}
