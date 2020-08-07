import com.address.Address;
import com.person.Person;

/**
 * class employee
 * that has a person and an address object as contained data members;
 */
public class Employee {
    private Person person;
    private Address address;

    /**
     * parameterize constructor
     * @param person details
     * @param address address of employee
     */
    Employee(Person person, Address address){
        this.address = address;
        this.person = person;
    }

    /**
     * get address
     * @return
     */
    public Address getAddress() {
        return address;
    }

    /**
     * get person
     * @return
     */
    public Person getPerson() {
        return person;
    }

    /**
     * set address
     * @param address
     */
    public void setAddress(Address address) {
        this.address = address;
    }

    /**
     * set person
     * @param person
     */
    public void setPerson(Person person) {
        this.person = person;
    }

    @Override
    public String toString() {
        return "Employee{" +
                "person=" + person.toString() +
                ", address=" + address.toString() +
                '}';
    }
}
