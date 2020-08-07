import java.util.Random;

public interface Randomizable {
    Random random = new Random();

    /**
     * function to fill list with random number;
     */
    void rand();
}
