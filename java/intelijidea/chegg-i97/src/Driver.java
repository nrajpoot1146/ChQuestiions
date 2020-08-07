public class Driver {
    public static void main(String... args){
        // create a new list
        OurLinkedList<Integer> lst = new OurLinkedList<>();
        // add elements
        for (int i=0; i<=6; i++){
            lst.add(i);
        }

        // create another list
        OurLinkedList<Integer> lst1 = new OurLinkedList<>();
        // add elements
        for (int i=0; i<=6; i++){
            lst1.add(i);
        }

        // check equals function
        System.out.println("Equality check (Should be true): " + lst.equals(lst1));
        lst.clear();
        // check equals function
        System.out.println("Equality check (Should be false): " + lst.equals(lst1));

        lst.add(3);
        lst.add(4);
        lst.add(5);
        lst.add(3);
        lst.add(3);
        // check find common function
        System.out.println("findCommonCheck (should be 8): " + lst.findCommons(lst1));
    }
}
