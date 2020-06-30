import java.util.Date;

public class Reptile extends Pet implements Mobility{
    private String type;

    Reptile(String name, char gender, Date date, String type){
        super(name, gender, date);
        this.type = type;
    }

    public String getType() {
        return type;
    }

    @Override
    public String move() {
        return "Must be caged, crawls or slithers";
    }

    public String sound(){
        return "Not much sound, maybe a hiss";
    }

    public String toString(){
        return this.getName()+", "+this.getType()+", "+this.getGender();
    }
}
