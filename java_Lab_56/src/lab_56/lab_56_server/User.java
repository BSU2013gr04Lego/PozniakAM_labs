/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_56.lab_56_server;

import java.net.Socket;
import java.io.*;

/**
 *
 * @author krucios
 */
public class User extends Thread {
    private final Socket socket;
    private final BufferedReader in;
    private final PrintWriter out;
    private String name;

    public User(Socket s) throws Exception {
        socket = s;
        in = new BufferedReader(new InputStreamReader(socket.getInputStream()));
        out = new PrintWriter(socket.getOutputStream(), true);
    }

    public boolean isConnected() {
        return socket.isConnected();
    }

    private void enterance() {
        try {
            Thread.sleep(1000);
            try {
                out.println("Enter your name please: ");
                name = in.readLine();
            } catch (IOException e) 
            {
                Server.logging(e);
            }
        } catch (Exception e) 
        {
            Server.logging(e);
        }
    }

    @Override
    public void run()  {
        enterance();
        String s = "";
        while (!isInterrupted()) 
            try {
                s = in.readLine();
                // TODO
            } catch (IOException e) 
            {
                Server.logging(e);
            }
    }

    public String getUsername() {
        return name;
    }

    public void println(String name, String message) {
        try {
            if (!isInterrupted()) 
                out.println(name + " : " + message);
        } catch (Exception e) 
        {
            Server.logging(e);
        }
    }

    public void close()  {
        try {
            in.close();
            out.close();
            socket.close();
            super.interrupt();
        } catch (Exception e) 
        {
            Server.logging(e);
        }
    }
}
 

