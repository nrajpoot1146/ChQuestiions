public class DS1BW3Queue { // BW means BackWards see above. BW3 means version 3 or a sports bar

    private Node front, back;

    static boolean showMeSuccess = true; // change to true to also show tests that pass

    static class Node {
        public Node (char item, Node next) { this.item = item; this.next = next; }
        public char item;
        public Node next;
        public char value;
        public Node head;
    }

    public void removeEveryKthNode (int k) {
        // toDo 3 remove every kth element from the *original* invoking queue
        if(head == null) {
            return;
        }
        Node prev = null;
        Node curr = head;
        int count = 1;

        while (curr != null) {
            count++;
            prev = curr;
            curr = curr.next;

            if (count == k) {
                prev.next = curr.next;
                curr = curr.next;
                count = 1;
            }
        }
    }
    public void insert (char c) {
        Node h = head;
        if (h == null) {
            head = new Node();
            head.value = c;
            return;
        }
        while(h.next != null) {
            h = h.next;
        }
        h.next = new Node();
        h.next.value = c;
    }

    public static void main( String[] args) {
        //debugSomething();
        //dequeueTests();
        //toStringTests();
        removeEveryKthTests();
        isOrderedTests();
    }
    private static void debugSomething () {
        // Use this for debugging!
        // Add the names of helper functions if you use them.
        Trace.drawStepsOfMethod ("toString");
        Trace.drawStepsOfMethod ("removeEveryKthNode");
        Trace.drawStepsOfMethod ("dequeue");
        Trace.drawStepsOfMethod ("removeEveryKthNode");
        Trace.run ();
        // To Use: Put the test here you want to debug:
        //testRemoveEveryKthNode( "abcdef",3,"abde"); // source queue data, value of k
    }

    private static void removeEveryKthTests () {

        testRemoveEveryKthNode( "abcdef",2,"ace"); // source queue data, value of k, expected queue
        testRemoveEveryKthNode( "abcdef",3,"abde");
        testRemoveEveryKthNode( "abcdefg",2,"aceg");
        testRemoveEveryKthNode( "abcdefgh",3,"abdegh");
        testRemoveEveryKthNode( "abcdefghijkl",4,"abcefgijk");
        testRemoveEveryKthNode("abcdef",1,"");
        StdOut.println(" ....6 removeEveryKth tests completed");
    }

    private static void testRemoveEveryKthNode( String qData, int k, String expected) {
        DS1BW3Queue aQueue = DS1BW3Queue.of (qData);

        aQueue.removeEveryKthNode(k); // invoke function to be tested
        String r = extra(aQueue);

        boolean status = true;
        if (!r.equals(expected)) {
            StdOut.format ("Failed {%s}.removeEveryKthNode(%d): Expecting [%s] Actual [%s]\n", qData, k, expected, r);
            status = false;
        }
        if ( status && showMeSuccess)
            StdOut.format ("Success {%s}.removeEveryKthNode(%d) Result= [%s] \n", qData,k, r);
    }

    /* Method to create populate queues */
    public static DS1BW3Queue of(String s) {
        Node first = null;
        DS1BW3Queue result = new DS1BW3Queue ();

        for (int i = s.length()-1; i >= 0; i--) {
            first = new Node (s.charAt(i), first);
            if ( i==s.length()-1 ) result.front=first;
        }
        result.back =first;
        return result;
    }
    // extra method
    public static String extra( DS1BW3Queue q) {
        String t = "";
        for ( Node tmp=q.back; tmp != null; tmp = tmp.next)
            t += tmp.item;
        return t;
    }
}