

public class MyLinkedList {

    /**
     * private class node
     * represent a single node of linkedlist
     */
    private class Node {
        String value;
        Node next;

        /**
         * overloaded Constructor
         * @param value of node
         */
        public Node(String value){
            this.value = value;
            this.next = null;
        }

        /**
         * overloaded constructor
         * sets value
         * sets next
         * @param value to store
         * @param next link to next pointer
         */
        public Node(String value, Node next){
            this.value = value;
            this.next = next;
        }
    }

    Node first;
    Node last;
    Node pointer;
    int numElements;

    /**
     * Default constructor
     * set first and next to null
     * set numElements to 0
     */
    public MyLinkedList(){
        this.first = this.last = null;
        this.numElements = 0;
    }

    /**
     * check current list is empty or not
     * @return if list is empty return true otherwise return false
     */
    public boolean isEmpty(){
        return this.first == null;
    }

    /**
     * append an element to the list
     * @param s
     */
    public void add(String s){
        if (isEmpty()){
            first = last = new Node(s);
            this.pointer = this.first;
        }else {
            last.next = new Node(s);
            last = last.next;
        }
        this.numElements++;
    }

    /**
     * search an element in current list
     * use iterative method
     * @param t to be search
     * @return true if element is found otherwise return false
     */
    private boolean findI(String t){
        Node d = first;
        while (d != null){
            if (d.value.equals(t)){
                return true;
            }
            d = d.next;
        }
        return false;
    }

    /**
     * search an element in current list
     * use recursive method
     * @param t to be search
     * @return true if element is found otherwise return false
     */
    private boolean findR (String t, Node d){
        if (d == null){
            return false;
        }else if (d.value.equals(t))
            return true;
        else
            return findR(t, d.next);
    }

    /**
     * search an element in current list
     * call recursive method
     * @param t to be search
     * @return true if element is found otherwise return false
     */
    public boolean find(String t){
        return findR(t, first);
    }

    /**
     * print value of current linked list
     */
    public void print(){
        Node d = first;
        while (d != null){
            System.out.println(d.value+" ");
            d = d.next;
        }
        System.out.println();
    }

    /**
     * print all value of current linked list
     */
    public void printAll(){
        Node d = first;
        System.out.print("[");
        while (d != null){
            System.out.print(d.value);
            if (d.next != null){
                System.out.print(", ");
            }
            d = d.next;
        }
        System.out.print("]");
    }

    /**
     * get frequency of given value in current linked list
     * @param t
     * @return count
     */
    public int getNumberOfOccurrences(String t){
        int count = 0;
        Node d = first;
        while (d != null){
            if (d.value.equals(t)){
                count++;
            }
            d = d.next;
        }
        return count;
    }

    /**
     * add node to middle of linked list
     * @param s to be add
     */
    public void addToTheMiddle(String s){
        Node newNode = new Node(s);
        Node d = first;
        int middle = this.numElements / 2;
        int i=0;
        while (d != null){
            if (i == middle){
                break;
            }
            d = d.next;
        }
        newNode.next = d.next;
        d.next = newNode;
    }

    /**
     * create reverse of current list
     * @return reverse list of current list
     */
    public MyLinkedList createAndReverse(){
        MyLinkedList newList = new MyLinkedList();
        Node d = first;
        while (d != null){
            Node newNode = new Node(d.value, newList.first);
            newList.first = newNode;
            if (newList.last == null){
                newList.last = newNode;
            }
            d = d.next;
        }

        return newList;
    }

    /**
     * reset pointer to first node
     */
    public void resetPointer(){
        this.pointer = this.first;
    }

    /**
     * get current pointer node value
     * @return string
     */
    public String getCurr(){
        if (pointer == null){
            return null;
        }
        String s = pointer.value;
        pointer = pointer.next;
        return s;
    }

}
