public class Main {
    public static void main(String...  args){
        // create an instance of producerConsumer class
        // to access produce and consume function
        ProducerConsumer pc = new ProducerConsumer();

        Producer p = new Producer(pc); // create an instance of producer thread
        Consumer c = new Consumer(pc); // create an instance of consumer thread

        p.start(); // start producer thread
        c.start(); // start consumer thread
    }
}
