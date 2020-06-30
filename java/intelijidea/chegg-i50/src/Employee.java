import java.util.ArrayList;

/**
 * The Employee class is an abstract class that holds general data about a company's
 * employee. Classes representing more specific types of employees should inherit
 * from this class.
 *
 * @author [student name] - Group member 2
 */
public abstract class Employee
{
    // static variable
    private static int nextEmployeeID = 1;

    // instance variables
    private int employeeID;
    private String firstName;
    private String lastName;
    private ArrayList listOfPaychecks = new ArrayList<>();

    /**
     * This is the default constructor. It only initializes the employee's id.
     */
    public Employee()
    {
        employeeID = nextEmployeeID;
        firstName = "";
        lastName = "";

        nextEmployeeID++;
    }

    /**
     * This constructor sets the employee's id and name.
     * @param first The employee's first name.
     * @param last The employee's last name.
     */
    public Employee(String first, String last)
    {
        employeeID = nextEmployeeID;
        firstName = first;
        lastName = last;

        nextEmployeeID++;
    }

    /**
     * The calculateGrossAmount method calculates the gross amount paid to an employee
     * during a pay period.
     * @return The gross amount for a pay period.
     */
    abstract public double calculateGrossAmount();

    /**
     * The getEmployeeID method returns the employee's identification number.
     * @return The employee's id.
     */
    public int getEmployeeID()
    {
        return this.employeeID;
    }

    /**
     * The getFirstName method returns the employee's first name.
     * @return The employee's first name.
     */
    public String getFirstName()
    {
        return this.firstName;
    }

    /**
     * The getLastName method returns the employee's last name.
     * @return The employee's last name.
     */
    public String getLastName()
    {
        return this.lastName;
    }

    /**
     * The setFirstName method sets the employee's first name.
     * @param first The value to store in the first name field.
     */
    public void setFirstName(String first)
    {
        this.firstName = first;
    }

    /**
     * The setLastName method sets the employee's last name.
     * @param last The value to store in the last name field.
     */
    public void setLastName(String last)
    {
        this.lastName = last;
    }

    /**
     * The addPaycheck method creates and adds a Paycheck object to the list of paychecks that
     * the employee has received.
     * @param beginDate Begin date for this paycheck's pay period.
     * @param endDate End date for this paycheck's pay period.
     */
    public void addPaycheck(String beginDate, String endDate)
    {
        double grossAmount = calculateGrossAmount(); // Call the calculateGrossAmount() method,
        Paycheck  paycheck = new Paycheck(beginDate, endDate, grossAmount); // Call the constructor in the Paycheck class passing beginDate, endDate, and gross amount
        listOfPaychecks.add(paycheck); // Add the Paycheck object just created to listOfPaychecks
    }

    /**
     * The toString method returns a string containing the state of an Employee object.
     * @return A string containing the employee's information: id, first name,
     * last name, and list of paychecks received.
     */
    @Override
    public String toString()
    {
        String output = String.format( "\n%-30s %s \n%-30s %s \n%-30s %s \n%-30s %-15s %-15s %s",
                "Employee ID:", this.employeeID,
                "First Name:", this.firstName,
                "Last Name:", this.lastName,
                "Paychecks Received:", "PERIOD BEGIN", "PERIOD END", "GROSS AMOUNT");

        if( listOfPaychecks == null || listOfPaychecks.isEmpty() )
        {
            output += String.format("\n%-30s %s", "", "None");
        }
        else
        {
            for( Paycheck checkElement : listOfPaychecks)
            {
                output += String.format( "\n%-30s %-15s %-15s %s",
                        "",
                        checkElement.getPeriodBeginDate(),
                        checkElement.getPeriodEndDate(),
                        checkElement.getGrossAmount());
            }
        }

        return output;
    }

}