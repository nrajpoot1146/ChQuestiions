public class MyLinkedListTester {
    public static void main(String[] args){

        // list 1
        MyLinkedList l1 = new MyLinkedList();
        l1.add("1");
        l1.add("2");
        l1.add("3");

        // list 2
        MyLinkedList l2 = new MyLinkedList();
        l2.add("3");
        l2.add("5");
        l2.add("7");

        MyLinkedList l3 = union(l1, l2); // union of list 1 and list 2

        l1.printAll(); // print list 1
        System.out.print(" + ");
        l2.printAll(); // print list 2
        System.out.print(" = ");
        l3.printAll(); // print union


        System.out.println();
        MyLinkedList l4 = new MyLinkedList(); // list 4
        l4.add("10");
        l4.add("9");
        l4.add("8");
        l4.add("7");

        MyLinkedList l5 = new MyLinkedList(); // list 5
        l5.add("2");
        l5.add("4");
        l5.add("6");
        l5.add("8");

        MyLinkedList l6 = intersection(l4, l5); // intersection of list 4 and list 5

        l4.printAll(); // print list 4
        System.out.print(" * ");
        l5.printAll(); // print list 5
        System.out.print(" = ");
        l6.printAll(); // print list 6


        System.out.println();
        // list 7
        MyLinkedList l7 = new MyLinkedList();
        l7.add("5");
        l7.add("10");
        l7.add("15");
        l7.add("20");

        // list 8
        MyLinkedList l8 = new MyLinkedList();
        l8.add("0");
        l8.add("10");
        l8.add("20");

        MyLinkedList l9 = difference(l7, l8); // difference of list 7 and list 8

        l7.printAll(); // print list 7
        System.out.print(" - ");
        l8.printAll(); // print list 8
        System.out.print(" = ");
        l9.printAll(); // print list 9

        System.out.println();
        System.out.println();
        System.out.println("Reverse function test: ");
        System.out.print("before reverse: ");
        l4.printAll();
        System.out.println();
        System.out.print("after reverse: ");
        l4.createAndReverse().printAll();
    }

    /**
     * function to calculate union of list A and B
     * @param A
     * @param B
     * @return union of two given list
     */
    public static MyLinkedList union(MyLinkedList A, MyLinkedList B){
        MyLinkedList newList = new MyLinkedList();
        String value;
        while ( (value = A.getCurr()) != null ){
            if (!newList.find(value)){
                newList.add(value);
            }
        }

        while ( (value = B.getCurr()) != null ){
            if (!newList.find(value)){
                newList.add(value);
            }
        }

        return newList;
    }

    /**
     * function to calculate intersection of two list
     * @param A
     * @param B
     * @return intersection of two list
     */
    public static MyLinkedList intersection(MyLinkedList A, MyLinkedList B){
        MyLinkedList newList = new MyLinkedList();
        String value;
        while ( (value = A.getCurr()) != null ){
            if (B.find(value)){
                newList.add(value);
            }
        }
        return newList;
    }

    /**
     * function to calculate difference of two list
     * @param A
     * @param B
     * @return A - B
     */
    public static MyLinkedList difference(MyLinkedList A, MyLinkedList B){
        MyLinkedList newList = new MyLinkedList();
        String value;
        while ( (value = A.getCurr()) != null ){
            if (!B.find(value)){
                newList.add(value);
            }
        }
        return newList;
    }
}
