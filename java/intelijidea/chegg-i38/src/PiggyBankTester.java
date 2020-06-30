

import org.junit.Test;

import static org.junit.Assert.*;

public class PiggyBankTester {

    /**
     * junit tester function to test your testGetCoinName function
     */
    @Test
    public void testGetCoinName(){
        assertTrue(PiggyBank.testGetCoinName());
    }

    /**
     * Junit Tester function to test your testGetBalance function
     */
    @Test
    public void testGetBalance(){
        assertTrue(PiggyBank.testGetBalance());
    }

}
