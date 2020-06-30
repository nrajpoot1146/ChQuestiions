public class Account {
   private int accountId;
   private String name;
   private double balance;
  
   /**
   *
   * @param id account id
   * @param name account holder name
   * @param balance amount in account
   */
   public Account(int id, String name, double balance) {
       this.accountId = id;
       this.balance = balance;
       this.name = name;
   }
  
   /**
   *
   * @return balance
   */
   public double getBalance() {
       return this.balance;
   }
  
   /**
   *
   * @return AccoundId
   */
   public int getAccountID() {
       return this.accountId;
   }
  
   /**
   *
   * @return name account holder name
   */
   public String getName() {
       return this.name;
   }
  
   /**
   *
   * @param amount to be deposit in account
   */
   public void deposit(double amount) {
       if(amount <= 0) {
           throw new IllegalArgumentException("Error: Invalid deposit amount");
       }else {
           this.balance += amount;
       }
   }
  
   /**
   *
   * @param amount to be withdraw from
   */
   public void withdraw(double amount) {
       if(amount <= 0 || amount > this.balance) {
           throw new IllegalArgumentException("Error: Invalid withdraw amount");
       }else {
           this.balance -=amount;
       }
   }
  
   /**
   *
   * @param amount to be transfer
   * @param destinationAccount in witch amount going to transfer
   */
   public void transfer(double amount, Account destinationAccount) {
       if(amount <=0 || this.balance < amount) {
           throw new IllegalArgumentException();
       }else {
           this.balance -= amount;
           destinationAccount.balance += amount;
       }
   }
  
   /**
   * @return res String
   */
   public String toString() {
       String res = String.format("%d %s %9.2f", this.accountId, this.name, this.balance);
       return res;
   }

   /**
   * @return boolean return true when both account has same account id otherwise return false
   */
   public boolean equals(Object obj) {
       if(this.accountId == ((Account) obj).accountId) {
           return true;
       }
       return false;
   }
}