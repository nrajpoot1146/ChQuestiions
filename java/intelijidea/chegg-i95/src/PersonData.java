public class PersonData {
    private String firstname;
    private String lastname;
    private String address;
    private String city;
    private String zip;
    private String phone;

    /**
     * user constructor
     * @param firstname of person
     * @param lastname of person
     */
    PersonData(String firstname, String lastname){
        this.firstname = firstname;
        this.lastname = lastname;
    }

    /**
     * getter method for first name
     * @return first name of person
     */
    public String getFirstname() {
        return firstname;
    }

    /**
     * setter method for first name
     * @param firstname of person to be set
     */
    public void setFirstname(String firstname) {
        this.firstname = firstname;
    }

    /**
     * getter method for last name
     * @return lastname of user
     */
    public String getLastname() {
        return lastname;
    }

    /**
     * setter method for lastname
     * @param lastname of person
     */
    public void setLastname(String lastname) {
        this.lastname = lastname;
    }

    /**
     * getter method for address
     * @return address of person
     */
    public String getAddress() {
        return address;
    }

    /**
     * setter method for address
     * @param address of person to be set
     */
    public void setAddress(String address) {
        this.address = address;
    }

    /**
     * getter method for city
     * @return city of person
     */
    public String getCity() {
        return city;
    }

    /**
     * setter method for city
     * @param city of person
     */
    public void setCity(String city) {
        this.city = city;
    }

    /**
     * getter method for xip
     * @return zip of person
     */
    public String getZip() {
        return zip;
    }

    /**
     * setter method for zip
     * @param zip of person
     */
    public void setZip(String zip) {
        this.zip = zip;
    }

    /**
     * getter method for phone
     * @return phone of person
     */
    public String getPhone() {
        return phone;
    }

    /**
     * setter method for phoone
     * @param phone of person to be set
     */
    public void setPhone(String phone) {
        this.phone = phone;
    }

    @Override
    public String toString() {
        return " " +
                "firstname='" + firstname + '\'' +
                ", lastname='" + lastname + '\'' +
                ", address='" + address + '\'' +
                ", city='" + city + '\'' +
                ", zip='" + zip + '\'' +
                ", phone='" + phone + '\'';
    }
}
