package ch05.collections;

public class SortedArrayCollection<T> implements CollectionInterface<T> {
    protected final int DEFCAP = 100; // default capacity
    protected int origCap;           // original capacity
    protected T[] elements;          // array to hold collection elements
    protected int numElements = 0;   // number of elements in this collection
    // set by find method
    protected boolean found; // true if target found, otherwise false
    protected int location;  // indicates location of target if found,
    // indicates add index if not found

    public SortedArrayCollection() {
        elements = (T[]) new Object[DEFCAP];
        origCap = DEFCAP;
    }

    public SortedArrayCollection(int capacity) {
        elements = (T[]) new Object[capacity];
        this.origCap = capacity;
    }

    protected void enlarge()
    // Increments the capacity of the collection by an amount
    // equal to the original capacity.
    {
        // Create the larger array.
        T[] larger = (T[]) new Object[elements.length + origCap];
        // Copy the contents from the smaller array into the larger array.
        for (int i = 0; i < numElements; i++) {
            larger[i] = elements[i];
        }
        // Reassign elements reference.
        elements = larger;
    }
    protected void find(T target)
    // Searches elements for an occurrence of an element e such that
    // e.equals(target). If successful, sets instance variables
    // found to true and location to the array index of e. If
    // not successful, sets found to false and location to the
    // array index where target should be inserted.
    {
        location = 0;
        found = false;
        if (!isEmpty())
            recFind(target, 0, numElements - 1);
    }

    protected void recFind(T target, int first, int last)
    // Used by find.
    {
        int result;      // result of the comparison
        if (first > last)
        {
            found = false;
            result = ((Comparable)target).compareTo(elements[location]);
            if (result > 0)
                location++;   // adjust location to indicate insert index
        }
        else
        {
            location = (first + last) / 2;
            result = ((Comparable)target).compareTo(elements[location]);
            if (result == 0) // found target
                found = true;
            else
            if (result > 0)  // target too high
                recFind(target, location + 1, last);
            else              // target too low
                recFind(target, first, location - 1);
        }
    }

    public boolean add(T element)
    // Precondition: element is Comparable to previously added objects
    //
    // Adds element to this collection.
    {
        if (numElements == elements.length)
            enlarge();
        find(element); // sets location to index where element belongs
        for (int index = numElements; index > location; index--)
            elements[index] = elements[index - 1];
        elements[location] = element;
        numElements++;
        return true;
    }

    public boolean remove (T target)
    // Removes an element e from this collection such that e.equals(target)
    // and returns true; if no such element exists, returns false.
    {
        find(target);
        if (found)
        {
            for (int i = location; i <= numElements - 2; i++)
                elements[i] = elements[i+1];
            elements[numElements - 1] = null;
            numElements--;
        }
        return found;
    }

    public int size()
    // Returns the number of elements on this collection.
    {
        return numElements;
    }

    public boolean contains (T target)
    // Returns true if this collection contains an element e such that
    // e.equals(target); otherwise, returns false.
    {
        find(target);
        return found;
    }

    public T get(T target)
    // Returns an element e from this collection such that e.equals(target);
    // if no such element exists, returns null.
    {
        find(target);
        if (found)
            return elements[location];
        else
            return null;
    }

    public boolean isEmpty()
    // Returns true if this collection is empty; otherwise, returns false.
    {
        return (numElements == 0);
    }

    public boolean isFull()
    // This collection is unbounded so always returns false.
    {
        return false;
    }

    // return smallest element of SortedArrayCollection
    public T smallest(){
        if (isEmpty()){
            return null;
        }
        else
            return this.elements[0];
    }

    // return number of elements which are greater than given element
    public int greater(T ele){
        int count = 0;
        for (int i=0; i<this.numElements; i++){
            if (((Comparable) this.elements[i]).compareTo(((Comparable)ele)) > 0){
                count++;
            }
        }
        return count;
    }

    // combine two SortedArrayCollection in sorted order and return new
    public SortedArrayCollection<T> combine(SortedArrayCollection<T> sc){
        int i=0;
        int j=0;
        SortedArrayCollection<T> newSC = new SortedArrayCollection<>(this.numElements + sc.numElements);
        while (i < this.numElements && j < sc.numElements){
            if (((Comparable) this.elements[i]).compareTo(((Comparable)sc.elements[j])) < 0){
                newSC.add(this.elements[i]);
                i++;
            }else {
                newSC.add(sc.elements[j]);
                j++;
            }
        }

        while (i < this.numElements){
            newSC.add(this.elements[i]);
            i++;
        }

        while (j < this.numElements){
            newSC.add(this.elements[j]);
            j++;
        }

        return newSC;
    }

    // generate string and return
    public String toString(){
        StringBuffer stringBuffer = new StringBuffer();
        for (int i=0; i<this.numElements; i++){
            stringBuffer.append(this.elements[i].toString());
            if (i != this.numElements -1){
                stringBuffer.append(", ");
            }
        }
        return stringBuffer.toString();
    }

}