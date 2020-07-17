import java.util.ArrayList;
import java.util.Scanner;

public class Driver {
    public static void main(String[] args){
        ArrayList<Computer> computers = new ArrayList<>();
        Scanner scanner = new Scanner(System.in);

        System.out.print("Enter number of different computers: ");
        int num = scanner.nextInt();
        scanner.nextLine();

        for (int i = 0; i < num; i++){
            // read details about screen
            System.out.println("Enter screen details: ");
            System.out.print("Serial number: ");
            String srNumber = scanner.nextLine();
            System.out.print("Height: ");
            int height = scanner.nextInt();
            System.out.print("Width: ");
            int width = scanner.nextInt();
            System.out.print("Basic price: ");
            double basicPrice = scanner.nextDouble();

            // create screen object
            Screen screen = new Screen(srNumber, width, height, basicPrice);

            // read details about computer
            System.out.println("Enter computer details: ");
            System.out.print("type: (1,2 or 3)");
            int type = scanner.nextInt();
            System.out.print("price: ");
            double price = scanner.nextDouble();
            System.out.print("Number of computers: ");
            int numOfComputers = scanner.nextInt();
            scanner.nextLine();

            // create computer object
            Computer computer = new Computer(type, screen, price, numOfComputers);

            computers.add(computer);
        }
        totalPriceOfScreen(computers);
        totalPriceOfComputer(computers);
        printDetailsTypeTwo(computers);
        computerWithSpecificScreen(computers);
        scanner.close();
    }

    /**
     * total price of screen
     * @param computers list of computers
     */
    public static void totalPriceOfScreen(ArrayList<Computer> computers){
        double totalPrice = 0;
        for (Computer c : computers){
            totalPrice += c.getScreen().computePrice();
        }
        System.out.println("Total price of Screens = " + totalPrice);
    }

    /**
     * total price of computers
     * @param computers list of computers
     */
    public static void totalPriceOfComputer(ArrayList<Computer> computers){
        double totalPrice = 0;
        for (Computer c : computers){
            totalPrice += c.computePrice();
        }
        System.out.println("Total price of Computers = " + totalPrice);
    }

    /**
     * print details of type two computer
     * @param computers list of computers
     */
    public static void printDetailsTypeTwo(ArrayList<Computer> computers){
        for (Computer c : computers){
            if (c.getType() == 2){
                System.out.println(c.toString());
            }
        }
    }

    /**
     * find computer information of computer with current serial number
     * @param computers list of computers
     */
    public static void computerWithSpecificScreen(ArrayList<Computer> computers){
        System.out.print("Enter serial number: ");
        String srNumber = new Scanner(System.in).nextLine();
        for (Computer c : computers){
            if (c.getScreen().getSrNumber().equals(srNumber)){
                System.out.println(c.toString());
            }
        }
    }
}
