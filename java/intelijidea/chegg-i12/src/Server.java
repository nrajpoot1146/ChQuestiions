
import java.io.*;
import java.net.ServerSocket;
import java.net.Socket;

public class Server {
    public static boolean isLocked = true;
    public static void main(String[] args){


        new Thread(new Runnable() {
            @Override
            public void run() {
                try {
                    ServerSocket serverSocket = new ServerSocket(8060);
                    while(true){
                        Socket socket = serverSocket.accept();
                        new Communication(socket).start();
                    }
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
        }).start();
    }

}

class Communication extends Thread{
    private Socket socket;

    Communication(Socket socket){
        this.socket = socket;
    }

    @Override
    public void run() {
        super.run();
        try {
            InputStream inputStream = this.socket.getInputStream();
            BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(inputStream));
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            String line = bufferedReader.readLine();
            if(line.equals("lock")){
                if(Server.isLocked == false) {
                    System.out.println("Device has been locked.");
                    bw.write("Device has been locked.\n");
                    bw.flush();
                    Server.isLocked = true;
                }
                else {
                    System.out.println("Device is already locked.");
                    bw.write("device already locked\n");
                    bw.flush();
                }
            }else if(line.equals("unlock")){
                if(Server.isLocked == true) {
                    System.out.println("Device has been unlocked");
                    bw.write("Device has been unlocked\n");
                    bw.flush();
                    Server.isLocked = false;
                }
                else {
                    System.out.println("Device already unlocked.");
                    bw.write("Device already unlocked\n");
                    bw.flush();
                }
            }
            bufferedReader.close();;
            bw.close();
            socket.close();
        } catch (IOException e) {
            System.out.println(e.getMessage());
        }
    }
}

