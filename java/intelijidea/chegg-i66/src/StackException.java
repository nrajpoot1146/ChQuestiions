public class StackException extends Exception{
    private int size;

    /**
     * constructor with parameter size
     * @param size of stack
     */
    StackException(int size){
        this.size = size;
    }

    /**
     * size of stack
     * @return size of stack
     */
    public int getSize() {
        return size;
    }
}
