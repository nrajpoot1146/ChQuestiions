/**
 * CreditCard.java
 *
 * @author
 */
public class CreditCard {
    private int balance;
    private int points;
    CreditCard(){
        this.balance = 0;
        this.points = 0;
    }

    /**
     * charge credit card balance with given amount
     * @param amount to charge credit card
     */
    public void charge(int amount){
        if (amount < 0){
            return;
        }
        this.balance += amount;
        this.points += amount * 0.01;
    }

    /**
     * make a payment from current credit card
     * @param amount to pay
     */
    public void pay(int amount){
        if (amount > 0 && this.balance - amount > 0){
            this.balance -= amount;
        }
    }

    /**
     * print current balance and points;
     */
    public void seeCurrentBalance(){
        System.out.println("Balance: " + this.balance);
        System.out.println("Points: " + this.points);
    }
}
