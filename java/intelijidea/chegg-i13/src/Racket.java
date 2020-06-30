

public class Racket extends TennisShop {
    private int racketType;

    /**
     * Default constructor
     */
    Racket(){

    }

    /**
     *
     * @param brand of item
     * @param price of item
     * @param quantity of item
     * @param racketType of item
     */
    Racket(String brand, double price, int quantity, int racketType){
        super(brand, price, quantity);
        this.racketType = racketType;
        if (this.racketType == 1){
            super.setPrice(80.00);
        }else if(this.racketType == 2){
            super.setPrice(110.00);
        }else if(this.racketType == 3) {
            super.setPrice(235.00);
        }else{
            super.setPrice(185.00);
        }
    }

    /**
     * display racket details
     */
    @Override
    public void display() {
        System.out.println("TENNIS RACKET");
        System.out.println("Brand\t: "+this.getBrand());
        System.out.println("Type\t: "+this.getType());
        System.out.println("Price\t: RM" + String.format("%5.1f",this.getPrice()) );
        System.out.println("No Discount!");
        System.out.println("Quantity: "+ this.getQuantity());
        System.out.println("Subtotal: RM" + String.format("%5.2f", this.calcPrice()));
    }

    /**
     *
     * @return total price of item
     */
    @Override
    public double calcPrice() {
        double totalPrice = this.getQuantity() * this.getPrice();
        return totalPrice;
    }

    /**
     *
     * @return type of racket
     */
    private String getType(){
        if(this.racketType == 1){
            return "Junior Tennis Racket";
        }else if(this.racketType == 2){
            return "Beginners Tennis Racket";
        }else if(this.racketType == 3){
            return  "Advanced Tennis Racket";
        }
        return "All Tennis Racket";
    }
}
