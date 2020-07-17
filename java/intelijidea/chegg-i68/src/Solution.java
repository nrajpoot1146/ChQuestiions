import java.util.Scanner;

public class Solution {

    public static void main(String[] ags){
        // initialize scanner to get data from user
        Scanner scanner = new Scanner(System.in);

        // initialize string buffer to store final result string
        StringBuffer stringBuffer = new StringBuffer();
        while (true){
            // read a line
            String line = scanner.nextLine();
            // remove " ." from string
            if (line.contains("."))
                line = line.substring(0, line.indexOf("."));

            // split line into words
            String[] words = line.split(" ");
            if (words.length == 1){ // if line contains single word break current loop
                stringBuffer.append(words[0]);
                break;
            }

            sortWords(words); // sort array of words

            // generate string from words
            for (String word : words){
                stringBuffer.append(word+" ");
            }
            stringBuffer.deleteCharAt(stringBuffer.length()-1); // remove last white space
            stringBuffer.append("\n");
        }
        scanner.close();

        // print result
        System.out.println(stringBuffer.toString());
    }

    /**
     * sort array of words
     * use bubble sort algorithm
     * @param words array of words to sort
     * @return sorted array of words
     */
    public static String[] sortWords(String[] words){
        for (int i = 0; i < words.length-1; i++){
            for (int j = 0; j < words.length - i - 1; j++){
                if (words[j].compareTo(words[j+1]) > 0){
                    // swap word
                    String temp = words[j];
                    words[j] = words[j+1];
                    words[j+1] = temp;
                }
            }
        }
        return words;
    }
}
