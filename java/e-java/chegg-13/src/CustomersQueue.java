import java.util.ArrayList;


public class CustomersQueue {
	private ArrayList<Customer> queue;
	private int count;
	
	/**
	 * create customer queue
	 */
	public CustomersQueue() {
		this.queue = new ArrayList<Customer>();
		this.count=0;
	}
	
	/**
	 * get front customer in queue
	 * @return front Customer element
	 * @throws Exception if queue is empty
	 */
	public Customer getFront() throws Exception {
		if(this.queue.size()<=0) {
			throw new Exception("Error: Customer queue is empty.");
		}
		return this.queue.get(0);
	}
	
	/**
	 * add Customer to queue
	 * @param name
	 */
	public void enQueue(String name) {
		count++;
		this.queue.add(new Customer(count, name));
	}
	
	/**
	 * remove front customer from queue
	 * @throws Exception if customer queue is empty
	 */
	public void deQueue() throws Exception {
		if(this.size()<=0) {
			throw new Exception("Error: Customer queue is empty.");
		}
		this.queue.remove(0);
	}
	
	/**
	 * get customer queue as a string
	 */
	public String toString(){
		String res = "";
		int index = 0;
		
		while(index < this.queue.size()) {
			res += this.queue.get(index).toString();
			res += " ";
			index++;
		}
		if(this.size()<=0) {
			res = "Error: Customer queue is empty.";
		}
		res = "[ " + res + " ]";
		return res;
	}
	
	/**
	 * 
	 * @return number of elements in customer queue
	 */
	public int size() {
		return this.queue.size();
	}
}
