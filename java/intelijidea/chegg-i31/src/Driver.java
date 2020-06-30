public class Driver {

    public static void main(String[] args){
        ShoppingCart shoppingCart = new ShoppingCart(4);

        shoppingCart.addItems(new Shoe(123, 98.0, "Adidas", 38));
        shoppingCart.addItems(new Shoe(124, 99.0, "Adidas", 40));
        shoppingCart.addItems(new Tshirt(125, 78.0, "Jio", "Black"));
        shoppingCart.addItems(new Tshirt(129, 88.0, "Jio", "Red"));

        shoppingCart.displayTshirts("Black");

        Item[] items = shoppingCart.getItems();

        for (Item i : items){
            if(i instanceof Shoe){
                Shoe shoe = (Shoe) i;
                if(shoe.getSize() == 40)
                    System.out.println(shoe.toString());
            }
        }
    }
}
