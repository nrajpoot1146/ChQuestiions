import java.util.Collection;

public class LinkedListDS<E> {
    private Node<E> head;
    private Node<E> tail;
    private int numElements;

    /**
     * Appends the specified element to the end of this DS.
     * @param e
     */
    public void add(E e){
        Node<E> newNode = new Node(e);
        this.numElements++;
        if (isEmpty()){
            this.head = this.tail = newNode;
            return;
        }

        this.tail.next = newNode;
        newNode.prev = tail;
        this.tail = newNode;
    }

    /**
     * Inserts the specified element at the specified position in this DS.
     * @param index
     * @param element
     */
    public void add(int index, E element){
        Node<E> newNode = new Node(element);
        this.numElements++;
        int i = 0;
        Node curr = this.head;
        while (i != index && curr != null){
            i++;
            curr = curr.next;
        }
        if (i == 0){
            this.head.prev = newNode;
            newNode.next = this.head;
            this.head = newNode;
            return;
        }

        newNode.next = curr;
        newNode.prev = curr.prev;
        curr.prev.next = newNode;
        curr.prev = newNode;
    }

    /**
     * Appends all of the elements in the specified collection to the end of
     * this DS, in the order that they are held by the specified collection.
     * @param c
     * @return
     */
    public void addAll(Collection<? extends E> c){
        for (E e : c){
            this.add(e);
        }
    }

    /**
     * Inserts all of the elements in the specified collection into this list
     * at the specified position.
     * @param index
     * @param c
     * @return
     */
    public void addAll(int index, Collection<? extends E> c){
        for (E e : c){
            this.add(index, e);
        }
    }

    /**
     * Removes all of the elements from this DS.
     */
    public void clear(){
        this.head = this.tail = null;
        numElements = 0;
    }

    /**
     * Returns true if this DS contains the specified element.
     * @param o
     * @return
     */
    public boolean contains(Object o){
        Node<E> curr = this.head;
        while (curr != null){
            if (curr.data.equals(o)){
                return true;
            }
            curr = curr.next;
        }
        return false;
    }

    /**
     * Returns true if this list contains all of the elements of the specified
     * collection.
     * @param c
     * @return
     */
    public boolean containsAll(Collection<?> c){
        Node<E> curr = this.head;
        Object[] array = c.toArray();
        int  i = 0;
        while (curr != null && i != c.size()){
            if (curr.data.equals(array[i])){
                i++;
            }
            curr = curr.next;
        }
        if (i == array.length){
            return true;
        }
        return false;
    }


    /**
     * Returns the element at the specified position in this DS.
     * @param index
     * @return
     */
    public E get(int index){
        Node<E> curr = this.head;
        int i = 0;
        while (curr != null){
            if (i == index){
                return curr.data;
            }
            curr = curr.next;
        }
        return null;
    }

    /**
     * Returns the index of the first occurrence of the specified element in
     * this DS, or -1 if this list does not contain the element.
     * @param o
     * @return
     */
    public int indexOf(Object o){
        Node<E> curr = this.head;
        int i = 0;
        while (curr != null){
            if (curr.data.equals(o)){
                return i;
            }
            i++;
            curr = curr.next;
        }
        return 0;
    }

    /**
     * Returns true if this list contains no elements.
     * @return
     */
    public boolean isEmpty(){
        return this.head == null;
    }

    /**
     * Removes the element at the specified position in this DS.
     * @param index
     * @return
     */
    public E remove(int index){
        Node<E> curr = this.head;
        int i = 0;
        while (curr != null){
            if (i == index){
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                return curr.data;
            }
            curr = curr.next;
        }
        return null;
    }

    /**
     * Removes the first occurrence of the specified element from this DS,
     * if it is present.
     * @param o
     * @return
     */
    public void remove(Object o){
        Node<E> curr = this.head;
        while (curr != null){
            if (curr.equals(o)){
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                return;
            }
            curr = curr.next;
        }
    }

    /**
     * Removes from this DS all of its elements that are contained in the
     * specified collection.
     * @param c
     * @return
     */
    public void   removeAll(Collection<?> c){
        Node<E> curr = this.head;
        while (curr != null){
            if (curr.equals(o)){
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                return;
            }
            curr = curr.next;
        }
    }

    /**
     * Retains only the elements in this DS that are contained in the specified
     * collection.
     * @param c
     * @return
     */
    public void retainAll(Collection<?> c){
    }

    /**
     * Replaces the element at the specified position in this DS with the
     * specified element.
     * @param index
     * @param element
     * @return
     */
    public void set(int index, E element){

    }

    /**
     * Returns the number of elements in this DS.
     * @return
     */
    public int   size(){
        return 0;
    }
}