public class GenericQueueTest {

    public static void main(String[] args){

        // creating instance of generic queue
        GenericQueue<String> genericQueue = new GenericQueue<>();

        // enqueue patient
        genericQueue.enqueue("Tom");
        genericQueue.enqueue("George");
        genericQueue.enqueue("Peter");
        genericQueue.enqueue("Jean");
        genericQueue.enqueue("Jane");
        genericQueue.enqueue("Michael");
        genericQueue.enqueue("Michelle");
        genericQueue.enqueue("Daniel");

        // dequeue patient
        // and show a message
        while (genericQueue.getSize() > 0){
            String p = genericQueue.dequeue();
            System.out.println(p+", the doctor will see you now.");
        }
    }
}
