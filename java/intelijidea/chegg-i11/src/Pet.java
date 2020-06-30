import java.util.Date;

public abstract class Pet {
    private String name;
    private char gender;
    private Date acquired;

    Pet(String name, char gender, Date date) {
        this.name = name;
        this.gender = gender;
        this.acquired = date;
    }

    public String getName() {
        return name;
    }

    public char getGender() {
        return gender;
    }

    public Date getAcquired() {
        return acquired;
    }

    public abstract String sound();
}
