/**
 * Driver.java
 */

public class Driver {
    public static void main(String[] args){
        ArrayList<Integer> arrayList = new ArrayList<Integer>(3);

        System.out.println("ArrayList size: "+arrayList.size());

        // add some elements in array list
        arrayList.add(3);
        arrayList.add(4);

        System.out.println("ArrayList size: "+arrayList.size());
        System.out.println("Is empty: "+arrayList.isEmpty());

        arrayList.add(8);
        arrayList.add(9);

        System.out.println();
        System.out.println("Array element: "+arrayList.toString());

        // remove an element from index 2
        arrayList.remove(2);
        System.out.println();
        System.out.println("Array element: "+arrayList.toString());
    }
}
