import java.lang.Math;
import java.util.Date;
public class CDAccount extends Account {
	private int duration;
	private double CDannualInterestRate;
	
	CDAccount(){
		
	}
	CDAccount(int id,double balance,int duration){
		super.setId(id);
		super.setBalance(balance);
		this.duration = duration;
		super.setDateCreated(new Date());
		super.setAnnualInterestRate(5.50);
	}
	public void setDuration(int duration) {
		this.duration = duration;
	}
	public int getDuration() {
		return this.duration;
	}
	public double getMatureBalance() {
		double matureBalance = 0;
		matureBalance = super.getBalance() * Math.pow((1+super.getMonthlyInterestRate()),this.duration);
		return matureBalance;
	}
	public void setCDAnnualInterestRate(double CDannualInterestRate) {
		this.CDannualInterestRate = CDannualInterestRate;
	}
	public double getCDAnnualInterestRate() {
		return super.getAnnualInterestRate();
	}
	public double getMonthlyInterestRate() {
		return super.getMonthlyInterestRate();
	}
	public double getMonthlyInterest() {
		return super.getMonthlyInterest();
	}
	public final void withdraw(double num) {
		System.out.println("A CD Account can't withdraw any cash. You need to close this CD account.");
	}
	public final void deposit(double num) {
		System.out.println("A CD Account can't make any additional deposit. You may open another CD account.");
	}
	public String toString() {
		String res = String.format("%2s%25.2f%20.2f%16.2f%5s%20s", super.getId(), super.getBalance(),
                this.getMatureBalance(), this.getAnnualInterestRate(), "",
                this.getDateCreated());
		System.out.format(res);
		System.out.println();
		return res;
	}
	public void displayMonthlyinterests() {
		System.out.println();
		for(int i=0;i<this.duration;i++) {
			String res = String.format("%2s%25.2f", "Month "+Integer.toString((i+1)), (this.getBalance() + this.getMonthlyInterest()*(i+1)));
			System.out.println(res);
		}
	}
}
