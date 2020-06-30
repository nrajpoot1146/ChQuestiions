public class CheckingAccount extends BankAccount{
    private static final double FEE = 15; // check clearing fee

    /**
     *
     * @param name owner of account
     * @param amount initial balance in account
     */
    CheckingAccount(String name, double amount){
        super(name, amount);
        // set account number
        super.setAccountNumber("10"+BankAccount.numberOfAccounts);
        BankAccount.numberOfAccounts++;
    }

    /**
     * function to withdraw amount from checking account
     * add before withdraw check clearing fee
     * @param amount to be withdraw
     * @return true if amount withdraw successfully otherwise return false
     */
    @Override
    public boolean withdraw(double amount) {
        amount += FEE;
        return super.withdraw(amount);
    }
}
