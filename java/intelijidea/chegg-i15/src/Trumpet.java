public class Trumpet {
    private String brand;
    private String type;
    private double price;
    private double sale;

    /**
     * constructor to create Trumpet instance with parameter
     * @param brand name
     * @param type type whether professional or intermediate
     * @param price of sale
     */
    public Trumpet(String brand, String type, double price){
        this.brand = brand;
        this.type = type;
        this.price = price;
        this.sale = 0;
    }

    /**
     * set value of sale in percent
     * @param sale off on sale
     */
    public void sale(int sale){
        this.sale = sale;
        System.out.println("Sale Price: "+String.format("%3.1f",this.sale)+" percent off");
    }

    /**
     * generate string
     * @return string of value of all properties
     */
    public String toString(){
        String res = "";
        res += "Brand:"+this.brand+" ";
        res += "Type:"+this.type+" ";
        res += "Price:"+String.format("%5.1f",(this.price-(this.price*this.sale/100)));
        return res;
    }

}
