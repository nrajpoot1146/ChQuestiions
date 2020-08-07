import com.address.Address;
import com.person.Person;

/**
 * class employee1
 * that inherits from Person
 * and act as a container class for address object;
 */
public class Employee1 extends Person {
    private Address address;

    /**
     * parameterize constructor
     * @param name of employee
     * @param age of employee
     * @param gender of employee
     * @param address of employee
     */
    Employee1(String name, int age, char gender, Address address){
        super(name, age, gender);
        this.address = address;
    }

    /**
     * get address of employee
     * @return
     */
    public Address getAddress() {
        return address;
    }

    /**
     * set address of employee
     * @param address
     */
    public void setAddress(Address address) {
        this.address = address;
    }

    @Override
    public String toString() {
        return "Employee1{" +
                "person= " + super.toString()+
                "address=" + address +
                '}';
    }
}
