package employeedemo;

public class EmployeeDemo {
    public static void main(String... args){
        // -----EmployeeDemo test to verify constructor---------
        //----CustomerNumber, overload toString() method--------
        Employee emp = new Employee();
        emp.setEmployeeName("Scott.Tiger");
        emp.setEmployeeNumber("123-M");
        System.out.println(emp.toString());

        // Implementing inheritance and overload toString class Employee
        Person p = new Person("Scott.Tiger", "123-M", 2000);
        p.setNewSalary(40000);
        System.out.println(p.toString());
    }
}
