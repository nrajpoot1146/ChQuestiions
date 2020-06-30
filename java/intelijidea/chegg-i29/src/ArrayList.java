/**
 * ArrayList.java
 */

public class ArrayList<E> {
    private E[] array;
    private int numElements;


    /**
     * Default constructor for ArrayList
     * Creates an empty array of length 10
     * Sets numElements to 0
     */
    @SuppressWarnings("unchecked")
    public ArrayList() {
        array = (E[]) new Object[10];
        numElements = 0;
    }

    /**
     * Constructor for ArrayList
     * Creates an empty array of length size
     * Sets numElements to 0
     * @param size the initial size of the
     * ArrayList
     */
    @SuppressWarnings("unchecked")
    public ArrayList(int size) {
        array = (E[]) new Object[size];
        numElements = 0;
    }

    /**
     * Copy constructor for ArrayList
     * Creates a new list array of the
     * same size as the ArrayList passed
     * in as a parameter, and copies the
     * parameter's data into the new
     * ArrayList using a for loop
     * Also sets the numElements to be
     * the same as the parameter's
     * numElements
     * @param la the ArrayList to copy
     */
    @SuppressWarnings("unchecked")
    public ArrayList(ArrayList<E> la) {
        this.array = (E[]) new Object[la.array.length];
        this.numElements = la.size();
        for (int i=0; i<la.numElements; i++){
            this.array[i] = la.get(i);
        }
    }

    /**
     * Returns whether the ArrayList is
     * currently empty
     * @return whether the ArrayList is
     * empty
     */
    public boolean isEmpty() {
        return this.numElements == 0;
    }

    /**
     * Returns the current number of
     * elements stored in the ArrayList
     * @return the number of elements
     */
    public int size() {
        return this.numElements;
    }

    /**
     * Returns the element at the specified
     * index. Throws an exception if index is
     * larger than or equal to numElements
     * @param index the index of the element
     * to access
     * @return the element at index
     */
    public E get(int index) throws IndexOutOfBoundsException{
        if(index >= numElements){
            throw new IndexOutOfBoundsException();
        }
        return this.array[index];
    }

    /**
     * Uses the linearSearch algorithm to
     * locate an element in the ArrayList
     * @param element the element to locate
     * @return whether or not the element
     * is in the ArrayList
     */
    public boolean contains(E element) {
        for (int i=0; i<numElements; i++){
            if(this.array[i].equals(element)){
                return true;
            }
        }
        return false;
    }

    /**
     * Uses the linearSearch algorithm to
     * locate an element in the ArrayList
     * @param element the element to locate
     * @return the location of the element
     * or -1 if the element is not in the
     * ArrayList
     */
    public int indexOf(E element) {
        for (int i=0; i<numElements; i++){
            if(this.array[i].equals(element)){
                return i;
            }
        }
        return -1;
    }

    /**
     * Determines whether the ArrayList
     * is currently full
     * @return whether the ArrayList
     * is at maximum capacity
     * Should be called by the add methods
     */
    private boolean atCapacity() {
        return numElements == array.length;
    }


    /**
     * Resizes the ArrayList by making a new
     * array that has a length (capacity)
     * 10 larger than the current array's
     * length (capacity)
     */
    @SuppressWarnings("unchecked")
    private void reSize() {
        E[] temp = (E[]) new Object[this.array.length + 10];
        for (int i = 0; i<this.array.length; i++){
            temp[i] = this.array[i];
        }
        this.array = temp;
    }

    /**
     * Inserts a new element to the end
     * of the list array.
     * Resizes the ArrayList if it is
     * at capacity before inserting
     * @param element the element to insert
     */
    public void add(E element) {
        if (this.atCapacity()){
            this.reSize();
        }
        this.array[numElements] = element;
        numElements++;
    }

    /**
     * Inserts a new element at the specified
     * index in the ArrayList.
     * Resizes the ArrayList if it is
     * at capacity before inserting
     * @param index the index at which to insert
     * @param element the element to insert
     */
    public void add(int index, E element) throws IndexOutOfBoundsException {
        if (this.atCapacity()){
            this.reSize();
        }
        for (int i = this.numElements-1; i>=index; i--){
            this.array[i+1] = this.array[i];
        }
        this.array[index] = element;
        this.numElements++;
    }

    /**
     * Assigns a new value to the ArrayList
     * at a specified index
     * @param index the index at which to update
     * @param element the new element
     */
    public void set(int index, E element) throws IndexOutOfBoundsException {
        if(this.numElements <= index){
            throw new IndexOutOfBoundsException();
        }
        this.array[index] = element;
    }

    /**
     * Removes an element at a specified index in
     * the ArrayList
     * @param index the index at which to remove
     * @return the element that was removed
     */
    @SuppressWarnings("unchecked")
    public E remove(int index) throws IndexOutOfBoundsException{
        if(index >= numElements){
            throw new IndexOutOfBoundsException();
        }
        E remvEle = this.array[index];
        for (int i = index; i<this.numElements-1; i++){
            this.array[i] = this.array[i+1];
        }
        this.numElements--;
        return remvEle;
    }

    /**
     * Removes the first instance of the specified
     * element in the list array
     * @param element the element to remove
     * @return whether the element was successfully
     * removed
     */
    public boolean remove(E element) {
        int index = this.indexOf(element);
        this.remove(index);
        return true;
    }

    /**
     * Returns whether two ArrayLists and
     * the same length and store
     * the same data in the same order
     */
    @SuppressWarnings("unchecked")
    @Override public boolean equals(Object o) {
        ArrayList arrayList = (ArrayList) o;
        if(this.numElements != arrayList.numElements || this.array.length != arrayList.array.length){
            return false;
        }
        for (int i=0; i<this.numElements; i++){
            if(!this.array[i].equals(arrayList.array[i])){
                return false;
            }
        }
        return true;
    }

    /**
     * Creates a String of all elements,
     * with [] around the elements,
     * each element separated from the next
     * with a comma
     */
    @Override public String toString() {
        String result = "[";
        for (int i=0; i<this.numElements; i++){
            result += (i == 0 ? this.array[i] : ", "+this.array[i]);
        }
        return result + "]";
    }

}