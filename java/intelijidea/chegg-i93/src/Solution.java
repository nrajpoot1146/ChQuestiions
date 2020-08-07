import java.util.Scanner;

public class Solution {
    private static double ansPositive = 0;
    private static double ansNegative = 0;
    private static int n;
    private static boolean isPositiveSum = false;
    private static boolean isNegativeSum = false;

    public static void main(String... args){
        Scanner sc = new Scanner(System.in);
        System.out.println("Enter the value of n: ");
        n = sc.nextInt(); // read value of n

        // thread to calculate sum of positive term
        Thread calPositive = new Thread(new Runnable() {
            @Override
            public void run() {
                int i=1;
                while (i <= n){
                    ansPositive += Math.pow(i, i);
                    i=i+2;
                }
                isPositiveSum = true;
            }
        });

        // thread to calculate sum of negative term
        Thread calNegative = new Thread(new Runnable() {
            @Override
            public void run() {
                int i=2;
                while (i <= n){
                    ansNegative += Math.pow(i, i);
                    i=i+2;
                }
                isNegativeSum = true;
            }
        });

        // starts both threads
        calPositive.start();
        calNegative.start();

        // wait until sum of both negative term and positive term are not ready
        while (!isPositiveSum || !isNegativeSum);

        // print result
        System.out.println("sum of series = "+ (ansPositive - ansNegative));
    }
}
