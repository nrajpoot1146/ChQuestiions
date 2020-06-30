//Controller class starts from here

package info.hccis.assignment;

import info.hccis.assignment.bo.Customer;
import info.hccis.assignment.bo.Login;
import info.hccis.assignment.bo.Order;
import info.hccis.util.CisUtility;
import java.text.NumberFormat;
import java.util.ArrayList;
import java.util.HashSet;
import java.util.Locale;
import java.util.Scanner;

public class Controller {
    private static double totalSoFar = 0;
    public static final String MENU = "\nMain Menu\n1 – Add an order\n"
            + "2 – Show total of all orders since program start\n" + "3 – Show all orders since program start\n"
            + "4 – Show all customers since program start\n" + "0 – Exit";

    private static ArrayList orders = new ArrayList();
    private static Login login = new Login();

    public static void main(String[] args) {

        Order.showBusinessInformation();

        String option = "";
        Scanner input = new Scanner(System.in);
        do {
            System.out.println(MENU);
            option = input.nextLine();
            switch (option) {
                case "1":
                    orders.add(addOrder());
                    break;
                case "2":
                    showTotalOfAllOrders();
                    break;
                case "3":
                    showOrders();
                    break;
                case "4":
                    showCustomers();
                    break;
                case "0":
                    System.out.println("Goodbye");
                    break;
                default:
                    System.out.println("Invalid option");
            }
        } while (!option.equalsIgnoreCase("0"));

    }

    public static void loadUsers() {
        String[] userNameArray = { "John", "Steve", "Bonnie", "Kylie", "Logan", "Robert" };
        String[] passwordArray = { "1111", "2222", "3333", "4444", "5555", "6666" };

        login.loadCredentials(userNameArray, passwordArray);

    }

    public static Order addOrder() {
        Order order = new Order();
        order.getInformation();
        order.display();
        totalSoFar += order.getTotal();

        return order;
    }

    public static void showTotalOfAllOrders() {

        NumberFormat format = NumberFormat.getCurrencyInstance(Locale.CANADA);
        System.out.println("Total so far: " + format.format(totalSoFar));
    }

    public static void showOrders() {
        for (Order order : orders) {
            order.display();
            System.out.println("");
        }
    }

    public static void showCustomers() {
        HashSet customers = new HashSet();
        for (Order order : orders) {
            customers.add(order.getCustomer());
        }
        for (Customer customer : customers) {
            customer.display();
            System.out.println("");
        }
    }

} // Controller class ends here