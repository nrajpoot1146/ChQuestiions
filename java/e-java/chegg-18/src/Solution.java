import java.util.NoSuchElementException;

public class Solution {

	public static void main(String[] args) {
		SinglyLinkedList singlyLinkedList = new SinglyLinkedList();
		singlyLinkedList.display();
		
		try {
		singlyLinkedList.min();
		}
		catch(NoSuchElementException e) {
			e.printStackTrace();
		}
		singlyLinkedList.display();
	}

}
