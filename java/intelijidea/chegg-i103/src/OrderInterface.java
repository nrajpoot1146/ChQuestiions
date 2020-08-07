public interface OrderInterface {
    // this constants can be used in your Order class or OrderBurger class
    final double TAX = 0.09;

    void displayMenu(); // displays the menu
    void getInputs(); //gets inputs
    void calculate(); //calculates the cost
    void printBill(); //prints the bill

    void saveBillToFile(); //saves the bill in a text file

}