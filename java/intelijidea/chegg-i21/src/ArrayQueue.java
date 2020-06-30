import java.util.Arrays;
import java.util.NoSuchElementException;

public class ArrayQueue {
    private int[] data;
    private int size;
    private int numberOfElements;
    private int front,rear;


    /**
     *
     * @param size of data array
     */
    ArrayQueue(int size){
        this.size = size;
        this.numberOfElements = 0;
        this.data = new int[this.size];
        this.front = -1;
        this.rear = -1;
    }

    /**
     *
     * @return max size of queue
     */
    public int getSize() {
        return size;
    }

    /**
     *
     * @return total number of element stored in array queue
     */
    public int getNumberOfElements() {
        return numberOfElements;
    }

    /**
     *
     * @return front element of array queue
     */
    public int peek(){
        if(this.isEmpty()){
            throw new NoSuchElementException();
        }
        return this.data[front];
    }

    /**
     * enqueue an data in array queue
     * @param data to enqueue in array queue
     * @return true if an element add successfully otherwise return false;
     */
    public boolean enqueue(int data){
        if(this.isFull()){
            return false;
        }
        if(this.front == -1){
            this.rear = 0;
            this.front = 0;
            this.data[this.front] = data;
            this.numberOfElements++;
            return true;
        }

        if(this.rear == this.size -1 && this.front != 0){
            this.rear = 0;
            this.data[this.rear] = data;
            this.numberOfElements++;
            return true;
        }

        this.rear++;
        this.data[this.rear] = data;
        this.numberOfElements++;
        return true;
    }


    /**
     * dequeue data from array queue
     * @return an element from front of array queue if array queue is empty, throw an error
     * @throws NoSuchElementException if array queue is empty
     */
    public int deQueue(){
        if(this.isEmpty()){
            throw new NoSuchElementException();
        }

        int data = this.data[this.front];

        if(this.front == this.rear){
            this.front = this.rear = -1;
        }else if(this.front == this.size-1){
            this.front = 0;
        }else
            this.front++;

        return data;
    }

    /**
     *
     * @return true if array queue is empty otherwise return false
     */
    public boolean isEmpty(){
        if(this.front != -1){
            return false;
        }
        return true;
    }

    /**
     *
     * @return true if array queue is full otherwise return false
     */
    public boolean isFull(){
        if((this.front == 0 && this.rear == this.size-1) || (this.rear == (front-1) % (this.size-1))){
            return true;
        }
        return false;
    }

    /**
     *
     * @return an string of data array of array queue;
     */
    public String toString(){
        return Arrays.toString(this.data);
    }

}
