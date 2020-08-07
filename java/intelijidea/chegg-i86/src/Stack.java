
public class Stack {
    private user[] data;
    private int capacity;
    private int top;

    /**
     * parameterize constructor
     * @param capacity max capacity of stack
     */
    Stack(int capacity){
        this.capacity = capacity;
        this.top = -1;
        this.data = new user[this.capacity];
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
    public user pop(){
        if (isEmpty()){
            return null;
        }
        user t = this.data[top];
        this.data[top] = null;
        this.top--;
        return t;
    }

    /**
     * push an element into stack
     * @param us element to be push
     */
    public void push(user us){
        if (isOverflowed()){
            throw new StackOverflowError();
        }
        this.top++;
        this.data[top] = us;
    }

    /**
     * return top of the stack
     * @return if list is not empty return top of the stack otherwise return null
     */
    public user top(){
        if (isEmpty()){
            return null;
        }
        return this.data[top];
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
            if (i == this.top){
                System.out.println(this.data[i].toString()+" <---top");
                continue;
            }
            System.out.println(this.data[i].toString());
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
            user us1 = this.data[i];
            user us2 = o.data[i];
            if (!us1.equals(us2)){
                return false;
            }
        }
        return true;
    }
}
