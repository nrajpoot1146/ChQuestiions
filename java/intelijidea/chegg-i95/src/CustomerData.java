public class CustomerData extends PersonData{
    private int customerNumber;
    private boolean mailingList;

    /**
     * parameterize constructor
     * @param firstname of customer
     * @param lastname of customer
     * @param customerNumber of customer
     */
    CustomerData(String firstname, String lastname, int customerNumber){
        super(firstname, lastname);
        this.customerNumber = customerNumber;
    }

    /**
     * getter method for customer number
     * @return customer number
     */
    public int getCustomerNumber() {
        return customerNumber;
    }

    /**
     * setter method for customer number
     * @param customerNumber of customer
     */
    public void setCustomerNumber(int customerNumber) {
        this.customerNumber = customerNumber;
    }


    /**
     * getter method for maillist
     * @return
     */
    public boolean isMailingList() {
        return mailingList;
    }

    /**
     * setter method of maillist
     * @param mailingList to be set
     */
    public void setMailingList(boolean mailingList) {
        this.mailingList = mailingList;
    }

    @Override
    public String toString() {
        return "C " +
                "customerNumber=" + customerNumber +
                ", mailingList=" + mailingList;
    }
}
