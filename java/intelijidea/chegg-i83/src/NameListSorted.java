import java.io.File;
import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.util.Scanner;

public class NameListSorted {
    private LLNode head; // first node of the list
    private LLNode tail; // last node of the list
    private int numName; // number of node in the list
    private int capacity; // max capacity of the list
    private static final int DEFAULT_CAPACITY = 30; // default max capacity of the list

    /**
     * default constructor
     */
    NameListSorted(){
        this(DEFAULT_CAPACITY);
    }

    /**
     * overloaded constructor
     * @param capacity of the list
     */
    NameListSorted(int capacity){
        head = null;
        tail = null;
        numName = 0;
        this.capacity = capacity;
    }

    /**
     * add an name into the list
     * @param name to be added
     */
    public void add(Name name){
        if (!this.isFull()){
            this.numName++;
            LLNode newNode = new LLNode(name, null);
            if (this.isEmpty()){
                this.head = this.tail = newNode;
                return;
            }

            if (name.compareTo(this.head.getName()) < 0){
                newNode.setNext(this.head);
                this.head = newNode;
                return;
            }

            if (tail.getName().compareTo(name) < 0){
                this.tail.setNext(newNode);
                this.tail = this.tail.getNext();
                return;
            }
            LLNode prev = this.head;
            LLNode curr = prev.getNext();

            while (curr.getName().compareTo(name) < 0){
                prev = curr;
                curr = curr.getNext();
            }

            newNode.setNext(curr);
            prev.setNext(newNode);
        }
    }

    /**
     * insert a name into the list
     * @param name to be insert
     */
    public void insert(Name name){
        add(name);
    }

    /**
     * search a name
     * @param name to be search
     * @return if found index of name, otherwise return -1;
     */
    public int search(Name name){
        if (this.isEmpty()){
            return -1;
        }

        LLNode curr = this.head;

        int i = 0;
        while (curr != null){
            if (curr.getName().compareTo(name) == 0)
                return i;
            i++;
            curr = curr.getNext();
        }
        return -1;
    }

    /**
     * get name at given index
     * @param index of name
     * @return name at given index
     */
    public Name get(int index){
        if (this.isEmpty() || index < 0 || index >= this.numName){
            return null;
        }

        LLNode curr = this.head;

        int i=0;
        while (curr != null){
            if (i == index){
                return curr.getName();
            }
            curr = curr.getNext();
            i++;
        }
        return null;
    }

    /**
     * remove element at given index
     * @param index
     */
    public void remove(int index){
        if (this.isEmpty()){
            return;
        }

        if (index == 0){
            this.head = this.head.getNext();
            return;
        }

        LLNode prev = this.head;
        LLNode curr = this.head.getNext();

        int i=1;
        while (curr != null){
            if (i == index){
                prev.setNext(curr.getNext());
                this.numName--;
            }
            prev = curr;
            curr = curr.getNext();
            i++;
        }
    }

    /**
     * remove given name from the list
     * @param name to remove
     */
    public void remove(Name name){
        while (!isEmpty() && this.head.getName().compareTo(name) == 0){
            this.numName--;
            this.head = this.head.getNext();
        }

        if (this.isEmpty()){
            return;
        }

        LLNode prev = this.head;
        LLNode curr = this.head.getNext();

        while (curr != null){
            if (curr.getName().compareTo(name) == 0){
                prev.setNext(curr.getNext());
                this.numName--;
            } else {
                prev = curr;
            }
            curr = curr.getNext();
        }
    }

    /**
     * remove all name of the list
     */
    public void removeAll(){
        this.head = this.tail = null;
        this.numName--;
    }

    /**
     * print name whose lastName start with given prefix
     * @param prefix
     */
    public void print(String prefix){
        if (this.isEmpty()){
            return;
        }

        LLNode curr = this.head;
        while (curr != null){
            if (curr.getName().getLastName().startsWith(prefix)){
                System.out.println(curr.getName().toString());
            }
            curr = curr.getNext();
        }
    }

    /**
     * print complete list
     */
    public void print(){
        print(0);
    }

    /**
     * print list from given index
     * @param startingIndex
     */
    public void print(int startingIndex){
        print(startingIndex, this.numName);
    }

    /**
     * print name from starting index to ending index
     * @param startingIndex
     * @param endingIndex
     */
    public void print(int startingIndex, int endingIndex){
        if (this.isEmpty() || startingIndex < 0 || endingIndex < startingIndex || endingIndex > numName){
            return;
        }

        LLNode curr = this.head;

        int i = 0;
        while (curr != null){
            if (i >= startingIndex && i < endingIndex){
                System.out.println(curr.getName().toString());
            } else if (i >= endingIndex){
                break;
            }
            curr = curr.getNext();
            i++;
        }
    }

    /**
     * generate a sublist from starting index to ending index
     * @param startingIndex
     * @param endingIndex
     * @return
     */
    public NameListSorted sublist(int startingIndex, int endingIndex){
        if (startingIndex<0){
            startingIndex = 0;
        }
        if (endingIndex >= numName ){
            endingIndex = numName - 1;
        }

        NameListSorted newList = new NameListSorted();
        LLNode curr = this.head;
        int i = 0;
        while (curr != null){
            if (i >=startingIndex && i< endingIndex) {
                newList.add(curr.getName());
            } else if (i >= endingIndex){
                break;
            }
            i++;
            curr = curr.getNext();
        }
        return newList;
    }

    /**
     * return number of name in list
     * @return
     */
    public int size(){
        return this.numName;
    }

    /**
     * build a list from a input file
     * @param file
     */
    public void build(File file){
        Scanner sc = null;
        try {
            sc = new Scanner(new FileInputStream(file));
            this.capacity = Integer.parseInt(sc.nextLine());
            while (sc.hasNextLine()){
                String line = sc.nextLine();
                String[] n = line.split(" ");
                Name name = new Name();
                if (n.length > 0){
                    name.setFirstName(n[0]);
                }
                if (n.length > 1){
                    name.setLastName(n[1]);
                }
                this.add(name);
            }
            sc.close();
        } catch (FileNotFoundException e) {
            e.printStackTrace();
            sc.close();
        }
    }

    /**
     * check list is empty or not
     * @return true if list is empty otherwise return false
     */
    boolean isEmpty(){
        return this.head == null;
    }

    /**
     * check list is full or not
     * @return true if list is full otherwise return false
     */
    boolean isFull(){
        return this.numName == this.capacity;
    }
}
