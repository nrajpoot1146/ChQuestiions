import java.io.IOException;
import java.util.Arrays;

public class Driver {
    public static void main(String[] args) throws IOException {
        Student[] students = util.readFromFile("students.txt");

        System.out.println("Lowest: "+Arrays.toString(Statistics.getLowest(students)));
        System.out.println("Highest: "+Arrays.toString(Statistics.getHighest(students)));
        System.out.println("Average: "+Arrays.toString(Statistics.getAverage(students)));
    }
}
