import java.io.BufferedReader;
import java.io.File;
import java.io.FileInputStream;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.Scanner;

public class AccountDriver {
   private static ArrayList<Account> accounts;
   private static Scanner sc;
   public static void main(String[] args) throws IOException {
       accounts = new ArrayList<Account>();
       AccountDriver.readFromFile();
       sc = new Scanner(System.in);
       while(true) {
           System.out.println("1. Display Account Info for all Accounts\r\n" +
                   "2. Display Account Info for a particular Account\r\n" +
                   "3. Withdraw\r\n" +
                   "4. Deposit\r\n" +
                   "5. Transfer\r\n" +
                   "6. Add New Account\r\n" +
                   "7. Delete Account\r\n" +
                   "8. Exit\r\n" +
                   "\r\n" +
                   "Please select your choice: ");
           int op = sc.nextInt();
           sc.nextLine();
          
           if( op == 1) {
               displayAllAccountInfo();
               AccountDriver.waitForEnterKey();
           }else if(op == 2) {
               displayAccountInfo();
               AccountDriver.waitForEnterKey();
           }else if(op == 3) {
               withdraw();
               AccountDriver.waitForEnterKey();
           }else if(op == 4) {
               deposit();
               AccountDriver.waitForEnterKey();
           }else if(op == 5) {
               transfer();
               AccountDriver.waitForEnterKey();
           }else if(op == 6) {
               addAccount();
               AccountDriver.waitForEnterKey();
           }else if(op == 7) {
               deleteAccount();
               AccountDriver.waitForEnterKey();
           }else if(op == 8) {
//               saveAccountsToFile();
               AccountDriver.waitForEnterKey();
               break;
           }
       }
       sc.close();
   }
  
   private static void displayAllAccountInfo() {
       if(accounts.size() <= 0){
           System.out.println("No Account is present.");
           return;
       }
       int i=0;
       System.out.println("AccountID \t Account Owner \t Account Balance (SAR)");
       while(i < accounts.size()){
           System.out.printf("%d\t%s\t%9.2f",accounts.get(i).getAccountID(),accounts.get(i).getName(),accounts.get(i).getBalance());
           System.out.println();
           i++;
       }
       return;
   }
  
   private static void displayAccountInfo() {
       System.out.print("Enter accountID: ");
       int accountid = sc.nextInt();
       sc.nextLine();
       int index = searchAccount(accountid);
       if(index > 0)
           System.out.printf("AccountId : %d\t Account Owner : %s\t Account Balance: %9.2f\n", accounts.get(index).getAccountID(),accounts.get(index).getName(),accounts.get(index).getBalance());
       else {
           System.out.println("Error: Invalid account number");
       }
   }
  
   private static void withdraw() {
       System.out.print("Please enter accountID: ");
       int accountid = sc.nextInt();
       System.out.print("Please enter withdraw amount (SAR): ");
       double amount = sc.nextDouble();
       sc.nextLine();
       int index = searchAccount(accountid);
       if(index>0) {
           try {
               double balance = accounts.get(index).getBalance();
               accounts.get(index).withdraw(amount);
               System.out.printf("Balance before withdrawal : %9.2f Saudi Riyals\n",balance);
               System.out.printf("Amount withdrawn from Account: %9.0f Saudi Riyals\n",amount);
               System.out.printf("New Balance : %9.2f Saudi Riyals\n",accounts.get(index).getBalance());
           }catch(IllegalArgumentException e){
               System.out.println(e.getMessage());
           }
       }else {
           System.out.println("Error: Invalid account number");
       }
   }
  
   private static void deposit() {
       System.out.print("Please enter accountID: ");
       int accountid = sc.nextInt();
       System.out.print("Please enter deposit amount (SAR): ");
       double amount = sc.nextDouble();
       sc.nextLine();
       int index = searchAccount(accountid);
       if(index>0) {
           try {
               double balance = accounts.get(index).getBalance();
               accounts.get(index).deposit(amount);
               System.out.printf("Balance before deposit : %9.2f Saudi Riyals\n", balance);
               System.out.printf("Amount deposited to Account: %9.0f Saudi Riyals\n", amount);
               System.out.printf("New Balance : %9.2f Saudi Riyals\n", accounts.get(index).getBalance());
           }catch(IllegalArgumentException e) {
               System.out.println(e.getMessage());
           }
       }else {
           System.out.println("Error: Invalid account number");
       }
   }
  
   private static void transfer() {
       System.out.print("Please enter source accountID: ");
       int sourceAccountId = sc.nextInt();
       System.out.print("Please enter destination accouuntID: ");
       int destinationAccountId = sc.nextInt();
       System.out.print("Please enter transfer amount (SAR): ");
       double transferAmount = sc.nextDouble();
       sc.nextLine();
       int sourceIndex = searchAccount(sourceAccountId);
       int destinationIndex = searchAccount(destinationAccountId);
       if(sourceIndex < 0) {
           System.out.println("Error: Invalid source account ID ");
           return;
       }else if(destinationIndex < 0) {
           System.out.println("Error: Invalid destination account ID");
           return;
       }
      
       try {
           double sourceBforeTranferBalance = accounts.get(sourceIndex).getBalance();
           accounts.get(sourceIndex).transfer(transferAmount, accounts.get(destinationIndex));
           System.out.printf("Source balance before transfer: %9.2f Saudi Riyals\n",sourceBforeTranferBalance);
           System.out.printf("Amount transferred to account %d: %9.0f Saudi Riyals\n", destinationAccountId, transferAmount);
           System.out.printf("New source balance: %9.2f Saudi Riyals\n",accounts.get(sourceIndex).getBalance());
       }catch(IllegalArgumentException e) {
           System.out.println(e.getMessage());
       }
   }
  
   private static void addAccount() {
       System.out.print("Please enter accountID: ");
       int accountid = sc.nextInt();
       sc.nextLine();
       System.out.print("Please enter account owner name: ");
       String name = sc.nextLine();
       System.out.print("Please enter account balance: ");
       double balance = sc.nextDouble();
      
       int index = searchAccount(accountid);
       if(index<0) {
           System.out.println("Error: Account number already exist: ");
           return;
       }
      
       Account newAccount = new Account(accountid, name, balance);
       accounts.add(newAccount);
   }
  
   private static void deleteAccount() {
       System.out.print("Please enter accountID: ");
       int accountid = sc.nextInt();
       sc.nextLine();
       int index = searchAccount(accountid);
       if(index>0) {
           accounts.remove(index);
       }else {
           System.out.println("Error: Invalid account number");
       }
   }
  
   private static int searchAccount(int accountid) {
       int index = 0;
       while(index < accounts.size() && accounts.get(index).getAccountID() != accountid ) {
           index++;
       }
      
       if(index == accounts.size()) {
           return -1;
       }
       return index;
   }
  
   private static void waitForEnterKey() {
       System.out.println("Press Enter key to continue...");
       AccountDriver.sc.nextLine();
   }
  
   private static void readFromFile() throws IOException {
       File f = new File("accountinfo.txt");
       FileInputStream fileInputStream = new FileInputStream(f);
       try (BufferedReader bufferedReader = new BufferedReader(new InputStreamReader(fileInputStream))) {
           String line = "";
           while( (line = bufferedReader.readLine()) != "" && line != null) {
               String[] temp = line.split(" ");
               int accountID = Integer.parseInt(temp[0]);
               String name = temp[1] + " " + temp[2];
               double balance = Double.parseDouble(temp[3]);
              
               accounts.add(new Account(accountID, name, balance));
           }
           bufferedReader.close();
       }
   }

}