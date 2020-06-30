import java.time.DateTimeException;
import java.time.LocalDate;
import java.util.Scanner;

public class Solution {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int dateInt = sc.nextInt();

        int year = dateInt % 10000;
        dateInt = dateInt / 10000;
        int month = dateInt % 100;
        dateInt = dateInt / 100;
        int day = dateInt % 100;

        LocalDate localDate = null;
        try{
            localDate = LocalDate.of(year, month, day);

            String leapYearMsg = "";
            StringBuilder msg = new StringBuilder();
            if(localDate.isLeapYear()){
                leapYearMsg = "It is a Leap year.";
            }

            if(day >= 11 && day <= 20){
                msg.append("It is the "+day+"th day of "+localDate.getMonth().name().charAt(0) + localDate.getMonth().name().substring(1).toLowerCase()+", in "+year);
            }else if(day % 10 == 1){
                msg.append("It is the "+day+"st day of "+localDate.getMonth().name().charAt(0) + localDate.getMonth().name().substring(1).toLowerCase()+", in "+year);
            }else if(day % 10 == 2){
                msg.append("It is the "+day+"nd day of "+localDate.getMonth().name().charAt(0) + localDate.getMonth().name().substring(1).toLowerCase()+", in "+year);
            }else if(day % 10 == 3){
                msg.append("It is the "+day+"rd day of "+localDate.getMonth().name().charAt(0) + localDate.getMonth().name().substring(1).toLowerCase()+", in "+year);
            }else{
                msg.append("It is the "+day+"th day of "+localDate.getMonth().name().charAt(0) + localDate.getMonth().name().substring(1).toLowerCase()+", in "+year);
            }

            msg.append(". ");
            msg.append(leapYearMsg);

            System.out.println(msg.toString());

        }
        catch (DateTimeException e){
            System.out.println("Error, this day does not exist.");
            return;
        }

        sc.close();
    }

}
