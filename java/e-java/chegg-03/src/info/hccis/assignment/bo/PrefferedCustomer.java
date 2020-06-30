package info.hccis.assignment.bo;

public class PrefferedCustomer extends Customer {
	String loyaltyCardNumber;
	public PrefferedCustomer(String loyaltyCardNumber) {
		this.loyaltyCardNumber = loyaltyCardNumber;
	}
	
	public PrefferedCustomer() {
		this.loyaltyCardNumber = null;
	}
	
	public void setLoyaltyCardNumber(String loyaltyCardNumber) {
		this.loyaltyCardNumber = loyaltyCardNumber;
	}
	
	public String getLoyaltyCardNumber() {
		return this.loyaltyCardNumber;
	}
}
