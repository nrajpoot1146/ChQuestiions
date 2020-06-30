public class ArrayList<Type> {
    private int size;
    private Node<Type> head;
    private Node<Type> last;
    ArrayList(){
        this.size = 0;
        head = null;
        last = null;
    }

    public void add(Type ele){
        if(head == null){
            this.head = new Node<Type>(ele,null);
            this.last = this.head;
            this.size++;
            return;
        }
        Node<Type> node = new Node<Type>(ele,null);
        this.last.next = node;
        this.last = node;
        this.size++;
    }

    public void remove(int index){
        if(index > this.size){
            return;
        }else if(index == 0){
            this.head = this.head.next;
            this.size--;
            if(this.size == 0){
                this.head = this.last = null;
            }
            return;
        }
        int i=0;

        Node<Type> temp = this.head;
        Node<Type> prevTemp = temp;
        while(i != index){
            prevTemp = temp;
            temp = temp.next;
            i++;
        }

        prevTemp.next = temp.next;
        this.size--;

    }

    public Type get(int index){
        if(index>this.size){
            return null;
        }
        int i = 0;
        Node<Type> temp = this.head;
        while (i != index){
            temp = temp.next;
            i++;
        }
        return temp.info;
    }

    public int size(){
        return this.size;
    }

    class Node<E>{
        public E info;
        public Node<E> next;

        Node(E info, Node<E> node){
            this.info = info;
            this.next  = null;
        }
    }
}
