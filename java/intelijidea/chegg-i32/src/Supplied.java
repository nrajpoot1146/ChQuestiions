public class Supplied {
    private int suppliesSold;
    private int booksSold;
    private int apparelSold;

    /**
     *
     * @param suppliesSold supplies sold in dollar
     * @param booksSold books sold in dollar
     * @param apparelSold apparel sold in dollar
     */
    Supplied(int suppliesSold, int booksSold, int apparelSold){
        this.apparelSold = suppliesSold;
        this.apparelSold = apparelSold;
        this.booksSold = booksSold;
    }

    Supplied(){
        this.booksSold = 0;
        this.suppliesSold = 0;
        this.apparelSold = 0;
    }

    /**
     *
     *
     * @param apparelSold
     */
    public void setApparelSold(int apparelSold) {
        this.apparelSold = apparelSold;
    }

    /**
     *
     * @param booksSold
     */
    public void setBooksSold(int booksSold) {
        this.booksSold = booksSold;
    }

    /**
     *
     * @param suppliesSold
     */
    public void setSuppliesSold(int suppliesSold) {
        this.suppliesSold = suppliesSold;
    }


    /**
     *
     * @return apparel sold
     */
    public int getApparelSold() {
        return apparelSold;
    }

    /**
     *
     * @return books sold
     */
    public int getBooksSold() {
        return booksSold;
    }

    /**
     *
     * @return supplies sold
     */
    public int getSuppliesSold() {
        return suppliesSold;
    }

    /**
     *
     * @return total sold = suppliesSold + booksSold + apparel sold
     */
    public int getTotalSupplied(){
        int toatalSold = 0;
        toatalSold  = this.suppliesSold +this.booksSold + this.apparelSold;
        return toatalSold;
    }

    @Override
    public String toString() {
        return "Supplied{" +
                "suppliesSold=" + suppliesSold +
                ", booksSold=" + booksSold +
                ", apparelSold=" + apparelSold +
                '}';
    }
}
