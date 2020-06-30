public class Person {
    public static int nPerson = 0;
    private String name;
    private String lastName;

    /**
     * Constructor create instance of Person
     * sets name to given name
     * sets lastname to empty
     * @param name of person
     */
    Person(String name){
        this.name = name;
        this.lastName = "";
    }

    /**
     * Constructor to create instance of Person
     * sets name to passed name
     * sets lastname to passed lastname
     * @param name name of person
     * @param lastName lastname of person
     */
    Person(String name, String lastName){
        this.name = name;
        this.lastName = lastName;
    }

    /**
     * sets name of person
     * @param name name of person
     */
    public void setName(String name) {
        this.name = name;
    }

    /**
     * get name of person
     * @return name of person
     */
    public String getName() {
        return name;
    }

    /**
     * sets last name of person
     * @param lastName name of person
     */
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    /**
     * get last name of person
     * @return last name of person
     */
    public String getLastName() {
        return lastName;
    }

    /**
     * generate a string with person attribute
     * @return string of person attribute
     */
    @Override
    public String toString() {
        return "name : "+this.name+" "+this.lastName;
    }
}
