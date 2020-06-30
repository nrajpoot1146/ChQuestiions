import java.util.Scanner;

public class Solution {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the grades, the raise, and the number of failed courses of any student:");

        String line = sc.nextLine(); // read data from user
        String[] data = line.split(","); // extract data from a single line
        double GPA = Double.parseDouble(data[0]);
        double fees = Double.parseDouble(data[1]);
        int years = Integer.parseInt(data[2]);

        double netFees = NetFees(GPA, fees, years);
        System.out.println("The Netfees is "+ netFees +"$"); // print result for user

        sc.close();
    }

    /**
     * this function calculate netfees for any student on the basis of gpa, fees and year
     * @param GPA gpa of any student
     * @param fees fees per year of any student
     * @param years year of any student
     * @return netfees of student for given year
     */
    public static double NetFees(double GPA, double fees, int years){
        if(GPA >= 3.5){
            return (fees - fees * 0.05 * years);
        }else
            return (fees - fees * 0.025 *years);
    }
}
