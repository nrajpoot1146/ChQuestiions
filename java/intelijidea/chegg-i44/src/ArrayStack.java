
import java.util.EmptyStackException;

public class ArrayStack implements Stack{
    private int size;
    private Element[] elements;
    ArrayStack(){
        this.size = 0;
        elements = new Element[100];
    }

    /**
     * push an element into stack
     * @param e element to push
     */
    public void push(Element e){
        if (this.stackFull()){
            throw new StackOverflowError();
        }
        this.elements[size] = e;
        this.size++;
    }

    /**
     * pop an element from stack
     * @return popped element
     */
    public Element pop(){
        if (stackEmpty()){
            throw new EmptyStackException();
        }
        this.size--;
        return this.elements[size];
    }

    /**
     * check stack is empty or not
     * @return true if stack is empty otherwise return false
     */
    public boolean stackEmpty(){
        if (size == 0){
            return true;
        }
        return false;
    }

    /**
     * check stack is full or not
     * @return true if stack ic full otherwise return false
     */
    public boolean stackFull(){
        if (size == elements.length){
            return true;
        }
        return false;
    }

    /**
     * get top of stack
     * @return top of stack
     */
    public int getTopValue(){
        if (!this.stackEmpty()){
            this.elements[size-1].getKeyValue();
        }
        throw new EmptyStackException();
    }

    /**
     *
     * @return size of stack
     */
    public int size() {
        return size;
    }

    @Override
    public String toString() {
        StringBuilder res = new StringBuilder();
        res.append("[");
        for (int i=0; i<this.size; i++){
            res.append(elements[i].getKeyValue());
            if (i != this.size-1){
                res.append(", ");
            }
        }
        res.append("]");
        return res.toString();
    }
}