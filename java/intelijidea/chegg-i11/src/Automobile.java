public class Automobile implements Comparable<Automobile>{
    private String model;
    private int year;
    private double price;

    Automobile(String model, int year, double price){
        this.model = model;
        this.year = year;
        this.price = price;
    }

    public void setModel(String model) {
        this.model = model;
    }

    public void setPrice(double price) {
        this.price = price;
    }

    public void setYear(int year) {
        this.year = year;
    }

    public double getPrice() {
        return price;
    }

    public int getYear() {
        return year;
    }

    public String getModel() {
        return model;
    }

    @Override
    public int compareTo(Automobile o) {
        if(this.year == o.year){
            return 0;
        }else if (this.year > o.year){
            return 1;
        }
        return -1;
    }

    public void display(){
        System.out.println(this.model+" "+this.year+ " " +this.price);
    }
}
