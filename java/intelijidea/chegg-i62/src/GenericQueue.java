import java.util.LinkedList;

public class GenericQueue<E> extends LinkedList<E> {

    /**
     * default constructor
     */
    GenericQueue(){
        super();
    }

    /**
     * enqueue an element to current queue
     * @param e element to enqueue
     */
    public void enqueue(E e){
        this.add(e);
    }

    /**
     * dequeue an element from current queue
     * @return de-queued element if queue is not empty otherwise return null;
     */
    public E dequeue(){
        if (this.size() > 0){ // condition to check queue is empty or not
            E item = this.get(0); // read front variable
            this.remove(0); // remove de-queued element
            return item;
        }

        return null;
    }

    /**
     * size of current queue
     * @return size;
     */
    public int getSize(){
        return this.size();
    }
}
