public class Solution {
    public static void main(String[] args){
        CheckingAccount checkingAccount = new CheckingAccount("owner", 1200);

        System.out.println("Before withdraw");
        System.out.println(checkingAccount.withdraw(200));
        System.out.println("Balance: "+checkingAccount.getBalance());
    }
}
