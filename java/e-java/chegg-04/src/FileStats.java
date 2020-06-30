import java.util.Scanner;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.InputStreamReader;

public class FileStats {
    public static void main(String[] args) throws Exception {
        Scanner input = new Scanner(System.in);
        System.out.println("Enter a filename");
        
        String file_name = input.nextLine();
        int word_line_count = 0, line_count = 0;
        
        
        File file = new File(file_name);
        FileInputStream fin = new FileInputStream(file);
        BufferedReader buffer = new BufferedReader(new InputStreamReader(fin));
        String sentence;
        
        while ((sentence = buffer.readLine()) != null) {
            line_count++;
        }
        System.out.println(file_name + " has " + line_count + " lines");
       
        fin.getChannel().position(0);
        System.out.println("Enter some text");
        String search_word = input.nextLine();
        
        while ((sentence = buffer.readLine()) != null) {
            if(sentence.toLowerCase().contains(search_word.toLowerCase())){
            	word_line_count++;
            }
        }
        
        System.out.println(word_line_count + " line(s) contain " + '\u0022' + search_word + '\u0022');
        buffer.close();
        input.close();
    }
}
