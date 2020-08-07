import java.util.Random;

/**
 * ProducerConsumer class
 * contains produce and consume function
 */
public class ProducerConsumer {
    private int num;
    private boolean flag;
    private Random random;

    ProducerConsumer(){
        this.flag = false;
        this.random = new Random();
    }

    /**
     * function to produce a random number between 1 - 100
     * @throws InterruptedException
     */
    public void produce() throws InterruptedException {
        while (true){
            synchronized (this){
                while (flag)
                    wait();
                this.num = random.nextInt(100) + 1;
                System.out.println("Producer produce: " + this.num);
                flag = true;
                notify();
                Thread.sleep(1000);
            }
        }
    }

    /**
     * consume a produced number and tell user consumed number is even or odd
     * @throws InterruptedException
     */
    public void consume() throws InterruptedException {
        while (true){
            synchronized (this){
                while (!flag)
                    wait();
                if (this.num % 2 == 0)
                    System.out.println("Consumed number is even.");
                else
                    System.out.println("Consumed number is odd.");
                flag = false;
                notify();
                Thread.sleep(1000);
            }
        }
    }
}
