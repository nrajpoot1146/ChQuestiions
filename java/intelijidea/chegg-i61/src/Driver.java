import java.util.Scanner;

/**
 * Driver.java
 *
 * @author
 */

public class Driver {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        CreditCard creditCard = new CreditCard();

        // loop to read option from user
        while (true){
            menu();
            int op;
            op = scanner.nextInt();
            if (op == 4){
                break;
            }

            switch (op){
                // case to charge credit card
                case 1:
                    System.out.println("Amount to charge: ");
                    int amount = scanner.nextInt();
                    creditCard.charge(amount);
                    break;

                // case to make a payment
                case 2:
                    System.out.println("Amount to pay: ");
                    amount = scanner.nextInt();
                    creditCard.pay(amount);
                    break;

                // case to show balance and points
                case 3:
                    creditCard.seeCurrentBalance();
                    break;
                default:

            }
            System.out.println();
        }

        scanner.close();
    }

    /**
     * print menu on console window
     */
    public static void menu(){
        System.out.println("Would you like to: ");
        System.out.println("1) Charge");
        System.out.println("2) Make a payment");
        System.out.println("3) See current balance");
        System.out.println("4) Quit");
    }
}
