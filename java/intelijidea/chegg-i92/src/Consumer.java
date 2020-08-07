/**
 * Consumer thread
 */
public class Consumer extends Thread{
    private ProducerConsumer pc;
    Consumer(ProducerConsumer pc){
        this.pc = pc;
    }

    @Override
    public void run() {
        try {
            this.pc.consume();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        super.run();
    }
}
