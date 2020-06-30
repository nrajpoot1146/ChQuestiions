import java.util.Scanner;

public class LinearSearch {

    /**
     *
     * @param list of integers
     * @param listSize size of list
     * @param key integer value to search
     * @return index of key otherwise return -1
     */
    public static int linearSearch(int[] list, int listSize, int key){
        int i;
        for(i = 0; i<listSize; i++){
            if(list[i] == key){
                return i;
            }
        }
        return -1; // old: return xxx;
    }

    public static void main(String[] args){
        Scanner scnr = new Scanner(System.in);
        int[] list = {3, 5, 8, 11, 12, 33, 46, 88};
        final int LIST_SIZE = 8;
        int i = 0;
        int key;
        int keyIndex;
        System.out.print("LIST ");
        for (i = 0; i<LIST_SIZE; i++){
            System.out.print(list[i]+" ");
        }

        System.out.println();
        System.out.print("Enter a value: ");
        key = scnr.nextInt();
        keyIndex = linearSearch(list, LIST_SIZE, key);
        if(keyIndex == -1){
            System.out.println(key + " was not found.");
        }else{
            System.out.println("Found "+key+" at index "+ keyIndex+".");
        }
    }
}
