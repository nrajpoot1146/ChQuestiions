abstract public class IntContainer implements Comparable<IntContainer>, Randomizable{
    protected int size;
    protected final static int MaxCapacity = 16;

    IntContainer(){
        this.size = 0;
    }
    @Override
    abstract public int compareTo(IntContainer o);
    /**
     * saves "x" at given index "pos"
     * @param x
     * @param pos
     */
    abstract void set(int x, int pos);

    /**
     * retrieves element at position "pos"
     */
    abstract int get(int pos);

    /**
     * returns all element in  the intContainer in a single string
     */
    @Override
    abstract public String toString();

    /**
     * check equality of all elements in two IntContainer objects.
     */
    @Override
    abstract public boolean equals(Object obj);
}
