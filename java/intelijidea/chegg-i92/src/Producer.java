/**
 * Producer thread
 */
public class Producer extends Thread{
    private ProducerConsumer pc;
    Producer(ProducerConsumer pc){
        this.pc = pc;
    }
    @Override
    public void run() {
        try {
            this.pc.produce();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
        super.run();
    }
}
