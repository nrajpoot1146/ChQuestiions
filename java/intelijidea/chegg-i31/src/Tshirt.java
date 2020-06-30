import java.util.Objects;

public class Tshirt extends Item{
    private String color;

    Tshirt(int id, double price, String brand, String color){
        super(id, price, brand);
        this.color = color;
    }

    /**
     *
     * @param color of Tshirt
     */
    public void setColor(String color) {
        this.color = color;
    }

    /**
     *
     * @return color of Tshirt
     */
    public String getColor() {
        return color;
    }

    @Override
    public boolean equals(Object o) {
        if(this.color.equals(((Tshirt)o).color) && this.getPrice() == ((Tshirt)o).getPrice()){
            return true;
        }
        return false;
    }


    @Override
    public String toString() {
        return "T-shirt: " +
                "ID: "+this.getId()+", " +
                "Price: "+this.getPrice()+", " +
                "Brand: "+this.getBrand()+", " +
                "Color: "+this.getColor();
    }
}
