package employeedemo;

public class Person extends Employee implements HRpay{
    private double Salary; // salary of person

    /**
     * overloaded constructor
     * @param name of person
     * @param number of person
     * @param Salary of person
     */
    Person(String name, String number, double Salary){
        super(name, number);
    }

    @Override
    public void setNewSalary(double Salary) {
        this.Salary = Salary;
    }

    @Override
    public double getNewSalary() {
        return this.Salary;
    }

    /**
     * overloaded to string method
     * @return
     */
    @Override
    public String toString() {
        String result = "Employee\nhier Date: "+ getCurrentDateTime() +
                "\n name: "+getEmployeeName() +
                "\n number: "+getEmployeeNumber() +
                "\n Salary: "+getNewSalary();
        return result;
    }
}
