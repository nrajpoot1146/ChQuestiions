import java.util.Iterator;
import java.util.NoSuchElementException;

public class LinkedList<E> implements Iterable<E>{
    private Node head;
    private Node tail;
    private int size;

    LinkedList(){
        this.head = null;
        this.tail = null;
        this.size = 0;
    }

    /**
     *
     * @param data data value to be insert in linked list
     */
    void add(E data){
        Node newNode = new Node(data);
        if(this.head == null){
            this.head = newNode;
            this.tail = newNode;
            this.size++;
            return;
        }
        this.tail.next = newNode;
        this.tail = newNode;
        this.size++;
    }

    /**
     *
     * @param n remove a node from list
     */
    void remove(Node n){
        if(n == this.head){
            this.head = this.head.next;
            this.size--;
            return;
        }
        Node current = this.head.next;
        Node prev = this.head;
        while (current != null){
            if(current == n){
                prev.next = current.next;
                return;
            }
            prev = current;
            current = current.next;
        }
        this.size--;
    }

    @Override
    public Iterator<E> iterator() {
        return new LinkedIterator<>(this.head);
    }


    class Node<E>{
        Node next;
        E data;
        Node(E data, Node next){
            this.data = data;
            this.next = next;
        }
        Node(E data){
            this.data = data;
            this.next = null;
        }
    }

    class LinkedIterator<E> implements Iterator<E>{
        private Node currentNode;

        LinkedIterator(Node<E> head){
            this.currentNode = head;
        }

        @Override
        public boolean hasNext() {
            return this.currentNode != null;
        }

        @Override
        public void remove() {
            if(this.hasNext()){
                LinkedList.this.remove(this.currentNode);
                LinkedList.this.size--;
            }else{
                throw new IllegalStateException();
            }
        }

        @Override
        public E next() {
            if(!this.hasNext()){
                throw new NoSuchElementException();
            }
            E data = (E) this.currentNode.data;
            this.currentNode = this.currentNode.next;
            return data;
        }
    }
}
