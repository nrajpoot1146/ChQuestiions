import java.io.*;
import java.util.Scanner;

public class Solution {
    public static void main(String[] args){
        // get object of Authors.txt file
        File authors = new File("Authors.txt");
        // get object of Books.txt file
        File books = new File("Books.txt");

        // get instance of scanner to read data from user
        Scanner scanner = new Scanner(System.in);

        // read name of author
        System.out.println("Enter name of an author: ");
        String name = scanner.nextLine();

        // read title of book
        System.out.println("Enter Title of book: ");
        String title = scanner.nextLine();

        writeInFile( name, authors);

        //write title of book to books.txt file
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader(new FileInputStream(authors)));
            int lineNo = 0;
            String line = null;

            // get line no of author name from authors.txt file
            while ((line = br.readLine()) != null){
                lineNo++;
                if(line.equals(name)){
                    break;
                }
            }
            br.close();

            PrintWriter pw = new PrintWriter(new BufferedWriter(new FileWriter(books, true)));

            // append book title and line number to Books.txt file
            pw.println(title+" "+lineNo);

            System.out.println("Books title and author name successfully added to files.");

            pw.flush();
            pw.close();
        }catch (IOException e){
            e.printStackTrace();
        }

        scanner.close();
    }

    /**
     * function to write author name to Authors.txt file
     * if author name does not exist then append author name to file
     * otherwise do nothing.
     * @param name of author0
     * @param file object of author file
     */
    public static void writeInFile(String name, File file){
        try {
            BufferedReader br = new BufferedReader(new InputStreamReader( new FileInputStream(file)));
            BufferedWriter bw = new BufferedWriter(new FileWriter(file, true));
            PrintWriter pw = new PrintWriter(bw);
            String line = null;
            while ((line = br.readLine()) !=null){
                if(line.equals(name)){
                    return;
                }
            }
            pw.println(name);
            pw.flush();
            pw.close();
            br.close();
        }  catch (IOException e) {
            e.printStackTrace();
        }
    }
}
