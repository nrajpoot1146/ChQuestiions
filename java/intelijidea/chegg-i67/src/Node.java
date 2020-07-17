public class Node<E> {
    E data;
    Node next;
    Node prev;

    Node(E data){
        this.data = data;
        this.next = null;
        this.prev = null;
    }
}
