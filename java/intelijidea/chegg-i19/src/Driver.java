public class Driver {
    public static void main(String[] args){
        ArrayList<Integer> arrayList = new ArrayList<Integer>();

        arrayList.add(5);
        arrayList.add(6);
        arrayList.add(67);
        System.out.println("Element in arraylist before removing any element ");
        for (Integer i : arrayList){
            System.out.println(i);
        }

        ArrayList.ArrayIterator arrayIterator = (ArrayList.ArrayIterator) arrayList.iterator();
        arrayIterator.remove();
        System.out.println("Element in arraylist after removing first element ");
        for (Integer i : arrayList){
            System.out.println(i);
        }
        System.out.println();

        LinkedList<Integer> linkedList = new LinkedList<Integer>();
        linkedList.add(5);
        linkedList.add(7);
        linkedList.add(8);
        linkedList.add(9);
        System.out.println("Element in linked list before removing any element ");
        for(Integer i : linkedList){
            System.out.println(i);
        }

        LinkedList.LinkedIterator linkedIterator = (LinkedList.LinkedIterator) linkedList.iterator();
        linkedIterator.remove();
        System.out.println("Element in linked list after removing first element ");
        for(Integer i : linkedList){
            System.out.println(i);
        }
    }
}
