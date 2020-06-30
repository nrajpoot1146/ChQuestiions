import java.util.Scanner;

public class Tax {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Scanner sc = new Scanner(System.in);
		
		System.out.println("Enter income amount");
		int income = sc.nextInt();
		sc.nextLine();
		
		System.out.println("Enter type I or i for <Incomme Tax> and P or p doe <Property Tax>");
		String type = sc.nextLine();
		
		System.out.println("Enter Tax Pay years");
		int year  = sc.nextInt();
		
		double taxableAmount = calTaxableAmount(income, type);
		
		double tax = calTax(taxableAmount, type, year);
		
		System.out.println("Taxable amount is "+String.format("%2.1f", taxableAmount));
		System.out.println("Overall Total Tax = "+String.format("%2.1f", tax));
		
		
		sc.close();
	}
	
	/**
	 * 
	 * @param amount income of one year
	 * @param type of tax
	 * @return taxable amount
	 */
	public static int calTaxableAmount(int amount, String type) {
		
		if(type.equalsIgnoreCase("i")) {
			if(amount > 20000) {
				return 2*amount;
			}else {
				return amount;
			}
		}else if(type.equalsIgnoreCase("p")){
			if(amount > 20000) {
				return 3*amount;
			}else {
				return 2*amount;
			}
		}else {
			return -1;
		}
		
	}
	
	/**
	 * 
	 * @param taxableAmount amount on which tax is apply
	 * @param type of tax
	 * @param year for tax
	 * @return total tax
	 */
	public static double calTax(double taxableAmount, String type, int year) {
		
		if(type.equalsIgnoreCase("i")) {
			if(year>1) {
				return taxableAmount * 0.03;
			}else {
				return taxableAmount * 0.02;
			}
		}else if(type.equalsIgnoreCase("p")) {
			if(year>1) {
				return taxableAmount * 0.04;
			}else {
				return taxableAmount * 0.03;
			}
		}else {
			return -1;
		}
	}

}
