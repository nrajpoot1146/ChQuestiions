
public class OurLinkedList<AnyType> implements Iterable<AnyType>{

    private int theSize;
    private int modCount = 0;
    private Node<AnyType> begin;
    private Node<AnyType> end;

    public OurLinkedList()
    {
        doClear();
    }

    public void clear() {
        doClear();
    }

    private void doClear() {

        begin = new Node<AnyType> (null, null, null);
        end = new Node<AnyType> (null, begin, null);
        begin.next = end;

        theSize = 0;
        modCount++;
    }

    public int size() {
        return theSize;
    }

    public boolean isEmpty() {
        return size() == 0;
    }

    public boolean add (AnyType x) {

        add(size(), x);
        return true;

    }

    public void add(int idx, AnyType x) {
        addBefore(getNode(idx, 0, size()), x);
    }

    public AnyType get(int idx) {
        return getNode(idx).data;
    }

    public AnyType set (int idx, AnyType newVal) {
        Node<AnyType> p = getNode(idx);
        AnyType oldVal = p.data;
        p.data = newVal;
        return oldVal;
    }

    public AnyType remove(int idx) {
        return remove(getNode(idx));
    }

    public void addBefore( Node<AnyType> p, AnyType x) {
        Node<AnyType> newNode = new Node<AnyType> (x, p.prev, p);
        newNode.prev.next = newNode;
        p.prev = newNode;
        theSize++;
        modCount++;
    }

    private AnyType remove( Node<AnyType> p) {
        p.next.prev = p.prev;
        p.prev.next = p.next;
        theSize--;
        modCount++;

        return p.data;

    }

    private Node<AnyType> getNode(int idx){

        return getNode(idx, 0, size() - 1);
    }

    private Node<AnyType> getNode(int idx, int lower, int upper){

        Node<AnyType> p;

        if( idx < lower || idx > upper)
            throw new IndexOutOfBoundsException();

        if (idx < size() / 2) {
            p = begin.next;
            for (int i = 0; i < idx; i++)
                p = p.next;
        }
        else {
            p = end;
            for( int i = size(); i > idx; i--)
                p = p.prev;
        }

        return p;

    }



    public java.util.Iterator<AnyType> iterator(){
        return new OurLinkedListIterator();
    }

    private class OurLinkedListIterator implements java.util.Iterator<AnyType>{
        private Node<AnyType> current = begin.next;
        private int expectedModCount = modCount;
        private boolean ok2Remove = false;


        public boolean hasNext() {
            return current != end;
        }

        public AnyType next() {
            if (modCount != expectedModCount)
                throw new java.util.ConcurrentModificationException();
            if ( ! hasNext())
                throw new java.util.NoSuchElementException();

            AnyType nextItem = current.data;
            current = current.next;
            ok2Remove = true;
            return nextItem;
        }

    }

    /**
     * function to check two list is equal or not
     * @param list_b other list
     * @return true if equal otherwise return false
     */
    public boolean equals(OurLinkedList<AnyType> list_b) {
        if (list_b.size() != this.size()){
            return false;
        }

        for (int i=0; i<this.size(); i++){
            if (this.get(i) != list_b.get(i)){
                return false;
            }
        }
        return true;
    }

    /**
     * function to count common number of item in two list
     * @param list_b other list
     * @return an positive integer number
     */
    public int findCommons(OurLinkedList<AnyType> list_b){
        int count = 0;
        for (AnyType a : this){
            for (AnyType b : list_b){
                if (a.equals(b)){
                    count++;
                    break;
                }
            }
        }

        for (AnyType b : list_b){
            for (AnyType a : this){
                if (a.equals(b)){
                    count++;
                    break;
                }
            }
        }

        return count;
    }
}

class Node<AnyType>{

    public AnyType data;
    public Node<AnyType> prev;
    public Node<AnyType> next;
    public Node (AnyType d, Node<AnyType> p, Node<AnyType> n) {
        data = d; prev = p; next = n;
    }

    public String toString() {
        return data + "";
    }
}