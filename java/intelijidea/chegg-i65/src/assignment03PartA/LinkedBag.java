package assignment03PartA;

import java.util.LinkedList;
import java.util.List;

public final class LinkedBag<T> implements PrimaryDataStructureBagInterface<T> {

    private Node firstNode;
    private int numberOfEntries;

    public LinkedBag() {
        firstNode = null;
        numberOfEntries = 0;
    }

    /**
     * get number of entries in current bag
     * @return number of entries
     */
    @Override
    public int getCurrentSize() {
        return this.numberOfEntries;
    }

    /**
     * check whether bag is empty or not
     * @return true if bag is empty otherwise return false
     */
    @Override
    public boolean isEmpty() {
        return this.numberOfEntries == 0;
    }

    /**
     * add new entry to current bag
     * @param newEntry to be added
     * @return true if successfully added
     */
    @Override
    public boolean add(T newEntry) {
        Node newNode = new Node(newEntry);

        // if bag is empty new entry added as first node
        if (isEmpty()){
            this.firstNode = newNode;
            this.numberOfEntries++;
            return true;
        }

        // if bag is not empty
        Node curr = this.firstNode;
        while (curr.next != null){
            curr = curr.next;
        }
        curr.next = newNode;
        this.numberOfEntries++;
        return true;
    }

    /**
     * converting 2d array to 1d array
     * remove all occurrence from given array
     * remove 1d array item from bag
     * @param entries 2d array
     * @return true
     */
    @Override
    public boolean removeAllOccurrences(T[][] entries) {
        List<T> list = new LinkedList<>();
        T[] temp = (T[]) new Object[entries.length * entries[0].length];

        System.out.println("[+] Removing 2d test array items from the bag...");

        // converting 2d array to 1d array
        System.out.println(" [-] Converting 2D array to 1D...");
        int k =0;
        for (int i=0; i<entries.length; i++){
            for (int j = 0; j<entries[i].length; j++){
                temp[k] = entries[i][j];
                k++;
            }
        }

        // remove all duplicate from 1d array
        // store entries into list
        System.out.println(" [-] Removing duplicates in 1D array...");
        for (int i = 0; i<temp.length; i++){
            if (!list.contains(temp[i]) && temp[i] != null)
                list.add(temp[i]);
        }

        temp = (T[]) list.toArray(); // convert list to 1d array

        // print final 1d array
        System.out.print(" [>] The final 1D array now contains: ");
        for (int i = 0; i<temp.length; i++){
            System.out.print(temp[i]+" ");
        }
        System.out.println();

        // removing 1d array item from current bag
        System.out.println(" [-] Removing the final 1D array items from the bag...");
        for (int i = 0; i < temp.length; i++){
            while (this.firstNode.data.equals(temp[i])){
                this.firstNode = this.firstNode.next;
                this.numberOfEntries--;
            }
            Node prev = this.firstNode;
            Node curr = this.firstNode.next;
            while (curr != null){
                if (curr.data.equals(temp[i])){
                    prev.next = curr.next;
                    this.numberOfEntries--;
                } else
                    prev = curr;
                curr = curr.next;
            }
        }

        return true;
    }

    @Override
    public T[] toArray() {
        T[] temp = (T[]) new Object[this.numberOfEntries];
        Node curr = this.firstNode;

        for (int i=0; curr != null; i++){
            temp[i] = curr.data;
            curr = curr.next;
        }

        return temp;
    }


    private class Node {
        private T data;
        private Node next;

        private Node(T dataPortion) {
            this(dataPortion, null);
        } // end constructor

        private Node(T dataPortion, Node nextNode) {
            data = dataPortion;
            next = nextNode;
        }
    }
}