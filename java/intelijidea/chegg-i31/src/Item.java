public class Item {
    private int id;
    private double price;
    private String brand;

    Item(int id, double price, String brand){
        this.id = id;
        this.price = price;
        this.brand = brand;
    }

    /**
     * function to set id of item
     * @param id of item
     */
    public void setId(int id) {
        this.id = id;
    }

    /**
     * function to set price of item
     * @param price of item
     */
    public void setPrice(double price) {
        this.price = price;
    }

    /**
     * function to set brand of item
     * @param brand of item
     */
    public void setBrand(String brand) {
        this.brand = brand;
    }

    /**
     *
     * @return id of item
     */
    public int getId() {
        return id;
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
     * @return brand of item
     */
    public String getBrand() {
        return brand;
    }

    @Override
    public String toString() {
        return "ID: "+this.id
                + ", Price: "+this.price
                + ", Brand: "+this.brand;
    }
}
