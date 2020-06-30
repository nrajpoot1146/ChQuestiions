
/**
========Implementation of Priority Heap ======
Complete the following class with given prototype/header of a priority heap
+ Look for the TODO tasks and complete them
+ You may need to create a few more helper methods and heapify methods
+ add more test cases into the driver to test your code
*/

import java.util.*;

public class QHeap<K,V extends Comparable<V>> {
    // ==========================================================
	
	
    /** a simple nested class to represent the key-value pair */
    class Item {
        public K key;
        public V value;

        public Item(K key, V value) {
            this.key = key;
            this.value = value;
        }

        public String toString() {
            return "key: " + this.key + "\nValue: " + this.value;
        }
    }// end of nested class
     // ==========================================================

    // attributes
    private final int DEFAULT_CAPACITY = 15;
    private int count;
    private int capacity; // the maximum heap before resize is needed
    private ArrayList<Item> storage;// array used to store the items

    // constructors
    public QHeap() { // new heap with default size
        this.count = 0; // no item in the storage yet
        this.capacity = DEFAULT_CAPACITY;
        // create the storage
        this.storage = new ArrayList<Item>(DEFAULT_CAPACITY);
    }

    /** create a heap with a specific size */
    public QHeap(int requestSize) {
        this.count = 0; // no item in the storage yet
        this.capacity = requestSize;
        this.storage = new ArrayList<Item>(this.capacity);// create the storage
    }

    /* copy constructor - copy the content of the given heap into a new one */
    public QHeap(QHeap given) {

        // TODO: copy the data of the given heap to the new heap ***** PART 1 OF
        // QUESTION*****
    	this.capacity = given.capacity;
    	this.count = given.count;
    	this.storage = given.storage;

    }

    // methods
    /* merge the given heap into this one */
    public int merge(QHeap second) {
        // TODO: merge the heap here

        return this.count;
    }
    
    private static int parent(int i) {
		return (i-1)/2;
	}

    /** insert a key/value pair - the key is use for priority */
    public void insert(K key, V value) {
        // TODO: insert an Item into the heap *****PART 2 OF QUESTION***/****
        // invoke heapify operation to keep the heap integrity
    	Item item = new Item(key, value);
    	this.storage.add(item);
    	int loc = this.storage.size()-1;
    	while (loc > 0 && this.storage.get(loc).value.compareTo(this.storage.get(parent(loc)).value) < 0) {
			swap(this.storage, loc, parent(loc));
			loc = parent(loc);
		}
    }

    /** return the min Item */
    public Item min() {
        // TODO: get the min item and return *****PART 3 OF QUESTION*******
    	if (this.storage.size() <= 0)
			return null;
		else {
			E minVal = this.storage.get(0);
			this.storage.set(0, this.storage.get(this.storage.size()-1));  // Move last to position 0
			this.storage.remove(this.storage.size()-1);
			minHeapify(this.storage, 0);
			return minVal;
		}
        // dummy return
        return null;
    }

    /** remove and return the root node, i.e. min Item */
    public Item removeMin() {

        // TODO: remove the min item and return *****PART 4 OF QUESTION*******

        // dummy return
        return null;
    }

    // traverse the heap
    public String inOrderTraversal() {
        String output = "";

        // TODO: return a string representing the in order traversal of the heap
        return output;
    }

    // ======

    // return the number of elements in the heap
    public int size() {
        return this.count;
    }

    // return true if the heap is empty
    public boolean isEmpty() {
        return this.count <= 0;
    }

    // print the content of the heap
    public String toString() {
        // empty heap
        if (this.storage == null || this.count <= 0)
            return "";

        // print the content of the heap
        Iterator<Item> itr = this.storage.iterator();
        String output = "";
        while (itr.hasNext())
            output += itr.next();
        return output;
    }

    // ==============================================
    // ===== Driver
    // TODO: add more testing cases *****PART 5 OF QUESTION*******
    public static void main(String[] args) {
        // create a heap
        QHeap heap = new QHeap<Integer,String>(20);
        heap.insert(2, "p1");
        heap.insert(3, "p2");
        // todo: put more data

        System.out.println(heap.size());
        System.out.println(heap);
        System.out.println(heap.min());
        heap.removeMin();
        System.out.println(heap);

        // testing traversal
        System.out.println(heap.inOrderTraversal());

        // create a new heap
        QHeap heap2 = new QHeap<Integer, String>(10);
        heap2.insert(4, "some data");
        heap2.insert(5, "some more data");
        System.out.println(heap2);

        // merge the heap
        heap.merge(heap2);
        System.out.println(heap);// print the merged heap
        heap.removeMin();
        heap2.removeMin();
        System.out.println(heap.size());
        System.out.println(heap);// print the merged heap
        System.out.println(heap2.size());
        System.out.println(heap2);// print the heap

        // create a new heap by copying an existing one
        QHeap heap3 = new QHeap<Integer, String>(heap2);
        System.out.println(heap3.size());
        System.out.println(heap3);
        System.out.println(heap3.min());
        heap.removeMin();
        System.out.println(heap3);
    }// ==================================================
    
    private static <E> void swap(ArrayList<E> a, int i, int j) {
		E t = a.get(i);
		a.set(i, a.get(j));
		a.set(j, t);
	}
    private static <E extends Comparable<E>> void minHeapify(ArrayList<QHeap<Integer, String>.Item> storage2, int i) {
		int left = leftChild(i);
		int right = rightChild(i);
		int smallest;
		if (left <= storage2.size()-1 && storage2.get(left).V.compareTo(storage2.get(i).V) < 0)
			smallest = left;
		else
			smallest = i;
		if (right <= storage2.size()-1 && storage2.get(right).compareTo(storage2.get(smallest)) < 0)
			smallest = right;
		if (smallest != i) {
			swap(storage2, i, smallest);
			minHeapify(storage2, smallest);
		}
	}
 // Return the index of the left child of node i.
 	private static int leftChild(int i) {
 		return 2*i + 1;
 	}

 	// Return the index of the right child of node i.
 	private static int rightChild(int i) {
 		return 2*i + 2;
 	}

}// end of the class