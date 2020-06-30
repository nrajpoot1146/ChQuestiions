/**
 * TennisShop class
 */
abstract public class TennisShop {
    private String brand;
    private double price;
    private int quantity;

    /**
     * Default constructor
     */
    TennisShop(){

    }

    /**
     *
     * Constructor with parameter
     * @param brand brand name
     * @param price price for itme
     * @param quantity quantity of item
     */
    TennisShop(String brand, double price, int quantity){
        this.brand = brand;
        this.price = price;
        this.quantity = quantity;
    }

    /**
     *
     * setter method for price of item
     * @param price
     */
    public void setPrice(double price) {
        this.price = price;
    }

    /**
     *
     * @return brand of item;
     */
    public String getBrand() {
        return brand;
    }

    /**
     *
     * @return price of item
     */
    public double getPrice() {
        return price;
    }

    /**
     *
     * @return quantity of item
     */
    public int getQuantity() {
        return quantity;
    }

    /**
     * display abstract method
     */
    abstract public void display();

    /**
     *
     * calPrice abstract method
     */
    abstract public double calcPrice();
}
