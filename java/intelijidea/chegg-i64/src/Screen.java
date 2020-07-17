public class Screen {
    private String srNumber;
    private int height;
    private int width;
    private double basicPrice;

    /**
     * default constructor
     */
    Screen(){
        this.srNumber = null;
        this.width = 0;
        this.height = 0;
        this.basicPrice = 0;
    }

    /**
     * parameterize constructor
     * @param srrNumber of screen
     * @param width of screen
     * @param height of screen
     * @param basicPrice of screen
     */
    Screen(String srrNumber, int width, int height, double basicPrice){
        this.srNumber = srrNumber;
        this.width = width;
        this.height = height;
        this.basicPrice = basicPrice;
    }

    /**
     * get serial number of screen
     * @return serial number of screen
     */
    public String getSrNumber() {
        return srNumber;
    }

    /**
     * sets serial number of screen
     * @param srNumber serial number of screen
     */
    public void setSrNumber(String srNumber) {
        this.srNumber = srNumber;
    }

    /**
     * get height of screen
     * @return height of screen
     */
    public int getHeight() {
        return height;
    }

    /**
     * set height of screen
     * @param height of screen
     */
    public void setHeight(int height) {
        this.height = height;
    }

    /**
     * get width of screen
     * @return width of screen
     */
    public int getWidth() {
        return width;
    }

    /**
     * set width of screen
     * @param width width of screen
     */
    public void setWidth(int width) {
        this.width = width;
    }

    /**
     * get basic price of screen
     * @return basic price of screen
     */
    public double getBasicPrice() {
        return basicPrice;
    }

    /**
     * set basic price of screen
     * @param basicPrice basic price of screen
     */
    public void setBasicPrice(double basicPrice) {
        this.basicPrice = basicPrice;
    }

    @Override
    public String toString() {
        return "Details{" +
                "srNumber='" + srNumber + '\'' +
                ", height=" + height +
                ", width=" + width +
                ", basicPrice=" + basicPrice +
                '}';
    }

    /**
     * compute total price of screen
     * @return total price of screen
     */
    public double computePrice(){
        double price = basicPrice;
        if (this.height > 500){
            price  = price + this.basicPrice + 50;
        }

        if (this.width > 900){
            price = price + this.basicPrice + 100;
        }

        return price;
    }
}
