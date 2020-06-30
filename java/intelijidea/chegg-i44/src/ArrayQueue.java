import java.util.NoSuchElementException;

public class ArrayQueue implements Queue{
    private int front, back;
    private Element[] elements;
    ArrayQueue(){
        this.front = this.back = -1;
        elements = new Element[100];
    }

    /**
     * enqueue an element into stack
     * @param e element to be enqueue
     */
    public void enQueue(Element e){
        if (this.front == -1){
            this.front = 0;
            this.back = 0;
            this.elements[this.front] = e;
            return;
        }

        this.back++;
        this.elements[this.back] = e;
    }

    /**
     * dequeue element from stack
     * @return dequeued element
     */
    public Element deQueue(){
        if (queueEmpty()){
            return null;
        }
        Element e = this.elements[this.front];
        this.front++;
        if (this.back < this.front){
            this.front = this.back = -1;
        }
        return e;
    }

    /**
     *
     * @return true if queue is empty otherwise return false
     */
    public boolean queueEmpty(){
        if (this.front == -1){
            return true;
        }
        return false;
    }

    /**
     *
     * @return true if queue is full otherwise return false
     */
    public boolean queueFull(){
        if (this.back == this.elements.length-1){
            return true;
        }
        return false;
    }

    /**
     * get front value
     * @return value of front element
     */
    public int getHeadValue(){
        if (this.queueEmpty()){
            throw new NoSuchElementException();
        }
        return this.elements[this.front].getKeyValue();
    }

    /**
     * get last value of element
     * @return value of last element
     */
    public int getTailValue(){
        if (this.queueEmpty()){
            throw new NoSuchElementException();
        }
        return this.elements[this.back].getKeyValue();
    }

}