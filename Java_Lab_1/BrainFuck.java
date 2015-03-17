import java.io.IOException;
import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

class BFException extends Exception {
    public BFException (String message) {
        super(message);
    }
}

class BFI {
    // FIELDS
    private final InputStream consoleReader;
    private final PrintStream consoleWriter;
    private String program;

    private int i;
    private byte[] memory;

    public BFI(InputStream in, PrintStream out)
    {
        program = "";

        i = 0;
        memory = new byte[30000];

        consoleReader = in;
        consoleWriter = out;

        consoleWriter.print("Hello, i would fuck you brain!\n"
                +"Enter your program now.\n All before '#' symbol will be interpreted as BF program\n"
                +"===================\n");
    }

    public void readProgram() throws IOException {
        Scanner sc = new Scanner(consoleReader);
        program = sc.nextLine();
        consoleWriter.println("--== PROGRAM SUCCESSFULLY LOAD ==--");
    }

    public void printProgram() {
        consoleWriter.println(program);
    }

    public void execute() throws BFException, IOException {
        int j = 0;
        for(; j < program.length();) {
            switch (program.charAt(j)) {
                case '>':
                    if (i == 29999)
                        throw new BFException("Range error");
                    ++i;
                    ++j;
                    break;
                case '<':
                    if (i == 0)
                        throw new BFException("Range error");
                    --i;
                    ++j;
                    break;
                case '+':
                    ++memory[i];
                    ++j;
                    break;
                case '-':
                    --memory[i];
                    ++j;
                    break;
                case '.':
                    consoleWriter.print((char) memory[i]);
                    ++j;
                    break;
                case ',':
                    memory[i] = (byte) consoleReader.read();
                    ++j;
                    break;
                case '[':
                    if (memory[i] == 0)
                    {
                        int balance = 1;
                        while (balance != 0)
                        {
                            ++j;
                            if (j >= program.length())
                                throw new BFException("Expected ] but not found");
                            if (program.charAt(j) == ']')
                                --balance;
                            else if (program.charAt(j) == '[')
                                ++balance;
                        }
                        ++j;
                    }
                    break;
                case ']':
                    if (memory[i] != 0)
                    {
                        int balance = -1;
                        while (balance != 0)
                        {
                            --j;
                            if (j < 0)
                                throw new BFException("Expected [ but not found");
                            if (program.charAt(j) == '[')
                                ++balance;
                            else if (program.charAt(j) == ']')
                                --balance;
                        }
                    }
                    break;
                default:
                    throw new BFException("Unknown command: " + program.charAt(j));
            }
        }
    }

    public void terminate() {
        consoleWriter.print("\n===================\nGood bye!\n");
    }
}


public class  BrainFuck {

    public static void main(String[] args) throws IOException, BFException {
        BFI BF = new BFI(System.in, System.out);
        BF.readProgram();
        //BF.printProgram();
        BF.execute();
        BF.terminate();
    }

}
