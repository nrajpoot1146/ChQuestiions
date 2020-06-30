public class Customer {
    private String custName;
    private TennisShop[] itemList;
    private int numOfItem;
    private double totalPay;

    /**
     *
     * @param custName customer name
     */
    Customer(String custName){
        this.custName = custName;
        this.numOfItem = 0;
        this.totalPay = 0;
        this.itemList = new TennisShop[10];
    }

    /**
     *
     * @return customer name
     */
    public String getName() {
        return custName;
    }

    /**
     *
     * @return total payable ammount
     */
    public double getTotalPay() {
        return totalPay;
    }

    /**
     *
     * @return number of items
     */
    public int getNumOfItem() {
        return numOfItem;
    }

    /**
     *
     * @param tennisShop buy an item
     */
    public void buy(TennisShop tennisShop){
        this.totalPay += tennisShop.calcPrice();
        this.itemList[this.numOfItem] = tennisShop;
        this.numOfItem++;
        System.out.println("\nItem "+numOfItem);
        tennisShop.display();
    }

    /**
     *
     * @return heading of message
     */
    public String toString(){
        String res = "Welcome the "+ this.custName +"\n\nList of Tennis Items Bought\n";
        return res;
    }

    /**
     * print total payable amount
     */
    public void print(){
        double totalPrice = 0;
        for (TennisShop tennisShop : this.itemList){
            if(tennisShop == null){
                break;
            }
            totalPrice += tennisShop.calcPrice();
        }
        System.out.println("\nTOTAL: RM" + String.format("%5.2f",totalPrice));
    }
}
