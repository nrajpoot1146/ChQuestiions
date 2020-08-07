public class Name {
    private String firstName;
    private String lastName;

    /**
     * constructor with one parameter
     * sets lastname to empty string
     * @param firstName
     */
    Name(String firstName){
        this(firstName, "");
    }

    /**
     * constructor with two parameter
     * @param firstName
     * @param lastName
     */
    Name(String firstName, String lastName){
        this.firstName = firstName;
        this.lastName = lastName;
    }

    /**
     * set first name
     * @param firstName to be set
     */
    public void setFirstName(String firstName) {
        this.firstName = firstName;
    }

    /**
     * set last name
     * @param lastName to be set
     */
    public void setLastName(String lastName) {
        this.lastName = lastName;
    }

    /**
     * get last name
     * @return last name
     */
    public String getLastName() {
        return lastName;
    }

    /**
     * get first name
     * @return first name
     */
    public String getFirstName() {
        return firstName;
    }

    /**
     * check whether two name are equal or not
     * @param o another name object
     * @return true if both name is equal otherwise return false
     */
    public boolean equals(Name o){
        if (this.firstName.equals(o.firstName) && this.lastName.equals(o.lastName)){
            return true;
        }
        return false;
    }

    @Override
    public String toString() {
        return this.firstName + " " + this.lastName;
    }
}
