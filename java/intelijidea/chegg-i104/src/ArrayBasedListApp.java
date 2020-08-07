class Node {
    private int key;
    public Node() {
        key = -1;
    }
    public Node(int k) {
        key = k;
    }
    public int getKey() {
        return key;
    }
    public void setKey(int k) {
        key = k;
    }
}

class ArrayBasedList {
    private int SIZE = 5;
    private Node[] abl = new Node[SIZE];
    private int front, rear;
    private int kCount;
    public ArrayBasedList() {
        for(int i = 0; i < SIZE; i++) {
            abl[i] = new Node();
        }
        front = rear = 0;
        kCount = 0;
    }
    public boolean insertFront(int k) {
        if(kCount == 0) {
            abl[front].setKey(k);
            kCount++;
            return true;
        }
        else if(kCount == SIZE) {
            System.out.println("** > OVERFLOW < **");
            return false;
        }
        else {
            Node temp = abl[front];
            while(temp.getKey() != -1) {
                front--;
                if(front == -1) front = SIZE-1;
                temp = abl[front];
            }
            abl[front].setKey(k);
            kCount++;
            return true;
        }
    }//closes insertFront method
    public boolean insertRear(int k) {
        if(kCount == 0) {
            abl[rear].setKey(k);
            kCount++;
            return true;
        }
        else if(kCount == SIZE) {
            System.out.println("** > OVERFLOW < **");
            return false;
        }
        else {
            Node temp = abl[rear];
            while(temp.getKey() != -1) {
                rear++;
                if(rear == SIZE) rear = 0;
                temp = abl[rear];
            }
            abl[rear].setKey(k);
            kCount++;
            return true;
        }
    }//closes insertRear method
    public boolean deleteRear() {
        if(kCount == 0) {
            System.out.println(">> Empty ABL <<");
            return false;
        }
        Node temp = abl[rear];
        temp.setKey(-1);
        rear--;
        if(rear == -1) rear = SIZE-1;
        kCount--;
        return true;
    }//closes deleteRear method

    public boolean deleteFront() {
        if(kCount == 0) {
            System.out.println(">> Empty ABL <<");
            return false;
        }
        Node temp = abl[front];
        temp.setKey(-1);
        front++;
        if(front == SIZE) front = 0;
        kCount--;
        return true;
    }//closes deleteFront method

    public void display() {
        int i = front;
        int count = 0;
        Node temp = abl[i];
        while(temp.getKey() != -1 && count < SIZE) {
            System.out.print("*> " + temp.getKey() + " <*");
            i++;
            count++;
            if(i == SIZE) i = 0;
            temp = abl[i];
        }
        System.out.println("** END **");
    }//closes display method

    /**
     * required find function
     * @param key to find in arraylist
     * @return true if given key is found otherwise return false
     */
    public boolean find(int key) {
        int i = front;
        int count = 0;
        while(abl[i].getKey() != -1 && count < SIZE) {
            if (abl[i].getKey() == key)
                return true;
            i++;
            count++;
            if(i == SIZE)
                i = 0;
        }
        return false;
    }
}//closes ArrayBasedList class

public class ArrayBasedListApp {

    public static void main(String[] args) {
        ArrayBasedList alpha = new ArrayBasedList();
        alpha.display();
        alpha.insertRear(9);
        alpha.insertFront(11);
        alpha.display();
        alpha.insertFront(19);
        alpha.display();
        alpha.insertRear(81);
        alpha.display();
        alpha.insertFront(22);
        alpha.display();
        alpha.insertFront(86);
        alpha.display();
        alpha.deleteRear();
        alpha.display();
        alpha.deleteFront();
        alpha.display();

        // test find function
        System.out.println("list has 11: "+alpha.find(11));
        System.out.println("list has 86: "+alpha.find(86));
    }
}