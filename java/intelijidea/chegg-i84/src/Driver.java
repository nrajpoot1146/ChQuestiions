import com.address.Address;
import com.person.Person;

public class Driver {
    public static void main(String... args){
        Person person = new Person("John", 22, 'M');
        Address address = new Address("Mysure", "Karnataka", "255645");

        System.out.println("Using container: ");
        Employee employee = new Employee(person, address);
        System.out.println(employee.toString());
        System.out.println();

        System.out.println("Using inherit class: ");
        Employee1 employee1 = new Employee1("John", 21, 'M', address);
        System.out.println(employee1.toString());
        System.out.println();
    }
}
