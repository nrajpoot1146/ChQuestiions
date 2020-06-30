public class Paper {
    private int numberOfPounds;
    private int pricePerPound;

    /**
     *
     * @param numberOfPounds
     * @param pricePerPound
     */
    Paper(int numberOfPounds, int pricePerPound){
        this.numberOfPounds = numberOfPounds;
        this.pricePerPound = pricePerPound;
    }

    /**
     *
     * @param numberOfPounds
     */
    public void setNumberOfPounds(int numberOfPounds) {
        this.numberOfPounds = numberOfPounds;
    }

    /**
     *
     * @param pricePerPound
     */
    public void setPricePerPound(int pricePerPound) {
        this.pricePerPound = pricePerPound;
    }

    /**
     *
     * @return numbers of pounnd
     */
    public int getNumberOfPounds() {
        return numberOfPounds;
    }

    /**
     *
     * @return price per pound
     */
    public int getPricePerPound() {
        return pricePerPound;
    }

    /**
     *
     * @return paper cost = number of pounds + price per pound
     */
    public int getPaper(){
        int paper = this.numberOfPounds * this.pricePerPound;
        return paper;
    }

    @Override
    public String toString() {
        return "Paper{" +
                "numberOfPounds=" + numberOfPounds +
                ", pricePerPound=" + pricePerPound +
                '}';
    }
}
