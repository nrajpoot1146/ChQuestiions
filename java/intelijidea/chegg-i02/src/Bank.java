mport java.util.Scanner;
import java.text.DecimalFormat;

class Bank {
    public static Scanner scan;
    public static double cb = 0; //checking account
    public static double sb = 0; // savings account
    private boolean userAuthenticated; // whether user is authenticated
    private BankDatabase bankDatabase; // account information database
    private int currentAccountNumber; // current user's account number

    // attempts to authenticate user against database
    private void authenticateUser() {
        System.out.println("\nPlease enter your account number: ");
        int account = scan.nextInt(); // input account number
        System.out.println("\nEnter your PIN: "); // prompt for PIN
        int pin = scan.nextInt(); // input PIN

        // set userAuthenticated to boolean value returned by database
        userAuthenticated =
                bankDatabase.authenticateUser(accountNumber, pin);

        // check whether authentication succeeded
        if (userAuthenticated) {
            currentAccountNumber = accountNumber; // save user's account
        } // end if
        else
            System.out.println("Invalid account number or PIN. Please try again.");
    } // end method authenticateUser

    public static void main(String args[]) {
        transaction(cb, sb);
        Scanner scan = new Scanner(System.in);
        bankDatabase = new BankDatabase();
        currentAccountNumber = 0; // no current account number to start

        int choice = scan.nextInt();
        if (choice == 1) {
            withdraw(cb, sb);
        } else if (choice == 2) {
            deposit(cb, sb);
        } else if (choice == 3) {
            balance(cb, sb);
        } else if (choice == 4) {
            transfer(cb, sb);
        } else if (choice == -1) {
            System.exit(-1);
        } else {
            System.out.println("Your input is not valid, please try again.. ");
            choice = scan.nextInt();
        }
    }

    public static void transaction(double checking, double savings) {
        //DecimalFormat df = new DecimalFormat("0.00");
        //df.format(checking);
        // df.format(savings);

        System.out.println("Please select an option below: (-1 to exit)");
        System.out.println("1. Withdraw");
        System.out.println("2. Deposit");
        System.out.println("3. Balance");
        System.out.println("4. Transfer funds");



    }

    private static double withdraw(double checking, double savings) {
        Scanner scan = new Scanner(System.in);
        System.out.println("You have chosen to withdraw cash.");
        System.out.print("Which account would you like to withdraw from? (1 for checking, 2 for savings)");
        int account = scan.nextInt();
        if (account == 1) { // checkings account
            System.out.println("You have selected checkings.");
            System.out.println("Balance: " + checking);
            System.out.print("How much would you like to withdraw?");
            double amount = scan.nextDouble();
            if (amount > checking || checking <= 0) {
                System.out.println("You have insufficient funds\n");
                amount = scan.nextDouble();
            } else {
                checking -= amount;
                System.out.println("You have withdrawn " + amount + " and your new balance is " + checking + "\n");
                anotherTransaction();
            }
        } else if (account == 2) { //savings account
            System.out.println("You have selected savings.");
            System.out.println("Balance: " + savings);
            System.out.print("How much would you like to withdraw?");
            double amount = scan.nextDouble();
            if (amount > savings || savings <= 0) {
                System.out.println("You have insufficient funds\n");
                amount = scan.nextDouble();
            } else {
                savings -= amount;
                System.out.println("You have withdrawn " + amount + " and your new balance is " + savings + "\n");
                anotherTransaction();
            }
        } else { //invalid option
            System.out.println("Your option is not valid, please try again..");
            account = scan.nextInt();
        }
        //return withdraw(checking, savings);
        return temp;
    }

    private static double deposit(double checking, double savings) {
        Scanner scan = new Scanner(System.in);
        System.out.println("You have chosen to deposit cash.");
        System.out.print("Which account would you like to deposit into? (1 for checking, 2 for savings)");
        int account = scan.nextInt();
        if (account == 1) { // checkings account
            System.out.println("You have selected checkings.");
            System.out.println("Balance: " + checking);
            System.out.print("How much would you like to deposit?");
            double amount = scan.nextDouble();
            checking += amount;
            System.out.println("You have added " + amount + " and your new balance is " + checking + "\n");
            // anotherTransaction();
            return temp;

        } else if (account == 2) { //savings account
            System.out.println("You have selected savings.");
            System.out.println("Balance: " + savings);
            System.out.print("How much would you like to deposit?");
            double amount = scan.nextDouble();
            savings += amount;
            System.out.println("You have added " + amount + " and your new balance is " + savings + "\n");
            // anotherTransaction();

            return temp;

        } else { //invalid option
            System.out.println("Your option is not valid, please try again..");
            account = scan.nextInt();
        }

        return temp;
    }

    private static void balance(double checking, double savings) {
        System.out.println("You have chosen to display your balance.");
        System.out.println("Your checking balance is: " + checking);
        System.out.println("Your savings balance is: " + savings);
    }

    private static double transfer(double checking, double savings) {
        Scanner scan = new Scanner(System.in);
        System.out.println("You have chosen to tranfser between your accounts.");
        System.out.print("Which account would you like to transfer from? (1 for checking, 2 for savings)");
        int account = scan.nextInt();
        if (account == 1) { // checkings account
            System.out.println("You have selected to transfer from checkings to savings.");
            System.out.println("Balance: " + checking);
            System.out.print("How much would you like to transfer over?");
            double amount = scan.nextDouble();
            if (amount > checking || checking <= 0) {
                System.out.println("You have insufficient funds\n");
                amount = scan.nextDouble();
            } else {
                checking -= amount;
                savings += amount;
                System.out.println("You have transferred " + amount + "from checkings to savings.");
                anotherTransaction();
            }
        } else if (account == 2) { //savings account
            System.out.println("You have selected to transfer from savings to checkings.");
            System.out.println("Balance: " + savings);
            System.out.print("How much would you like to transfer over?");
            double amount = scan.nextDouble();
            if (amount > savings || savings <= 0) {
                System.out.println("You have insufficient funds\n");
                amount = scan.nextDouble();
            } else {
                savings -= amount;
                checking += amount;
                System.out.println("You have traferred " + amount + "from savings to checkings.");
                anotherTransaction();
            }
        } else { //invalid option
            System.out.println("Your option is not valid, please try again..");
            account = scan.nextInt();
        }
        //return transfer(checking, savings);
        return temp;

    }
    private void Transaction(int type) {
        Transaction temp = null; // temporary Transaction variable

        // determine which type of Transaction to create   
        switch (type) {
            case BALANCE_INQUIRY: // create new BalanceInquiry transaction
                temp = new BalanceInquiry(
                        currentAccountNumber, bankDatabase);
                break;
            case WITHDRAWAL: // create new Withdrawal transaction
                temp = new Withdrawal(currentAccountNumber, bankDatabase);
                break;
            case DEPOSIT: // create new Deposit transaction
                temp = new Deposit(currentAccountNumber, bankDatabase);
                break;
        } // end switch

        return temp; // return the newly created object
    }

    private static void anotherTransaction() {
        Scanner scan = new Scanner(System.in);
        System.out.println("Do you want another transaction?\n\nPress 1 for another transaction\n2 To exit");
        int anotherTransaction = scan.nextInt();
        if (anotherTransaction == 1) {
            transaction(cb, sb); // call transaction method
        } else if (anotherTransaction == 2) {
            System.out.println("Thanks for choosing us. Good Bye!");
            System.exit(-1);
        } else {
            System.out.println("Invalid choice\n\n");
            anotherTransaction();
        }
    }
}