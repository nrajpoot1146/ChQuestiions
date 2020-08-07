public abstract class Order implements OrderInterface{
    //... anything based on your design
    protected double[] price = new double [5];
    protected String[] name = new String[5];
    protected int quantity[];
    protected double billAmount;
    protected double tax;
    protected String s;
    Order(){

    }
    // display the menu
    public void displayMenu() {
        System.out.println("==========================================");
        // show the food's name and price
        System.out.println("********** De Anza Burger Menu **********\n");
        for(int i = 0; i < name.length; i++) {
            System.out.println((i + 1) + "." + name[i] + "\t$" + price[i]);
        }
        System.out.println("6.Exit <= Thank you for ordering\n");
        // Your displayMenu method body
        System.out.println("==========================================");
    }

    public abstract void getInputs();// get integer from user  //should be overridden in OrderBurger class
    public abstract void calculate();// calculate the bill //should be overridden in OrderBurger class
    public abstract void printBill(); // print out the bill //should be overridden in OrderBurger class
    public abstract void saveBillToFile();// saves the bill in a file //should be overridden in OrderBurger class
}