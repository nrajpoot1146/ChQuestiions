import java.util.Date;

public class Dog extends Pet implements Mobility,Comparable<Dog>{
    private String breed;
    private int weight;

    Dog(String name, char gender, Date date, String breed, int weight) {
        super(name, gender, date);
        this.breed = breed;
        this.weight = weight;
    }


    @Override
    public String move() {
        return "Walks on a leash";
    }

    public int getWeight() {
        return weight;
    }

    public String getBreed() {
        return breed;
    }

    public String sound(){
        return "Barks or howls";
    }

    public String toString(){
        return this.getName()+", "+this.getBreed()+", "+this.getGender();
    }

    @Override
    public int compareTo(Dog o) {
        if(this.weight == o.weight){
            return 0;
        }else if(this.weight > o.weight){
            return 1;
        }
        return -1;
    }
}
