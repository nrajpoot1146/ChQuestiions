import java.util.Scanner;

public class ISBNChecker {

    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        System.out.println("Enter 13-digit ISBN: ");
        Long isbn = sc.nextLong();
        // condition to check entered number is larger than 13 or not
        if(digitCounter(isbn) == 13){
            int res = varify(isbn);
            if(res == 0){ // condition for correct isbn number
                System.out.println("Number is valid!");
            }else{
                System.out.println("Number is invalid!");
            }
        }else{
            // if number is larger then print error message
            System.out.println("Error - number exceeds 13 digits");
        }
        sc.close();
    }

    /**
     * function to count number of digits presents in isbn number
     * @param isbn number of book
     * @return number of digits in isbn number
     */
    public static int digitCounter(Long isbn){
        int count = 0;

        while (isbn != 0){
            isbn /= 10;
            count++;
        }

        return count;
    }

    /**
     *
     * @param num long isbn number
     * @return calculated value, zero if isbn is correct
     * used formula
     * x1 + 3 x2 + x3 + 3 x4 + x5 + 3 x6 + x7 + 3 +x8 + x9 + 3 x10 + x11 + 3 x12 +x13 = 0
     */
    public static int varify(Long num){
        int res = 0;
        // flag variable, if it is true then digit directly added to result otherwise digit multiplied by 3 and add
        boolean flag = true;
        while (num != 0){
            // get rightmost digit
            int digit = (int)(num % 10);
            if (flag){
                res += digit;
                flag = false;
            }else{
                res += (3 * digit);
                flag = true;
            }
            num /= 10;
        }
        return res % 10;
    }
}
