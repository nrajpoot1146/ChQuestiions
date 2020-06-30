public class Shoe extends Item{
    private int size;

    Shoe(int id, double price, String brand, int size){
        super(id, price, brand);
        this.size = size;
    }

    /**
     *
     * @param size of shoe
     */
    public void setSize(int size) {
        this.size = size;
    }

    /**
     *
     * @return size of shoe
     */
    public int getSize() {
        return size;
    }

    @Override
    public String toString() {
        return "Shoe: " +
                "Id: "+this.getId()+", " +
                "Price: "+this.getPrice()+", " +
                "Brand: "+this.getBrand()+", " +
                "Size: "+this.getBrand();
    }
}
