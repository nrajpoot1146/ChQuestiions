import java.io.*;

public class Solution {
    public static void main(String[] args) throws IOException {

        EmailFromFile emailFromFile = new EmailFromFile("emails.txt");


        System.out.println(emailFromFile.getCommaSeparateEmails());
    }
}
