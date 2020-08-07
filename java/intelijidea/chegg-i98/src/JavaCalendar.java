import java.util.Calendar;
import java.util.GregorianCalendar;

public class JavaCalendar {
    public static void main(String... args){
        // check length of arguments
        if (args.length<0){
            return;
        }

        int month = 0;
        int year = 0;
        try {
            month = Integer.parseInt(args[0]); // parse month from args
            year = Integer.parseInt(args[1]); // parse year from args
        } catch (NumberFormatException e){
            System.out.println("please Enter valid month or year!");
            return;
        }

        Calendar calendar = new GregorianCalendar();
        // set date month and year to calender
        calendar.set(Calendar.DATE, 1);
        calendar.set(GregorianCalendar.MONTH, month-1);
        calendar.set(GregorianCalendar.YEAR, year);

        // print details
        System.out.println("-----------------------------");
        System.out.println("  Your name 123456 Calender");
        System.out.println("-----------------------------");
        System.out.println(" |Sun|Mon|Tue|Wed|Thu|Fri|Sat"); // print day column
        System.out.println("-----------------------------");

        int maxDate = calendar.getActualMaximum(Calendar.DAY_OF_MONTH);

        // print calender of given month
        for (int i = 1, j=1; j <= maxDate; i++){
            if (i >= calendar.get(Calendar.DAY_OF_WEEK)){
                System.out.print(String.format(" |%2d", j));
                j++;
            } else {
                System.out.print("    ");
            }
            if (i % 7 == 0){
                System.out.println();
            }
        }
        System.out.println();
        System.out.println("-----------------------------");
    }
}
