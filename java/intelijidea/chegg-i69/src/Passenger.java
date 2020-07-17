abstract public class Passenger implements DiscConsiderable{
    String name;
    int age;

    Passenger(String name, int age){
        this.name = name;
        this.age = age;
    }

    abstract void displayDetails();
}
