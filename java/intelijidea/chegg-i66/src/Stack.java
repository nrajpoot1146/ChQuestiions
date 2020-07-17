public class Stack<T >{
    private T[] items;
    private int top;

    /**
     * Default constructor
     */
    Stack(){
        items = (T[]) new Object[2];
        this.top = -1;
    }

    /**
     * Parameterize constructor
     * @param size of stack
     */
    Stack(int size){
        items = (T[]) new Object[size];
        this.top = -1;
    }

    /**
     * remove top of the stack
     * @return top of the stack
     */
    T pop(){
        return this.items[top--];
    }

    /**
     * check stack is empty or not
     * @return true if stack is empty otherwise return false
     */
    public boolean isEmpty(){
        return this.top == -1;
    }

    /**
     * push an element into stack
     * @param item element to be push
     * @throws StackException throws an exception if stack is full
     */
    void push(T item) throws StackException{
        if (this.top + 1 < this.items.length){
            this.items[++top] = item;
            return;
        }
        throw new StackException(this.items.length);
    }

}
