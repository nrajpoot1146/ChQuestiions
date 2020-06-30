import org.w3c.dom.Node;

import java.util.Arrays;
import java.util.Iterator;
import java.util.NoSuchElementException;

public class ArrayList<E> implements Iterable<E>{
    private int size;
    private E[] data;
    public static int DEFAULT_CAPACITY = 10;


    public ArrayList() {
        this(DEFAULT_CAPACITY);
    }

    @SuppressWarnings("unchecked")
    public ArrayList(int capacity) {
        if(capacity <=0) {
            throw new IllegalArgumentException("capacity must be positive "+capacity);

        }
        size = 0;
        data = (E[]) (new Object[capacity]);
    }

    public ArrayList(ArrayList<E> other) {
        this.size = other.size;
        this.data = other.data;
    }

    public boolean add(E item) {
        ensureCapacity(size + 1);
        data[size++] = item;
        return true;

    }

    public void add(int index, E value) {
        checkIndex(index);
        for (int i = size; i > index; i--) {
            data[i] = data[i - 1];
        }


        data[index] = value;
        size++;
    }

    private void checkIndex(int index) {
        if (index < 0 || index >= size) {
            throw new IndexOutOfBoundsException("index: " + index);
        }
    }

    public void clear() {
        for (int i = 0; i < size; i++) {
            data[i] = null;
        }

        size = 0;
    }

    public boolean contains(E value) {
        return indexOf(value) >= 0;
    }


    @SuppressWarnings ("unchecked")
    public void ensureCapacity(int minCapacity) {
        int oldCapacity = data.length;
        int newCapacity = oldCapacity + (oldCapacity >> 1);
        if (newCapacity - minCapacity < 0)
            newCapacity = minCapacity;

        for ( int i = 0; i < oldCapacity;i++ ) {
            data = Arrays.copyOf(data, newCapacity);
        }
    }

    public boolean equals(ArrayList<E> other) {
        boolean equal = true;
        if (this.size == other.size) {
            for(int i = 0; i < size ; i++) {
                equal = this.data[i].equals(other.data[i]) ;
                if (equal == false) {
                    return equal;
                }
            }
        }
        return equal;

    }

    public E get(int index) {
        checkIndex(index);
        return data[index];
    }

    public int indexOf(E value) {
        if (value == null) {
            for (int i = 0; i < size; i++)
                if (data[i]==null)
                    return i;
        } else {
            for (int i = 0; i < size; i++)
                if (value.equals(data[i]))
                    return i;
        }
        return -1;
    }

    public boolean isEmpty() {
        return size == 0;
    }

    public E remove(int index) {
        checkIndex(index);
        E item = this.data[index];
        this.shiftLeft(index);
        this.size--;
        return item;
    }

    public boolean remove(E item) {
        boolean remove = false;
        int i = 0;
        while(!remove&& i < size) {
            if(item == this.data[i]) {
                remove = true;
                this.remove(i);
            }
        }
        return remove;
    }

    public E set(int index, E item) {
        checkIndex(index);
        return this.data[index] = item;
    }

    private void shiftLeft(int index) {
        checkIndex(index);
        for (int i = index; i < this.size - 1; i++) {
            this.data[i] = this.data[i + 1];
        }
    }

    private void shiftRight(int index) {

    }

    public int size() {
        return this.size;
    }

    public String toString() {
        if (size == 0) {
            return "[]";
        } else {
            String result = "[" + data[0];
            for (int i = 1; i < size; i++) {
                result += ", " + data[i];
            }
            result += "]";
            return result;
        }
    }

    @Override
    public Iterator<E> iterator() {
        return new ArrayIterator<E>(this.data);
    }

    /**
     *
     * @param <E>
     */
    class ArrayIterator<E> implements Iterator<E>{
        private E[] data;
        int cursor;

        ArrayIterator(E[] data){
            this.data = data;
            this.cursor = 0;
        }

        /**
         * remove current element
         */
        @Override
        public void remove() {
            if(!hasNext()){
                throw new IllegalStateException();
            }
            ArrayList.this.remove(cursor);
        }

        /**
         *
         * @return return true if list has next element otherwise return false
         */
        @Override
        public boolean hasNext() {
            return cursor<ArrayList.this.size();
        }

        /**
         *
         * @return next data
         */
        @Override
        public E next() {
            if(!this.hasNext()){
                throw new NoSuchElementException();
            }
            E temp = data[this.cursor];
            cursor++;
            return temp;
        }
    }
}