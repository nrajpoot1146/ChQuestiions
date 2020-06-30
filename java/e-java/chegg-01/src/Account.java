import java.util.Date;

public class Account {
    private int id = 0;
    private double balance = 0;
    private double annualInterestRate = 0;
    private Date dateCreated = new Date();

    // constructor with all parameters
    public Account(int id, double balance, double annualInterestRate, Date dateCreated) {
        this.id = id;
        this.balance = balance;
        this.annualInterestRate = annualInterestRate;
        this.dateCreated = dateCreated;
    }

    // default constructor
    public Account() {
    }

    // getter and setter methods
    public int getId() {
        return id;
    }

    public void setId(int id) {
        this.id = id;
    }

    public double getBalance() {
        return balance;
    }

    public void setBalance(double balance) {
        this.balance = balance;
    }

    public double getAnnualInterestRate() {
        return annualInterestRate;
    }

    public void setAnnualInterestRate(double annualInterestRate) {
        this.annualInterestRate = annualInterestRate;
    }

    public Date getDateCreated() {
        return dateCreated;
    }

    public void setDateCreated(Date dateCreated) {
        this.dateCreated = dateCreated;
    }

    // calculate monthly interest rate
    public double getMonthlyInterestRate() {
        return Math.round(((this.annualInterestRate / 12) * 100.0) / 100.0);
    }

    // calculate monthly interest
    public double getMonthlyInterest() {
        return (balance * this.getAnnualInterestRate()) / 100;
    }

    // withdraw amount if amount is less then balance
    public void withdraw(double amount) {
        if (amount < this.balance) {
            this.setBalance(balance - amount);
        }
    }

    // deposit account if amount > 0
    public void deposit(double amount) {
        if (amount > 0) {
            this.setBalance(balance + amount);
        }
    }
}