import java.util.Scanner;

public class HelloWorld {

    public static void main(String[] args){
        // Creates a reader instance which takes
        // input from standard input - keyboard
        Scanner reader = new Scanner(System.in); // old: Scanner reader = Scanner(System.in)
        System.out.print("Enter a number: ");

        // nextInt reads the next integer from the keyboard
        int number = reader.nextInt(); // old: int number = reader.next()

        // println() prints the following line to the output screen
        System.out.println("You entered: "+number);

    }
}