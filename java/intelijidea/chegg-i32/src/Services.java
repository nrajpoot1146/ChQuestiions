public class Services {
    private int numberOfHours;
    private int pricePerHour;

    /**
     *
     * @param numberOfHours number of working hour
     * @param pricePerHour rate per hour
     */
    Services(int numberOfHours, int pricePerHour){
        this.numberOfHours = numberOfHours;
        this.pricePerHour = pricePerHour;
    }

    Services(){
        this.numberOfHours = 0;
        this.pricePerHour = 0;
    }

    /**
     *
     * @param numberOfHours
     */
    public void setNumberOfHours(int numberOfHours) {
        this.numberOfHours = numberOfHours;
    }

    /**
     *
     * @param pricePerHour
     */
    public void setPricePerHour(int pricePerHour) {
        this.pricePerHour = pricePerHour;
    }

    /**
     *
     * @return number of hour
     */
    public int getNumberOfHours() {
        return numberOfHours;
    }

    /**
     *
     * @return rate or price per hour
     */
    public int getPricePerHour() {
        return pricePerHour;
    }

    /**
     *
     * @return get total service cost
     */
    public int getServices(){
        int services = this.numberOfHours * this.pricePerHour;
        return services;
    }

    @Override
    public String toString() {
        return "Services{" +
                "numberOfHours=" + numberOfHours +
                ", pricePerHour=" + pricePerHour +
                '}';
    }
}
