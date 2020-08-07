import java.util.LinkedList;

public class Stack<T> {
    private T[] data;
    private int capacity;
    private int top;
    private LinkedList<T> linkedList;

    /**
     * parameterize constructor
     * @param capacity max capacity of stack
     */
    Stack(int capacity){
        this.data = (T[]) new Object[capacity];
        linkedList = new LinkedList<>();
        this.capacity = capacity;
        this.top = -1;
    }

    /**
     * check stack is empty or not
     * @return true if stack is empty otherwise return false
     */
    boolean isEmpty(){
        return this.top == -1;
    }

    /**
     * check stack is overflow or not
     * @return true is stack is overflow otherwise return falsee
     */
    boolean isOverflowed(){
        return this.top+1 == this.capacity;
    }

    /**
     * remove top element of the stack
     * @return top of the stack, if list is empty return null
     */
    public void pop(){
        if (isEmpty()){
            return;
        }

        if (this.linkedList.size()>0){
            this.linkedList.remove(linkedList.size()-1);
            return;
        }

        this.data[top] = null;
        this.top--;
        return;
    }

    /**
     * push an element into stack
     * @param item element to be push
     */
    public void push(T item){
        if (isOverflowed()){
            this.linkedList.add(item);
            return;
        }
        this.top++;
        this.data[top] = item;
    }

    /**
     * return top of the stack
     * @return if list is not empty return top of the stack otherwise return null
     */
    public T top(){
        if (isEmpty()){
            return null;
        }

        if (this.linkedList.size()>0){
            T l = this.linkedList.get(linkedList.size()-1);
            return l;
        }

        T t = this.data[top];
        return t;
    }

    /**
     * get size of stack
     * @return size of stack
     */
    public int size(){
        return this.top+1;
    }

    /**
     * get max capacity of stack
     * @return capacity of stack
     */
    public int capacity(){
        return this.capacity;
    }

    /**
     * print all elements of stack
     * highlight top of the stack with (<---) symbol
     */
    public void print(){
        for (int i=0; i<=this.top; i++){
            if (i == this.top && linkedList.size() == 0){
                System.out.println(this.data[i].toString()+" <---top");
                continue;
            }
            System.out.println(this.data[i].toString());
        }

        for (int i=0; i<linkedList.size(); i++){
            if (i == linkedList.size()-1){
                System.out.println(linkedList.get(i).toString()+" <---top");
                continue;
            }
            System.out.println(linkedList.get(i).toString());
        }
    }

    /**
     * check whether two stack is equal or not
     * @param o another stack object
     * @return true if both stack is equal otherwise return false
     */
    public boolean isEqual(Stack o){
        if (this.size() != o.size() || this.capacity != o.capacity){ // check capacity and size of stack is equal or not
            return false;
        }
        for (int i=0; i<this.size(); i++){
            T item1 = this.data[i];
            T item2 = (T) o.data[i];
            if (!item1.equals(item2)){
                return false;
            }
        }

        if (isOverflowed()){
            if (this.linkedList.size() != o.linkedList.size()){
                return false;
            }
            for (int i=0; i<linkedList.size(); i++){
                if (!this.linkedList.get(i).equals(o.linkedList.get(i))){
                    return false;
                }
            }
        }
        return true;
    }
}
