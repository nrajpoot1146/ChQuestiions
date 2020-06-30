public class BankAccount {
    private double balance;
    private String owner;
    private String accountNumber;
    public static int numberOfAccounts;
    BankAccount(){

    }

    BankAccount(String name, double amount){
        this.owner = name;
        this.balance = amount;
    }

    BankAccount(BankAccount oldAccount, double amount){
        this.owner = oldAccount.owner;
        this.balance = amount;
    }

    public void deposit(double amount){
        this.balance += amount;
    }

    public boolean withdraw(double amount){
        if(this.balance - amount >= 0){
            this.balance -= amount;
            return true;
        }
        return false;
    }

    public double getBalance() {
        return balance;
    }

    public String getOwner() {
        return owner;
    }

    public String getAccountNumber() {
        return accountNumber;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public void setAccountNumber(String accountNumber) {
        this.accountNumber = accountNumber;
    }
}
