import java.util.Random;

public class PiggyBank {

    public final static int[] COINS_VALUES = {1, 5, 10, 25}; // coins values in cents // coins names

    public final static String[] COINS_NAMES = {"PENNY", "NICKEL", "DIME", "QUARTER"};

    public final static String NO_SUCH_COIN = "N/A"; // N/A string

    private final static Random RAND_GEN = new Random(100); // generator of random integers

    /**
     * Returns the name of a specified coin value
     *
     * @param coin represents a coin value in cents.
     * @return the String name of a specified coin value if it is valid and N/A if the
     * <p>
     * coin value is not valid
     */

    public static String getCoinName(int coin) {
        String name = PiggyBank.NO_SUCH_COIN;

        for ( int i = 0; i<COINS_VALUES.length; i++){
            if (COINS_VALUES[i] == coin){
                name = COINS_NAMES[i];
                break;
            }
        }
        return name; // return an empty string
    }

    /**
     * Checks whether PiggyBank.getCoinName() method works as expected.
     *
     * @return true when this test verifies a correct functionality, and false otherwise
     */

    public static boolean testGetCoinName() {

        // consider all coin values as input arguments

        for (int i = 0; i < PiggyBank.COINS_VALUES.length; i++)
            if (!PiggyBank.getCoinName(PiggyBank.COINS_VALUES[i]).equals(PiggyBank.COINS_NAMES[i]))
                return false;

        // consider input argument which does not correspond to a coin value

        if (!PiggyBank.getCoinName(7).equals(PiggyBank.NO_SUCH_COIN)) return false;

        if (!PiggyBank.getCoinName(-10).equals(PiggyBank.NO_SUCH_COIN))

            return false;

        return true;

    }

    /**
     * Calls the test methods implemented in this class and displays their output
     *
     * @param args input arguments if any
     */

    public static void main(String[] args) {

        System.out.println("testGetCoinName(): " + testGetCoinName());
        System.out.println("testGetBalance(): " + testGetBalance());

    }

    /**
     * Returns the balance of a piggy bank in cents
     *
     * @param coins an oversize array which contains all the coins held in a piggy bank
     * @param size  the total number of coins stored in coins array
     * @return the total value of the coins held in a piggy bank in cents
     */

    public static int getBalance(int[] coins, int size) {
        int sum = 0;
        for (int i = 0; i<size; i++){
            sum += coins[i];
        }

        return sum;
    }

    /**
     * Returns the total number of coins of a specific coin value held in a piggy bank
     *
     * @param coinValue the value of a specific coin
     * @param coins     an oversize array which contains all the coins held in a piggy
     *                  <p>
     *                  bank
     * @param size      the total number of coins stored in coins array
     * @return the number of coins of value coinValue stored in the array coins
     */

    public static int getSpecificCoinCount(int coinValue, int[] coins, int size) {
        int count = 0;
        for (int i=0; i<size; i++){
            if (coins[i] == coinValue)
                count += 1;
        }
        return count;
    }

    /**
     * Checks whether PiggyBank.getBalance() method works as expected.
     *
     * @return true when this test verifies a correct functionality, and false otherwise
     */

    public static boolean testGetBalance() {

        // scenario 1 - empty piggy bank

        int[] coins = new int[10]; // array storing the coins held in a piggy bank

        int size = 0; // number of coins held in coins array

        if (PiggyBank.getBalance(coins, size) != 0) {

            System.out.println("Problem detected. Your PiggyBank.getBalance() did not " + "return the expected output when passed an empty piggy bank.");

            return false;
        }

        // scenario 2 - non empty piggy bank

        coins = new int[]{10, 1, 5, 25, 1, 0, 0};

        size = 5;

        if (PiggyBank.getBalance(coins, size) != 42) {

            System.out.println("Problem detected. Your PiggyBank.getBalance() did not " + "return the expected output when passed an piggy bank that holds " + "two pennies, a nickel, a dime, and a quarter.");

            return false;
        }

        // scenario 3 - another non empty piggy bank

        coins = new int[]{10, 1, 5, 25, 1, 0};
        size = 3;
        if (PiggyBank.getBalance(coins, size) != 16) {

            System.out.println("Problem detected. Your PiggyBank.getBalance() did not " + "return the expected output when passed an piggy bank that holds " + "a penny, a nickel, and a dime, only.");
            return false;

        }

        return true;

    }

    /**
     * Displays information about the content of a piggy bank
     *
     * @param coins an oversize array storing the coins held in a piggy bank
     * @param size  number of coin held array coins
     */

    public static void printPiggyBank(int[] coins, int size) {

        System.out.println("QUARTERS: " + getSpecificCoinCount(25, coins, size));

        System.out.println("DIMES: " + getSpecificCoinCount(10, coins, size));

        System.out.println("NICKELS: " + getSpecificCoinCount(5, coins, size));

        System.out.println("PENNIES: " + getSpecificCoinCount(1, coins, size));

        System.out.println("Balance: $" + getBalance(coins, size) * 0.01);

    }

    /**
     * Adds a given coin to a piggy bank. This operation can terminate
     * <p>
     * successfully or unsuccessfully. For either cases, this method
     * <p>
     * displays a descriptive message for either cases.
     *
     * @param coin  the coin value in cents to be added to the array coins
     * @param coins an oversize array storing the coins held in a piggy bank
     * @param size  the total number of coins contained in the array coins
     *              <p>
     *              before this addCoin method is called.
     * @return the new size of the coins array after trying to add coin.
     */

    public static int addCoin(int coin, int[] coins, int size) {
        return 0;
    }

    /**
     * Removes an arbitrary coin from a piggy bank. This method may terminate
     * <p>
     * successfully or unsuccessfully. In either cases, a descriptive message
     * <p>
     * is displayed.
     *
     * @param coins an oversize array which contains the coins held in a piggy bank
     * @param size  the number of coins held in the coins array before this method
     *              <p>
     *              is called
     * @return the size of coins array after this method returns successfully
     */

    public static int removeCoin(int[] coins, int size) {
        return 0;
    }

    /**
     * Removes all the coins in a piggy bank. It also displays the total value
     * <p>
     * of the removed coins
     *
     * @param coins an oversize array storing the coins held in a piggy bank application
     * @param size  number of coins held in coins array before this method is called
     * @return the new size of the piggy bank after removing all its coins.
     */

    public static int emptyPiggyBank(int[] coins, int size) {
        return 0;
    }

}