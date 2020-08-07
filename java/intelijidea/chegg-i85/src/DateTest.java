import java.util.Scanner;

public class DateTest {
    public static void main(String... args){
        Scanner sc = new Scanner(System.in);
        int day;
        int month;
        int year;

        System.out.print("Enter month: ");
        month = sc.nextInt(); // read month
        System.out.print("Enter day: ");
        day = sc.nextInt(); // read day
        System.out.print("Enter year: ");
        year = sc.nextInt(); // read year

        Date date = new Date(month, day, year); // create date object
        System.out.println("Current date: "+date.toString()); // print date

        // call next date using loop
        Date prevDate = date;
        for (int i=0; i<3; i++){
            System.out.println(prevDate.toString());
            prevDate = prevDate.nextDate();
        }

    }
}
