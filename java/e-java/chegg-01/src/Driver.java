import java.util.Date;

public class Driver {

	public static void main(String[] args) {
		CDAccount cdaccount = new CDAccount(1001, 5000, 3);
		System.out.format("%2s%22s%18s%12s%5s%20s", "Account Number", "Initial Balance", "Matural Balance", "Rate(%)",
                "", "Date Created");
		System.out.println(
                "\n==========================================================================================================");
		cdaccount.toString();
		cdaccount.displayMonthlyinterests();
		cdaccount.withdraw(20);
		cdaccount.deposit(30);
	}

}
