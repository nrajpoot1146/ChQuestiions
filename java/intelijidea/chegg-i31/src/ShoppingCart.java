import java.util.Arrays;

public class ShoppingCart {
    private Item[] items;
    private int nbAddedItems;

    ShoppingCart(int maxNbItems){
        this.items = new Item[maxNbItems];
        this.nbAddedItems = 0;
    }

    /**
     * this function return array of items
     * @return array of items
     */
    public Item[] getItems() {
        return items;
    }

    /**
     * This function is use to add an item to shopping cart
     * @param i item to be added
     */
    public void addItems(Item i){
        if(nbAddedItems < this.items.length-1){
            this.items[this.nbAddedItems] = i;
            this.nbAddedItems++;
        }
    }

    /**
     *
     * @return number of items in cart
     */
    public int getNbAddedItems() {
        return nbAddedItems;
    }

    /**
     *
     * @param id of item to be buy
     * @return price of item with given id
     */
    public double buyItem(int id) {
         for (Item item : this.items){
             if(item.getId() == id){
                 return item.getPrice();
             }
         }
         return -1;
    }

    /**
     *
     * @return number of shoe present in shopping cart
     */
    private int getNumberOfShoes(){
        int count = 0;
        for (Item i : this.items){
            if(i instanceof Shoe){
                count++;
            }
        }
        return count;
    }

    /**
     *
     * @param color display all tshirt information with specific color
     */
    void displayTshirts(String color){
        for (Item item : this.items){
            if(item instanceof Tshirt){
                if (((Tshirt)item).getColor().equals(color)){
                    System.out.println(item.toString());
                }
            }
        }
    }

    @Override
    public String toString() {
        super.toString();
        return "ShoppingCart{" +
                "items=" + Arrays.toString(items)+"}";
    }
}
