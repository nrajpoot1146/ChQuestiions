import java.util.NoSuchElementException;

public class SinglyLinkedList {
    protected Node start;
    protected Node end;
    public int size;

    /* Constructor */
    public SinglyLinkedList() {
        start = null;
        end = null;
        size = 0;
    }

    /* Function to check if list is empty */
    public boolean isEmpty() {
        return start == null;
    }

    /* Function to get size of list */
    public int getSize() {
        return size;
    }

    /* Function to insert an element at beginning */
    public void insertAtStart(int val) {
        Node newnode = new Node(val, null);
        size++;
        if (start == null) {
            start = newnode;
            end = start;
        } else {
            newnode.setLink(start);
            start = newnode;
        }
    }

    /* Function to insert an element at end */
    public void insertAtEnd(int val) {
        Node newnode = new Node(val, null);
        size++;
        if (start == null) {
            start = newnode;
            end = start;
        } else {
            end.setLink(newnode);
            end = newnode;
        }
    }

    /* Function to insert an element at position */
    public void insertAtPos(int val, int pos) {
        Node newnode = new Node(val, null);
        Node ptr = start;
        pos = pos - 1;
        for (int i = 1; i < size; i++) {
            if (i == pos) {
                Node tmp = ptr.getLink();
                ptr.setLink(newnode);
                newnode.setLink(tmp);
                break;
            }
            ptr = ptr.getLink();
        }
        size++;
    }

    /* Function to delete an element at position */
    public void deleteAtPos(int pos) {
        if (pos == 1) {
            start = start.getLink();
            size--;
            return;
        }
        if (pos == size) {
            Node s = start;
            Node t = start;
            while (s != end) {
                t = s;
                s = s.getLink();
            }
            end = t;
            end.setLink(null);
            size--;
            return;
        }
        Node ptr = start;
        pos = pos - 1;
        for (int i = 1; i < size - 1; i++) {
            if (i == pos) {
                Node tmp = ptr.getLink();
                tmp = tmp.getLink();
                ptr.setLink(tmp);
                break;
            }
            ptr = ptr.getLink();
        }
        size--;
    }

    /* Function to display elements */
    public void display() {
        System.out.print("\nSingly Linked List = ");
        if (size == 0) {
            System.out.print("empty\n");
            return;
        }
        if (start.getLink() == null) {
            System.out.println(start.getData());
            return;
        }
        Node ptr = start;
        System.out.print(start.getData() + "->");
        ptr = start.getLink();
        while (ptr.getLink() != null) {
            System.out.print(ptr.getData() + "->");
            ptr = ptr.getLink();
        }
        System.out.print(ptr.getData() + "\n");
    }
    
    /**
     * 
     * @param index position at we want to set the value
     * @param value
     */
    public void set(int index, int value) {
    	Node temp = this.start;
    	if(this.isEmpty()) {
    		throw new NoSuchElementException("Error: linked list is empty.");
    	}
    	int i=0;
    	for(i=0; i<this.size; i++) {
    		if(i == index) {
    			temp.data = value;
    			break;
    		}
    		temp = temp.getLink();
    	}
    	if(i == this.size) {
    		throw new IndexOutOfBoundsException("Error: no index found");
    	}
    }
    
    /**
     * 
     * @return minimum value present in linkedlist
     */
    public int min() {
    	if(this.isEmpty()) {
    		throw new NoSuchElementException("Error: linked list is empty");
    	}
    	
    	int min = this.start.getData();
    	int i=1;
    	Node temp = this.start.getLink();
    	while(i<this.size) {
    		if(min > temp.getData()) {
    			min = temp.getData();
    		}
    		temp = temp.getLink();
    		i++;
    	}
    	
    	return min;
    }
    
    /**
     * 
     * @return true if linked list is sorted in nondecreasing order  otherwise return false
     */
    public boolean isSorted() {
    	int i = 0;
    	Node temp = this.start;
    	while(i<this.size -1) {
    		if(temp.getData() > temp.getLink().getData()) {
    			return false;
    		}
    		temp = temp.getLink();
    		i++;
    	}
    	
    	return true;
    }
    
    /**
     * 
     * @param value
     * @return index form last node of given value
     */
    public int indexOf(int value) {
    	int i = 0;
    	int res = -1;
    	Node temp = this.start;
    	while(i < this.size) {
    		if(value == temp.getData()) {
    			res = i;
    		}
    		temp = temp.getLink();
    		i++;
    	}
    	return res;
    }

    class Node {
        protected int data;
        protected Node link;

        /* Constructor */
        public Node() {
            link = null;
            data = 0;
        }

        /* Constructor */
        public Node(int d) {
            data = d;
            link = null;
        }

        /* Constructor */
        public Node(int d, Node n) {
            data = d;
            link = n;
        }

        /* Function to set link to next Node */
        public void setLink(Node n) {
            link = n;
        }

        /* Function to set data to current Node */
        public void setData(int d) {
            data = d;
        }

        /* Function to get link to next node */
        public Node getLink() {
            return link;
        }

        /* Function to get data from current Node */
        public int getData() {
            return data;
        }
    }
}