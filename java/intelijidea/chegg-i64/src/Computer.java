public class Computer {
    private int type;
    private Screen screen;
    private double price;
    private int computers;
    private double totalPrice;

    /**
     * Default constructor
     */
    Computer(){
        this.type = 1;
        this.screen = null;
        this.price = 0;
        this.computers = 0;
        this.totalPrice = 0;
    }

    /**
     * parameterize constructor
     * @param type of computer
     * @param screen of computer
     * @param price price of computer
     * @param computers number of computers of this type
     */
    Computer(int type, Screen screen, double price, int computers){
        this.setType(type);
        this.setScreen(screen);
        this.setPrice(price);
        this.setComputers(computers);
    }

    /**
     * get type of computer
     * @return type of computer
     */
    public int getType() {
        return type;
    }

    /**
     * set type of computer
     * @param type of computer
     */
    public void setType(int type) {
        if (type > 0 && type < 3)
            this.type = type;
    }

    /**
     * get attach screen details of computer
     * @return attach screen details
     */
    public Screen getScreen() {
        return screen;
    }

    /**
     * set screen to current computer
     * @param screen of current computer
     */
    public void setScreen(Screen screen) {
        this.screen = screen;
    }

    /**
     * get price of computer
     * @return price of computer
     */
    public double getPrice() {
        return price;
    }

    /**
     * set price of computer
     * @param price of computer
     */
    public void setPrice(double price) {
        this.price = price;
    }

    /**
     * get number of computers
     * @return number of computers
     */
    public int getComputers() {
        return computers;
    }

    /**
     * sets number of computers of this type
     * @param computers
     */
    public void setComputers(int computers) {
        this.computers = computers;
    }

    /**
     * get total price
     * @return total price
     */
    public double getTotalPrice() {
        return totalPrice;
    }

    @Override
    public String toString() {
        return "Computer{" +
                "type=" + type +
                ", screen=" + screen +
                ", price=" + price +
                ", computers=" + computers +
                ", totalPrice=" + totalPrice +
                '}';
    }

    /**
     * compute total price
     * @return total price
     */
    public double computePrice(){
        totalPrice = (this.price + this.screen.computePrice()) * this.computers;
        return totalPrice;
    }
}
