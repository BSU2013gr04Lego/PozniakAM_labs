/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */
package lab_56.lab_56_server;

import java.net.ServerSocket;
import java.util.*;
import java.util.logging.*;

/**Server*/
public class Server extends Thread {
    static private ArrayList<User> clients = new ArrayList<>();
    static private ServerSocket server;
    private static final Logger logger = Logger.getLogger("Server_logger");
    private int current_point;

    public Server(int port) throws Exception{
        server = new ServerSocket(port);
        
        FileHandler handler = new FileHandler("Server.log", true);
        handler.setFormatter(new SimpleFormatter());
        
        logger.addHandler(handler);
        logger.setLevel(Level.FINEST);
        
        current_point = 0;
    }

    static public void logging(Exception e) {
        StackTraceElement elements[] = e.getStackTrace();
        String s = "CallStack:\n";

        for (StackTraceElement i : elements)
            s += i.getClassName() + "." + i.getMethodName() + " ...  " + i.getLineNumber() + "\n";

        logger.log(Level.WARNING, e + "\n" + s);
    }

    private class Cleaner extends Thread {
        @Override
        public void run() {
            while (true)
                for (int i = 0; i < clients.size(); ++i)
                    if (clients.get(i).isInterrupted() || !clients.get(i).isConnected()) {
                        clients.get(i).close();
                        clients.remove(i);
                        --i;
                    }
        }
    }
    
    private class Speaker extends Thread {
        private int period = 1000; //ms
        
        @Override
        public void run() {
            while (true)
            {
                try
                {
                    Thread.sleep(period);
                    Server.println("Current point - " + current_point, "server");
                } catch (Exception e)
                {
                    Server.logging(e);
                }
                
                
            }
        }
        
        public void setPeriod(int new_period)
        {
            this.period = new_period;
        }
    }

    @Override
    public void run() {
        Cleaner c = new Cleaner();
        c.start();
        
        Speaker s = new Speaker();
        s.start();
        
        while (true)
        {
            try {
                clients.add(new User(server.accept()));
                clients.get(clients.size() - 1).start();
            } catch (Exception e) 
            {
                Server.logging(e);
            }
        }
    }
    
    public void incrementPoint()
    {
        if (current_point == Integer.MAX_VALUE)
            current_point = Integer.MIN_VALUE;
        else
            current_point++;
    }
    
    public int getPoint()
    {
        return current_point;
    }

    public static void println(String message, String username) {
        for (User client : clients) {
            client.println(message, username);
        }
    }

    public static void main(String [] args) throws Exception {
        Server s = new Server(30000);
        s.start();
    }
}
