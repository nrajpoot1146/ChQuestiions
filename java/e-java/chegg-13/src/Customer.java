
public class Customer {
	private int id;
	private String name;
	
	/**
	 * 
	 * @param id customer id
	 * @param name customer name
	 */
	public Customer(int id, String name) {
		this.id = id;
		this.name = name;
	}
	
	/**
	 * 
	 * @return name of the customer
	 */
	public String getName() {
		return this.name;
	}
	
	/**
	 * 
	 * @return id of the customer
	 */
	public int getId() {
		return this.id;
	}
	
	/**
	 * @return customer id and customer name as a string 
	 */
	public String toString() {
		String res;
		res = this.id +": "+this.name;
		return res;
	}
}
