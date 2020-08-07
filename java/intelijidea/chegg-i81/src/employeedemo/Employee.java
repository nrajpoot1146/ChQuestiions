package employeedemo;

import java.time.LocalDateTime;

public class Employee {
    private String name; // name of employee
    private String number; // number of employee

    /**
     * default constructor
     * set name to null
     * set number to null
     */
    Employee(){
        this.name = null;
        this.number = null;
    }

    /**
     * overloaded constructor
     * @param name of employee
     * @param number of employee
     */
    Employee(String name, String number){
        this.name = name;
        this.number = number;
    }

    /**
     * get name of employee
     * @return name of employee
     */
    public String getEmployeeName() {
        return name;
    }

    /**
     * get number of employee
     * @return number of employee
     */
    public String getEmployeeNumber() {
        return number;
    }

    /**
     * set name of employee
     * @param name new name of employee
     */
    public void setEmployeeName(String name) {
        this.name = name;
    }

    /**
     * set number of employee
     * @param number number of employee
     */
    public void setEmployeeNumber(String number) {
        this.number = number;
    }

    /**
     * get current date and time
     * @return
     */
    public LocalDateTime getCurrentDateTime() {
        LocalDateTime currentTime = LocalDateTime.now();
        return currentTime;
    }

    /**
     * overloaded to string number
     * @return string of employee
     */
    @Override
    public String toString() {
        String result = "Employee\nhier Date: "+ getCurrentDateTime() +
                "\n name: "+getEmployeeName() +
                "\n number: "+getEmployeeNumber();
        return result;
    }
}
