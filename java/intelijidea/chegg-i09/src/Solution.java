
import java.util.Scanner;

public class Solution {

    public static void main(String[] args){
        Table table = null;

        Scanner sc = new Scanner(System.in);
        println("Enter message : ");
        String message = sc.nextLine();
        println("Choose any one operation: ");
        println("1. Encryption");
        println("2. Decryption");
        int op = sc.nextInt();
        sc.nextLine();

        if(op == 1){
            table = new EncTable();
        }else if(op == 2){
            table = new DecTable();
        }else{
            return;
        }

        println("Enter your roll number: ");
        String rollNo = sc.nextLine();
        int[] key = new int[5];
        if(rollNo.length() >= 5) {
            int len = rollNo.length();
            int i = 4;
            while (i >= 0){
                key[i] = Integer.parseInt(Character.toString(rollNo.charAt(len-1)));
                len--;
                i--;
            }
        }else{
            println("Roll number must be of five or more than five character.");
        }

        int trace = 0;
        StringBuilder stringBuilder = new StringBuilder();
        for (int i = 0; i<message.length(); i++){
            char c = message.charAt(i);
            stringBuilder.append(table.getAt(c, key[trace]));
            trace++;
            trace = trace < 5 ? trace : 0;
        }

        println("Your encrypted/decrypted msg is: "+stringBuilder.toString());
    }

    public static void println(String msg){
        System.out.println(msg);
    }
}
