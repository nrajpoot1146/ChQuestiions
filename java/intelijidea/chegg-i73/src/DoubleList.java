public class DoubleList<T> {
    private DoubleNode<T> front;
    private DoubleNode<T> rear;
    private int count;

    /**
     * default constructor
     * sets
     * front = null
     * rear = null
     * count = 0
     */
    DoubleList(){
        this.front = null;
        this.rear = null;
        this.count = 0;
    }

    /**
     * add an element to next element of rear
     * @param ele element to be add
     */
    public void addToRear(T ele){
        DoubleNode<T> newNode = new DoubleNode<>(ele); // create a node
        this.count++;
        if (isEmpty()){
            this.rear = this.front = newNode;
            return;
        }

        this.rear.setNext(newNode);
        newNode.setPrevious(this.rear);
        this.rear = newNode;
    }

    /**
     * traverse list from front to back
     * @param n number of element to traverse
     * @return ends node
     */
    public DoubleNode traverseForwards(int n){
        if (isEmpty())
            return null;
        DoubleNode curr = this.front;
        for (int i=0; i<n && curr != null; i++){
            curr = curr.getNext();
        }

        return curr;
    }

    /**
     * traverse list from back to front
     * @param n number of element to traverse
     * @return ends node
     */
    public DoubleNode traverseBackwards(int n){
        if (isEmpty())
            return null;
        DoubleNode curr = this.rear;
        for (int i=0; i<n && curr != null; i++){
            curr = curr.getPrevious();
        }

        return curr;
    }

    /**
     * get node at given index
     * @param index of node
     * @return node element
     */
    public DoubleNode<T> getNode(int index) {
        if (isEmpty())
            return null;
        if (index > count - 1 || index < 0){
            throw new DoubleListException();
        }

        int mid = count / 2;
        if (index < mid){
            return this.traverseForwards(index);
        }else {
            return this.traverseBackwards(count-1-index);
        }
    }

    /**
     * set element at given index
     * @param index, position to set a node
     * @param ele element to be set
     */
    public void setElement(int index, T ele){
        DoubleNode node = getNode(index);
        node.setElement(ele);
    }

    /**
     * get element at given index
     * @param index of node
     * @return element of search index
     */
    public T getElement(int index){
        return this.getNode(index).getElement();
    }

    /**
     * generate a string of element of list node
     * @return string of list
     */
    public String toString(){
        if (this.isEmpty()){
            return "Empty list";
        }

        DoubleNode curr = this.front;
        StringBuilder stringBuilder = new StringBuilder();
        while (curr != null){
            stringBuilder.append(curr.getElement());
            stringBuilder.append(" ");
            curr = curr.getNext();
        }

        return stringBuilder.toString();
    }

    /**
     * check whether list is empty or not
     * @return true if list is empty otherwise return false
     */
    public boolean isEmpty(){
        return this.front == null;
    }
}
