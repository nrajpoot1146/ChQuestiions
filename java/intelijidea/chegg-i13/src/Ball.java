

public class Ball extends TennisShop implements DiscConsiderable{
    private int numOfCan;

    /**
     * Default Constructor
     */
    Ball(){

    }

    /**
     *
     * @param brand of item
     * @param price of item
     * @param quantity of item
     * @param numOfCan of item
     */
    Ball(String brand, double price, int quantity, int numOfCan){
        super(brand, price, quantity);
        this.numOfCan = numOfCan;
    }

    /**
     * display details of ball
     */
    @Override
    public void display() {
        System.out.println("TENNIS BALL");
        System.out.println("Brand\t: "+this.getBrand());
        System.out.println("Price\t: RM"+String.format("%5.2f",this.getPrice()) +" for "+this.numOfCan+" can case");
        System.out.println("Discount: "+ String.format("%2.1f", DiscConsiderable.RATE * 100) +"%");
        System.out.println("Quantity: "+this.getQuantity());
        System.out.println("Subtotal: RM"+String.format("%5.2f",this.calcPrice()));
    }

    /**
     *
     * @return total price of balls
     */
    @Override
    public double calcPrice() {
        double totalPrice = this.calcDisc() * this.getQuantity();
        return totalPrice;
    }

    /**
     *
     * @return new price after discount
     */
    @Override
    public double calcDisc() {
        double newPrice = this.getPrice() - this.getPrice() * DiscConsiderable.RATE;
        return newPrice;
    }
}
