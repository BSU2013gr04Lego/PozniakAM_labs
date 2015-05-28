/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_56.lab_56_client;

import java.net.Socket;
import java.io.*;
import java.util.regex.Pattern;
import java.util.regex.Matcher;
/** input reader for server */
class Input extends Thread {
    private BufferedReader in;
    public boolean isAlive = true;

    Input(InputStreamReader stream) {
        in = new BufferedReader(stream);
    }
    public void run() {
        String s="";
        while (isAlive)
            try {
                s = in.readLine();
                if (s == null) {
                    close();
                    break;
                } else System.out.println(s);
            } catch (Exception e) {}
    }
    public void close() throws Exception {
        super.interrupt();
        isAlive = false;
        in.close();
    }
}
/** output reader */
class Output extends Thread {
    private PrintWriter out;
    public boolean isAlive = true;

    Output (OutputStream stream) {
        out = new PrintWriter(stream, true);
    }

    public void run() {
        BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        String s="";
        while (isAlive)
            try {
                s = in.readLine();
                if (s.equalsIgnoreCase("exit")) isAlive = false;
                out.println(s);
            } catch (IOException e) {isAlive = false;}
        close();
    }

    public void close() {
        super.interrupt();
        isAlive = false;
        out.close();
    }
}

/**
 *
 * @author krucios
 */
public class Client {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException, Exception {
        Socket socket;

        BufferedReader cons = new BufferedReader(new InputStreamReader(System.in));
        Output out;
        Input in;

        Matcher matcher;
        Pattern pattern = Pattern.compile("(?:(?:25[0-5]|2[0-4][0-9]|[01]?\\d\\d?)\\.){3}(?:25[0-5]|2[0-4]\\d|[01]?\\d\\d?)"); //ip regex
        String s="";

        if ( (args.length >=2) && (pattern.matcher(args[0]).matches() || args[0].equals("localhost")) ) socket = new Socket(args[0], Integer.parseInt(args[1]));
        else {
                System.out.println("ip and port : ");
                socket = new Socket(cons.readLine(), Integer.parseInt(cons.readLine()));
        }

        socket = new Socket(s, 30000);
        out = new Output(socket.getOutputStream());
        in = new Input(new InputStreamReader(socket.getInputStream()));
        in.start();
        out.start();

        System.out.println("try to connecting");

        while (!out.isInterrupted() && !in.isInterrupted()) {}

        socket.close();
        in.close();
        out.close();
        System.out.println("bye");
    }
    
}
