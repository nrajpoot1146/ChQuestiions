public class Name implements Comparable<Name>{

    private String firstName;
    private String lastName;

    public Name(){
        firstName = "";
        lastName = "";
    }

    public Name(String firstName, String lastName){
        setFirstName(firstName);
        setLastName(lastName);
    }

    public String getFirstName() {
        return firstName;
    }

    public String getLastName() {
        return lastName;
    }

    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    @Override
    public int compareTo(Name n) {
        if (lastName.compareTo(n.getLastName()) == 0){
            return firstName.compareTo(n.getFirstName());
        }
        return lastName.compareTo(n.getLastName());
    }

    @Override
    public String toString() {
        return firstName + " " + lastName;
    }
}
