public class Train {
    private Node head;
    private Node tail;

    Train(){
        this.add(new Node("engine"));
    }

    /**
     *
     * @param node add car node at the end of linked list
     */
    public void add(Node node){
        if(this.isEmpty()){
            this.head = node;
            this.tail = node;
            return;
        }
        this.tail.next = node;
        node.previous = this.tail;
        this.tail = node;
    }

    /**
     *
     * @param node as a engine and add at the front of linked list
     */
    public void addEngine(Node node){
        node.next = this.head;
        this.head.previous = node;
        this.head = node;
    }

    /**
     * frop first n cars
     * @param n number of element to be drop
     */
    public void dropFirst(int n){
        if(isEmpty()){
            return;
        }
        Node current = this.head;
        int i = 0;
        while (current != null && i<n){
            if(current.car.name.equals("engine")){
                current = current.next;
                continue;
            }
            current.previous.next = current.next;
            if(current.next != null) {
                current.next.previous = current.previous;
                current = current.next;
            }
            else {
                this.tail = current.previous;
                break;
            }
            i++;
        }
    }

    /**
     * drop last n car
     * @param n number of car to be drop
     */
    public void dropLast(int n){
        if(isEmpty()){
            return;
        }
        for(int i = 0 ;i<n; i++){
            if (tail.car.name.equals("engine")){
                break;
            }
            this.tail = this.tail.previous;
            this.tail.next = null;
        }
    }

    /**
     * drop n specific car name with
     * @param name car name
     * @param n number to be drop
     */
    public void drop(String name, int n){
        if(isEmpty()){
            return;
        }
        Node current = this.head;
        int i = 0;
        while (current != null && i<n){

            if(current.car.name.equals(name)){
                current.previous.next = current.next;
                if(current.next != null)
                    current.next.previous = current.previous;
                else{
                    this.tail = current;
                }
                i++;
            }

            current = current.next;
        }
    }

    public String toString(){
        StringBuilder res = new StringBuilder();
        Node current = this.head;
        while (current != null){
            if(res.length() == 0){
                res.append(current.car.name);
            }else{
                res.append(" - ");
                res.append(current.car.name);
            }
            current = current.next;
        }
        return res.toString();
    }

    public int[] getCount(){
        int[] count = {0, 0, 0};
        Node current = this.head;
        while (current != null){
            if(current.car.name.equals("engine")){
                count[0]++;
            }else{
                count[1]++;
                count[2]+=current.car.cargo;
            }
            current = current.next;
        }

        return count;
    }

    public boolean isEmpty(){
        if(this.head == null){
            return true;
        }
        return false;
    }
}
