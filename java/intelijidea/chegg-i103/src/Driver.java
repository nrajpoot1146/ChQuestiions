import java.io.FileNotFoundException;

public class Driver {

    public static void main(String[] args) {
        OrderBurger order = new OrderBurger();

// Order ord = new Order(); <= Cannot instantiate the type Order because Order is an abstract class

        order.displayMenu(); //displays the men
        order.getInputs(); //gets inputs
        order.calculate(); //calculates cost
        order.printBill(); //prints bill

        order.saveBillToFile(); //saves the bill in a text file
    }

}