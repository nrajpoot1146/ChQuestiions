public class Flight {
    private double price;
    private String from, to, id;
    private int numAdults, numKids;
    private Passenger[] passengerList;

    Flight(String id, String from, String to, double price){
        this.id = id;
        this.from = from;
        this.to = to;
        this.price = price;
    }
}
