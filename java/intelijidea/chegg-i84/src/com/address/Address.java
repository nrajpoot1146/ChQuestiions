package com.address;

/**
 * class address
 */
public class Address {
    private String city;
    private String state;
    private String pincode;

    /**
     * parameterize constructor
     * @param city
     * @param state
     * @param pincode
     */
    public Address (String city, String state, String pincode){
        this.city = city;
        this.state = state;
        this.pincode = pincode;
    }

    /**
     * get city
     * @return
     */
    public String getCity() {
        return city;
    }

    /**
     * get pincode
     * @return
     */
    public String getPincode() {
        return pincode;
    }

    /**
     * get state
     * @return
     */
    public String getState() {
        return state;
    }

    /**
     * set city
     * @param city
     */
    public void setCity(String city) {
        this.city = city;
    }

    /**
     * set pincode
     * @param pincode
     */
    public void setPincode(String pincode) {
        this.pincode = pincode;
    }

    /**
     * set state;
     * @param state
     */
    public void setState(String state) {
        this.state = state;
    }

    @Override
    public String toString() {
        return "Address{" +
                "city='" + city + '\'' +
                ", state='" + state + '\'' +
                ", pincode='" + pincode + '\'' +
                '}';
    }
}
