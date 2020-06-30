import java.io.*;
import java.net.Socket;
import java.util.Scanner;

public class Client {
    public static void main(String[] args) throws IOException {
        Scanner sc = new Scanner(System.in);
        while (true){
            menu();
            int o = sc.nextInt();
            Socket socket = new Socket("127.0.0.1", 8060);
            BufferedWriter bw = new BufferedWriter(new OutputStreamWriter(socket.getOutputStream()));
            BufferedReader br = new BufferedReader(new InputStreamReader(socket.getInputStream()));
            if(o==1){
                bw.write("lock\n");
                bw.flush();
                String line = br.readLine();
                System.out.println("res: "+line);
            }else if(o==2){
                bw.write("unlock\n");
                bw.flush();
                String line = br.readLine();
                System.out.println("res: "+line);
            }else if(o==-1){
                break;
            }else{
                System.out.println("Please enter correct number.");
            }
            bw.close();
            br.close();
            socket.close();
        }
        sc.close();
    }

    public static void menu(){
        System.out.println("Enter your choice no.");
        System.out.println("1. to lock device.");
        System.out.println("2. to unlock device.");
        System.out.println("-1 to exit.");
    }
}
