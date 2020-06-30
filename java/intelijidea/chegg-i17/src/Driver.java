public class Driver {
    public static void main(String[] args){
        IntList intList = new IntList();

        intList.insertInDescendingOrder(new IntNode(3));
        intList.insertInDescendingOrder(new IntNode(4));
        intList.insertInDescendingOrder(new IntNode(2));
        intList.insertInDescendingOrder(new IntNode(5));
        intList.insertInDescendingOrder(new IntNode(1));
        intList.insertInDescendingOrder(new IntNode(6));
        intList.insertInDescendingOrder(new IntNode(7));
        intList.insertInDescendingOrder(new IntNode(9));
        intList.insertInDescendingOrder(new IntNode(8));
        intList.insertInDescendingOrder(new IntNode(-1));

        intList.printIntList();
    }
}
