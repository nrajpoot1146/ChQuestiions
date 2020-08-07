import java.util.Scanner;

public class Orders {
    private double[] price = new double [5];
    private String[] name = new String[5];
    private int quantity[];
    private double billAmount;
    private double tax;
    private String s;
    Orders(){
        price = new double[5];
        this.price[0] = 5.25; //double
        this.price[1] = 5.75;
        this.price[2] = 5.95;
        this.price[3] = 5.95;
        this.price[4] = 5.95;

        this.name = new String[5];
        this.name[0] = "De Anza Burger"; //These are string, char just hold a letter
        this.name[1] = "Bacon Cheese ";
        this.name[2] = "Masroom Swiss ";
        this.name[3] = "Western Burger";
        this.name[4] = "Don Cali Burger";
        this.quantity = new int[5];
        this.billAmount = 0;
        this.tax = 0;
    }

    public void displayMenu() {
        System.out.println("********** De Anza Burger Menu **********\n");
        for(int i = 0; i < name.length; i++) {
            System.out.println((i + 1) + "." + name[i] + "\t$" + price[i]);
        }
        System.out.println("6.Exit <= Thank you for ordering\n");
    }
    //ask the user what burger and how many

    public void getInputs() {
        int qty = 0; //quantity
        int choice;
        Scanner sc = new Scanner(System.in);
        do
        {
        //Get the input by user
            System.out.println("Please enter your number 1 to 6: ");
            choice = sc.nextInt();
            if(choice < 6 && choice >= 1) {
                System.out.println("Enter the quantity: ");
                qty = sc.nextInt();
                quantity[choice - 1] += qty;
                displayMenu();
            }
            else if(choice > 6 || choice <= 0) {
                System.out.println("Unavailable number please enter again\n");
            }
        }while(choice != 6);

        boolean IsAllZero = true; //if the user enter 6 at the very beginning the code exit
        for(int i = 0; i < quantity.length; i++) {
            if(quantity[i] != 0) {
                IsAllZero = false;
            }
        }
        if (IsAllZero) {
            System.out.println("Thank for coming!");
            System.exit(0);
        }
        System.out.println("Are you a student or a staff: ");
        s = sc.next(); //student or staff
    }

    public void calculate() {
        for (int i = 0; i< quantity.length; i++) {
            billAmount += quantity[i] * price[i];
        }

        if (s.equalsIgnoreCase("staff")) {
            tax = 0.09 * billAmount;
        }
    }

    public void printBill() {
        System.out.println("\n******************** Bill ********************\n");
        System.out.println("Food Item " + " Quantity " + " Price Per Item");
        for(int i = 0; i < quantity.length; i++) {
            if(quantity[i] != 0) {
                System.out.println(name[i] + " "+ quantity[i] + " " + price[i]);
            }
        }
        System.out.printf("\nTotal(before tax) : %5.2f" , billAmount);
        System.out.printf("\nTax : %19.2f" , tax);
        System.out.printf("\nTotal(after tax) : %5.2f" , (billAmount+tax));
    }
}