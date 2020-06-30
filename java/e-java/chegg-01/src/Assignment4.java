import java.util.Date;

public class Assignment4 {

    // display all account details in table format using string formatting
    public static void displayAccounts(Account[] account) {
        System.out.format("%2s%22s%18s%12s%5s%20s", "Account Number", "Initial Balance", "Monthly Interest", "Balance",
                "", "Date Created");
        System.out.println(
                "\n==========================================================================================================");
        for (int i = 0; i < account.length; i++) {
            System.out.format("%2s%25.2f%20.2f%16.2f%5s%20s", account[i].getId(), account[i].getBalance(),
                    account[i].getMonthlyInterest(), (account[i].getBalance() + account[i].getMonthlyInterest()), "",
                    account[i].getDateCreated());
            System.out.println("");
        }
    }

    public static void main(String[] args) {
        Account[] accounts = new Account[5];

        // initialize 5 account objects
        // withdraw 500 and deposit 1000 in each account
        Account account1 = new Account(1000, 1000, 3, new Date());
        account1.withdraw(500);
        account1.deposit(1000);
        Account account2 = new Account(2000, 2000, 3, new Date());
        account2.withdraw(500);
        account2.deposit(1000);
        Account account3 = new Account(3000, 3000, 3, new Date());
        account3.withdraw(500);
        account3.deposit(1000);
        Account account4 = new Account(4000, 4000, 3, new Date());
        account4.withdraw(500);
        account4.deposit(1000);
        Account account5 = new Account(5000, 5000, 3, new Date());
        account5.withdraw(500);
        account5.deposit(1000);

        accounts[0] = account1;
        accounts[1] = account2;
        accounts[2] = account3;
        accounts[3] = account4;
        accounts[4] = account5;

        displayAccounts(accounts);
    }
}